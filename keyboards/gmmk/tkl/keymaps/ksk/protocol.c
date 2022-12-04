#include "protocol.h"

#include "led_matrix.h"

#include <stdint.h>
#include <string.h>

#include "raw_hid.h"
#include "usb_descriptor.h"
#include "action_layer.h"

void protocol_send(ksk_op op, uint8_t header_data, uint8_t *data, uint8_t length) {
    uint8_t buf[RAW_EPSIZE];
    buf[0] = 'k';
    buf[1] = 's';
    buf[2] = 'k';
    buf[3] = (op << 4) | (header_data & 0b00001111);

    memcpy(buf + 4, data, length);
    raw_hid_send(buf, RAW_EPSIZE);
}

void raw_hid_receive(uint8_t *data, uint8_t length) {
    if (length < 4 || data[0] != 'k' || data[1] != 's' || data[2] != 'k') {
        return;
    }

    ksk_op op = data[3] >> 4;
    uint8_t header_data = data[3] & 0b00001111;

    const uint8_t body_start = 4;

    switch (op) {
        case KSK_RGB_SET:
            if (header_data == 0) { // set all
                set_color_all(data[body_start], data[body_start + 1], data[body_start + 2]);
            } else {
                for (uint8_t i = 0; i < header_data; i++) {
                    uint8_t idx_start = body_start + i * 4;
                    set_color(data[idx_start], data[idx_start + 1], data[idx_start + 2], data[idx_start + 3]);
                }
            }

            break;

        case KSK_LAYER:
            if (header_data == 0) {
                layer_off(data[body_start]);
            } else {
                layer_on(data[body_start]);
            }

            break;

        default:
            break;
    }
}
