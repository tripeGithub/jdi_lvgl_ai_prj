#include "lv_obj.h"

// 设置对象的宽度
void lv_obj_set_style_width(struct _lv_obj_t * obj, lv_coord_t value, lv_style_selector_t selector)
{
    lv_style_value_t v = {
        .num = (int32_t)value
    };
    lv_obj_set_local_style_prop(obj, LV_STYLE_WIDTH, v, selector);
}

// 设置对象的最小宽度
void lv_obj_set_style_min_width(struct _lv_obj_t * obj, lv_coord_t value, lv_style_selector_t selector)
{
    lv_style_value_t v = {
        .num = (int32_t)value
    };
    lv_obj_set_local_style_prop(obj, LV_STYLE_MIN_WIDTH, v, selector);
}

// 设置对象的最大宽度
void lv_obj_set_style_max_width(struct _lv_obj_t * obj, lv_coord_t value, lv_style_selector_t selector)
{
    lv_style_value_t v = {
        .num = (int32_t)value
    };
    lv_obj_set_local_style_prop(obj, LV_STYLE_MAX_WIDTH, v, selector);
}

// 设置对象的高度
void lv_obj_set_style_height(struct _lv_obj_t * obj, lv_coord_t value, lv_style_selector_t selector)
{
    lv_style_value_t v = {
        .num = (int32_t)value
    };
    lv_obj_set_local_style_prop(obj, LV_STYLE_HEIGHT, v, selector);
}

// 设置对象的最小高度
void lv_obj_set_style_min_height(struct _lv_obj_t * obj, lv_coord_t value, lv_style_selector_t selector)
{
    lv_style_value_t v = {
        .num = (int32_t)value
    };
    lv_obj_set_local_style_prop(obj, LV_STYLE_MIN_HEIGHT, v, selector);
}

// 设置对象的最大高度
void lv_obj_set_style_max_height(struct _lv_obj_t * obj, lv_coord_t value, lv_style_selector_t selector)
{
    lv_style_value_t v = {
        .num = (int32_t)value
    };
    lv_obj_set_local_style_prop(obj, LV_STYLE_MAX_HEIGHT, v, selector);
}

// 设置对象的x坐标
void lv_obj_set_style_x(struct _lv_obj_t * obj, lv_coord_t value, lv_style_selector_t selector)
{
    lv_style_value_t v = {
        .num = (int32_t)value
    };
    lv_obj_set_local_style_prop(obj, LV_STYLE_X, v, selector);
}

// 设置对象的y坐标
void lv_obj_set_style_y(struct _lv_obj_t * obj, lv_coord_t value, lv_style_selector_t selector)
{
    lv_style_value_t v = {
        .num = (int32_t)value
    };
    lv_obj_set_local_style_prop(obj, LV_STYLE_Y, v, selector);
}

// 设置对象的对齐方式
void lv_obj_set_style_align(struct _lv_obj_t * obj, lv_align_t value, lv_style_selector_t selector)
{
    lv_style_value_t v = {
        .num = (int32_t)value
    };
    lv_obj_set_local_style_prop(obj, LV_STYLE_ALIGN, v, selector);
}

// 设置对象的变换宽度
void lv_obj_set_style_transform_width(struct _lv_obj_t * obj, lv_coord_t value, lv_style_selector_t selector)
{
    lv_style_value_t v = {
        .num = (int32_t)value
    };
    lv_obj_set_local_style_prop(obj, LV_STYLE_TRANSFORM_WIDTH, v, selector);
}

// 设置对象的变换高度
void lv_obj_set_style_transform_height(struct _lv_obj_t * obj, lv_coord_t value, lv_style_selector_t selector)
{
    lv_style_value_t v = {
        .num = (int32_t)value
    };
    lv_obj_set_local_style_prop(obj, LV_STYLE_TRANSFORM_HEIGHT, v, selector);
}

// 设置对象的变换x坐标
void lv_obj_set_style_translate_x(struct _lv_obj_t * obj, lv_coord_t value, lv_style_selector_t selector)
{
    lv_style_value_t v = {
        .num = (int32_t)value
    };
    lv_obj_set_local_style_prop(obj, LV_STYLE_TRANSLATE_X, v, selector);
}

// 设置对象的变换y坐标
void lv_obj_set_style_translate_y(struct _lv_obj_t * obj, lv_coord_t value, lv_style_selector_t selector)
{
    lv_style_value_t v = {
        .num = (int32_t)value
    };
    lv_obj_set_local_style_prop(obj, LV_STYLE_TRANSLATE_Y, v, selector);
}

// 设置对象的变换缩放
void lv_obj_set_style_transform_zoom(struct _lv_obj_t * obj, lv_coord_t value, lv_style_selector_t selector)
{
    lv_style_value_t v = {
        .num = (int32_t)value
    };
    lv_obj_set_local_style_prop(obj, LV_STYLE_TRANSFORM_ZOOM, v, selector);
}

// 设置对象的变换角度
void lv_obj_set_style_transform_angle(struct _lv_obj_t * obj, lv_coord_t value, lv_style_selector_t selector)
{
    lv_style_value_t v = {
        .num = (int32_t)value
    };
    lv_obj_set_local_style_prop(obj, LV_STYLE_TRANSFORM_ANGLE, v, selector);
}

// 设置对象的变换中心x坐标
void lv_obj_set_style_transform_pivot_x(struct _lv_obj_t * obj, lv_coord_t value, lv_style_selector_t selector)
{
    lv_style_value_t v = {
        .num = (int32_t)value
    };
    lv_obj_set_local_style_prop(obj, LV_STYLE_TRANSFORM_PIVOT_X, v, selector);
}

// 设置对象的变换中心y坐标
void lv_obj_set_style_transform_pivot_y(struct _lv_obj_t * obj, lv_coord_t value, lv_style_selector_t selector)
{
    lv_style_value_t v = {
        .num = (int32_t)value
    };
    lv_obj_set_local_style_prop(obj, LV_STYLE_TRANSFORM_PIVOT_Y, v, selector);
}

// 设置对象的上内边距
void lv_obj_set_style_pad_top(struct _lv_obj_t * obj, lv_coord_t value, lv_style_selector_t selector)
{
    lv_style_value_t v = {
        .num = (int32_t)value
    };
    lv_obj_set_local_style_prop(obj, LV_STYLE_PAD_TOP, v, selector);
}

// 设置对象的下内边距
void lv_obj_set_style_pad_bottom(struct _lv_obj_t * obj, lv_coord_t value, lv_style_selector_t selector)
{
    lv_style_value_t v = {
        .num = (int32_t)value
    };
    lv_obj_set_local_style_prop(obj, LV_STYLE_PAD_BOTTOM, v, selector);
}

// 设置对象的左内边距
void lv_obj_set_style_pad_left(struct _lv_obj_t * obj, lv_coord_t value, lv_style_selector_t selector)
{
    lv_style_value_t v = {
        .num = (int32_t)value
    };
    lv_obj_set_local_style_prop(obj, LV_STYLE_PAD_LEFT, v, selector);
}

// 设置对象的右内边距
void lv_obj_set_style_pad_right(struct _lv_obj_t * obj, lv_coord_t value, lv_style_selector_t selector)
{
    lv_style_value_t v = {
        .num = (int32_t)value
    };
    lv_obj_set_local_style_prop(obj, LV_STYLE_PAD_RIGHT, v, selector);
}

// 设置对象行内边距
void lv_obj_set_style_pad_row(struct _lv_obj_t * obj, lv_coord_t value, lv_style_selector_t selector)
{
    lv_style_value_t v = {
        .num = (int32_t)value
    };
    lv_obj_set_local_style_prop(obj, LV_STYLE_PAD_ROW, v, selector);
}

// 设置对象列内边距
void lv_obj_set_style_pad_column(struct _lv_obj_t * obj, lv_coord_t value, lv_style_selector_t selector)
{
    lv_style_value_t v = {
        .num = (int32_t)value
    };
    lv_obj_set_local_style_prop(obj, LV_STYLE_PAD_COLUMN, v, selector);
}

// 设置对象的背景颜色
void lv_obj_set_style_bg_color(struct _lv_obj_t * obj, lv_color_t value, lv_style_selector_t selector)
{
    lv_style_value_t v = {
        .color = value
    };
    lv_obj_set_local_style_prop(obj, LV_STYLE_BG_COLOR, v, selector);
}

// 设置对象的背景不透明度
void lv_obj_set_style_bg_opa(struct _lv_obj_t * obj, lv_opa_t value, lv_style_selector_t selector)
{
    lv_style_value_t v = {
        .num = (int32_t)value
    };
    lv_obj_set_local_style_prop(obj, LV_STYLE_BG_OPA, v, selector);
}

// 设置对象的背景渐变颜色
void lv_obj_set_style_bg_grad_color(struct _lv_obj_t * obj, lv_color_t value, lv_style_selector_t selector)
{
    lv_style_value_t v = {
        .color = value
    };
    lv_obj_set_local_style_prop(obj, LV_STYLE_BG_GRAD_COLOR, v, selector);
}

// 设置对象的背景渐变方向
void lv_obj_set_style_bg_grad_dir(struct _lv_obj_t * obj, lv_grad_dir_t value, lv_style_selector_t selector)
{
    lv_style_value_t v = {
        .num = (int32_t)value
    };
    lv_obj_set_local_style_prop(obj, LV_STYLE_BG_GRAD_DIR, v, selector);
}

// 设置对象的背景主色停止点
void lv_obj_set_style_bg_main_stop(struct _lv_obj_t * obj, lv_coord_t value, lv_style_selector_t selector)
{
    lv_style_value_t v = {
        .num = (int32_t)value
    };
    lv_obj_set_local_style_prop(obj, LV_STYLE_BG_MAIN_STOP, v, selector);
}

// 设置对象的背景渐变色停止点
void lv_obj_set_style_bg_grad_stop(struct _lv_obj_t * obj, lv_coord_t value, lv_style_selector_t selector)
{
    lv_style_value_t v = {
        .num = (int32_t)value
    };
    lv_obj_set_local_style_prop(obj, LV_STYLE_BG_GRAD_STOP, v, selector);
}

// 设置对象的背景渐变
void lv_obj_set_style_bg_grad(struct _lv_obj_t * obj, const lv_grad_dsc_t * value, lv_style_selector_t selector)
{
    lv_style_value_t v = {
        .ptr = value
    };
    lv_obj_set_local_style_prop(obj, LV_STYLE_BG_GRAD, v, selector);
}

// 设置对象的背景抖动模式
void lv_obj_set_style_bg_dither_mode(struct _lv_obj_t * obj, lv_dither_mode_t value, lv_style_selector_t selector)
{
    lv_style_value_t v = {
        .num = (int32_t)value
    };
    lv_obj_set_local_style_prop(obj, LV_STYLE_BG_DITHER_MODE, v, selector);
}

// 设置对象的背景图片源
void lv_obj_set_style_bg_img_src(struct _lv_obj_t * obj, const void * value, lv_style_selector_t selector)
{
    lv_style_value_t v = {
        .ptr = value
    };
    lv_obj_set_local_style_prop(obj, LV_STYLE_BG_IMG_SRC, v, selector);
}

// 设置对象的背景图片不透明度
void lv_obj_set_style_bg_img_opa(struct _lv_obj_t * obj, lv_opa_t value, lv_style_selector_t selector)
{
    lv_style_value_t v = {
        .num = (int32_t)value
    };
    lv_obj_set_local_style_prop(obj, LV_STYLE_BG_IMG_OPA, v, selector);
}

// 设置对象的背景图片重绘颜色
void lv_obj_set_style_bg_img_recolor(struct _lv_obj_t * obj, lv_color_t value, lv_style_selector_t selector)
{
    lv_style_value_t v = {
        .color = value
    };
    lv_obj_set_local_style_prop(obj, LV_STYLE_BG_IMG_RECOLOR, v, selector);
}

// 设置对象的背景图片重绘颜色不透明度
void lv_obj_set_style_bg_img_recolor_opa(struct _lv_obj_t * obj, lv_opa_t value, lv_style_selector_t selector)
{
    lv_style_value_t v = {
        .num = (int32_t)value
    };
    lv_obj_set_local_style_prop(obj, LV_STYLE_BG_IMG_RECOLOR_OPA, v, selector);
}

// 设置对象的背景图片平铺
void lv_obj_set_style_bg_img_tiled(struct _lv_obj_t * obj, bool value, lv_style_selector_t selector)
{
    lv_style_value_t v = {
        .num = (int32_t)value
    };
    lv_obj_set_local_style_prop(obj, LV_STYLE_BG_IMG_TILED, v, selector);
}

// 设置对象的边框颜色
void lv_obj_set_style_border_color(struct _lv_obj_t * obj, lv_color_t value, lv_style_selector_t selector)
{
    lv_style_value_t v = {
        .color = value
    };
    lv_obj_set_local_style_prop(obj, LV_STYLE_BORDER_COLOR, v, selector);
}

// 设置对象的边框不透明度
void lv_obj_set_style_border_opa(struct _lv_obj_t * obj, lv_opa_t value, lv_style_selector_t selector)
{
    lv_style_value_t v = {
        .num = (int32_t)value
    };
    lv_obj_set_local_style_prop(obj, LV_STYLE_BORDER_OPA, v, selector);
}

// 设置对象的边框宽度
void lv_obj_set_style_border_width(struct _lv_obj_t * obj, lv_coord_t value, lv_style_selector_t selector)
{
    lv_style_value_t v = {
        .num = (int32_t)value
    };
    lv_obj_set_local_style_prop(obj, LV_STYLE_BORDER_WIDTH, v, selector);
}

// 设置对象的边框边
void lv_obj_set_style_border_side(struct _lv_obj_t * obj, lv_border_side_t value, lv_style_selector_t selector)
{
    lv_style_value_t v = {
        .num = (int32_t)value
    };
    lv_obj_set_local_style_prop(obj, LV_STYLE_BORDER_SIDE, v, selector);
}

// 设置对象的边框后
void lv_obj_set_style_border_post(struct _lv_obj_t * obj, bool value, lv_style_selector_t selector)
{
    lv_style_value_t v = {
        .num = (int32_t)value
    };
    lv_obj_set_local_style_prop(obj, LV_STYLE_BORDER_POST, v, selector);
}

// 设置对象的轮廓宽度
void lv_obj_set_style_outline_width(struct _lv_obj_t * obj, lv_coord_t value, lv_style_selector_t selector)
{
    lv_style_value_t v = {
        .num = (int32_t)value
    };
    lv_obj_set_local_style_prop(obj, LV_STYLE_OUTLINE_WIDTH, v, selector);
}

// 设置对象的轮廓颜色
void lv_obj_set_style_outline_color(struct _lv_obj_t * obj, lv_color_t value, lv_style_selector_t selector)
{
    lv_style_value_t v = {
        .color = value
    };
    lv_obj_set_local_style_prop(obj, LV_STYLE_OUTLINE_COLOR, v, selector);
}
 
// 设置对象的轮廓不透明度
void lv_obj_set_style_outline_opa(struct _lv_obj_t * obj, lv_opa_t value, lv_style_selector_t selector)
{
    lv_style_value_t v = {
        .num = (int32_t)value
    };
    lv_obj_set_local_style_prop(obj, LV_STYLE_OUTLINE_OPA, v, selector);
}

// 设置对象的轮廓内边距
void lv_obj_set_style_outline_pad(struct _lv_obj_t * obj, lv_coord_t value, lv_style_selector_t selector)
{
    lv_style_value_t v = {
        .num = (int32_t)value
    };
    lv_obj_set_local_style_prop(obj, LV_STYLE_OUTLINE_PAD, v, selector);
}

// 设置对象的阴影宽度
void lv_obj_set_style_shadow_width(struct _lv_obj_t * obj, lv_coord_t value, lv_style_selector_t selector)
{
    lv_style_value_t v = {
        .num = (int32_t)value
    };
    lv_obj_set_local_style_prop(obj, LV_STYLE_SHADOW_WIDTH, v, selector);
}

// 设置对象的阴影x偏移
void lv_obj_set_style_shadow_ofs_x(struct _lv_obj_t * obj, lv_coord_t value, lv_style_selector_t selector)
{
    lv_style_value_t v = {
        .num = (int32_t)value
    };
    lv_obj_set_local_style_prop(obj, LV_STYLE_SHADOW_OFS_X, v, selector);
}

// 设置对象的阴影y偏移
void lv_obj_set_style_shadow_ofs_y(struct _lv_obj_t * obj, lv_coord_t value, lv_style_selector_t selector)
{
    lv_style_value_t v = {
        .num = (int32_t)value
    };
    lv_obj_set_local_style_prop(obj, LV_STYLE_SHADOW_OFS_Y, v, selector);
}

// 设置对象的阴影扩散
void lv_obj_set_style_shadow_spread(struct _lv_obj_t * obj, lv_coord_t value, lv_style_selector_t selector)
{
    lv_style_value_t v = {
        .num = (int32_t)value
    };
    lv_obj_set_local_style_prop(obj, LV_STYLE_SHADOW_SPREAD, v, selector);
}

// 设置对象的阴影颜色
void lv_obj_set_style_shadow_color(struct _lv_obj_t * obj, lv_color_t value, lv_style_selector_t selector)
{
    lv_style_value_t v = {
        .color = value
    };
    lv_obj_set_local_style_prop(obj, LV_STYLE_SHADOW_COLOR, v, selector);
}

// 设置对象的阴影不透明度
void lv_obj_set_style_shadow_opa(struct _lv_obj_t * obj, lv_opa_t value, lv_style_selector_t selector)
{
    lv_style_value_t v = {
        .num = (int32_t)value
    };
    lv_obj_set_local_style_prop(obj, LV_STYLE_SHADOW_OPA, v, selector);
}

// 设置对象的图片不透明度
void lv_obj_set_style_img_opa(struct _lv_obj_t * obj, lv_opa_t value, lv_style_selector_t selector)
{
    lv_style_value_t v = {
        .num = (int32_t)value
    };
    lv_obj_set_local_style_prop(obj, LV_STYLE_IMG_OPA, v, selector);
}

// 设置对象的图片重绘颜色
void lv_obj_set_style_img_recolor(struct _lv_obj_t * obj, lv_color_t value, lv_style_selector_t selector)
{
    lv_style_value_t v = {
        .color = value
    };
    lv_obj_set_local_style_prop(obj, LV_STYLE_IMG_RECOLOR, v, selector);
}

// 设置对象的图片重绘颜色不透明度
void lv_obj_set_style_img_recolor_opa(struct _lv_obj_t * obj, lv_opa_t value, lv_style_selector_t selector)
{
    lv_style_value_t v = {
        .num = (int32_t)value
    };
    lv_obj_set_local_style_prop(obj, LV_STYLE_IMG_RECOLOR_OPA, v, selector);
}

// 设置对象的线条宽度
void lv_obj_set_style_line_width(struct _lv_obj_t * obj, lv_coord_t value, lv_style_selector_t selector)
{
    lv_style_value_t v = {
        .num = (int32_t)value
    };
    lv_obj_set_local_style_prop(obj, LV_STYLE_LINE_WIDTH, v, selector);
}

// 设置对象的线条虚线宽度
void lv_obj_set_style_line_dash_width(struct _lv_obj_t * obj, lv_coord_t value, lv_style_selector_t selector)
{
    lv_style_value_t v = {
        .num = (int32_t)value
    };
    lv_obj_set_local_style_prop(obj, LV_STYLE_LINE_DASH_WIDTH, v, selector);
}

// 设置对象的线条虚线间隔
void lv_obj_set_style_line_dash_gap(struct _lv_obj_t * obj, lv_coord_t value, lv_style_selector_t selector)
{
    lv_style_value_t v = {
        .num = (int32_t)value
    };
    lv_obj_set_local_style_prop(obj, LV_STYLE_LINE_DASH_GAP, v, selector);
}

// 设置对象的线条是否为圆角
void lv_obj_set_style_line_rounded(struct _lv_obj_t * obj, bool value, lv_style_selector_t selector)
{
    lv_style_value_t v = {
        .num = (int32_t)value
    };
    lv_obj_set_local_style_prop(obj, LV_STYLE_LINE_ROUNDED, v, selector);
}

// 设置对象的线条颜色
void lv_obj_set_style_line_color(struct _lv_obj_t * obj, lv_color_t value, lv_style_selector_t selector)
{
    lv_style_value_t v = {
        .color = value
    };
    lv_obj_set_local_style_prop(obj, LV_STYLE_LINE_COLOR, v, selector);
}

// 设置对象的线条不透明度
void lv_obj_set_style_line_opa(struct _lv_obj_t * obj, lv_opa_t value, lv_style_selector_t selector)
{
    lv_style_value_t v = {
        .num = (int32_t)value
    };
    lv_obj_set_local_style_prop(obj, LV_STYLE_LINE_OPA, v, selector);
}

// 设置对象的弧线宽度
void lv_obj_set_style_arc_width(struct _lv_obj_t * obj, lv_coord_t value, lv_style_selector_t selector)
{
    lv_style_value_t v = {
        .num = (int32_t)value
    };
    lv_obj_set_local_style_prop(obj, LV_STYLE_ARC_WIDTH, v, selector);
}

// 设置对象的弧线是否为圆角
void lv_obj_set_style_arc_rounded(struct _lv_obj_t * obj, bool value, lv_style_selector_t selector)
{
    lv_style_value_t v = {
        .num = (int32_t)value
    };
    lv_obj_set_local_style_prop(obj, LV_STYLE_ARC_ROUNDED, v, selector);
}

// 设置对象的弧线颜色
void lv_obj_set_style_arc_color(struct _lv_obj_t * obj, lv_color_t value, lv_style_selector_t selector)
{
    lv_style_value_t v = {
        .color = value
    };
    lv_obj_set_local_style_prop(obj, LV_STYLE_ARC_COLOR, v, selector);
}

// 设置对象的弧线不透明度
void lv_obj_set_style_arc_opa(struct _lv_obj_t * obj, lv_opa_t value, lv_style_selector_t selector)
{
    lv_style_value_t v = {
        .num = (int32_t)value
    };
    lv_obj_set_local_style_prop(obj, LV_STYLE_ARC_OPA, v, selector);
}

// 设置对象的弧线图片源
void lv_obj_set_style_arc_img_src(struct _lv_obj_t * obj, const void * value, lv_style_selector_t selector)
{
    lv_style_value_t v = {
        .ptr = value
    };
    lv_obj_set_local_style_prop(obj, LV_STYLE_ARC_IMG_SRC, v, selector);
}

// 设置对象的文本颜色
void lv_obj_set_style_text_color(struct _lv_obj_t * obj, lv_color_t value, lv_style_selector_t selector)
{
    lv_style_value_t v = {
        .color = value
    };
    lv_obj_set_local_style_prop(obj, LV_STYLE_TEXT_COLOR, v, selector);
}

// 设置对象的文本不透明度
void lv_obj_set_style_text_opa(struct _lv_obj_t * obj, lv_opa_t value, lv_style_selector_t selector)
{
    lv_style_value_t v = {
        .num = (int32_t)value
    };
    lv_obj_set_local_style_prop(obj, LV_STYLE_TEXT_OPA, v, selector);
}

// 设置对象的文本字体
void lv_obj_set_style_text_font(struct _lv_obj_t * obj, const lv_font_t * value, lv_style_selector_t selector)
{
    lv_style_value_t v = {
        .ptr = value
    };
    lv_obj_set_local_style_prop(obj, LV_STYLE_TEXT_FONT, v, selector);
}

// 设置对象的文本字母间距
void lv_obj_set_style_text_letter_space(struct _lv_obj_t * obj, lv_coord_t value, lv_style_selector_t selector)
{
    lv_style_value_t v = {
        .num = (int32_t)value
    };
    lv_obj_set_local_style_prop(obj, LV_STYLE_TEXT_LETTER_SPACE, v, selector);
}

// 设置对象的文本行间距
void lv_obj_set_style_text_line_space(struct _lv_obj_t * obj, lv_coord_t value, lv_style_selector_t selector)
{
    lv_style_value_t v = {
        .num = (int32_t)value
    };
    lv_obj_set_local_style_prop(obj, LV_STYLE_TEXT_LINE_SPACE, v, selector);
}

// 设置对象的文本装饰
void lv_obj_set_style_text_decor(struct _lv_obj_t * obj, lv_text_decor_t value, lv_style_selector_t selector)
{
    lv_style_value_t v = {
        .num = (int32_t)value
    };
    lv_obj_set_local_style_prop(obj, LV_STYLE_TEXT_DECOR, v, selector);
}

// 设置对象的文本对齐方式
void lv_obj_set_style_text_align(struct _lv_obj_t * obj, lv_text_align_t value, lv_style_selector_t selector)
{
    lv_style_value_t v = {
        .num = (int32_t)value
    };
    lv_obj_set_local_style_prop(obj, LV_STYLE_TEXT_ALIGN, v, selector);
}

// 设置对象的圆角半径
void lv_obj_set_style_radius(struct _lv_obj_t * obj, lv_coord_t value, lv_style_selector_t selector)
{
    lv_style_value_t v = {
        .num = (int32_t)value
    };
    lv_obj_set_local_style_prop(obj, LV_STYLE_RADIUS, v, selector);
}

// 设置对象的剪裁角
void lv_obj_set_style_clip_corner(struct _lv_obj_t * obj, bool value, lv_style_selector_t selector)
{
    lv_style_value_t v = {
        .num = (int32_t)value
    };
    lv_obj_set_local_style_prop(obj, LV_STYLE_CLIP_CORNER, v, selector);
}

// 设置对象的不透明度
void lv_obj_set_style_opa(struct _lv_obj_t * obj, lv_opa_t value, lv_style_selector_t selector)
{
    lv_style_value_t v = {
        .num = (int32_t)value
    };
    lv_obj_set_local_style_prop(obj, LV_STYLE_OPA, v, selector);
}

// 设置对象的不透明度层
void lv_obj_set_style_opa_layered(struct _lv_obj_t * obj, lv_opa_t value, lv_style_selector_t selector)
{
    lv_style_value_t v = {
        .num = (int32_t)value
    };
    lv_obj_set_local_style_prop(obj, LV_STYLE_OPA_LAYERED, v, selector);
}

// 设置对象的颜色过滤器描述
void lv_obj_set_style_color_filter_dsc(struct _lv_obj_t * obj, const lv_color_filter_dsc_t * value, lv_style_selector_t selector)
{
    lv_style_value_t v = {
        .ptr = value
    };
    lv_obj_set_local_style_prop(obj, LV_STYLE_COLOR_FILTER_DSC, v, selector);
}

// 设置对象的颜色过滤器不透明度
void lv_obj_set_style_color_filter_opa(struct _lv_obj_t * obj, lv_opa_t value, lv_style_selector_t selector)
{
    lv_style_value_t v = {
        .num = (int32_t)value
    };
    lv_obj_set_local_style_prop(obj, LV_STYLE_COLOR_FILTER_OPA, v, selector);
}

// 设置对象的动画
void lv_obj_set_style_anim(struct _lv_obj_t * obj, const lv_anim_t * value, lv_style_selector_t selector)
{
    lv_style_value_t v = {
        .ptr = value
    };
    lv_obj_set_local_style_prop(obj, LV_STYLE_ANIM, v, selector);
}

// 设置对象的动画时间
void lv_obj_set_style_anim_time(struct _lv_obj_t * obj, uint32_t value, lv_style_selector_t selector)
{
    lv_style_value_t v = {
        .num = (int32_t)value
    };
    lv_obj_set_local_style_prop(obj, LV_STYLE_ANIM_TIME, v, selector);
}

// 设置对象的动画速度
void lv_obj_set_style_anim_speed(struct _lv_obj_t * obj, uint32_t value, lv_style_selector_t selector)
{
    lv_style_value_t v = {
        .num = (int32_t)value
    };
    lv_obj_set_local_style_prop(obj, LV_STYLE_ANIM_SPEED, v, selector);
}

// 设置对象的过渡
void lv_obj_set_style_transition(struct _lv_obj_t * obj, const lv_style_transition_dsc_t * value, lv_style_selector_t selector)
{
    lv_style_value_t v = {
        .ptr = value
    };
    lv_obj_set_local_style_prop(obj, LV_STYLE_TRANSITION, v, selector);
}

// 设置对象的混合模式
void lv_obj_set_style_blend_mode(struct _lv_obj_t * obj, lv_blend_mode_t value, lv_style_selector_t selector)
{
    lv_style_value_t v = {
        .num = (int32_t)value
    };
    lv_obj_set_local_style_prop(obj, LV_STYLE_BLEND_MODE, v, selector);
}

// 设置对象的布局
void lv_obj_set_style_layout(struct _lv_obj_t * obj, uint16_t value, lv_style_selector_t selector)
{
    lv_style_value_t v = {
        .num = (int32_t)value
    };
    lv_obj_set_local_style_prop(obj, LV_STYLE_LAYOUT, v, selector);
}

// 设置对象的基础方向
void lv_obj_set_style_base_dir(struct _lv_obj_t * obj, lv_base_dir_t value, lv_style_selector_t selector)
{
    lv_style_value_t v = {
        .num = (int32_t)value
    };
    lv_obj_set_local_style_prop(obj, LV_STYLE_BASE_DIR, v, selector);
}
