
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "LVGL_Driver.h"

#include "ui_def.h"

#define MSGBOX_STR_LEN 32
// 弹窗状态 枚举
enum
{
  MBOX_STATE_SEND = 0, // 发送阶段
  MBOX_STATE_ENTER,    // 进入阶段
  MBOX_STATE_REMAIN,   // 停留阶段
  MBOX_STATE_TIMER,    // 定时器运行阶段
  MBOX_STATE_EXIT,     // 退出阶段
  MBOX_STATE_CLEAR,    // 清空
  MBOX_STATE_FORCE,    // 强制发送
};

// 弹窗结构体
typedef struct str_msgbox
{
  lv_obj_t *p;
  bool keyMode;             // 按键模式
  uint8_t state;            // 0-发送中 1-运行中 2-退出中 3-清空
  uint16_t recordTime;      // 记录弹窗的整个运行时间，包括动画

  //String title;           // 标题
  //String text;            // 内容
  //String button;          // 是否有按钮，用换行隔开
  
  char title[32];
  char text[32];
  char button[32];

  uint16_t time;            // 弹窗的停留时间，不包括动画

  lv_event_cb_t event_cb; // 按钮的回调函数

} MBOX;

extern MBOX mbox;