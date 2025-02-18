#ifndef _ENCODER_H_
#define _ENCODER_H_
#include "lvgl.h"
#include <stdio.h>
//#include "lv_port_indev_Key.h"
//#include "lvgl_function.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "driver/ledc.h"
#include "esp_err.h"
#include "sdkconfig.h"


#define     Encoder_A     21    //编码器通道一
#define     Encoder_B     40    //编码器通道二
#define     Encoder_K     39    //编码器按键通道

#define     Encoder_CHA_GPIO_INPUT_PIN_SEL      ((1ULL<<Encoder_A))
#define     Encoder_CHB_GPIO_INPUT_PIN_SEL      ((1ULL<<Encoder_B))
#define     Encoder_KEY_GPIO_INPUT_PIN_SEL      ((1ULL<<Encoder_K))

extern QueueHandle_t encoder_gpio_event_queue;

extern volatile uint8_t encoder_dir_buzzer_trig;
extern volatile uint8_t encoder_key_buzzer_trig;

void EncoderGpioConfig(void);
void Encoder_Init(void);
void Encoder_Loop(void);

uint8_t user_lvgl_encoder_key_get(void);
int16_t user_lvgl_encoder_dir_get(void);

void encoder_read(lv_indev_drv_t *indev_drv, lv_indev_data_t *data);
void keypad_read(lv_indev_drv_t *indev_drv, lv_indev_data_t *data);

#endif
