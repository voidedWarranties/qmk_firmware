#ifdef RGB_MATRIX_ENABLE
#include "rgb_matrix.h"
#else
#include <stdint.h>
#endif // RGB_MATRIX_ENABLE

extern void _set_color(int index, uint8_t r, uint8_t g, uint8_t b);

#ifdef RGB_MATRIX_ENABLE
extern void process_backlight(uint8_t devid, volatile LED_TYPE* states);

static void flush(void)
{
    process_backlight(0, NULL);
}
#endif // RGB_MATRIX_ENABLE

void set_color(int index, uint8_t r, uint8_t g, uint8_t b) {
    if (index >= 0 && index < RGB_MATRIX_LED_COUNT)
    {
        _set_color(index, r, g, b);
    }
}

#ifdef RGB_MATRIX_ENABLE
static void set_color_all(uint8_t r, uint8_t g, uint8_t b) {
    for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++)
        set_color(i, r, g, b);
}

void init(void) {
}

const rgb_matrix_driver_t rgb_matrix_driver = {
    .init          = init,
    .flush         = flush,
    .set_color     = set_color,
    .set_color_all = set_color_all,
};
#endif // RGB_MATRIX_ENABLE
