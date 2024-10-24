#include QMK_KEYBOARD_H
#include "pejer.h"

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_180;
}
// just testing w. kyria!
bool oled_task_user(void) {
    // if (is_keyboard_master()) {
        oled_write_P(PSTR(" The Display"), false);
    // } else {
        // oled_write_P(PSTR(" Slave"), false);
    // }
    return false;
}
