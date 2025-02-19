#include "LVGL_Driver.h"

#include "ui_screen1.h"
#include "ui_screen2.h"

void demo_img(void);
void demo_gif(void);
void demo_kabi_img(void);
void demo_kabi_gif(void);
void demo_label(void);


extern void _ui_screen_change( lv_obj_t ** target, lv_scr_load_anim_t fademode, int spd, int delay, void (*target_init)(void));

extern void jdi_ui_demo(void);