
#include "ui_screen2.h"

lv_obj_t *ui_Image1;
lv_obj_t *btn11;
lv_obj_t *label11;

lv_group_t *group2;


lv_obj_t *ui_Screen2;
lv_obj_t *ui_Panel2;

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

void ui_screen2_event_Button_cb(lv_event_t * e)
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

  btn11 = lv_btn_create(ui_Panel2);
  //btn11 = lv_btn_create(ui_Screen2);
  lv_obj_set_size(btn11, 68, 22);
  lv_obj_align(btn11, LV_ALIGN_CENTER, 0, 45);
  lv_obj_add_flag(btn11, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     // Flags
  lv_obj_clear_flag(btn11, LV_OBJ_FLAG_SCROLLABLE);      // Flags
  lv_obj_set_style_radius(btn11, 8, 0);
  lv_obj_set_style_bg_color(btn11, lv_color_make(0, 255, 255), LV_STATE_DEFAULT); // rgb
  lv_obj_set_style_border_color(btn11, lv_color_make(0, 0, 0),LV_STATE_FOCUS_KEY);
  lv_obj_set_style_border_width(btn11, 2, LV_STATE_FOCUS_KEY);
  lv_obj_add_event_cb(btn11, ui_screen2_event_Button_cb, LV_EVENT_PRESSED,NULL);

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
