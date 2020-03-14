//
// Created by cyber on 29.02.20.
//

#include <lvgl/src/lv_core/lv_obj.h>
#include <lvgl/src/lv_objx/lv_btn.h>
#include <lvgl/src/lv_objx/lv_label.h>
#include "esp32_settings.h"
#include "reppanel_helper.h"
#include "reppanel.h"
#include <stdio.h>

void get_tmp_unit(char *buf) {
    if (temp_unit == 0)
        strcpy(buf, "°C");
    else
        strcpy(buf, "°F");
}

void init_reprap_buffers() {
    for (int i = 0; i < MAX_NUM_TOOLS; i++) {
        reprap_extruder_amounts[i] = -1;
        reprap_extruder_feedrates[i] = -1;
        reprap_chamber_temp_buff[i] = -1;
    }
}

void create_button(lv_obj_t *parent, lv_obj_t *button_pnt, char *text, void *event_handler) {
    lv_obj_t *label;
    button_pnt = lv_btn_create(parent, NULL);
    lv_btn_set_fit(button_pnt, LV_FIT_TIGHT);
    lv_obj_set_event_cb(button_pnt, event_handler);
    lv_obj_align(button_pnt, parent, LV_ALIGN_CENTER, 0, 0);
    label = lv_label_create(button_pnt, NULL);
    lv_label_set_text(label, text);
}