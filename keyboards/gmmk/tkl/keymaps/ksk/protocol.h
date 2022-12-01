#pragma once

#include <stdint.h>

typedef enum {
    KSK_PRESS = 0,
    KSK_LAYER,
    KSK_RGB_SET,
} ksk_op;

void protocol_send(ksk_op op, uint8_t header_data, uint8_t *data, uint8_t length);
