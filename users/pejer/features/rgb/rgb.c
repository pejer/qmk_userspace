#include "pejer.h"
// bool pejer_rgb_matrix_layer_state(uint8_t led_min, uint8_t led_max) {
//     if (host_keyboard_led_state().caps_lock) {
//         for (int i = led_min; i <= led_max; i++) {
//             if (g_led_config.flags[i] & LED_FLAG_MODIFIER) {
//                 rgb_matrix_set_color(i, RGB_RED);
//             }
//         }
//     }
//
//     uint8_t layer = get_highest_layer(layer_state);
//     bool pejer_update_color = false;
//     if (layer > 0) {
//         HSV hsv = rgb_matrix_get_hsv();
//         if (IS_LAYER_ON(_WORKMAN)) { // a silly attempt at setting color based on baselayer....
//             hsv = (HSV){HSV_RED};
//             pejer_update_color = true;
//         }
//         switch (get_highest_layer(layer_state)) {
//             case _MOUSE:
//                 hsv = (HSV){HSV_BLUE};
//                 pejer_update_color = true;
//                 break;
//             case _FKEYS:
//                 hsv = (HSV){HSV_GREEN};
//                 pejer_update_color = true;
//                 break;
//         };
//         if ( pejer_update_color == true) {
//             if (hsv.v > rgb_matrix_get_val()) {
//                 hsv.v = RGB_MATRIX_MAXIMUM_BRIGHTNESS;
//             }
//             RGB rgb = hsv_to_rgb(hsv);
//
//             for (int i = led_min; i <= led_max; i++) {
//                 if ( g_led_config.flags[i]) {
//                     rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
//                 }
//             };
//         }
//     }
//     return false;
// }

const HSV hsv_colors[] = {
    [ hOFF] = {  0,   0,   0},
    [hPRPL] = {205, 255, 255},
    [hDPRP] = {205, 255, 150},
    [hPINK] = {251, 223, 255},
    [hDPNK] = {251, 223, 155},
    [hCYAN] = {128, 255, 255},
    [hLRED] = {255, 239, 255},
    [hBLUE] = {170, 215, 221},
    [hORNG] = { 20, 208, 255},
    [ hRED] = {  0, 255, 255},
    [hMGTA] = {220, 255, 255},
    [hYELO] = { 15, 255, 255},
    [hGREN] = { 50, 255, 255},
    [ hIGN] = {  0,   0,   0},
    [ hDIM] = {128, 128, 255},
    [hTEAL] = HSV_TEAL
};
__attribute__((weak)) bool is_custom_rgb_indicator(uint8_t index) {
    return (index == 12 || index == 13 || index == 14 || index == 30 || index == 31 || index == 32);
}
bool pejer_rgb_matrix_per_key_layer_state(uint8_t led_min, uint8_t led_max){
    int layer = get_highest_layer(layer_state|default_layer_state);
    bool caps_lock_on = host_keyboard_led_state().caps_lock;
    for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
        for(uint8_t col = 0; col < MATRIX_COLS; ++col) {
            uint8_t index = g_led_config.matrix_co[row][col];

            if(led_min <= index && index <= led_max) {
                uint8_t color = pgm_read_byte(&ledmaps[layer][row][col]);
                if (color == hIGN) {
                    continue;
                }
                HSV hsv = hsv_colors[color];
                if(hsv.s > 0)
                    hsv.v = rgb_matrix_config.hsv.v;
                RGB rgb = hsv_to_rgb(hsv);
                rgb_matrix_set_color( index, rgb.r, rgb.g, rgb.b );
            };
        };
    };
    return false;
}
