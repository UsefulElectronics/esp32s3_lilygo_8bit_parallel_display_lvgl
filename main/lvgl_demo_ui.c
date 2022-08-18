/*
 * SPDX-FileCopyrightText: 2021 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: CC0-1.0
 */

#include <math.h>
#include "lvgl.h"

#ifndef PI
#define PI  (3.14159f)
#endif

// LVGL image declare

LV_IMG_DECLARE(ue_logo)

LV_IMG_DECLARE(ue_text)

static lv_style_t style;
static lv_style_t bgStyle;
static lv_style_t titleStyle;

typedef struct
{
    lv_obj_t *scr;
    int count_val;
} my_timer_context_t;

static lv_obj_t *arc[3];
static lv_obj_t *img_logo;
static lv_obj_t *img_text;

static lv_obj_t *lebel;

static lv_color_t arc_color[] =
{
    LV_COLOR_MAKE(0x0B, 0xF4, 0xF6),
    LV_COLOR_MAKE(126, 87, 162),
    LV_COLOR_MAKE(90, 202, 228),
};

static void anim_timer_cb(lv_timer_t *timer)
{
    my_timer_context_t *timer_ctx = (my_timer_context_t *) timer->user_data;
    int count = timer_ctx->count_val;
    lv_obj_t *scr = timer_ctx->scr;

    // Play arc animation
    if (count < 90)
    {
        lv_coord_t arc_start = count > 0 ? (1 - cosf(count / 180.0f * PI)) * 270 : 0;
        lv_coord_t arc_len = (sinf(count / 180.0f * PI) + 1) * 135;

        for (size_t i = 0; i < sizeof(arc) / sizeof(arc[0]); i++) {
            lv_arc_set_bg_angles(arc[i], arc_start, arc_len);
            lv_arc_set_rotation(arc[i], (count + 120 * (i + 1)) % 360);
        }
    }

    // Delete arcs when animation finished
    if (count == 90)
    {
        for (size_t i = 0; i < sizeof(arc) / sizeof(arc[0]); i++)
        {
            lv_obj_del(arc[i]);
        }

        // Create new image and make it transparent



        img_text = lv_img_create(scr);
        lv_img_set_src(img_text, &ue_text);
        lv_obj_set_style_img_opa(img_text, 0, 0);
    }

    // Move images when arc animation finished
    if ((count >= 100) && (count <= 180)) {
        lv_coord_t offset = (sinf((count - 140) * 2.25f / 90.0f) + 1) * 20.0f;
        lv_obj_align(img_logo, LV_ALIGN_CENTER, 0, -offset);
        lv_obj_align(img_text, LV_ALIGN_CENTER, 0, 1 * offset);
        lv_obj_set_style_img_opa(img_text, offset / 40.0f * 255, 0);
//        lv_obj_set_style_text_opa(obj, value, selector)
    }

    // Delete timer when all animation finished
    if ((count += 5) == 220)
    {
        lv_timer_del(timer);
        //TODO start another timer and do another animation

        lebel = lv_label_create(lv_scr_act());
        lv_obj_add_style(lebel, &style, 0);
        lv_label_set_long_mode(lebel, LV_LABEL_LONG_SCROLL_CIRCULAR);     /*Circular scroll*/
        //To let scroll feature work properly, the text size must be larger than the assigned size.
        lv_obj_set_width(lebel, 150);
        lv_label_set_text(lebel, "SUBSCRIBE");
        lv_obj_align(lebel, LV_ALIGN_CENTER, 0, 60);


//        lv_style_set_text_font
    }
    else
    {
        timer_ctx->count_val = count;
    }
}

void example_lvgl_demo_ui(lv_obj_t *scr)
{
    // Create image
    img_logo = lv_img_create(scr);
//    lv_img_set_src(img_logo, &esp_logo);
    lv_img_set_src(img_logo, &ue_logo);

    lv_obj_center(img_logo);
    //create style
    lv_style_init(&style);
    lv_style_init(&bgStyle);
    lv_style_init(&titleStyle);


//    lv_color_t	textColor16;
//    textColor16.ch.blue = 0b11;	//green
//    textColor16.ch.green = 0b000; //red
//    textColor16.ch.red = 0b000;   //blue			//lv_color_hex(0xblue 0xred 0xgreen)

    lv_color_t textColor16 = lv_color_hex(0x30FC30);

    lv_style_set_text_color(&style,textColor16);
    lv_style_set_text_font(&style,  &lv_font_montserrat_28);
    //Change background color
    textColor16 = lv_color_hex(0x000000);
    lv_obj_add_style(lv_scr_act(), &bgStyle, 0);
    lv_style_set_bg_color(&bgStyle, textColor16);




    // Create arcs
    for (size_t i = 0; i < sizeof(arc) / sizeof(arc[0]); i++)
    {
        arc[i] = lv_arc_create(scr);

        // Set arc caption
        lv_obj_set_size(arc[i], 220 - 30 * i, 220 - 30 * i);
        lv_arc_set_bg_angles(arc[i], 120 * i, 10 + 120 * i);
        lv_arc_set_value(arc[i], 0);

        // Set arc style
        lv_obj_remove_style(arc[i], NULL, LV_PART_KNOB);
        lv_obj_set_style_arc_width(arc[i], 10, 0);
        lv_obj_set_style_arc_color(arc[i], arc_color[i], 0);

        // Make arc center
        lv_obj_center(arc[i]);
    }

    // Create timer for animation
    static my_timer_context_t my_tim_ctx = {
        .count_val = -90,
    };
    my_tim_ctx.scr = scr;
    lv_timer_create(anim_timer_cb, 20, &my_tim_ctx);
}
