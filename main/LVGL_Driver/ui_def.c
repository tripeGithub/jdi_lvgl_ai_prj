
#include "ui_def.h"
#include "LVGL_Driver.h"

uint64_t millis(void)
{
    return esp_timer_get_time() / 1000;
}
  