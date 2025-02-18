#include "bsp_led.h"
#include "buzzer.h"
#include "encoder.h"

//配置输出寄存器
#define GPIO_OUTPUT_PIN_SEL  (1ULL<<LED_PIN)

volatile uint8_t led_blink_flag = 0;
volatile uint16_t led_blink_delay_ms = 0;

/**
 * @函数说明        LED的初始化
 *
 */
void LedGpioConfig(void)
{
    gpio_config_t gpio_init_struct = {0};

    //配置IO为通用IO
    esp_rom_gpio_pad_select_gpio(LED_PIN);

    gpio_init_struct.intr_type = GPIO_INTR_DISABLE;             //不使用中断
    gpio_init_struct.mode = GPIO_MODE_OUTPUT;                   //输出模式
    gpio_init_struct.pull_up_en = GPIO_PULLUP_ENABLE;           //使能上拉模式
    gpio_init_struct.pull_down_en = GPIO_PULLDOWN_DISABLE;      //失能下拉模式
    gpio_init_struct.pin_bit_mask = GPIO_OUTPUT_PIN_SEL;        //使用GPIO9输出寄存器

    //将以上参数配置到引脚
    gpio_config( &gpio_init_struct );

    //设置引脚输出高电平，默认不让LED亮
    gpio_set_level(LED_PIN, 1);
}

/**
 * @函数说明        设置LED亮
 *
 */
void LedOn(void)
{
    gpio_set_level(LED_PIN, 0);
}

/**
 * @函数说明        设置LED灭
 *
 */
void LedOff(void)
{
    gpio_set_level(LED_PIN, 1);
}


void Led_Loop(void *parameter)
{
    //Wireless_Init();
    while(1)
    {
        if(led_blink_flag == 0)
        {  
            //LedOff();
            //printf("LedOff\n");

            //buzzer_play(500, BUZZER_DUTY);

            led_blink_flag = 1;
            led_blink_delay_ms = 300;
        }
        else
        {   
            //LedOn();
            //printf("LedOn\n");

            //buzzer_play(800, BUZZER_DUTY);

            led_blink_flag = 0;
            led_blink_delay_ms = 300;
        }

        if(encoder_dir_buzzer_trig == 1)
        {
            encoder_dir_buzzer_trig = 0;

            buzzer_play(1500, BUZZER_DUTY);
            vTaskDelay(pdMS_TO_TICKS(50));
            buzzer_stop();
        }

        if(encoder_key_buzzer_trig == 1)
        {
            encoder_key_buzzer_trig = 0;

            buzzer_play(1300, BUZZER_DUTY);
            vTaskDelay(pdMS_TO_TICKS(80));
            buzzer_play(1450, BUZZER_DUTY);
            vTaskDelay(pdMS_TO_TICKS(80));
            buzzer_stop();    

        }
        
        //QMI8658_Loop();
        //PCF85063_Loop();
        //BAT_Get_Volts();
        //PWR_Loop();
        vTaskDelay(pdMS_TO_TICKS(led_blink_delay_ms));
    }
    vTaskDelete(NULL);
}

void LED_Init(void)
{
    //LED初始化
    //LedGpioConfig();

    
    xTaskCreatePinnedToCore(
        Led_Loop, 
        "led blink task",
        4096, 
        NULL, 
        3, 
        NULL, 
        0);
    

}