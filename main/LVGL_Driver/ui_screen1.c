
#include "ui_screen1.h"

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

lv_group_t *group1;

lv_obj_t *ui_Screen1;
lv_obj_t *ui_Panel1;

LV_FONT_DECLARE(lv_font_youyuan_12_user);
LV_FONT_DECLARE(lv_font_misans_normal_12_user);
LV_FONT_DECLARE(lv_font_dengxian_12_user);
LV_FONT_DECLARE(lv_font_opposans_r_12_user);



void ui_screen1_event_Button_cb( lv_event_t * e)
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
  btn1 = lv_btn_create(ui_Panel1);
  lv_obj_set_size(btn1, 68, 22);
  lv_obj_add_flag(btn1, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     // Flags
  lv_obj_clear_flag(btn1, LV_OBJ_FLAG_SCROLLABLE);      // Flags
  lv_obj_set_style_radius(btn1, 8, 0);
  lv_obj_set_style_bg_color(btn1, lv_color_make(0, 255, 255), LV_STATE_DEFAULT); // rgb
  lv_obj_set_style_border_color(btn1, lv_color_make(0, 0, 0),LV_STATE_FOCUS_KEY);
  lv_obj_set_style_border_width(btn1, 2, LV_STATE_FOCUS_KEY);
  lv_obj_add_event_cb(btn1, ui_screen1_event_Button_cb, LV_EVENT_PRESSED, NULL);


  label1 = lv_label_create(btn1);
  lv_obj_set_style_text_color(label1, lv_color_make(0, 0, 0), LV_PART_MAIN); // 设置字体颜色
  lv_obj_set_style_text_align(label1, LV_TEXT_ALIGN_CENTER, 0);
  lv_obj_set_style_text_font(label1, &lv_font_opposans_r_12_user, 0);
  lv_label_set_text(label1, "配网");
  lv_obj_center(label1); 

  ////////////////////////////////////////////////////////////////////////////////////////
  btn2 = lv_btn_create(ui_Panel1);
  lv_obj_set_size(btn2, 68, 46);
  lv_obj_add_flag(btn2, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     // Flags
  lv_obj_clear_flag(btn2, LV_OBJ_FLAG_SCROLLABLE);      // Flags
  lv_obj_set_style_radius(btn2, 8, 0);
  lv_obj_set_style_bg_color(btn2, lv_color_make(0, 255, 255), LV_STATE_DEFAULT); // rgb
  lv_obj_set_style_border_color(btn2, lv_color_make(0, 0, 0),LV_STATE_FOCUS_KEY);
  lv_obj_set_style_border_width(btn2, 2, LV_STATE_FOCUS_KEY);
  lv_obj_add_event_cb(btn2, ui_screen1_event_Button_cb, LV_EVENT_PRESSED, NULL);

  label2 = lv_label_create(btn2);
  lv_obj_set_style_text_color(label2, lv_color_make(0, 0, 0), LV_PART_MAIN); // 设置字体颜
  lv_obj_set_style_text_align(label2, LV_TEXT_ALIGN_CENTER, 0);
  lv_obj_set_style_text_font(label2, &lv_font_opposans_r_12_user, 0);
  lv_label_set_text(label2, "时钟自动\n""校准");
  lv_obj_center(label2);  

  ////////////////////////////////////////////////////////////////////////////////////////
  btn3 = lv_btn_create(ui_Panel1);
  lv_obj_set_size(btn3, 68, 46);
  lv_obj_add_flag(btn3, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     // Flags
  lv_obj_set_style_radius(btn3, 8, 0);
  lv_obj_set_style_bg_color(btn3, lv_color_make(0, 255, 255), LV_STATE_DEFAULT); // rgb
  lv_obj_set_style_border_color(btn3, lv_color_make(0, 0, 0),LV_STATE_FOCUS_KEY);
  lv_obj_set_style_border_width(btn3, 2, LV_STATE_FOCUS_KEY);
  lv_obj_add_event_cb(btn3, ui_screen1_event_Button_cb, LV_EVENT_PRESSED, NULL);

  label3 = lv_label_create(btn3);
  lv_obj_set_style_text_color(label3, lv_color_make(0, 0, 0), LV_PART_MAIN); // 设置字体颜色
  lv_obj_set_style_text_align(label3, LV_TEXT_ALIGN_CENTER, 0);
  lv_obj_set_style_text_font(label3, &lv_font_opposans_r_12_user, 0);
  lv_label_set_text(label3, "时钟手动\n""校准");
  lv_obj_center(label3);

  ////////////////////////////////////////////////////////////////////////////////////////
  btn4 = lv_btn_create(ui_Panel1);
  lv_obj_set_size(btn4, 68, 46);
  lv_obj_add_flag(btn4, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     // Flags
  lv_obj_set_style_radius(btn4, 8, 0);
  lv_obj_set_style_bg_color(btn4, lv_color_make(0, 255, 255), LV_STATE_DEFAULT); // rgb
  lv_obj_set_style_border_color(btn4, lv_color_make(0, 0, 0),LV_STATE_FOCUS_KEY);
  lv_obj_set_style_border_width(btn4, 2, LV_STATE_FOCUS_KEY);
  lv_obj_add_event_cb(btn4, ui_screen1_event_Button_cb, LV_EVENT_PRESSED, NULL);

  label4 = lv_label_create(btn4);
  lv_obj_set_style_text_color(label4, lv_color_make(0, 0, 0), LV_PART_MAIN); // 设置字体颜色
  lv_obj_set_style_text_align(label4, LV_TEXT_ALIGN_CENTER, 0);
  lv_obj_set_style_text_font(label4, &lv_font_opposans_r_12_user, 0);
  lv_label_set_text(label4, "时间界面\n""休眠时间");
  lv_obj_center(label4);

  ////////////////////////////////////////////////////////////////////////////////////////
  btn5 = lv_btn_create(ui_Panel1);
  lv_obj_set_size(btn5, 68, 46);
  lv_obj_add_flag(btn5, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     // Flags
  lv_obj_set_style_radius(btn5, 8, 0);
  lv_obj_set_style_bg_color(btn5, lv_color_make(0, 255, 255), LV_STATE_DEFAULT); // rgb
  lv_obj_set_style_border_color(btn5, lv_color_make(0, 0, 0),LV_STATE_FOCUS_KEY);
  lv_obj_set_style_border_width(btn5, 2, LV_STATE_FOCUS_KEY);
  lv_obj_add_event_cb(btn5, ui_screen1_event_Button_cb, LV_EVENT_PRESSED, NULL);

  label5 = lv_label_create(btn5);
  lv_obj_set_style_text_color(label5, lv_color_make(0, 0, 0), LV_PART_MAIN); // 设置字体颜色
  lv_obj_set_style_text_align(label5, LV_TEXT_ALIGN_CENTER, 0);
  lv_obj_set_style_text_font(label5, &lv_font_opposans_r_12_user, 0);
  lv_label_set_text(label5, "其他界面\n""休眠时间");
  lv_obj_center(label5);

  ////////////////////////////////////////////////////////////////////////////////////////
  btn6 = lv_btn_create(ui_Panel1);
  lv_obj_set_size(btn6, 68, 22);
  lv_obj_add_flag(btn6, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     // Flags
  lv_obj_set_style_radius(btn6, 8, 0);
  lv_obj_set_style_bg_color(btn6, lv_color_make(0, 255, 255), LV_STATE_DEFAULT); // rgb
  lv_obj_set_style_border_color(btn6, lv_color_make(0, 0, 0),LV_STATE_FOCUS_KEY);
  lv_obj_set_style_border_width(btn6, 2, LV_STATE_FOCUS_KEY);
  lv_obj_add_event_cb(btn6, ui_screen1_event_Button_cb, LV_EVENT_PRESSED, NULL);

  label6 = lv_label_create(btn6);
  lv_obj_set_style_text_color(label6, lv_color_make(0, 0, 0), LV_PART_MAIN); // 设置字体颜色
  lv_obj_set_style_text_align(label6, LV_TEXT_ALIGN_CENTER, 0);
  lv_obj_set_style_text_font(label6, &lv_font_opposans_r_12_user, 0);
  lv_label_set_text(label6, "抬手唤醒");
  lv_obj_center(label6);

  ////////////////////////////////////////////////////////////////////////////////////////
  btn7 = lv_btn_create(ui_Panel1);
  lv_obj_set_size(btn7, 68, 22);
  lv_obj_add_flag(btn7, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     // Flags
  lv_obj_set_style_radius(btn7, 8, 0);
  lv_obj_set_style_bg_color(btn7, lv_color_make(0, 255, 255), LV_STATE_DEFAULT); // rgb
  lv_obj_set_style_border_color(btn7, lv_color_make(0, 0, 0),LV_STATE_FOCUS_KEY);
  lv_obj_set_style_border_width(btn7, 2, LV_STATE_FOCUS_KEY);
  lv_obj_add_event_cb(btn7, ui_screen1_event_Button_cb, LV_EVENT_PRESSED, NULL);

  label7 = lv_label_create(btn7);
  lv_obj_set_style_text_color(label7, lv_color_make(0, 0, 0), LV_PART_MAIN); // 设置字体颜色
  lv_obj_set_style_text_align(label7, LV_TEXT_ALIGN_CENTER, 0);
  lv_obj_set_style_text_font(label7, &lv_font_opposans_r_12_user, 0);
  lv_label_set_text(label7, "拨轮唤醒");
  lv_obj_center(label7);

  ////////////////////////////////////////////////////////////////////////////////////////
  btn8 = lv_btn_create(ui_Panel1);
  lv_obj_set_size(btn8, 68, 22);
  lv_obj_add_flag(btn8, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     // Flags
  lv_obj_set_style_radius(btn8, 8, 0);
  lv_obj_set_style_bg_color(btn8, lv_color_make(0, 255, 255), LV_STATE_DEFAULT); // rgb
  lv_obj_set_style_border_color(btn8, lv_color_make(0, 0, 0),LV_STATE_FOCUS_KEY);
  lv_obj_set_style_border_width(btn8, 2, LV_STATE_FOCUS_KEY);
  lv_obj_add_event_cb(btn8, ui_screen1_event_Button_cb, LV_EVENT_PRESSED, NULL);

  label8 = lv_label_create(btn8);
  lv_obj_set_style_text_color(label8, lv_color_make(0, 0, 0), LV_PART_MAIN); // 设置字体颜色
  lv_obj_set_style_text_align(label8, LV_TEXT_ALIGN_CENTER, 0);
  lv_obj_set_style_text_font(label8, &lv_font_opposans_r_12_user, 0);
  lv_label_set_text(label8, "加速度计");
  lv_obj_center(label8);

  ////////////////////////////////////////////////////////////////////////////////////////
  btn9 = lv_btn_create(ui_Panel1);
  lv_obj_set_size(btn9, 68, 22);
  lv_obj_add_flag(btn9, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     // Flags
  lv_obj_set_style_radius(btn9, 8, 0);
  lv_obj_set_style_bg_color(btn9, lv_color_make(0, 255, 255), LV_STATE_DEFAULT); // rgb
  lv_obj_set_style_border_color(btn9, lv_color_make(0, 0, 0),LV_STATE_FOCUS_KEY);
  lv_obj_set_style_border_width(btn9, 2, LV_STATE_FOCUS_KEY);
  lv_obj_add_event_cb(btn9, ui_screen1_event_Button_cb, LV_EVENT_PRESSED, NULL);

  label9 = lv_label_create(btn9);
  lv_obj_set_style_text_color(label9, lv_color_make(0, 0, 0), LV_PART_MAIN); // 设置字体颜色
  lv_obj_set_style_text_align(label9, LV_TEXT_ALIGN_CENTER, 0);
  lv_obj_set_style_text_font(label9, &lv_font_opposans_r_12_user, 0);
  lv_label_set_text(label9, "闹钟");
  lv_obj_center(label9);

  ////////////////////////////////////////////////////////////////////////////////////////
  btn10 = lv_btn_create(ui_Panel1);
  lv_obj_set_size(btn10, 68, 22);
  lv_obj_add_flag(btn10, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     // Flags
  lv_obj_set_style_radius(btn10, 8, 0);
  lv_obj_set_style_bg_color(btn10, lv_color_make(0, 255, 255), LV_STATE_DEFAULT); // rgb
  lv_obj_set_style_border_color(btn10, lv_color_make(0, 0, 0),LV_STATE_FOCUS_KEY);
  lv_obj_set_style_border_width(btn10, 2, LV_STATE_FOCUS_KEY);
  lv_obj_add_event_cb(btn10, ui_screen1_event_Button_cb, LV_EVENT_PRESSED, NULL);

  label10 = lv_label_create(btn10);
  lv_obj_set_style_text_color(label10, lv_color_make(0, 0, 0), LV_PART_MAIN); // 设置字体颜色
  lv_obj_set_style_text_align(label10, LV_TEXT_ALIGN_CENTER, 0);
  lv_obj_set_style_text_font(label10, &lv_font_opposans_r_12_user, 0);
  lv_label_set_text(label10, "蜂鸣器");
  lv_obj_center(label10);
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

