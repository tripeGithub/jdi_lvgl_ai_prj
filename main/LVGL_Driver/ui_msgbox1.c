#include "ui_msgbox1.h"

MBOX mbox;

lv_timer_t *lvTimer_share[2] = {NULL}; // 通用定时器

lv_timer_t *lvTimer_msgbox = NULL;

static lv_group_t *group_my;    // 我的组
static lv_group_t *group_mbox0; // 弹窗组0
static lv_group_t *group_mbox1; // 弹窗组1
static lv_group_t *group_old;   // 上一个弹窗组

static lv_style_t style_shadow;

static uint8_t num[20] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
                          11, 12, 13, 14, 15, 16, 17, 18, 19};

void ui_msgbox1_init(void)
{
    mbox.p = NULL;
    mbox.keyMode = 1;
    mbox.state = 0;
    mbox.recordTime = 0;
    mbox.time = 0;
    mbox.event_cb = NULL;
}

// 弹窗动画 对X轴变化
void my_msgbox_anim_x_cb(void *var, int32_t v) 
{
  //lv_obj_set_x((lv_obj_t *)var, v);
  lv_obj_align((lv_obj_t *)var, LV_ALIGN_LEFT_MID, v, 0);
  //Serial.printf("v:%d\n",v);

  lv_obj_t * parent = lv_obj_get_parent((lv_obj_t *)var);
  lv_obj_invalidate(parent); 
}

// 弹窗退出动画结束时删除自己
void my_msgbox_exit_anim_end_cb(lv_anim_t *a) 
{
  lv_obj_t * parent = lv_obj_get_parent((lv_obj_t *)mbox.p);
  
  // lv_obj_delete((lv_obj_t *)a->var);
  lv_obj_del(mbox.p); // 删除对象
  mbox.p = NULL;         // 对象地址清空
  mbox.keyMode = KEY_MODE_RL;

  lv_indev_t * indev;
  indev = lv_indev_get_act();

  if (group_old != NULL)
  {
    lv_indev_set_group(indev, group_old); // 将组邦定到按键 group_my
    lv_obj_t *obj = lv_group_get_focused(group_old);
    group_old = NULL;
    lv_obj_add_state(obj, LV_STATE_PRESSED); // 设置状态
  }

  // 检查清空标志
  if (bitRead(mbox.state, MBOX_STATE_CLEAR) == 1)
  {
    mbox.title[0] = '\0';//mbox.title.clear();
    mbox.text[0] = '\0';//mbox.text.clear();
    mbox.time = 0;
    mbox.recordTime = 0;
    mbox.button[0] = '\0';//mbox.button.clear();
    mbox.event_cb = NULL;
    bitWrite(mbox.state, MBOX_STATE_CLEAR, 0);
  }

  // 定时器存在，删除定时器
  if (lvTimer_msgbox)
  {
    lv_timer_pause(lvTimer_msgbox);  // 暂停
    lv_timer_del(lvTimer_msgbox);
    lvTimer_msgbox = NULL;
  }

  bitWrite(mbox.state, MBOX_STATE_EXIT, 0);   // 标记退出完毕
  bitWrite(mbox.state, MBOX_STATE_REMAIN, 0); // 标记停留阶段结束
  bitWrite(mbox.state, MBOX_STATE_TIMER, 0);  // 取消标记定时器运行阶段

  //Serial.println("弹窗退出完毕");
  //Serial.print("mbox.state:");
  //Serial.println(mbox.state, BIN);
  //Serial.println();

  printf("弹窗退出完毕\n");
  printf("mbox.state: %02X\n", mbox.state);
  //printf(mbox.state, BIN);
  //printf();

  lv_obj_invalidate(parent);
}

// 弹窗退出 设置多少秒后退出的定时器回调
void my_msgbox_setExit_timer_cb(lv_timer_t *e)
{
  bitWrite(mbox.state, MBOX_STATE_EXIT, 1); // 标记退出中
  int16_t x = lv_obj_get_x(mbox.p);
  lv_anim_t b;
  lv_anim_init(&b);                                         // 动画初始化
  lv_anim_set_var(&b, mbox.p);                              // 设置需要动画的对象
  lv_anim_set_values(&b, x, -78);                           // 设置动画的开始值和结束值
  lv_anim_set_time(&b, MSGBOX_ANIM_TIME);               // 设置动画的持续时间
  lv_anim_set_exec_cb(&b, my_msgbox_anim_x_cb);             // 设置需要变化的值
  lv_anim_set_path_cb(&b, lv_anim_path_ease_in);            // 设置变化特效
  lv_anim_set_ready_cb(&b, my_msgbox_exit_anim_end_cb); // 设置动画完成时的函数调用
  lv_anim_start(&b);                                        // 动画开始
  
  //Serial.println("弹窗退出动画开始");
  printf("弹窗退出动画开始\n");

  if (lvTimer_msgbox)
  {
    lv_timer_pause(lvTimer_msgbox);  // 暂停
    lv_timer_del(lvTimer_msgbox); // 删除
    lvTimer_msgbox = NULL;
  }
}

// 弹窗退出 供用户调用
void my_msgbox_exit(uint32_t delay_ms)
{
  if (mbox.p == NULL) return;
  if (bitRead(mbox.state, MBOX_STATE_EXIT)) return;

  //Serial.println("弹窗退出开始创建");
  printf("弹窗退出开始创建\n");

  if (lvTimer_msgbox)
  {
    lv_timer_pause(lvTimer_msgbox);  // 暂停
    lv_timer_del(lvTimer_msgbox); // 删除
    lvTimer_msgbox = NULL;
  }

  if (delay_ms < 5) // 小于5ms直接运行
  {
    my_msgbox_setExit_timer_cb(NULL);
    return;
  } 

  bitWrite(mbox.state, MBOX_STATE_TIMER, 1); // 标记定时器运行阶段
  // 创建一个单次定时器
  lvTimer_msgbox = lv_timer_create(my_msgbox_setExit_timer_cb, delay_ms, NULL);
  lv_timer_set_repeat_count(lvTimer_msgbox, 1);
  //lv_timer_set_auto_delete(lvTimer_msgbox, false);
}

// 弹窗进入动画结束回调
void my_msgbox_enter_anim_end_cb(lv_anim_t *a)
{
  //Serial.println("弹窗进入动画结束");
  printf("弹窗进入动画结束\n");

  bitWrite(mbox.state, MBOX_STATE_ENTER, 0);  // 标记进入阶段结束
  bitWrite(mbox.state, MBOX_STATE_REMAIN, 1); // 标记进入停留阶段
}

// 正常发送弹窗 供用户调用
void my_msgbox_send(char* title_in, char* text_in, uint16_t time, char* button, lv_event_cb_t event_cb)
{
  //Serial.println("弹窗发送");
  //Serial.printf("title_in:%s\n", title_in.c_str());
  //Serial.printf("text_in:%s\n", text_in.c_str());
  //Serial.printf("time:%d\n", time);

  printf("弹窗发送\n");
  printf("title_in:%s\n", title_in);
  printf("text_in:%s\n", text_in);
  printf("time:%d\n", time);

  bitWrite(mbox.state, MBOX_STATE_SEND, 1); // 标记发送阶段

  if(title_in) 
    memcpy(mbox.title, title_in, MSGBOX_STR_LEN);//mbox.title = title_in;

  if(text_in)  
    memcpy(mbox.text, text_in, MSGBOX_STR_LEN);//mbox.text = text_in;

  mbox.time = time;

  if(button)   
    memcpy(mbox.button, button, MSGBOX_STR_LEN);//mbox.button = button;

  if(event_cb) 
    mbox.event_cb = event_cb;

}

// 强制发送弹窗 供用户调用
void my_msgbox_forceSend(char* title_in, char* text_in, uint16_t time, char* button, lv_event_cb_t event_cb)
{
  bitWrite(mbox.state, MBOX_STATE_FORCE, 1); // 标记强制发送
  my_msgbox_send(title_in, text_in, time, button, event_cb);
}


void ui_msgbox_process(char* title_in, char* text_in, uint16_t time, char* button, lv_event_cb_t event_cb)
{
    lv_indev_t * indev;
    indev = lv_indev_get_act();
    
    //uint8_t index = msgboxInit();
    bitWrite(mbox.state, MBOX_STATE_ENTER, 1); // 标记进入阶段

    const char *title = mbox.title;//title_in.c_str();
    const char *text = mbox.text;//text_in.c_str();
    
    // 计算按钮的数量
    uint8_t butNum = 0;
    char button_name[3][32];
  
    for (uint8_t i = 0; i < MSGBOX_STR_LEN; i++)
    {
        if (button[i] != '\n') 
            button_name[butNum][i] += button[i];
        else                   
            butNum++;

        if (butNum >= 3) 
            break;
    }
    
    // 大框
    mbox.p = lv_obj_create(lv_layer_top());
    lv_obj_set_scrollbar_mode(mbox.p, LV_SCROLLBAR_MODE_OFF); //关闭滑动条
    //uint16_t width_title = lv_text_get_width(title, strlen(title), lv_obj_get_style_text_font(mbox.p, 0), 0);
    //uint16_t width_text = lv_text_get_width(text, strlen(text), lv_obj_get_style_text_font(mbox.p, 0), 0);
    //uint16_t width_title_zl = (width_title / 69);
    //uint16_t width_text_zl = (width_text / 69);
    //Serial.printf("width_text:%d\n", width_text);
    //Serial.printf("width_text_zl:%d\n", width_text_zl);
    //lv_obj_set_size(mbox.p, 78, 48 + ((width_title_zl + width_text_zl) * 20));
    //lv_obj_set_size(msgbox, 78, 144);
    lv_obj_set_size(mbox.p, 78, 65);
    lv_obj_align(mbox.p, LV_ALIGN_LEFT_MID, -78, 72);
    lv_obj_set_style_text_color(mbox.p, MY_COLOR_BLACK, LV_STATE_DEFAULT);   // 字体颜色
    lv_obj_set_style_border_color(mbox.p, MY_COLOR_BLACK, LV_STATE_DEFAULT); // 边框颜色
    lv_obj_set_style_border_width(mbox.p, 2, LV_STATE_DEFAULT);              // 边框宽度
    lv_obj_set_style_pad_all(mbox.p, 0, LV_STATE_DEFAULT);                   // 边距
    lv_obj_set_style_radius(mbox.p, 9, LV_STATE_DEFAULT);                    // 设置圆角
    lv_obj_set_style_bg_opa(mbox.p, LV_OPA_100, LV_STATE_DEFAULT);

    lv_obj_update_layout(mbox.p); // 更新布局
    uint16_t i_w = lv_obj_get_width(mbox.p);
    uint16_t i_h = lv_obj_get_height(mbox.p);
    uint16_t i_r = lv_obj_get_style_radius(mbox.p, LV_STATE_DEFAULT);

    // 内边框
    lv_obj_t *innerBorder = lv_obj_create(mbox.p);
    lv_obj_set_style_bg_opa(innerBorder, LV_OPA_0, LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(innerBorder, MY_COLOR_CYAN, LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(innerBorder, 2, LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(innerBorder, 0, LV_STATE_DEFAULT);
    lv_obj_set_style_radius(innerBorder, i_r - 2, LV_STATE_DEFAULT);
    lv_obj_set_size(innerBorder, i_w - 4, i_h - 4);
    lv_obj_align(innerBorder, LV_ALIGN_CENTER, 0, 0);

    // 标题
    lv_obj_t *box_title = lv_label_create(mbox.p);
    // lv_obj_set_style_border_width(box_title, 0, LV_STATE_DEFAULT); // 边框宽度
    // lv_obj_set_style_pad_all(box_title, 0, LV_STATE_DEFAULT);      // 边距
    lv_obj_set_width(box_title, 66);                                                // 设置宽度
    lv_obj_align(box_title, LV_ALIGN_TOP_MID, 1, 2);                                // 设置对齐方式
    lv_obj_set_style_text_color(box_title, MY_COLOR_WHITE, LV_STATE_DEFAULT);       // 设置文本颜色
    lv_label_set_long_mode(box_title, LV_LABEL_LONG_WRAP);                          // 设置文本长字符模式
    lv_obj_set_style_text_align(box_title, LV_TEXT_ALIGN_CENTER, LV_STATE_DEFAULT); // 设置文本对齐方式
    //lv_label_set_text(box_title, title);    
    lv_label_set_text(box_title, title);                                          // 打印文本
    
    // 标题的背景
    lv_obj_t *title_bg = lv_obj_create(mbox.p);
    lv_obj_set_style_border_width(title_bg, 0, LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(title_bg, MY_COLOR_BLACK, LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(title_bg, 0, LV_STATE_DEFAULT); // 边距
    lv_obj_set_style_radius(title_bg, 0, LV_STATE_DEFAULT);  // 设置圆角
    lv_obj_update_layout(mbox.p);// 更新布局
    lv_obj_set_size(title_bg, i_w - 8, lv_obj_get_height(box_title));
    lv_obj_align(title_bg, LV_ALIGN_TOP_MID, 0, 2);
    lv_obj_swap(title_bg, box_title); // 交换层级

    // 内容
    lv_obj_t *box_text = lv_label_create(mbox.p);
    lv_obj_set_width(box_text, 66);                                                // 设置宽度
    lv_obj_align_to(box_text, box_title, LV_ALIGN_OUT_BOTTOM_MID, 0, 1);           // 设置对齐方式
    lv_label_set_long_mode(box_text, LV_LABEL_LONG_WRAP);                          // 设置文本长字符模式
    lv_obj_set_style_text_align(box_text, LV_TEXT_ALIGN_CENTER, LV_STATE_DEFAULT); // 设置文本对齐方式
    lv_label_set_text(box_text, text); 

    // 更新大框的尺寸
    uint8_t additional = 14; //额外高度
    if (butNum == 0) 
        additional = 8; //没有按钮时只需要8
    lv_obj_update_layout(mbox.p); // 更新布局
    i_h = lv_obj_get_height(box_title) + lv_obj_get_height(box_text) + additional + (butNum * 23);
    lv_obj_set_size(mbox.p, 78, i_h);
    lv_obj_align(mbox.p, LV_ALIGN_LEFT_MID, -7, 0);

    // 更新内框的尺寸
    lv_obj_set_size(innerBorder, i_w - 4, i_h - 4);
    lv_obj_align(innerBorder, LV_ALIGN_CENTER, 0, 0);
    lv_obj_move_to_index(innerBorder, lv_obj_get_index(mbox.p) - 2); // 移动到顶层-1

    // 按钮存在
    if (butNum != 0)
    {
        // 记录现在的组，以便在退出时恢复
        //group_old = lv_indev_get_group(indev);
        group_old = indev->group;
        // 启用弹窗组
        lv_indev_set_group(indev, group_mbox0);
        // 使能 lv_layer_top 点击
        // lv_obj_add_flag(lv_layer_top(), LV_OBJ_FLAG_CLICKABLE);
        // lv_obj_add_flag(lv_layer_top(), LV_OBJ_FLAG_SCROLL_WITH_ARROW);
        mbox.keyMode = KEY_MODE_PN; // 切换至焦点模式
        
        // 设置文本的背景
        lv_obj_t *text_bg = lv_obj_create(mbox.p);
        lv_obj_set_style_bg_color(text_bg, MY_COLOR_YELLOW, LV_STATE_DEFAULT);
        lv_obj_set_style_border_width(text_bg, 0, LV_STATE_DEFAULT); // 边框宽度
        lv_obj_set_style_pad_all(text_bg, 0, LV_STATE_DEFAULT);      // 边距
        lv_obj_set_style_radius(text_bg, 0, LV_STATE_DEFAULT);       // 设置圆角
        lv_obj_update_layout(mbox.p); // 更新布局
        lv_obj_set_size(text_bg, i_w - 8, lv_obj_get_height(box_text));
        lv_obj_align_to(text_bg, title_bg, LV_ALIGN_OUT_BOTTOM_MID, 0, 0);
        lv_obj_swap(text_bg, box_text); //交换层级
        
        // 绘制按钮
        lv_obj_t *but[butNum];
        lv_obj_t *label[butNum];
        lv_color_t color[3] = {MY_COLOR_RED, MY_COLOR_GREEN, MY_COLOR_CYAN};
        for (uint8_t i = 0; i < butNum; i++)
        {
            // 创建按钮
            but[i] = lv_btn_create(mbox.p);
            lv_obj_set_size(but[i], 65, 19);
            if (i == 0)
              lv_obj_align_to(but[i], box_text, LV_ALIGN_OUT_BOTTOM_MID, -4, 5);
            else
              lv_obj_align_to(but[i], but[i - 1], LV_ALIGN_OUT_BOTTOM_MID, 0, 4);

            lv_obj_set_style_radius(but[i], 4, LV_STATE_DEFAULT);                       // 设置圆角
            lv_obj_add_style(but[i], &style_shadow, LV_STATE_DEFAULT);                  // 添加不透明度样式
            lv_obj_set_style_bg_color(but[i], color[i], LV_STATE_DEFAULT);              // 设置背景颜色
            lv_obj_set_style_outline_width(but[i], 2, LV_STATE_FOCUS_KEY);              // 聚焦框的宽度
            lv_obj_set_style_outline_pad(but[i], 0, LV_STATE_FOCUS_KEY);                // 聚焦框的间隙
            lv_obj_set_style_outline_opa(but[i], LV_OPA_100, LV_STATE_FOCUS_KEY);       // 聚焦框的不透明度
            lv_obj_set_style_outline_width(but[i], 0, LV_STATE_DEFAULT);                // 失焦时的宽度
            lv_obj_set_style_outline_color(but[i], MY_COLOR_BLACK, LV_STATE_FOCUS_KEY); // 聚焦框颜色
            
            // 创建标签
            label[i] = lv_label_create(but[i]);
            lv_obj_align(label[i], LV_ALIGN_CENTER, 0, 1);            // 设置对齐方式
            if (i == 0)
              lv_obj_set_style_text_color(label[i], MY_COLOR_WHITE, 0); // 设置字体颜色
            else
              lv_obj_set_style_text_color(label[i], MY_COLOR_BLACK, 0); // 设置字体颜色

            //lv_label_set_text(label[i], button_name[i].c_str());         // 打印文本
            lv_label_set_text(label[i], button_name[i]);         // 打印文本
            
            // 将按键邦定到组
            lv_group_add_obj(group_mbox0, but[i]);
            // 添加按钮聚焦动画
            //lv_obj_add_event_cb(but[i], buttonFocus_anim_event, LV_EVENT_FOCUSED, NULL);
            // 添加按钮按下回调
            lv_obj_add_event_cb(but[i], event_cb, LV_EVENT_PRESSED, &num[i]);
        }
      
        // 创建线条
        //static lv_point_precise_t line_points[] = {{0, 0}, {69, 0}};
        static lv_point_t line_points[] = {{0, 0}, {69, 0}};
        lv_obj_t * line1;
        line1 = lv_line_create(mbox.p);
        lv_line_set_points(line1, line_points, 2); 
        lv_obj_set_style_line_width(line1, 2, 0);
        lv_obj_set_style_line_color(line1,MY_COLOR_CYAN,0);
        //lv_obj_set_style_outline_opa(line1, LV_OPA_0, 0);
        //lv_obj_add_style(line1, &style_shadow, LV_STATE_DEFAULT); // 添加不透明度样式
        //lv_obj_set_style_line_rounded(line1, true, 0);
        lv_obj_align_to(line1, text_bg, LV_ALIGN_OUT_BOTTOM_MID, 0, 1);
      //lv_obj_center(line1);
    }

    // lv_obj_set_style_border_color(box_title, MY_COLOR_BLACK, LV_STATE_DEFAULT);
    // lv_obj_set_style_border_width(box_title, 1, LV_STATE_DEFAULT);
    // lv_obj_set_style_bg_color(box_title, MY_COLOR_BLACK, LV_STATE_DEFAULT);
    // lv_obj_set_style_bg_color(box_content, lv_color_make(255, 255, 0), LV_STATE_DEFAULT);
    // lv_obj_set_style_bg_opa(box_title, LV_OPA_100, LV_STATE_DEFAULT);
    // lv_obj_set_style_bg_opa(box_content, LV_OPA_100, LV_STATE_DEFAULT);

    // 给弹窗添加进入动画
    //Serial.println("弹窗创建");
    //Serial.printf("title_in:%s\n",title_in.c_str());
    //Serial.printf("text_in:%s\n",text_in.c_str());
    //Serial.printf("time:%d\n",time);

    printf("弹窗创建\n");
    printf("title_in:%s\n",title_in);
    printf("text_in:%s\n",text_in);
    printf("time:%d\n",time);

    //int16_t x = lv_obj_get_x(mbox.p);
    //Serial.printf("x:%d\n",x);

    lv_anim_t a;
    lv_anim_init(&a);                                          // 动画初始化
    lv_anim_set_var(&a, mbox.p);                               // 设置需要动画的对象
    lv_anim_set_values(&a, -78, -7);                           // 设置动画的开始值和结束值
    lv_anim_set_time(&a, MSGBOX_ANIM_TIME);                    // 设置动画的持续时间
    lv_anim_set_exec_cb(&a, my_msgbox_anim_x_cb);              // 设置需要变化的值
    lv_anim_set_path_cb(&a, lv_anim_path_bounce);              // 设置变化特效
    lv_anim_set_ready_cb(&a, my_msgbox_enter_anim_end_cb);     // 设置动画完成时的函数调用
    lv_anim_start(&a);     // 动画开始

    if (time > 0) //一段时间后退出
    {
      //lv_obj_delete_delayed(mbox.p, time);
      my_msgbox_exit(MSGBOX_ANIM_TIME + time);
    }

    bitWrite(mbox.state, MBOX_STATE_SEND, 0); // 标记发送结束

}

// 弹窗监测 放到loop任务中使用，用户勿调用
void ui_msgbox_loop(void)
{
  if(mbox.state == 0)  return; 

  // 强制发送时
  if (bitRead(mbox.state, MBOX_STATE_FORCE) == 1) 
  {
    // Serial.println("强制发送");
    mbox.state = 0;     // 状态清零重新开始
    if (mbox.p != NULL) // 删除现在的弹窗
    {
      lv_obj_del(mbox.p); // 删除对象
      mbox.p = NULL;         // 对象地址清空
      // 定时器存在，删除定时器
      if (lvTimer_msgbox)
      {
        lv_timer_del(lvTimer_msgbox);
        lvTimer_msgbox = NULL;
      }
    }
    bitWrite(mbox.state, MBOX_STATE_SEND, 1); // 标记发送阶段
    ui_msgbox_process(mbox.title, mbox.text, mbox.time, mbox.button, mbox.event_cb);
    return;
  }

  if(bitRead(mbox.state, MBOX_STATE_ENTER) == 1) return;  // 进入阶段 返回
  if(bitRead(mbox.state, MBOX_STATE_EXIT) == 1)  return;  // 退出阶段 返回
  //if(bitRead(mbox.state, MBOX_STATE_TIMER) == 1)  return; // 定时阶段 返回

  // 有新的弹窗进入，挤掉现在的弹窗
  if (mbox.p != NULL && bitRead(mbox.state, MBOX_STATE_SEND) == 1)
  {
    //Serial.println("新的弹窗挤入1");
    printf("新的弹窗挤入1\n");

    if (millis() - mbox.recordTime < 800) return; // 最少运行800毫秒

    //Serial.println("新的弹窗挤入2");
    printf("新的弹窗挤入2\n");

    bitWrite(mbox.state, MBOX_STATE_CLEAR, 0); // 标记不清空
    my_msgbox_exit(0);                         // 退出当前弹窗

    return;
  }

  if(bitRead(mbox.state, MBOX_STATE_REMAIN) == 1) return;

  bitWrite(mbox.state, MBOX_STATE_CLEAR, 1); // 标记下次退出需要清空内容和标志位
  mbox.recordTime = millis(); // 记录整体运行时间，包括动画运行时间
  ui_msgbox_process(mbox.title, mbox.text, mbox.time, mbox.button, mbox.event_cb);
}
