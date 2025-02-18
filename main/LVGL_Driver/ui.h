#include "LVGL_Driver.h"

extern lv_group_t *group1;

extern lv_obj_t *ui_Screen1;
extern lv_obj_t *ui_Panel1;

extern lv_obj_t *btn1;
extern lv_obj_t *label1;
extern lv_obj_t *btn2;
extern lv_obj_t *label2;
extern lv_obj_t *btn3;
extern lv_obj_t *label3;
extern lv_obj_t *btn4;
extern lv_obj_t *label4;
extern lv_obj_t *btn5;
extern lv_obj_t *label5;
extern lv_obj_t *btn6;
extern lv_obj_t *label6;
extern lv_obj_t *btn7;
extern lv_obj_t *label7;
extern lv_obj_t *btn8;
extern lv_obj_t *label8;
extern lv_obj_t *btn9;
extern lv_obj_t *label9;
extern lv_obj_t *btn10;
extern lv_obj_t *label10;

extern lv_obj_t *ui_Screen2;
extern lv_obj_t *ui_Image1;
extern lv_obj_t *btn11;
extern lv_obj_t *label11;

extern lv_group_t *group2;

void demo_img(void);
void demo_gif(void);
void demo_kabi_img(void);
void demo_kabi_gif(void);
void demo_label(void);

extern void lvgl_screen1_init(void);
extern void lvgl_screen2_init(void);
extern void lvgl_screen1_group_init(void);
extern void lvgl_screen2_group_init(void);

extern void ui_event_Button_cb( lv_event_t * e);
extern void _ui_screen_change( lv_obj_t ** target, lv_scr_load_anim_t fademode, int spd, int delay, void (*target_init)(void));

extern void jdi_ui_demo(void);