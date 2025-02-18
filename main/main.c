/*
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <inttypes.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "driver/gpio.h"

#include "demos/lv_demos.h"
*/

#include "examples/libs/gif/lv_example_gif.h"

#include "bsp_led.h"
#include "JDI_LPM009M360A.h"
#include "encoder.h"
#include "buzzer.h"

#include "LVGL_Driver.h"

#include "ui.h"


void app_main(void)
{
    printf("hello esp32s3!!\n");

    // LED初始化
    LED_Init();

    // 蜂鸣器初始化
    Buzzer_Init();

    // 编码器初始化
    Encoder_Init();

    // LCD初始化
    LCD_Init();

    // LVGL库初始化
    LVGL_Init(); 

    //demo_img();
    //demo_gif();
    //lv_example_gif_1();

    //demo_kabi_img();
    //demo_kabi_gif();

    //demo_label();
    jdi_ui_demo();
	
	/* 下面5个demos 只打开1个运行 */
    // lv_demo_benchmark(); 
    // lv_demo_keypad_encoder(); 
    // lv_demo_music(); 
    // lv_demo_stress(); 
    // lv_demo_widgets();

    while(1)
    {

        // raise the task priority of LVGL and/or reduce the handler period can improve the performance
        // 延时10毫秒
        vTaskDelay(pdMS_TO_TICKS(10));

        // The task running lv_timer_handler should have lower priority than that running `lv_tick_inc`
        // 调用lvgl库中的定时器处理函数
        lv_timer_handler();
    }
}