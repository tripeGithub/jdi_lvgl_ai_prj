#ifndef _BUZZER_H_
#define _BUZZER_H_

#include "driver/ledc.h"
#include "esp_err.h"
#include "esp_log.h"

#define BUZZER_GPIO 48//42
#define BUZZER_CHANNEL LEDC_CHANNEL_0
#define BUZZER_TIMER LEDC_TIMER_0
#define BUZZER_FREQ 5000 // 5kHz
#define BUZZER_DUTY 1024//512  // 50% duty cycle

extern void Buzzer_Init(void);
extern void buzzer_play(uint32_t freq, uint32_t duty);
extern void buzzer_stop(void);

#endif // _BUZZER_H_