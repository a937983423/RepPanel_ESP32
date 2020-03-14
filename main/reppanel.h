//
// Created by cyber on 16.02.20.
//

#ifndef LVGL_REPPANEL_H
#define LVGL_REPPANEL_H

#include <stdint.h>

#include "reppanel_helper.h"
#include "esp32_settings.h"

#ifdef __cplusplus
extern "C" {
#endif

#define MAX_REPRAP_STATUS_LEN   15
#define MAX_PREPANEL_TEMP_LEN   8

// set as user data to ddlists to identify within common event
#define DDLIST_BED_TMP_ACTIVE 0
#define DDLIST_BED_TMP_STANDBY 1
#define DDLIST_TOOL_TMP_ACTIVE 2
#define DDLIST_TOOL_TMP_STANDBY 3

#define REPPANEL_NO_CONNECTION      0
#define REPPANEL_WIFI_CONNECTED     1
#define REPPANEL_WIFI_DISCONNECTED  2
#define REPPANEL_WIFI_RECONNECTING  3
#define REPPANEL_UART_CONNECTED     4

#define VERSION_STR             "v0.1.0"

#define NUM_TEMPS_BUFF      15
#define MAX_FILA_NAME_LEN   100

extern uint8_t reppanel_conn_status;               // 0=no connection, 1=connected wifi, 2=disconnected wifi, 3=reconnecting wifi,
                                            // 4=working UART

extern lv_obj_t *process_scr;               // screen for the process settings
extern lv_obj_t *mainmenu_scr;              // screen for the main_menue

extern lv_obj_t *cont_main;
extern lv_obj_t *label_status;
extern lv_obj_t *label_chamber_temp;
extern lv_obj_t *label_bed_temp;
extern lv_obj_t *label_tool_temp;
// extern lv_obj_t *label_progress_percent;
extern lv_obj_t *main_menu_button;
extern lv_obj_t *console_button;
extern lv_obj_t *label_extruder_name;
extern lv_obj_t *ddlist_tool_temp_active;
extern lv_obj_t *ddlist_tool_temp_standby;
extern lv_obj_t *ddlist_bed_temp_active;
extern lv_obj_t *ddlist_bed_temp_standby;
extern lv_obj_t *button_tool_filament;
extern lv_obj_t *label_sig_strength;
extern lv_obj_t *ta_wifi_pass;
extern lv_obj_t *ta_ssid;
extern lv_obj_t *ta_printer_addr;
extern lv_obj_t *ta_reprap_pass;
extern lv_obj_t *label_connection_status;

// Temp variable for writing to label. Contains current temp + °C or °F
extern char reppanel_status[MAX_REPRAP_STATUS_LEN];
extern char reppanel_chamber_temp[MAX_REPRAP_STATUS_LEN];
extern char reppanel_bed_temp[MAX_PREPANEL_TEMP_LEN];
extern char reppanel_job_progess[MAX_PREPANEL_TEMP_LEN];

extern int reprap_chamber_temp_curr_pos;
extern double reprap_chamber_temp_buff[NUM_TEMPS_BUFF];

// predefined by d2wc config. Temps the heaters can be set to
extern double reprap_babysteps_amount;
extern double reprap_extruder_amounts[NUM_TEMPS_BUFF];
extern double reprap_extruder_feedrates[NUM_TEMPS_BUFF];
extern double reprap_move_feedrate;
extern double reprap_mcu_temp;
extern char reprap_firmware_name[100];
extern char reprap_firmware_version[5];

typedef struct {
    int number;
    char name[100];
    int fans;
    char filament[MAX_FILA_NAME_LEN];
    int heater_indx;                    // only support one heater per tool for now
    double temp_buff[NUM_TEMPS_BUFF];   // Temp buffer contains temperature history of heaters
    int temp_hist_curr_pos;                  // Pointers to current position within the temp buffer
} reprap_tool_t;

typedef struct {
    double temp_buff[NUM_TEMPS_BUFF];   // Temp buffer contains temperature history of heater
    int temp_hist_curr_pos;                  // Pointers to current position within the temp buffer
    int heater_indx;
} reprap_bed_t;

typedef struct {
    double temps_standby[NUM_TEMPS_BUFF];
    double temps_active[NUM_TEMPS_BUFF];
} reprap_tool_poss_temps_t;

typedef struct {
    double temps_standby[NUM_TEMPS_BUFF];
    double temps_active[NUM_TEMPS_BUFF];
} reprap_bed_poss_temps_t;

// List with temps + unit. Entries separated by new line. Passed to littlevgl widget
extern char bed_tmps_active[MAX_LEN_TMPS_DDLIST_LEN];
extern char bed_tmps_standby[MAX_LEN_TMPS_DDLIST_LEN];
extern char tool_tmps_active[MAX_LEN_TMPS_DDLIST_LEN];
extern char tool_tmps_standby[MAX_LEN_TMPS_DDLIST_LEN];

// pos 0 is bed temp, rest are tool heaters
extern int heater_states[MAX_NUM_TOOLS];       // 0=off, 1=standby, 2=active, 3=fault - Storage for incoming data
extern int num_heaters;     // max is MAX_NUM_TOOLS
extern int num_tools;     // max is MAX_NUM_TOOLS
extern int current_visible_tool_indx;   // current indx of tool where temp data is displayed on process screen

extern reprap_tool_t reprap_tools[MAX_NUM_TOOLS];
extern reprap_bed_t reprap_bed;
extern reprap_tool_poss_temps_t reprap_tool_poss_temps;
extern reprap_bed_poss_temps_t reprap_bed_poss_temps;

extern char *filament_names;

void rep_panel_ui_create();
void update_rep_panel_conn_status();

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif //LVGL_REPPANEL_H
