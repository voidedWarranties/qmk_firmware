#pragma once

#include <stdint.h>

void set_color(int index, uint8_t r, uint8_t g, uint8_t b);
void set_color_all(uint8_t r, uint8_t g, uint8_t b);
void flush(void);
