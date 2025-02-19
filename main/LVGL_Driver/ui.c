

#include "ui.h"


void demo_img(void)
{
  // 1.准备一张图片
  LV_IMG_DECLARE(maomao);
  // 2.创建一个lv_img对象
  lv_obj_t *img1 = lv_img_create(lv_scr_act());
  // 3.给对象设置图片
  lv_img_set_src(img1, &maomao);
  // 4.设置图片位置
  lv_obj_align(img1, LV_ALIGN_BOTTOM_MID, 0, 0);

}

void demo_kabi_img(void)
{
  // 1.准备一张图片
  LV_IMG_DECLARE(kabi_img);
  // 2.创建一个lv_img对象
  lv_obj_t *img1 = lv_img_create(lv_scr_act());
  // 3.给对象设置图片
  lv_img_set_src(img1, &kabi_img);
  // 4.设置图片位置
  lv_obj_align(img1, LV_ALIGN_CENTER, 0, 0);

}

void demo_gif(void)
{
  /*
    // 1.准备一张图片
    LV_IMG_DECLARE(qft);
    // 2.创建一个lv_img对象
    lv_obj_t *gif1 = lv_gif_create(lv_screen_active());
    // 3.给对象设置图片
    lv_gif_set_src(gif1, &qft);
    // 4.设置图片位置
    lv_obj_align(gif1, LV_ALIGN_BOTTOM_MID, 0, 0);
  */

  // qft 千反田 tw 跳舞 xiaomai 小埋 yqs 摇汽水 liuhua 六花
  LV_IMG_DECLARE(liuhua);
  lv_obj_t *gif2 = lv_gif_create(lv_scr_act());
  lv_gif_set_src(gif2, &liuhua);
  lv_obj_align(gif2, LV_ALIGN_CENTER, 0, 0);
}

void demo_kabi_gif(void)
{

  // qft 千反田 tw 跳舞 xiaomai 小埋 yqs 摇汽水 liuhua 六花
  LV_IMG_DECLARE(kabi_gif);
  lv_obj_t *gif2 = lv_gif_create(lv_scr_act());
  lv_gif_set_src(gif2, &kabi_gif);
  lv_obj_align(gif2, LV_ALIGN_CENTER, 0, 0);
}

void _ui_screen_change( lv_obj_t ** target, lv_scr_load_anim_t fademode, int spd, int delay, void (*target_init)(void)) 
{
   if(*target == NULL)
      target_init();
   lv_scr_load_anim(*target, fademode, spd, delay, false);
   //lv_scr_load_anim(*target, fademode, spd, delay, true);
}

void jdi_ui_demo(void)
{
    lvgl_screen1_init();
    lvgl_screen2_init();  

    lvgl_screen1_group_init();

    lv_disp_load_scr(ui_Screen1); // 加载主屏幕
}