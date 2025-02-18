#include "encoder.h"
#include "ui.h"
#define ESP_INTR_FLAG_DEFAULT 0

QueueHandle_t encoder_gpio_event_queue = NULL;   //编码器队列
static unsigned int Value_count = 0;            //状态计数
static int Encoder_A_Last_Value = 0;            //第一次A项的值
static int Encoder_B_Last_Value = 0;            //第一次B项的值
static int Encoder_A_Value = 0;                 //第二次A项的值
static int Encoder_B_Value = 0;                 //第二次B项的值

volatile int16_t encoder_dir = 0;                        //编码器方向
volatile uint8_t encoder_dir_change = 0;                 //编码器方向变化标志位
volatile int16_t encoder_dir_count = 0;

volatile uint8_t encoder_dir_buzzer_trig = 0;
volatile uint8_t encoder_key_buzzer_trig = 0;

#define TAG "Encoder"

/*****************************************
 * @brief GPIO中断处理
 * @author wsp
 * @date  2022-2-21
 * ***************************************/
static void IRAM_ATTR encoder_gpio_isr_handler(void * arg)
{
    //uint32_t GPIO_Queue_Data = 0;       //发送队列变量
    //uint16_t gpio_num = (uint16_t) arg;
    
    //encoder_dir = 0;
    //gpio_intr_disable(Encoder_A);

    //////////////////////////
    Encoder_A_Value = gpio_get_level(Encoder_A);        //捕获A项的值
    Encoder_B_Value = gpio_get_level(Encoder_B);        //捕获B项的值

    //当A发生跳变时采集B当前的状态，并将B与上一次的状态进行对比。
    if(Encoder_A_Value != Encoder_A_Last_Value)
    {
        //若A 0->1 时，B 1->0 正转；若A 1->0 时，B 0->1 正转
        //若A 0->1 时，B 0->1 反转；若A 1->0 时，B 1->0 反转
        if(Encoder_A_Value == 1)
        {
            //EC11_B和上一次状态相比，为下降沿
            if((Encoder_B_Last_Value == 1)&&(Encoder_B_Value == 0))
            {
                //顺时针旋转
                //encoder_dir = 1;
                //encoder_dir_change = 1;

                encoder_dir_count++;
            }
            //EC11_B和上一次状态相比，为上升沿
            if((Encoder_B_Last_Value == 0)&&(Encoder_B_Value == 1))
            {
                //逆时针旋转
                //encoder_dir = -1;
                //encoder_dir_change = 1;

                encoder_dir_count--;
            }

            //>>>>>>>>>>>>>>>>下面为正转一次再反转或反转一次再正转处理<<<<<<<<<<<<<<<<//
            //A上升沿时，采集的B不变且为0
            if((Encoder_B_Last_Value == Encoder_B_Value)&&(Encoder_B_Value == 0))
            {
                //顺时针旋转
                //encoder_dir = 1;
                //encoder_dir_change = 1;

                encoder_dir_count++;
            }
            //A上升沿时，采集的B不变且为1
            if((Encoder_B_Last_Value == Encoder_B_Value)&&(Encoder_B_Value == 1))
            {
                //逆时针旋转
                //encoder_dir = -1;
                //encoder_dir_change = 1;

                encoder_dir_count--;
            }
        }
        else    //EC11_A和上一次状态相比，为下降沿
        {
            //EC11_B和上一次状态相比，为下降沿
            if((Encoder_B_Last_Value == 1)&&(Encoder_B_Value == 0))
            {
                //逆时针旋转
                //encoder_dir = -1;
                //encoder_dir_change = 1;

                encoder_dir_count--;
            }
            //EC11_B和上一次状态相比，为上升沿
            if((Encoder_B_Last_Value == 0)&&(Encoder_B_Value == 1))
            {
                //顺时针旋转
                //encoder_dir = 1;
                //encoder_dir_change = 1;

                encoder_dir_count++;
            }

            //>>>>>>>>>>>>>>>>下面为正转一次再反转或反转一次再正转处理<<<<<<<<<<<<<<<<//
            //A上升沿时，采集的B不变且为0
            if((Encoder_B_Last_Value == Encoder_B_Value)&&(Encoder_B_Value == 0))
            {
                //逆时针旋转
                //encoder_dir = -1;
                //encoder_dir_change = 1;

                encoder_dir_count--;
            }
            //A上升沿时，采集的B不变且为1
            if((Encoder_B_Last_Value == Encoder_B_Value)&&(Encoder_B_Value == 1))
            {
                //顺时针旋转
                //encoder_dir = 1;
                //encoder_dir_change = 1;

                encoder_dir_count++;
            }
        }

        Encoder_A_Last_Value = Encoder_A_Value;       //更新编码器上一个状态暂存变量
        Encoder_B_Last_Value = Encoder_B_Value;       //更新编码器上一个状态暂存变量
    }

    if(encoder_dir_count > 1)
    {
        encoder_dir_count = 0;
        encoder_dir = 1;
        encoder_dir_change = 1;
    }

    if(encoder_dir_count < -1)
    {
        encoder_dir_count = 0;
        encoder_dir = -1;
        encoder_dir_change = 1;
    }

    //gpio_intr_enable(Encoder_A);

    //if(GPIO_Queue_Data != 0)            //状态改变的时候 发送队列
        //xQueueSendFromISR(encoder_gpio_event_queue, &GPIO_Queue_Data, NULL); 
}
/*****************************************
 * @brief 编码器初始化
 * @author wsp
 * @date  2022-2-21
 * ***************************************/
void EncoderGpioConfig(void)
{
    gpio_config_t io_conf;                                  //配置GPIO结构体
    io_conf.intr_type = GPIO_INTR_DISABLE;                  //不使能GPIO中断
    io_conf.mode = GPIO_MODE_INPUT;                         //GPIO输入模式
    io_conf.pull_down_en = 0;                               //下拉不使能
    io_conf.pull_up_en = 1;                                 //上拉使能
    io_conf.pin_bit_mask = Encoder_CHB_GPIO_INPUT_PIN_SEL;  //GPIO输入引脚选择
    gpio_config(&io_conf);                                  //配置IO参数

    io_conf.intr_type = GPIO_INTR_ANYEDGE;                  //边沿触发中断
    //io_conf.intr_type = GPIO_INTR_DISABLE;
    io_conf.pin_bit_mask = Encoder_CHA_GPIO_INPUT_PIN_SEL;  //GPIO输入引脚选择
    gpio_config(&io_conf);                                  //配置IO参数

    io_conf.intr_type = GPIO_INTR_DISABLE;                  //不使能GPIO中断
    io_conf.pin_bit_mask = Encoder_KEY_GPIO_INPUT_PIN_SEL;  //GPIO输入引脚选择
    gpio_config(&io_conf);                                  //配置IO参数

    gpio_install_isr_service(ESP_INTR_FLAG_DEFAULT);        //安装GPIO中断服务
    gpio_isr_handler_add(Encoder_A,encoder_gpio_isr_handler,(void * )Encoder_A);//添加中断服务    
    
    //encoder_gpio_event_queue = xQueueCreate(1,sizeof(uint32_t));                //创建队列
}

void Encoder_Loop(void)
{
    char Capure_Enconder_State = 0;

    while(1)
    {
        //获取队列信息
        if (pdTRUE == xQueueReceive(encoder_gpio_event_queue, &Capure_Enconder_State, (TickType_t)portMAX_DELAY))
        {
            printf("Capure_Enconder_State:%d\n\r",Capure_Enconder_State);
        }

        vTaskDelay(pdMS_TO_TICKS(10));
    }   
    vTaskDelete(NULL);
}

void Encoder_Init(void)
{
    EncoderGpioConfig();

    /*
    xTaskCreatePinnedToCore(
        Encoder_Loop, 
        "Encoder task",
        4096, 
        NULL, 
        2, 
        NULL, 
        0);
    */
}

uint8_t user_lvgl_encoder_key_get(void)
{
    return (uint8_t)gpio_get_level(Encoder_K);
}

int16_t user_lvgl_encoder_dir_get(void)
{
    /*
    static bool _is_AB_all_HIGH = true;             // 只读取双双高电平后的第一个波形
    uint8_t _ch_a = gpio_get_level(Encoder_A);      // 先存再判断,避免刚好两次读的不一样
    uint8_t _ch_b = gpio_get_level(Encoder_B);      // 因为这些值要多次使用

    if (_is_AB_all_HIGH)    // 只读取双双高电平后的第一个波形
    {
        if (_ch_a == 0 && _ch_b == 1)
        {
            _is_AB_all_HIGH = false;    // 一格旋转只读取一次就够了

            encoder_dir = 1;

            return 1;                   // 直接返回,编码器顺时针
        }
        else if (_ch_a == 1 && _ch_b == 0)
        {
            _is_AB_all_HIGH = false;

            encoder_dir = -1;

            return -1; // 直接返回,编码器逆时针
        }
    }
    else
    {
        if (_ch_a == 1 && _ch_b == 1)
        {
            _is_AB_all_HIGH = true; // 都是高电平后,无旋转,进入可读状态

            encoder_dir = 0;
        }
  }

  return 0;
  */
    
    ///*
    if(encoder_dir_change == 1)
    {
        encoder_dir_change = 0;

        encoder_dir_buzzer_trig = 1; 

        /*
        if(encoder_dir == 0)
        {
            printf("Encoder_A_Last_Value:%d\n\r",Encoder_A_Last_Value);
            printf("Encoder_A_Value:%d\n\r",Encoder_A_Last_Value);
            printf("Encoder_B_Last_Value:%d\n\r",Encoder_B_Last_Value);
            printf("Encoder_B_Value:%d\n\r",Encoder_B_Value);

        }
        */
    }
    else
    {
        //printf("encoder_dir_count:%d\n\r",encoder_dir_count);
        
        encoder_dir = 0;
    }
    //*/

    /*
    encoder_dir = 0;

     //////////////////////////
    Encoder_A_Value = gpio_get_level(Encoder_A);        //捕获A项的值
    Encoder_B_Value = gpio_get_level(Encoder_B);        //捕获B项的值

    //当A发生跳变时采集B当前的状态，并将B与上一次的状态进行对比。
    if(Encoder_A_Value != Encoder_A_Last_Value)
    {
        //若A 0->1 时，B 1->0 正转；若A 1->0 时，B 0->1 正转
        //若A 0->1 时，B 0->1 反转；若A 1->0 时，B 1->0 反转
        if(Encoder_A_Value == 1)
        {
            //EC11_B和上一次状态相比，为下降沿
            if((Encoder_B_Last_Value == 1)&&(Encoder_B_Value == 0))
            {
                //顺时针旋转
                //encoder_dir = 1;
                //encoder_dir_change = 1;

                encoder_dir_count++;
            }
            //EC11_B和上一次状态相比，为上升沿
            if((Encoder_B_Last_Value == 0)&&(Encoder_B_Value == 1))
            {
                //逆时针旋转
                //encoder_dir = -1;
                //encoder_dir_change = 1;

                encoder_dir_count--;
            }

            //>>>>>>>>>>>>>>>>下面为正转一次再反转或反转一次再正转处理<<<<<<<<<<<<<<<<//
            //A上升沿时，采集的B不变且为0
            if((Encoder_B_Last_Value == Encoder_B_Value)&&(Encoder_B_Value == 0))
            {
                //顺时针旋转
                //encoder_dir = 1;
                //encoder_dir_change = 1;

                encoder_dir_count++;
            }
            //A上升沿时，采集的B不变且为1
            if((Encoder_B_Last_Value == Encoder_B_Value)&&(Encoder_B_Value == 1))
            {
                //逆时针旋转
                //encoder_dir = -1;
                //encoder_dir_change = 1;

                encoder_dir_count--;
            }
        }
        else    //EC11_A和上一次状态相比，为下降沿
        {
            //EC11_B和上一次状态相比，为下降沿
            if((Encoder_B_Last_Value == 1)&&(Encoder_B_Value == 0))
            {
                //逆时针旋转
                //encoder_dir = -1;
                //encoder_dir_change = 1;

                encoder_dir_count--;
            }
            //EC11_B和上一次状态相比，为上升沿
            if((Encoder_B_Last_Value == 0)&&(Encoder_B_Value == 1))
            {
                //顺时针旋转
                //encoder_dir = 1;
                //encoder_dir_change = 1;

                encoder_dir_count++;
            }

            //>>>>>>>>>>>>>>>>下面为正转一次再反转或反转一次再正转处理<<<<<<<<<<<<<<<<//
            //A上升沿时，采集的B不变且为0
            if((Encoder_B_Last_Value == Encoder_B_Value)&&(Encoder_B_Value == 0))
            {
                //逆时针旋转
                //encoder_dir = -1;
                //encoder_dir_change = 1;

                encoder_dir_count--;
            }
            //A上升沿时，采集的B不变且为1
            if((Encoder_B_Last_Value == Encoder_B_Value)&&(Encoder_B_Value == 1))
            {
                //顺时针旋转
                //encoder_dir = 1;
                //encoder_dir_change = 1;

                encoder_dir_count++;
            }
        }

        Encoder_A_Last_Value = Encoder_A_Value;       //更新编码器上一个状态暂存变量
        Encoder_B_Last_Value = Encoder_B_Value;       //更新编码器上一个状态暂存变量
    }

    if(encoder_dir_count > 1)
    {
        encoder_dir_count = 0;
        encoder_dir = 1;
        encoder_dir_change = 1;
    }

    if(encoder_dir_count < -1)
    {
        encoder_dir_count = 0;
        encoder_dir = -1;
        encoder_dir_change = 1;
    }
    */
    
    //printf("encoder_dir:%d\n\r",encoder_dir);

    return encoder_dir;
    //*/
}

uint32_t obj_count = 0;

void encoder_read(lv_indev_drv_t *indev_drv, lv_indev_data_t *data)
{
    int16_t enc_dir = 0;

    lv_obj_t * scr_act;
    lv_obj_t * focused_obj;
    lv_obj_t * first_obj;
    lv_group_t * group;
    lv_indev_t * indev;
    
    
    enc_dir = user_lvgl_encoder_dir_get(); //! 编码器和按键合一se版本  旋转方向  +1 0 和-1

    

    if(enc_dir == 1)
    {
        //data->key = LV_KEY_DOWN;
        //data->state = LV_INDEV_STATE_PRESSED;
        indev = lv_indev_get_act();
        focused_obj = lv_group_get_focused(indev->group); //获取当前焦点对象
        scr_act = lv_scr_act(); //获取当前屏幕

        if((scr_act == ui_Screen2) && (focused_obj == btn11))
        {
            enc_dir = 0;
            lv_group_del(indev->group);
            _ui_screen_change( &ui_Screen1, LV_SCR_LOAD_ANIM_MOVE_TOP, 500, 0, &lvgl_screen1_init);
            lvgl_screen1_group_init();
        }
    }
    else if(enc_dir == -1)
    {
        //data->key = LV_KEY_UP;
        //data->state = LV_INDEV_STATE_PRESSED;
        indev = lv_indev_get_act();
        focused_obj = lv_group_get_focused(indev->group); //获取当前焦点对象
        scr_act = lv_scr_act(); //获取当前屏幕

        if((scr_act == ui_Screen1) && (focused_obj == btn1))
        {
            enc_dir = 0;
            lv_group_del(indev->group);
            _ui_screen_change( &ui_Screen2, LV_SCR_LOAD_ANIM_MOVE_BOTTOM, 500, 0, &lvgl_screen2_init);
            lvgl_screen2_group_init();
        }

    }
    else if(enc_dir == 0)
    {
        //data->state = LV_INDEV_STATE_RELEASED;

        /*
        if (user_lvgl_encoder_key_get())    // 平时为1 按下为0
        {                                        
            //data->key = LV_KEY_ENTER;
            data->state = LV_INDEV_STATE_RELEASED; // 没有键被按下
        }
        else
        {
            //data->key = LV_KEY_ENTER;
            data->state = LV_INDEV_STATE_PRESSED; // 中键按下为0
        }
        */  
    }

    data->enc_diff = enc_dir; //编码器旋转方向

    if (user_lvgl_encoder_key_get())    // 平时为1 按下为0
    {                                        
        //data->key = LV_KEY_ENTER;
        data->state = LV_INDEV_STATE_RELEASED; // 没有键被按下
    }
    else
    {
        //data->key = LV_KEY_ENTER;
        data->state = LV_INDEV_STATE_PRESSED; // 中键按下为0
    }

}

void keypad_read(lv_indev_drv_t *indev_drv, lv_indev_data_t *data)
{
    /*
    int16_t enc_dir = 0;
    
    enc_dir = user_lvgl_encoder_dir_get(); //! 编码器和按键合一se版本  旋转方向  +1 0 和-1

    data->enc_diff = enc_dir;

    if(enc_dir == 1)
    {
        //data->key = LV_KEY_LEFT;
    }
    else if(enc_dir == -1)
    {
        //data->key = LV_KEY_RIGHT;
    }

    if (user_lvgl_encoder_key_get())    // 平时为1 按下为0
    {                                        
        data->state = LV_INDEV_STATE_RELEASED; // 没有键被按下
    }
    else
    {
        data->state = LV_INDEV_STATE_PRESSED; // 中键按下为0
    }
    */
}