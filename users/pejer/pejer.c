#include QMK_KEYBOARD_H

#include "custom_keycodes.h"
#include "layer_keys.h"

#if defined(CAPS_WORD_ENABLE)
bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
        case SE_MINS:
        case KC_MINS:
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
        case SE_UNDS:
            return true;

        default:
            return false;  // Deactivate Caps Word.
    }
}
#endif
#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    int layer = get_highest_layer(layer_state|default_layer_state);
    /* if (index == 0) { /* First encoder */ */
        switch(layer){
            case _FKEYS:
                tap_code(clockwise ? KC_PAUS : KC_SCRL);
            break;
            default:
                tap_code(clockwise ? KC_AUDIO_VOL_UP : KC_AUDIO_VOL_DOWN);
            break;
        }
    /* } */
    return false;
}
#endif // ENCODER_ENABLE
