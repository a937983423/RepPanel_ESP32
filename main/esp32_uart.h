//
// Copyright (c) 2020 Wolfgang Christl
// Licensed under Apache License, Version 2.0 - https://opensource.org/licenses/Apache-2.0
//

#ifndef REPPANEL_ESP32_ESP32_UART_H
#define REPPANEL_ESP32_ESP32_UART_H

#include "reppanel_request.h"

#define UART_MAX_READ_TIMEOUT_CNT   5
#define UART_DATA_BUFF_LEN  0

void init_uart();
void reppanel_write_uart(char *buffer, int buffer_len);
void esp32_flush_uart();
bool reppanel_is_uart_connected();
bool reppanel_read_response(uart_response_buff_t *receive_buff);

#endif //REPPANEL_ESP32_ESP32_UART_H
