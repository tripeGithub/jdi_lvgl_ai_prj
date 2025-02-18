

#include "ui.h"

#define GRADUAL_ANIM_TIME 600                    // 渐入渐出动画
#define MSGBOX_ANIM_TIME 280                     // 弹窗进入退出持续时间
#define MSGBOX_ANIM_TIME2 MSGBOX_ANIM_TIME + 150 // 弹窗进入退出等待
#define BUTTON_ANIM_TIME 160                     // 按钮收缩动画
#define PAGE_SWITCH_ANIM_TIME 300                // 上下左右页面切换动画
#define LABEL_ANIM_TIME 300                      // 标签抖动动画

#define MY_COLOR_RED lv_color_make(255, 0, 0)       // 红
#define MY_COLOR_GREEN lv_color_make(0, 255, 0)     // 绿
#define MY_COLOR_BLUE lv_color_make(0, 0, 255)      // 蓝
#define MY_COLOR_CYAN lv_color_make(0, 255, 255)    // 青
#define MY_COLOR_MAGENTA lv_color_make(255, 0, 255) // 洋红
#define MY_COLOR_YELLOW lv_color_make(255, 255, 0)  // 黄色
#define MY_COLOR_WHITE lv_color_make(255, 255, 255) // 白
#define MY_COLOR_BLACK lv_color_make(0, 0, 0)       // 黑

lv_group_t *group1;

lv_obj_t *ui_Screen1;
lv_obj_t *ui_Panel1;

lv_obj_t *btn1;
lv_obj_t *label1;
lv_obj_t *btn2;
lv_obj_t *label2;
lv_obj_t *btn3;
lv_obj_t *label3;
lv_obj_t *btn4;
lv_obj_t *label4;
lv_obj_t *btn5;
lv_obj_t *label5;
lv_obj_t *btn6;
lv_obj_t *label6;
lv_obj_t *btn7;
lv_obj_t *label7;
lv_obj_t *btn8;
lv_obj_t *label8;
lv_obj_t *btn9;
lv_obj_t *label9;
lv_obj_t *btn10;
lv_obj_t *label10;

lv_obj_t *ui_Screen2;
lv_obj_t *ui_Panel2;
lv_obj_t *ui_side_panel;
lv_obj_t *ui_Image1;
lv_obj_t *btn11;
lv_obj_t *label11;

lv_group_t *group2;

//lv_anim_t anim;


LV_FONT_DECLARE(lv_font_youyuan_12_user);
LV_FONT_DECLARE(lv_font_misans_normal_12_user);
LV_FONT_DECLARE(lv_font_dengxian_12_user);
LV_FONT_DECLARE(lv_font_opposans_r_12_user);

void demo_img(void)
{
  // 1.准备一张图片
  LV_IMG_DECLARE(maomao);
  // 2.创建一个lv_img对象
  lv_obj_t *img1 = lv_img_create(lv_scr_act());
  // 3.给对象设置图片
  lv_img_set_src(img1, &maomao);
  // 4.设置图片位置
  lv_obj_align(img1, LV_ALIGN_BOTTOM_MID, 0, 0);

}

void demo_kabi_img(void)
{
  // 1.准备一张图片
  LV_IMG_DECLARE(kabi_img);
  // 2.创建一个lv_img对象
  lv_obj_t *img1 = lv_img_create(lv_scr_act());
  // 3.给对象设置图片
  lv_img_set_src(img1, &kabi_img);
  // 4.设置图片位置
  lv_obj_align(img1, LV_ALIGN_CENTER, 0, 0);

}

void demo_gif(void)
{
  /*
    // 1.准备一张图片
    LV_IMG_DECLARE(qft);
    // 2.创建一个lv_img对象
    lv_obj_t *gif1 = lv_gif_create(lv_screen_active());
    // 3.给对象设置图片
    lv_gif_set_src(gif1, &qft);
    // 4.设置图片位置
    lv_obj_align(gif1, LV_ALIGN_BOTTOM_MID, 0, 0);
  */

  // qft 千反田 tw 跳舞 xiaomai 小埋 yqs 摇汽水 liuhua 六花
  LV_IMG_DECLARE(liuhua);
  lv_obj_t *gif2 = lv_gif_create(lv_scr_act());
  lv_gif_set_src(gif2, &liuhua);
  lv_obj_align(gif2, LV_ALIGN_CENTER, 0, 0);
}

void demo_kabi_gif(void)
{

  // qft 千反田 tw 跳舞 xiaomai 小埋 yqs 摇汽水 liuhua 六花
  LV_IMG_DECLARE(kabi_gif);
  lv_obj_t *gif2 = lv_gif_create(lv_scr_act());
  lv_gif_set_src(gif2, &kabi_gif);
  lv_obj_align(gif2, LV_ALIGN_CENTER, 0, 0);
}

void button_event_cb(lv_event_t *e)
{
    lv_obj_t *target = lv_event_get_target(e);      /* 获取触发源 */
 
    //if(target == btn)                      /* 加速按钮 */
    {
        //printf("okok");

    }


    //buzzer_play(750, BUZZER_DUTY);
    //vTaskDelay(pdMS_TO_TICKS(150));
    //buzzer_play(850, BUZZER_DUTY);
    //vTaskDelay(pdMS_TO_TICKS(150));
    //buzzer_stop();

    encoder_key_buzzer_trig = 1;
}

void _ui_screen_change( lv_obj_t ** target, lv_scr_load_anim_t fademode, int spd, int delay, void (*target_init)(void)) 
{
   if(*target == NULL)
      target_init();
   lv_scr_load_anim(*target, fademode, spd, delay, false);
   //lv_scr_load_anim(*target, fademode, spd, delay, true);
}

void ui_event_Button_cb( lv_event_t * e)
{
    lv_obj_t *target = lv_event_get_target(e);
    lv_event_code_t event_code = lv_event_get_code(e);
    uint32_t key_act = lv_event_get_key(e);

    //if(target == btn1 && event_code == LV_EVENT_DEFOCUSED && key_act == LV_KEY_LEFT  )
    //if(target == btn1 && event_code == LV_EVENT_KEY && key_act == LV_KEY_UP)
    //if(target == btn1 && event_code == LV_EVENT_LONG_PRESSED  )
    //if ( event_code == LV_EVENT_KEY &&  lv_event_get_key(e) == LV_KEY_UP  ) 
    {
      //_ui_screen_change( &ui_Screen2, LV_SCR_LOAD_ANIM_MOVE_BOTTOM, 500, 0, &lvgl_screen2_init);
    }
    if (event_code == LV_EVENT_PRESSED)// && key_movement == LV_KEY_LONG_PRESSED )
    {
        /* code */
        encoder_key_buzzer_trig = 1;
    }
}

// 定义动画时间和弹窗宽度
#define ANIM_TIME 600    // 动画时长（毫秒）
#define PANEL_WIDTH 55  // 侧边弹窗宽度

//static lv_obj_t *side_panel = NULL;  // 全局变量保存侧边弹窗对象

static lv_obj_t * msgbox = NULL;
static lv_anim_t anim;

// 动画回调函数：设置侧边弹窗的X坐标
static void set_x_anim(void *var, int32_t x) {
    
  //lv_obj_set_x((lv_obj_t *)var, x);

  lv_obj_align((lv_obj_t *)var, LV_ALIGN_LEFT_MID, x, 0);


    lv_obj_t * parent = lv_obj_get_parent((lv_obj_t *)var);
    lv_obj_invalidate(parent); 
}

// 动画结束回调函数：隐藏弹窗（如果是滑出动画）
static void anim_end_cb(lv_anim_t *a) {
    lv_obj_t * parent = lv_obj_get_parent(msgbox);
    
    
    lv_obj_del(msgbox);
    msgbox = NULL;

    lv_obj_invalidate(parent);
    
}

// 关闭消息框并复位动画
static void close_msgbox() {
    if (msgbox) {
        // 添加关闭动画：向左滑出屏幕
        lv_anim_init(&anim);
        lv_anim_set_var(&anim, msgbox);
        lv_anim_set_exec_cb(&anim, set_x_anim);
        lv_anim_set_values(&anim, -10, -70); // 滑出到左侧外部
        lv_anim_set_time(&anim, 400);
        lv_anim_set_path_cb(&anim, lv_anim_path_ease_out);
        lv_anim_set_ready_cb(&anim, anim_end_cb);
        lv_anim_start(&anim);

        // 动画结束后删除消息框
        //lv_anim_set_ready_cb(&anim, anim_end_cb);
    }
}

static lv_style_t msgbox_style;

// 按钮的点击事件回调函数
void btn_event_cb(lv_event_t * e)
{
    lv_obj_t * btn = lv_event_get_target(e); // 获取触发事件的按钮对象
    //lv_obj_t * panel = lv_obj_get_parent(btn); // 获取按钮的父对象，即侧边弹窗

    lv_event_code_t code = lv_event_get_code(e);
    if (code == LV_EVENT_PRESSED) 
    {
        encoder_key_buzzer_trig = 1;
        
        /*
        // 判断当前弹窗是否隐藏
        bool is_hidden = lv_obj_has_flag(ui_side_panel, LV_OBJ_FLAG_HIDDEN);

        // 创建动画对象
        //lv_anim_t anim;
        //lv_anim_init(&anim);
        lv_anim_set_var(&anim, ui_side_panel);
        //lv_anim_set_values(&anim, -55, 0); 
        lv_anim_set_exec_cb(&anim, anim_x_cb);
        lv_anim_set_time(&anim, ANIM_TIME);
        //lv_anim_set_path_cb(&anim, lv_anim_path_ease_out);  // 动画缓动效果

        if (is_hidden) {
            // 滑入动画：从左侧滑入
            lv_obj_clear_flag(ui_side_panel, LV_OBJ_FLAG_HIDDEN);
            lv_anim_set_values(&anim, -PANEL_WIDTH, 0);  // 从左侧滑入
        } else {
            // 滑出动画：滑回左侧
            lv_anim_set_values(&anim, 0, -PANEL_WIDTH);  // 滑出到左侧
            lv_anim_set_ready_cb(&anim, anim_end_cb);    // 动画结束时隐藏
        }

        lv_anim_start(&anim);  // 启动动画
        */

        /*
        // 创建消息框
        if (!msgbox) {
        msgbox = lv_msgbox_create(lv_scr_act(), NULL, "时间校准", NULL, false);
        
        lv_obj_set_style_bg_opa(msgbox, LV_OPA_COVER, 0);  // 半透明背景
        lv_obj_set_style_bg_color(msgbox, lv_color_hex(0xFFFFFF), 0);
        lv_obj_set_size(msgbox, 68, 80);             // 设置消息框尺寸
        lv_obj_align(msgbox, LV_ALIGN_CENTER, -60, 0); // 初始位置在左侧外部
        //lv_obj_align(msgbox, LV_ALIGN_CENTER, -10, 0);
        // 设置消息框的样式
        lv_style_init(&msgbox_style);
        //lv_style_set_bg_color(&msgbox_style, lv_color_hex(0xFFFFFF));
        lv_style_set_border_color(&msgbox_style, lv_color_make(0, 0, 0));
        lv_style_set_border_width(&msgbox_style, 2);
        lv_style_set_text_font(&msgbox_style, &lv_font_opposans_r_12_user);
        lv_obj_add_style(msgbox, &msgbox_style, 0);
        */

        //const char *title = title_in.c_str();
        //const char *text = text_in.c_str();
        if (!msgbox) {
        msgbox = lv_obj_create(lv_layer_top());
        lv_obj_set_scrollbar_mode(msgbox, LV_SCROLLBAR_MODE_OFF); //关闭滑动条
        //uint16_t width_title = lv_text_get_width(title, strlen(title), lv_obj_get_style_text_font(mbox.p, 0), 0);
        //uint16_t width_text = lv_text_get_width(text, strlen(text), lv_obj_get_style_text_font(mbox.p, 0), 0);
        //uint16_t width_title_zl = (width_title / 69);
        //uint16_t width_text_zl = (width_text / 69);
        //Serial.printf("width_text:%d\n", width_text);
        //Serial.printf("width_text_zl:%d\n", width_text_zl);
        //lv_obj_set_size(mbox.p, 78, 48 + ((width_title_zl + width_text_zl) * 20));
        //lv_obj_set_size(msgbox, 78, 144);
        lv_obj_set_size(msgbox, 78, 65);
        lv_obj_align(msgbox, LV_ALIGN_LEFT_MID, -78, 72);
        lv_obj_set_style_text_color(msgbox, MY_COLOR_BLACK, LV_STATE_DEFAULT);   // 字体颜色
        lv_obj_set_style_border_color(msgbox, MY_COLOR_BLACK, LV_STATE_DEFAULT); // 边框颜色
        lv_obj_set_style_border_width(msgbox, 2, LV_STATE_DEFAULT);              // 边框宽度
        lv_obj_set_style_pad_all(msgbox, 0, LV_STATE_DEFAULT);                   // 边距
        lv_obj_set_style_radius(msgbox, 9, LV_STATE_DEFAULT);                    // 设置圆角
        lv_obj_set_style_bg_opa(msgbox, LV_OPA_100, LV_STATE_DEFAULT);

        lv_obj_update_layout(msgbox); // 更新布局
        uint16_t i_w = lv_obj_get_width(msgbox);
        uint16_t i_h = lv_obj_get_height(msgbox);
        uint16_t i_r = lv_obj_get_style_radius(msgbox, LV_STATE_DEFAULT);

        // 内边框
        lv_obj_t *innerBorder = lv_obj_create(msgbox);
        lv_obj_set_style_bg_opa(innerBorder, LV_OPA_0, LV_STATE_DEFAULT);
        lv_obj_set_style_border_color(innerBorder, MY_COLOR_CYAN, LV_STATE_DEFAULT);
        lv_obj_set_style_border_width(innerBorder, 2, LV_STATE_DEFAULT);
        lv_obj_set_style_pad_all(innerBorder, 0, LV_STATE_DEFAULT);
        lv_obj_set_style_radius(innerBorder, i_r - 2, LV_STATE_DEFAULT);
        lv_obj_set_size(innerBorder, i_w - 4, i_h - 4);
        lv_obj_align(innerBorder, LV_ALIGN_CENTER, 0, 0);

        // 标题
        lv_obj_t *box_title = lv_label_create(msgbox);
        // lv_obj_set_style_border_width(box_title, 0, LV_STATE_DEFAULT); // 边框宽度
        // lv_obj_set_style_pad_all(box_title, 0, LV_STATE_DEFAULT);      // 边距
        lv_obj_set_width(box_title, 66);                                                // 设置宽度
        lv_obj_align(box_title, LV_ALIGN_TOP_MID, 1, 2);                                // 设置对齐方式
        lv_obj_set_style_text_color(box_title, MY_COLOR_WHITE, LV_STATE_DEFAULT);       // 设置文本颜色
        lv_label_set_long_mode(box_title, LV_LABEL_LONG_WRAP);                          // 设置文本长字符模式
        lv_obj_set_style_text_align(box_title, LV_TEXT_ALIGN_CENTER, LV_STATE_DEFAULT); // 设置文本对齐方式
        //lv_label_set_text(box_title, title);    
        lv_label_set_text(box_title, "123");                                          // 打印文本
        
        // 标题的背景
        lv_obj_t *title_bg = lv_obj_create(msgbox);
        lv_obj_set_style_border_width(title_bg, 0, LV_STATE_DEFAULT);
        lv_obj_set_style_bg_color(title_bg, MY_COLOR_BLACK, LV_STATE_DEFAULT);
        lv_obj_set_style_pad_all(title_bg, 0, LV_STATE_DEFAULT); // 边距
        lv_obj_set_style_radius(title_bg, 0, LV_STATE_DEFAULT);  // 设置圆角
        lv_obj_update_layout(msgbox);// 更新布局
        lv_obj_set_size(title_bg, i_w - 8, lv_obj_get_height(box_title));
        lv_obj_align(title_bg, LV_ALIGN_TOP_MID, 0, 2);
        lv_obj_swap(title_bg, box_title); // 交换层级

        // 内容
        lv_obj_t *box_text = lv_label_create(msgbox);
        lv_obj_set_width(box_text, 66);                                                // 设置宽度
        lv_obj_align_to(box_text, box_title, LV_ALIGN_OUT_BOTTOM_MID, 0, 1);           // 设置对齐方式
        lv_label_set_long_mode(box_text, LV_LABEL_LONG_WRAP);                          // 设置文本长字符模式
        lv_obj_set_style_text_align(box_text, LV_TEXT_ALIGN_CENTER, LV_STATE_DEFAULT); // 设置文本对齐方式
        lv_label_set_text(box_text, "456"); 
        
        // 设置消息框的回调函数
        //lv_obj_add_event_cb(msgbox, msgbox_event_cb, LV_EVENT_VALUE_CHANGED, NULL);
        
        // 实现侧滑效果
        lv_anim_init(&anim);
        lv_anim_set_var(&anim, msgbox);
        lv_anim_set_exec_cb(&anim, set_x_anim);
        lv_anim_set_values(&anim, -60, -10);
        //lv_anim_set_values(&anim, -10, 0);
        lv_anim_set_time(&anim, 400); // 动画时长300ms
        lv_anim_set_path_cb(&anim, lv_anim_path_ease_out); // 缓动效果
        lv_anim_start(&anim);
        } 
        else {
                // 再次按下按键关闭消息框
                close_msgbox();
            }
    }
}

void demo_label()
{
    
}

void lvgl_screen1_init(void)
{
  /*更改活动屏幕的背景色*/
  // lv_obj_set_style_bg_color(lv_screen_active(), lv_color_make(255, 0, 255), LV_PART_MAIN);

  /*Create a white label, set its text and align it to the center*/
  // lv_obj_t * label = lv_label_create(lv_screen_active());
  // lv_label_set_text(label, "Hello world");
  // lv_obj_set_style_text_color(lv_screen_active(), lv_color_hex(0xffffff), LV_PART_MAIN);
  // lv_obj_align(label, LV_ALIGN_CENTER, 0, 0);

  /*lv_obj_t *btn1 = lv_textarea_create(lv_scr_act());
  lv_obj_set_size(btn1, 70, 30);
  lv_obj_align(btn1, LV_ALIGN_CENTER, 0, -25);
  lv_obj_set_style_bg_color(btn1, lv_color_make(255, 0, 0), LV_STATE_DEFAULT);*/

  // 设置文本框的大小和位置
  /*
  lv_obj_t *btn1 = lv_textarea_create(lv_scr_act());
  lv_obj_set_size(btn1, 70, 30);
  lv_obj_align(btn1, LV_ALIGN_CENTER, 0, 30);
  lv_obj_set_style_bg_color(btn1, lv_color_make(255, 0, 0), LV_STATE_DEFAULT); // rgb
  */

  /*更改活动屏幕的背景色*/
  //lv_obj_set_style_bg_color(lv_scr_act(), lv_color_make(255, 0, 0), LV_PART_MAIN);

  ui_Screen1 = lv_obj_create(NULL);
  lv_obj_clear_flag(ui_Screen1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

  ui_Panel1 = lv_obj_create(ui_Screen1);
  //lv_obj_set_size(ui_Panel1, 72, 144);  
  lv_obj_set_size(ui_Panel1, 76, 160); 
  lv_obj_align(ui_Panel1, LV_ALIGN_CENTER, 0, 0);
  lv_obj_set_flex_flow(ui_Panel1, LV_FLEX_FLOW_COLUMN);
  lv_obj_set_flex_align(ui_Panel1, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
  lv_obj_set_scroll_dir(ui_Panel1, LV_DIR_VER);
  lv_obj_set_scrollbar_mode(ui_Panel1, LV_SCROLLBAR_MODE_OFF);

  /*
  // 设置文本框的大小和位置
  //lv_obj_t *btn1 = lv_textarea_create(lv_scr_act());
  btn1 = lv_textarea_create(ui_Screen1);
  //lv_obj_set_size(btn1, 124, 25);
  lv_obj_set_size(btn1, LV_PCT(100), LV_SIZE_CONTENT);

  //lv_obj_align(btn1, LV_ALIGN_CENTER, 0, -56);
  lv_obj_set_style_bg_color(btn1, lv_color_make(0, 255, 0), LV_STATE_DEFAULT); // rgb
  //lv_textarea_set_cursor_click_pos(btn1, false);

  //lv_obj_t *label = lv_label_create(lv_scr_act());
  label1 = lv_label_create(btn1);
  lv_label_set_long_mode(label1, LV_LABEL_LONG_SCROLL_CIRCULAR);
  lv_obj_set_width(label1, 124 - 4);
  lv_label_set_text(label1, "Hello ESP-IDF, I'm LVGL! -V8.4.0");
  lv_obj_center(label1);
  //lv_obj_align(label1, LV_ALIGN_CENTER, 0, -56);
  */

 ////////////////////////////////////////////////////////////////////////////////////////

  // 设置文本框的大小和位置
  //lv_obj_t *btn2 = lv_textarea_create(lv_scr_act());
  btn1 = lv_btn_create(ui_Panel1);

  lv_obj_set_size(btn1, 68, 22);
  //lv_obj_set_size(btn1, LV_PCT(90), LV_SIZE_CONTENT);
  //lv_obj_align(btn1, LV_ALIGN_CENTER, 0, -56);

  lv_obj_add_flag(btn1, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     // Flags
  //lv_obj_clear_flag(btn1, LV_OBJ_FLAG_SCROLLABLE);      // Flags

  lv_obj_set_style_radius(btn1, 8, 0);
  lv_obj_set_style_bg_color(btn1, lv_color_make(0, 255, 255), LV_STATE_DEFAULT); // rgb

  lv_obj_set_style_border_color(btn1, lv_color_make(0, 0, 0),LV_STATE_FOCUS_KEY);
  lv_obj_set_style_border_width(btn1, 2, LV_STATE_FOCUS_KEY);

  //lv_obj_set_style_outline_color(btn1, lv_color_make(255, 0, 0), LV_STATE_FOCUS_KEY); // rgb
  //lv_obj_set_style_outline_width(btn1, 3, LV_STATE_FOCUS_KEY); // rgb

  //lv_obj_add_event_cb(btn1, button_event_cb, LV_EVENT_PRESSED,NULL);
  lv_obj_add_event_cb(btn1, ui_event_Button_cb, LV_EVENT_PRESSED, NULL);


  label1 = lv_label_create(btn1);
  //lv_obj_align(label1, LV_ALIGN_CENTER, 0, -56);
  lv_obj_set_style_text_color(label1, lv_color_make(0, 0, 0), LV_PART_MAIN); // 设置字体颜色
  lv_obj_set_style_text_align(label1, LV_TEXT_ALIGN_CENTER, 0);
  //lv_obj_set_style_text_font(label1, &lv_font_youyuan_12_user, 0);
  //lv_obj_set_style_text_font(label1, &lv_font_misans_normal_12_user, 0);
  //lv_obj_set_style_text_font(label1, &lv_font_dengxian_12_user, 0);
  lv_obj_set_style_text_font(label1, &lv_font_opposans_r_12_user, 0);
  lv_label_set_text(label1, "配网");
  lv_obj_center(label1); 
  ////////////////////////////////////////////////////////////////////////////////////////

  // 设置文本框的大小和位置
  //lv_obj_t *btn2 = lv_textarea_create(lv_scr_act());
  btn2 = lv_btn_create(ui_Panel1);

  lv_obj_set_size(btn2, 68, 46);
  //lv_obj_set_size(btn2, LV_PCT(90), LV_SIZE_CONTENT);
  //lv_obj_align(btn2, LV_ALIGN_CENTER, 0, -25);

  lv_obj_add_flag(btn2, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     // Flags
  //lv_obj_clear_flag(btn2, LV_OBJ_FLAG_SCROLLABLE);      // Flags

  lv_obj_set_style_radius(btn2, 8, 0);
  lv_obj_set_style_bg_color(btn2, lv_color_make(0, 255, 255), LV_STATE_DEFAULT); // rgb

  lv_obj_set_style_border_color(btn2, lv_color_make(0, 0, 0),LV_STATE_FOCUS_KEY);
  lv_obj_set_style_border_width(btn2, 2, LV_STATE_FOCUS_KEY);

  //lv_obj_set_style_outline_color(btn2, lv_color_make(255, 0, 0), LV_STATE_FOCUS_KEY); // rgb
  //lv_obj_set_style_outline_width(btn2, 3, LV_STATE_FOCUS_KEY); // rgb

  //lv_obj_add_event_cb(btn2, button_event_cb, LV_EVENT_PRESSED,NULL);
  lv_obj_add_event_cb(btn2, ui_event_Button_cb, LV_EVENT_PRESSED, NULL);


  label2 = lv_label_create(btn2);
  //lv_obj_align(label2, LV_ALIGN_CENTER, 0, -25);
  lv_obj_set_style_text_color(label2, lv_color_make(0, 0, 0), LV_PART_MAIN); // 设置字体颜
  lv_obj_set_style_text_align(label2, LV_TEXT_ALIGN_CENTER, 0);
  //lv_obj_set_style_text_font(label2, &lv_font_youyuan_12_user, 0);
  //lv_obj_set_style_text_font(label2, &lv_font_misans_normal_12_user, 0);
  //lv_obj_set_style_text_font(label2, &lv_font_dengxian_12_user, 0);
  lv_obj_set_style_text_font(label2, &lv_font_opposans_r_12_user, 0);
  lv_label_set_text(label2, "时钟自动\n""校准");
  lv_obj_center(label2);  
  ////////////////////////////////////////////////////////////////////////////////////////

  // 设置文本框的大小和位置
  //lv_obj_t *btn3 = lv_textarea_create(lv_scr_act());
  btn3 = lv_btn_create(ui_Panel1);
  lv_obj_set_size(btn3, 68, 46);
  //lv_obj_set_size(btn3, LV_PCT(90), LV_SIZE_CONTENT);
  //lv_obj_align(btn3, LV_ALIGN_CENTER, 0, 10);

  lv_obj_add_flag(btn3, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     // Flags
  //lv_obj_clear_flag(btn3, LV_OBJ_FLAG_SCROLLABLE);      // Flags

  lv_obj_set_style_radius(btn3, 8, 0);
  lv_obj_set_style_bg_color(btn3, lv_color_make(0, 255, 255), LV_STATE_DEFAULT); // rgb

  lv_obj_set_style_border_color(btn3, lv_color_make(0, 0, 0),LV_STATE_FOCUS_KEY);
  lv_obj_set_style_border_width(btn3, 2, LV_STATE_FOCUS_KEY);

  //lv_obj_set_style_outline_color(btn3, lv_color_make(255, 0, 0), LV_STATE_FOCUS_KEY); // rgb
  //lv_obj_set_style_outline_width(btn3, 3, LV_STATE_FOCUS_KEY); // rgb

  //lv_obj_add_event_cb(btn3, button_event_cb, LV_EVENT_PRESSED,NULL);
  lv_obj_add_event_cb(btn3, ui_event_Button_cb, LV_EVENT_PRESSED, NULL);

  label3 = lv_label_create(btn3);
  //lv_obj_align(label3, LV_ALIGN_CENTER, 0, 10);
  lv_obj_set_style_text_color(label3, lv_color_make(0, 0, 0), LV_PART_MAIN); // 设置字体颜色
  lv_obj_set_style_text_align(label3, LV_TEXT_ALIGN_CENTER, 0);
  lv_obj_set_style_text_font(label3, &lv_font_opposans_r_12_user, 0);
  lv_label_set_text(label3, "时钟手动\n""校准");
  lv_obj_center(label3);  
  ////////////////////////////////////////////////////////////////////////////////////////

  // 设置文本框的大小和位置
  //lv_obj_t *btn4 = lv_textarea_create(lv_scr_act());
  btn4 = lv_btn_create(ui_Panel1);
  lv_obj_set_size(btn4, 68, 46);
  //lv_obj_set_size(btn4, LV_PCT(90), LV_SIZE_CONTENT);
  //lv_obj_align(btn4, LV_ALIGN_CENTER, 0, 45);

  lv_obj_add_flag(btn4, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     // Flags
  //lv_obj_clear_flag(btn4, LV_OBJ_FLAG_SCROLLABLE);      // Flags

  lv_obj_set_style_radius(btn4, 8, 0);
  lv_obj_set_style_bg_color(btn4, lv_color_make(0, 255, 255), LV_STATE_DEFAULT); // rgb

  lv_obj_set_style_border_color(btn4, lv_color_make(0, 0, 0),LV_STATE_FOCUS_KEY);
  lv_obj_set_style_border_width(btn4, 2, LV_STATE_FOCUS_KEY);

  //lv_obj_set_style_outline_color(btn4, lv_color_make(255, 0, 0), LV_STATE_FOCUS_KEY); // rgb
  //lv_obj_set_style_outline_width(btn4, 3, LV_STATE_FOCUS_KEY); // rgb

  //lv_obj_add_event_cb(btn4, button_event_cb, LV_EVENT_PRESSED,NULL);
  lv_obj_add_event_cb(btn4, ui_event_Button_cb, LV_EVENT_PRESSED, NULL);

  label4 = lv_label_create(btn4);
  //lv_obj_align(label4, LV_ALIGN_CENTER, 0, 45);
  lv_obj_set_style_text_color(label4, lv_color_make(0, 0, 0), LV_PART_MAIN); // 设置字体颜色
  lv_obj_set_style_text_align(label4, LV_TEXT_ALIGN_CENTER, 0);
  lv_obj_set_style_text_font(label4, &lv_font_opposans_r_12_user, 0);
  lv_label_set_text(label4, "时间界面\n""休眠时间");
  lv_obj_center(label4);
  ////////////////////////////////////////////////////////////////////////////////////////

  // 设置文本框的大小和位置
  //lv_obj_t *btn5 = lv_textarea_create(lv_scr_act());
  btn5 = lv_btn_create(ui_Panel1);
  lv_obj_set_size(btn5, 68, 46);
  //lv_obj_set_size(btn5, LV_PCT(90), LV_SIZE_CONTENT);
  //lv_obj_align(btn5, LV_ALIGN_CENTER, 0, 45);

  lv_obj_add_flag(btn5, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     // Flags
  //lv_obj_clear_flag(btn5, LV_OBJ_FLAG_SCROLLABLE);      // Flags

  lv_obj_set_style_radius(btn5, 8, 0);
  lv_obj_set_style_bg_color(btn5, lv_color_make(0, 255, 255), LV_STATE_DEFAULT); // rgb

  lv_obj_set_style_border_color(btn5, lv_color_make(0, 0, 0),LV_STATE_FOCUS_KEY);
  lv_obj_set_style_border_width(btn5, 2, LV_STATE_FOCUS_KEY);

  //lv_obj_set_style_outline_color(btn5, lv_color_make(255, 0, 0), LV_STATE_FOCUS_KEY); // rgb
  //lv_obj_set_style_outline_width(btn5, 3, LV_STATE_FOCUS_KEY); // rgb

  //lv_obj_add_event_cb(btn5, button_event_cb, LV_EVENT_PRESSED,NULL);
  lv_obj_add_event_cb(btn5, ui_event_Button_cb, LV_EVENT_PRESSED, NULL);

  label5 = lv_label_create(btn5);
  //lv_obj_align(label4, LV_ALIGN_CENTER, 0, 45);
  lv_obj_set_style_text_color(label5, lv_color_make(0, 0, 0), LV_PART_MAIN); // 设置字体颜色
  lv_obj_set_style_text_align(label5, LV_TEXT_ALIGN_CENTER, 0);
  lv_obj_set_style_text_font(label5, &lv_font_opposans_r_12_user, 0);
  lv_label_set_text(label5, "其他界面\n""休眠时间");
  lv_obj_center(label5);
  ////////////////////////////////////////////////////////////////////////////////////////

  // 设置文本框的大小和位置
  //lv_obj_t *btn6 = lv_textarea_create(lv_scr_act());
  btn6 = lv_btn_create(ui_Panel1);
  lv_obj_set_size(btn6, 68, 22);
  //lv_obj_set_size(btn6, LV_PCT(90), LV_SIZE_CONTENT);
  //lv_obj_align(btn6, LV_ALIGN_CENTER, 0, 45);

  lv_obj_add_flag(btn6, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     // Flags
  //lv_obj_clear_flag(btn6, LV_OBJ_FLAG_SCROLLABLE);      // Flags

  lv_obj_set_style_radius(btn6, 8, 0);
  lv_obj_set_style_bg_color(btn6, lv_color_make(0, 255, 255), LV_STATE_DEFAULT); // rgb

  lv_obj_set_style_border_color(btn6, lv_color_make(0, 0, 0),LV_STATE_FOCUS_KEY);
  lv_obj_set_style_border_width(btn6, 2, LV_STATE_FOCUS_KEY);

  //lv_obj_set_style_outline_color(btn6, lv_color_make(255, 0, 0), LV_STATE_FOCUS_KEY); // rgb
  //lv_obj_set_style_outline_width(btn6, 3, LV_STATE_FOCUS_KEY); // rgb

  //lv_obj_add_event_cb(btn6, button_event_cb, LV_EVENT_PRESSED,NULL);
  lv_obj_add_event_cb(btn6, ui_event_Button_cb, LV_EVENT_PRESSED, NULL);

  label6 = lv_label_create(btn6);
  //lv_obj_align(label6, LV_ALIGN_CENTER, 0, 45);
  lv_obj_set_style_text_color(label6, lv_color_make(0, 0, 0), LV_PART_MAIN); // 设置字体颜色
  lv_obj_set_style_text_align(label6, LV_TEXT_ALIGN_CENTER, 0);
  lv_obj_set_style_text_font(label6, &lv_font_opposans_r_12_user, 0);
  lv_label_set_text(label6, "抬手唤醒");
  //lv_label_set_text(label6, "button6");
  lv_obj_center(label6);

  ////////////////////////////////////////////////////////////////////////////////////////

  // 设置文本框的大小和位置
  //lv_obj_t *btn6 = lv_textarea_create(lv_scr_act());
  btn7 = lv_btn_create(ui_Panel1);
  lv_obj_set_size(btn7, 68, 22);
  //lv_obj_set_size(btn6, LV_PCT(90), LV_SIZE_CONTENT);
  //lv_obj_align(btn6, LV_ALIGN_CENTER, 0, 45);

  lv_obj_add_flag(btn7, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     // Flags
  //lv_obj_clear_flag(btn6, LV_OBJ_FLAG_SCROLLABLE);      // Flags

  lv_obj_set_style_radius(btn7, 8, 0);
  lv_obj_set_style_bg_color(btn7, lv_color_make(0, 255, 255), LV_STATE_DEFAULT); // rgb

  lv_obj_set_style_border_color(btn7, lv_color_make(0, 0, 0),LV_STATE_FOCUS_KEY);
  lv_obj_set_style_border_width(btn7, 2, LV_STATE_FOCUS_KEY);

  //lv_obj_set_style_outline_color(btn7, lv_color_make(255, 0, 0), LV_STATE_FOCUS_KEY); // rgb
  //lv_obj_set_style_outline_width(btn7, 3, LV_STATE_FOCUS_KEY); // rgb

  //lv_obj_add_event_cb(btn7, button_event_cb, LV_EVENT_PRESSED,NULL);
  lv_obj_add_event_cb(btn7, ui_event_Button_cb, LV_EVENT_PRESSED, NULL);

  label7 = lv_label_create(btn7);
  //lv_obj_align(label6, LV_ALIGN_CENTER, 0, 45);
  lv_obj_set_style_text_color(label7, lv_color_make(0, 0, 0), LV_PART_MAIN); // 设置字体颜色
  lv_obj_set_style_text_align(label7, LV_TEXT_ALIGN_CENTER, 0);
  lv_obj_set_style_text_font(label7, &lv_font_opposans_r_12_user, 0);
  lv_label_set_text(label7, "拨轮唤醒");
  //lv_label_set_text(label7, "button7");
  lv_obj_center(label7);

  ////////////////////////////////////////////////////////////////////////////////////////

  // 设置文本框的大小和位置
  //lv_obj_t *btn6 = lv_textarea_create(lv_scr_act());
  btn8 = lv_btn_create(ui_Panel1);
  lv_obj_set_size(btn8, 68, 22);
  //lv_obj_set_size(btn6, LV_PCT(90), LV_SIZE_CONTENT);
  //lv_obj_align(btn6, LV_ALIGN_CENTER, 0, 45);

  lv_obj_add_flag(btn8, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     // Flags
  //lv_obj_clear_flag(btn6, LV_OBJ_FLAG_SCROLLABLE);      // Flags

  lv_obj_set_style_radius(btn8, 8, 0);
  lv_obj_set_style_bg_color(btn8, lv_color_make(0, 255, 255), LV_STATE_DEFAULT); // rgb

  lv_obj_set_style_border_color(btn8, lv_color_make(0, 0, 0),LV_STATE_FOCUS_KEY);
  lv_obj_set_style_border_width(btn8, 2, LV_STATE_FOCUS_KEY);

  //lv_obj_set_style_outline_color(btn8, lv_color_make(255, 0, 0), LV_STATE_FOCUS_KEY); // rgb
  //lv_obj_set_style_outline_width(btn8, 3, LV_STATE_FOCUS_KEY); // rgb

  //lv_obj_add_event_cb(btn8, button_event_cb, LV_EVENT_PRESSED,NULL);
  lv_obj_add_event_cb(btn8, ui_event_Button_cb, LV_EVENT_PRESSED, NULL);

  label8 = lv_label_create(btn8);
  //lv_obj_align(label6, LV_ALIGN_CENTER, 0, 45);
  lv_obj_set_style_text_color(label8, lv_color_make(0, 0, 0), LV_PART_MAIN); // 设置字体颜色
  lv_obj_set_style_text_align(label8, LV_TEXT_ALIGN_CENTER, 0);
  lv_obj_set_style_text_font(label8, &lv_font_opposans_r_12_user, 0);
  lv_label_set_text(label8, "加速度计");
  //lv_label_set_text(label7, "button7");
  lv_obj_center(label8);

  ////////////////////////////////////////////////////////////////////////////////////////

  // 设置文本框的大小和位置
  //lv_obj_t *btn6 = lv_textarea_create(lv_scr_act());
  btn9 = lv_btn_create(ui_Panel1);
  lv_obj_set_size(btn9, 68, 22);
  //lv_obj_set_size(btn6, LV_PCT(90), LV_SIZE_CONTENT);
  //lv_obj_align(btn6, LV_ALIGN_CENTER, 0, 45);

  lv_obj_add_flag(btn9, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     // Flags
  //lv_obj_clear_flag(btn9, LV_OBJ_FLAG_SCROLLABLE);      // Flags

  lv_obj_set_style_radius(btn9, 8, 0);
  lv_obj_set_style_bg_color(btn9, lv_color_make(0, 255, 255), LV_STATE_DEFAULT); // rgb

  lv_obj_set_style_border_color(btn9, lv_color_make(0, 0, 0),LV_STATE_FOCUS_KEY);
  lv_obj_set_style_border_width(btn9, 2, LV_STATE_FOCUS_KEY);

  //lv_obj_set_style_outline_color(btn9, lv_color_make(255, 0, 0), LV_STATE_FOCUS_KEY); // rgb
  //lv_obj_set_style_outline_width(btn9, 3, LV_STATE_FOCUS_KEY); // rgb

  //lv_obj_add_event_cb(btn9, button_event_cb, LV_EVENT_PRESSED,NULL);
  lv_obj_add_event_cb(btn9, ui_event_Button_cb, LV_EVENT_PRESSED, NULL);

  label9 = lv_label_create(btn9);
  //lv_obj_align(label6, LV_ALIGN_CENTER, 0, 45);
  lv_obj_set_style_text_color(label9, lv_color_make(0, 0, 0), LV_PART_MAIN); // 设置字体颜色
  lv_obj_set_style_text_align(label9, LV_TEXT_ALIGN_CENTER, 0);
  lv_obj_set_style_text_font(label9, &lv_font_opposans_r_12_user, 0);
  lv_label_set_text(label9, "闹钟");
  //lv_label_set_text(label7, "button7");
  lv_obj_center(label9);

  ////////////////////////////////////////////////////////////////////////////////////////

  // 设置文本框的大小和位置
  //lv_obj_t *btn6 = lv_textarea_create(lv_scr_act());
  btn10 = lv_btn_create(ui_Panel1);
  lv_obj_set_size(btn10, 68, 22);
  //lv_obj_set_size(btn6, LV_PCT(90), LV_SIZE_CONTENT);
  //lv_obj_align(btn6, LV_ALIGN_CENTER, 0, 45);

  lv_obj_add_flag(btn10, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     // Flags
  //lv_obj_clear_flag(btn10, LV_OBJ_FLAG_SCROLLABLE);      // Flags

  lv_obj_set_style_radius(btn10, 8, 0);
  lv_obj_set_style_bg_color(btn10, lv_color_make(0, 255, 255), LV_STATE_DEFAULT); // rgb

  lv_obj_set_style_border_color(btn10, lv_color_make(0, 0, 0),LV_STATE_FOCUS_KEY);
  lv_obj_set_style_border_width(btn10, 2, LV_STATE_FOCUS_KEY);

  //lv_obj_set_style_outline_color(btn10, lv_color_make(255, 0, 0), LV_STATE_FOCUS_KEY); // rgb
  //lv_obj_set_style_outline_width(btn10, 3, LV_STATE_FOCUS_KEY); // rgb

  //lv_obj_add_event_cb(btn10, button_event_cb, LV_EVENT_PRESSED,NULL);
  lv_obj_add_event_cb(btn10, ui_event_Button_cb, LV_EVENT_PRESSED, NULL);

  label10 = lv_label_create(btn10);
  //lv_obj_align(label6, LV_ALIGN_CENTER, 0, 45);
  lv_obj_set_style_text_color(label10, lv_color_make(0, 0, 0), LV_PART_MAIN); // 设置字体颜色
  lv_obj_set_style_text_align(label10, LV_TEXT_ALIGN_CENTER, 0);
  lv_obj_set_style_text_font(label10, &lv_font_opposans_r_12_user, 0);
  lv_label_set_text(label10, "蜂鸣器");
  //lv_label_set_text(label7, "button7");
  lv_obj_center(label10);

  //
  //lv_disp_load_scr(ui_Screen1);
}

void lvgl_screen1_group_init(void)
{
  group1 = lv_group_create(); //! 给组指针赋值后才能用
  lv_group_add_obj(group1, btn1); // 只要这一句 添加每个进group1
  lv_group_add_obj(group1, btn2); // 只要这一句 添加每个进group1
  lv_group_add_obj(group1, btn3); // 只要这一句 添加每个进group1
  lv_group_add_obj(group1, btn4); // 只要这一句 添加每个进group1
  lv_group_add_obj(group1, btn5); // 只要这一句 添加每个进group1
  lv_group_add_obj(group1, btn6); // 只要这一句 添加每个进group1
  lv_group_add_obj(group1, btn7); // 只要这一句 添加每个进group1
  lv_group_add_obj(group1, btn8); // 只要这一句 添加每个进group1
  lv_group_add_obj(group1, btn9); // 只要这一句 添加每个进group1
  lv_group_add_obj(group1, btn10); // 只要这一句 添加每个进group1
  lv_indev_set_group(indev_encoder, group1); // 组绑定encoder&keypad
  //lv_indev_set_group(indev_keypad, group1); // 组绑定encoder&keypad
}

void lvgl_screen2_init(void)
{
  LV_IMG_DECLARE(espressif);
    
  ui_Screen2 = lv_obj_create(NULL);
  lv_obj_clear_flag( ui_Screen2, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
  
  ///*
  ui_Panel2 = lv_obj_create(ui_Screen2);
  //lv_obj_set_size(ui_Panel1, 72, 144);  
  lv_obj_set_size(ui_Panel2, 76, 160); 
  lv_obj_align(ui_Panel2, LV_ALIGN_CENTER, 0, 0);
  lv_obj_set_style_bg_color(ui_Panel2, lv_color_make(255, 255, 255), 0);
  //lv_obj_set_flex_flow(ui_Panel2, LV_FLEX_FLOW_COLUMN);
  //lv_obj_set_flex_align(ui_Panel2, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
  //lv_obj_set_scroll_dir(ui_Panel2, LV_DIR_VER);
  //lv_obj_set_scrollbar_mode(ui_Panel2, LV_SCROLLBAR_MODE_OFF);
  //lv_obj_set_style_overflow(ui_Panel2, LV_OVERFLOW_HIDDEN, 0); // 父对象裁剪超出部分
  //*/

  ///*
  ui_Image1 = lv_img_create(ui_Panel2);
  lv_img_set_src(ui_Image1, &espressif);
  lv_obj_set_width( ui_Image1, 44);  /// 1
  lv_obj_set_height( ui_Image1, 44);   /// 1
  //lv_obj_set_align( ui_Image1, LV_ALIGN_CENTER );
  lv_obj_align(ui_Image1, LV_ALIGN_CENTER, 0, -20);
  //lv_obj_add_flag( ui_Image1, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
  lv_obj_clear_flag( ui_Image1, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
  //*/

  //btn11 = lv_btn_create(ui_Panel2);
  btn11 = lv_btn_create(ui_Screen2);
  lv_obj_set_size(btn11, 68, 22);
  lv_obj_align(btn11, LV_ALIGN_CENTER, 0, 45);

  lv_obj_add_flag(btn11, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     // Flags
  lv_obj_clear_flag(btn11, LV_OBJ_FLAG_SCROLLABLE);      // Flags

  lv_obj_set_style_radius(btn11, 8, 0);
  lv_obj_set_style_bg_color(btn11, lv_color_make(0, 255, 255), LV_STATE_DEFAULT); // rgb

  lv_obj_set_style_border_color(btn11, lv_color_make(0, 0, 0),LV_STATE_FOCUS_KEY);
  lv_obj_set_style_border_width(btn11, 2, LV_STATE_FOCUS_KEY);

  lv_obj_add_event_cb(btn11, btn_event_cb, LV_EVENT_PRESSED,NULL);

  /*
  ui_side_panel = lv_obj_create(ui_Screen2);
  lv_obj_set_size(ui_side_panel, 55, lv_pct(30)); // 设置面板的大小为屏幕宽度的150%和屏幕高度的100%
  lv_obj_align(ui_side_panel, LV_ALIGN_LEFT_MID, -55, 0); // 将面板对齐到屏幕的左侧中间，并初始位置在屏幕左侧之外
  //lv_obj_set_style_bg_color(ui_side_panel, lv_color_black(), 0); // 设置面板的背景颜色为黑色
  //lv_obj_set_style_bg_opa(ui_side_panel, LV_OPA_50, 0); // 设置面板的背景透明度为50%
  //lv_obj_set_hidden(ui_side_panel, true); // 默认隐藏侧边弹窗
  lv_obj_add_flag(ui_side_panel, LV_OBJ_FLAG_HIDDEN);
  */

  label11 = lv_label_create(btn11);
  //lv_obj_align(label11, LV_ALIGN_CENTER, 0, 45);
  lv_obj_set_style_text_color(label11, lv_color_make(0, 0, 0), LV_PART_MAIN); // 设置字体颜色
  lv_obj_set_style_text_align(label11, LV_TEXT_ALIGN_CENTER, 0);
  //lv_obj_set_style_text_font(label11, &lv_font_opposans_r_12_user, 0);
  lv_label_set_text(label11, "button");
  lv_obj_center(label11);

}

void lvgl_screen2_group_init(void)
{
  group2 = lv_group_create(); //! 给组指针赋值后才能用
  lv_group_add_obj(group2, btn11); // 只要这一句 添加每个进group1
  lv_indev_set_group(indev_encoder, group2); // 组绑定encoder&keypad
}

void jdi_ui_demo(void)
{
    lvgl_screen1_init();
    lvgl_screen2_init();  

    lvgl_screen1_group_init();

    lv_anim_init(&anim);

    lv_disp_load_scr(ui_Screen1); // 加载主屏幕
    //lv_disp_load_scr(ui_Panel1); // 加载主屏幕


}