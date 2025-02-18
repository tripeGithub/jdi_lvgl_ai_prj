#include "buzzer.h"



static const char *TAG = "buzzer";

void Buzzer_Init(void) {
    ledc_timer_config_t ledc_timer = {
        .speed_mode       = LEDC_LOW_SPEED_MODE,
        .timer_num        = BUZZER_TIMER,
        .duty_resolution  = LEDC_TIMER_13_BIT,
        .freq_hz          = BUZZER_FREQ,
        .clk_cfg          = LEDC_AUTO_CLK
    };
    ledc_timer_config(&ledc_timer);

    ledc_channel_config_t ledc_channel = {
        .speed_mode     = LEDC_LOW_SPEED_MODE,
        .channel        = BUZZER_CHANNEL,
        .timer_sel      = BUZZER_TIMER,
        .intr_type      = LEDC_INTR_FADE_END,
        .gpio_num       = BUZZER_GPIO,
        .duty           = 0,
        .hpoint         = 0
    };
    ledc_channel_config(&ledc_channel);
}

void buzzer_play(uint32_t freq, uint32_t duty) {
    ledc_set_freq(LEDC_LOW_SPEED_MODE, BUZZER_TIMER, freq);
    ledc_set_duty(LEDC_LOW_SPEED_MODE, BUZZER_CHANNEL, duty);
    ledc_update_duty(LEDC_LOW_SPEED_MODE, BUZZER_CHANNEL);
}

void buzzer_stop(void) {
    ledc_stop(LEDC_LOW_SPEED_MODE, BUZZER_CHANNEL, 0);
}

/*
void app_main() {
    ESP_LOGI(TAG, "Initializing buzzer");
    buzzer_init();

    while (1) {
        ESP_LOGI(TAG, "Playing 1kHz sound");
        buzzer_play(1000, BUZZER_DUTY);
        vTaskDelay(1000 / portTICK_PERIOD_MS);

        ESP_LOGI(TAG, "Playing 2kHz sound");
        buzzer_play(2000, BUZZER_DUTY);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}
*/