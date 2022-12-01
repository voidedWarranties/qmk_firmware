#include "led_matrix.h"

#ifdef RGB_MATRIX_ENABLE
#include "rgb_matrix.h"
#else
#include <stdint.h>
#include <stddef.h>

#include "color.h"
#endif // RGB_MATRIX_ENABLE

extern void _set_color(int index, uint8_t r, uint8_t g, uint8_t b);
extern void process_backlight(uint8_t devid, volatile LED_TYPE* states);

void flush(void) {
    process_backlight(0, NULL);
}

void set_color(int index, uint8_t r, uint8_t g, uint8_t b) {
    if (index >= 0 && index < RGB_MATRIX_LED_COUNT) {
        _set_color(index, r, g, b);
    }
}

void set_color_all(uint8_t r, uint8_t g, uint8_t b) {
    for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++)
        set_color(i, r, g, b);
}

#ifdef RGB_MATRIX_ENABLE
void init(void) {
}

const rgb_matrix_driver_t rgb_matrix_driver = {
    .init          = init,
    .flush         = flush,
    .set_color     = set_color,
    .set_color_all = set_color_all,
};
#endif // RGB_MATRIX_ENABLE
