#include QMK_KEYBOARD_H

#include "pejer.h"
uint8_t pejer_enc_value = 0;

#ifdef ENCODER_MAP_ENABLE
const uint8_t PROGMEM encoder_hand_swap_config[NUM_ENCODERS] = {1,0};
#endif
#define LAYOUT_charybdis_3x5_wrapper(...) LAYOUT_charybdis_3x5(__VA_ARGS__)
#define LAYOUT_charybdis_3x5_base( \
    K01 ,K02 ,K03 ,K04 ,K05 , K06 ,K07 ,K08 ,K09 ,K0A , \
    K11 ,K12 ,K13 ,K14 ,K15 , K16 ,K17 ,K18 ,K19 ,K1A , \
    K21 ,K22 ,K23 ,K24 ,K25 , K26 ,K27 ,K28 ,K29 ,K2A , \
              K31 ,K30 ,K32 , K33 ,K34\
    ) \
    LAYOUT_charybdis_3x5 ( \
    K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, \
    K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, \
    K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, \
                   K30, K31, K32, K33, K34\
    )
#define LAYOUT_charybdis_3x5_base_wrapper(...)       LAYOUT_charybdis_3x5_base(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = LAYOUT_charybdis_3x5_base_wrapper(
        ________________________________3x5_QWERTY________________________________, \
        KC_ESC, LT(_NAV,KC_SPC), LT(_OSNAV,KC_TAB), LT(_SYM,KC_ENT), LT(_NUM,KC_BSPC)
    ),
    [_WORKMAN] = LAYOUT_charybdis_3x5_base_wrapper(
        ________________________________3x5_WORKMN________________________________, \
        KC_ESC, LT(_NAV,KC_SPC), LT(_OSNAV,KC_TAB), LT(_SYM,KC_ENT), LT(_NUM,KC_BSPC)
    ),
    [_MOUSE] = LAYOUT_charybdis_3x5_base_wrapper(
        ______________MOUSE_L1_______________, ______________MOUSE_R1_______________, \
        ______________MOUSE_L2_______________, ______________MOUSE_R2_______________, \
        ______________MOUSE_L3_______________, ______________MOUSE_R3_______________, \
                   KC_BTN3, KC_BTN1, KC_BTN2, LT(_SYM,KC_ENT), LT(_NUM,KC_BSPC)
    ),
    [_MEDIA] = LAYOUT_charybdis_3x5_base_wrapper(
        ______________MEDIA_L1_______________, ______________MEDIA_R1_______________, \
        ______________MEDIA_L2_______________, ______________MEDIA_R2_______________, \
        ______________MEDIA_L3_______________, ______________MEDIA_R3_______________, \
                   _______, _______, _______, KC_MSTP, KC_MPLY
    ),
    [_NAV] = LAYOUT_charybdis_3x5_base_wrapper(
        ______________NAV___L1_______________, ______________NAV___R1_______________, \
        ______________NAV___L2_______________, ______________NAV___R2_______________, \
        ______________NAV___L3_______________, ______________NAV___R3_______________, \
                   _______, _______, _______, KC_ENT, KC_BSPC
    ),
    [_NUM] = LAYOUT_charybdis_3x5_base_wrapper(
        ______________NUMBER_L1______________, ______________NUMBER_R1______________, \
        ______________NUMBER_L2______________, ______________NUMBER_R2______________, \
        ______________NUMBER_L3______________, ______________NUMBER_R3______________, \
                       _______, KC_0, SE_MINS, _______, _______
    ),
    [_SYM] = LAYOUT_charybdis_3x5_base_wrapper(
        ______________SYMBL_L1_______________, ______________SYMBL_R1_______________, \
        ______________SYMBL_L2_______________, ______________SYMBL_R2_______________, \
        ______________SYMBL_L3_______________, ______________SYMBL_R3_______________, \
                   _______, SE_RPRN, SE_UNDS, _______, _______
    ),
    [_FKEYS] = LAYOUT_charybdis_3x5_base_wrapper(
        ______________FKEYS_L1_______________, ______________FKEYS_R1_______________, \
        ______________FKEYS_L2_______________, ______________FKEYS_R2_______________, \
        ______________FKEYS_L3_______________, ______________FKEYS_R3_______________, \
                   _______, _______, _______, KC_MSTP, KC_MPLY
    ),
    [_OSNAV] = LAYOUT_charybdis_3x5_base_wrapper(
        ______________OSNAV_L1_______________, ______________OSNAV_R1_______________, \
        ______________OSNAV_L2_______________, ______________OSNAV_R2_______________, \
        ______________OSNAV_L3_______________, ______________OSNAV_R3_______________, \
                   _______, _______, _______, _______, _______
    ),
};
// combo

enum combos {
  TH_LEFT_COMBO,
  TH_RIGHT_COMBO,
  TH_RIGHT_SYM_COMBO,
  TH_RIGHT_NUM_COMBO,
  AEUML_COMBO,
  AERING_COMBO,
  MOUSE_DRAG_COMBO,
  MOUSE_BUTTON1_COMBO,
  MOUSE_BUTTON2_COMBO,
  PAREN_COMBO,
  BRACK_COMBO,
  QURLY_COMBO,
  PAREN_COMBO_CLOSE,
  BRACK_COMBO_CLOSE,
  QURLY_COMBO_CLOSE,
  LT_COMBO,
  Q_COMBO,
  // MOUSE_BUTTON3_COMBO,
  COMBO_LENGTH
};

uint16_t COMBO_LEN = COMBO_LENGTH; // remove the COMBO_COUNT define and use this instead!

const uint16_t PROGMEM th_left_combo[]       = {LT(_NAV,      KC_SPC),         LT(_OSNAV, KC_TAB),  COMBO_END};
const uint16_t PROGMEM th_right_combo[]      = {LT(_SYM,      KC_ENT),         LT(_NUM,   KC_BSPC), COMBO_END};
const uint16_t PROGMEM th_right_sym_combo[]  = {SE_RPRN,      SE_UNDS,         COMBO_END};
const uint16_t PROGMEM th_right_num_combo[]  = {KC_0,         SE_MINS,         COMBO_END};
const uint16_t PROGMEM aeuml_combo[]         = {RALT_T(SE_L), RSFT_T(SE_ODIA), COMBO_END};
const uint16_t PROGMEM aering_combo[]        = {KC_O,         KC_P,            COMBO_END};

const uint16_t PROGMEM mouse_btn1_combo[]    = {LALT_T(SE_S), LCTL_T(SE_D),    COMBO_END};
const uint16_t PROGMEM mouse_btn2_combo[]    = {LCTL_T(SE_D), LGUI_T(SE_F),    COMBO_END};
// const uint16_t PROGMEM mouse_btn3_combo[] = {LSFT_T(SE_A), LALT_T(SE_S),    COMBO_END};
const uint16_t PROGMEM mouse_drag_combo[]    = {LSFT_T(SE_A), LALT_T(SE_S),    COMBO_END};
const uint16_t PROGMEM qurly_combo[]         = {SE_W,         LALT_T(SE_S),    COMBO_END};
const uint16_t PROGMEM brack_combo[]         = {SE_E,         LCTL_T(SE_D),    COMBO_END};
const uint16_t PROGMEM paren_combo[]         = {SE_R,         LGUI_T(SE_F),    COMBO_END};
const uint16_t PROGMEM qurly_combo_close[]   = {SE_O,         RALT_T(SE_L),    COMBO_END};
const uint16_t PROGMEM brack_combo_close[]   = {SE_I,         RCTL_T(SE_K),    COMBO_END};
const uint16_t PROGMEM paren_combo_close[]   = {SE_U,         RGUI_T(SE_J),    COMBO_END};
const uint16_t PROGMEM lt_combo[]            = {LGUI_T(SE_F), SE_V,            COMBO_END};
const uint16_t PROGMEM q_combo[]             = {RGUI_T(SE_J), SE_M,            COMBO_END};

combo_t key_combos[]    = {
  [TH_LEFT_COMBO]       = COMBO(th_left_combo,      LT(_MEDIA, KC_ESC)),
  [TH_RIGHT_COMBO]      = COMBO(th_right_combo,     LT(_FKEYS, KC_DEL)),
  [TH_RIGHT_SYM_COMBO]  = COMBO(th_right_sym_combo, SE_QUES),
  [TH_RIGHT_NUM_COMBO]  = COMBO(th_right_num_combo, SE_LABK),
  [AEUML_COMBO]         = COMBO(aeuml_combo,        SE_ADIA),
  [AERING_COMBO]        = COMBO(aering_combo,       SE_ARNG),
  [MOUSE_DRAG_COMBO]    = COMBO(mouse_drag_combo,   DRGSCRL),
  [MOUSE_BUTTON1_COMBO] = COMBO(mouse_btn1_combo,   KC_BTN1),
  [MOUSE_BUTTON2_COMBO] = COMBO(mouse_btn2_combo,   KC_BTN2),
  [PAREN_COMBO]         = COMBO(paren_combo,        SE_LPRN),
  [BRACK_COMBO]         = COMBO(brack_combo,        SE_LBRC),
  [QURLY_COMBO]         = COMBO(qurly_combo,        SE_LCBR),
  [PAREN_COMBO_CLOSE]   = COMBO(paren_combo_close,  SE_RPRN),
  [BRACK_COMBO_CLOSE]   = COMBO(brack_combo_close,  SE_RBRC),
  [QURLY_COMBO_CLOSE]   = COMBO(qurly_combo_close,  SE_RCBR),
  [LT_COMBO]            = COMBO(lt_combo,           SE_LABK),
  [Q_COMBO]             = COMBO(q_combo,            SE_QUES),
  // [MOUSE_BUTTON3_COMBO] = COMBO(mouse_btn3_combo,   KC_BTN3),
};

bool is_mouse_record_user(uint16_t keycode, keyrecord_t* record) {
    switch(keycode) {
        case POINTER_DEFAULT_DPI_FORWARD:
        case POINTER_DEFAULT_DPI_REVERSE:
        case POINTER_SNIPING_DPI_FORWARD:
        case POINTER_SNIPING_DPI_REVERSE:
        case SNIPING_MODE:
        case SNIPING_MODE_TOGGLE:
        case DRAGSCROLL_MODE:
        case DRAGSCROLL_MODE_TOGGLE:
            return true;
        default:
            return false;
    }
    return false;
}

// uint16_t key_timer = 0;
//
// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//     if (record->event.pressed) { key_timer = timer_read();}
//     return true;
// }
report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    // if (timer_elapsed(key_timer) < 350) {
    //     mouse_report.x = 0;
    //     mouse_report.y = 0;
    // }
    // else {
        mouse_report.v = -mouse_report.v;
        mouse_report.h = mouse_report.h;
    // }
    return mouse_report;
}
#ifdef RGB_MATRIX_ENABLE
// clang-format off
const uint8_t PROGMEM ledmaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_charybdis_3x5_base_wrapper(
  // ╭────────────────────────────────────╮ ╭───────────────────────────────────────╮
        hIGN,  hIGN,  hIGN,  hIGN,  hIGN,     hIGN,  hIGN,  hIGN,  hIGN,  hIGN,
  // ├────────────────────────────────────┤ ├───────────────────────────────────────┤
        hIGN,  hIGN,  hIGN,  hIGN,  hIGN,     hIGN,  hIGN,  hIGN,  hIGN,  hIGN,
  // ├────────────────────────────────────┤ ├───────────────────────────────────────┤
        hIGN,  hIGN,  hIGN,  hIGN,  hIGN,     hIGN,  hIGN,  hIGN,  hIGN,  hIGN,
  // ╰────────────────────────────────────┤ ├───────────────────────────────────────╯
        hMGTA, hCYAN, hYELO,    hBLUE, hGREN
  //                     ╰─────────────────────╯ ╰──────────────╯
  ),
  [_WORKMAN] = LAYOUT_charybdis_3x5_base_wrapper(
  // ╭────────────────────────────────────╮ ╭───────────────────────────────────────╮
        hMGTA,  hMGTA,  hMGTA,  hMGTA,  hMGTA,     hMGTA,  hMGTA,  hMGTA,  hMGTA,  hMGTA,
  // ├────────────────────────────────────┤ ├───────────────────────────────────────┤
        hMGTA,  hMGTA,  hMGTA,  hMGTA,  hMGTA,     hMGTA,  hMGTA,  hMGTA,  hMGTA,  hMGTA,
  // ├────────────────────────────────────┤ ├───────────────────────────────────────┤
        hMGTA,  hMGTA,  hMGTA,  hMGTA,  hMGTA,     hMGTA,  hMGTA,  hMGTA,  hMGTA,  hMGTA,
  // ╰────────────────────────────────────┤ ├───────────────────────────────────────╯
                           hMGTA, hCYAN, hYELO,    hBLUE, hGREN
  //                     ╰─────────────────────╯ ╰──────────────╯
  ),
   [_MOUSE] = LAYOUT_charybdis_3x5_base_wrapper(
   // ╭─────────────────────────────────────────╮ ╭───────────────────────────────────────╮
         hOFF,  hOFF,  hGREN,  hGREN,  hOFF,     hIGN,  hIGN,  hIGN,  hIGN,  hIGN,
   // ├─────────────────────────────────────────┤ ├───────────────────────────────────────┤
         hOFF,  hOFF,  hOFF,  hOFF,  hOFF,     hIGN,  hIGN,  hIGN,  hIGN,  hIGN,
   // ├─────────────────────────────────────────┤ ├───────────────────────────────────────┤
         hOFF,  hOFF,  hGREN,  hGREN,  hOFF,     hIGN,  hIGN,  hIGN,  hIGN,  hIGN,
   // ╰─────────────────────────────────────────┤ ├───────────────────────────────────────╯
                              hRED, hRED, hRED,    hOFF, hOFF
   //                     ╰─────────────────────╯ ╰──────────────╯
   ),
   [_NAV] = LAYOUT_charybdis_3x5_base_wrapper(
   // ╭───────────────────────────────────╮ ╭────────────────────────────────────╮
         hIGN,  hIGN,  hIGN,  hIGN,  hIGN,     hOFF,  hOFF,  hOFF,  hOFF,  hOFF,
   // ├───────────────────────────────────┤ ├────────────────────────────────────┤
         hIGN,  hIGN,  hIGN,  hIGN,  hIGN,     hCYAN,  hCYAN,  hCYAN,  hCYAN,  hOFF,
   // ├───────────────────────────────────┤ ├────────────────────────────────────┤
         hIGN,  hIGN,  hIGN,  hIGN,  hIGN,     hOFF,  hCYAN,  hCYAN,  hCYAN,  hCYAN,
   // ╰───────────────────────────────────┤ ├────────────────────────────────────╯
                      hMGTA, hCYAN, hYELO,    hBLUE, hGREN
   //               ╰─────────────────────╯ ╰──────────────╯
  ),
  [_OSNAV] = LAYOUT_charybdis_3x5_base_wrapper(
  // ╭───────────────────────────────────╮ ╭────────────────────────────────────╮
        hIGN,  hIGN,  hIGN,  hIGN,  hIGN,    hYELO, hYELO, hYELO, hYELO, hYELO,
  // ├───────────────────────────────────┤ ├────────────────────────────────────┤
        hIGN,  hIGN,  hIGN,  hIGN,  hIGN,    hYELO, hYELO, hYELO, hYELO, hYELO,
  // ├───────────────────────────────────┤ ├────────────────────────────────────┤
        hIGN,  hIGN,  hIGN,  hIGN,  hIGN,    hOFF, hOFF, hOFF, hOFF, hOFF,
  // ╰───────────────────────────────────┤ ├────────────────────────────────────╯
                      hOFF,  hOFF,  hOFF,     hOFF,  hOFF
  //               ╰─────────────────────╯ ╰──────────────╯
  ),

  [_MEDIA] = LAYOUT_charybdis_3x5_base_wrapper(
  // ╭───────────────────────────────────╮ ╭────────────────────────────────────╮
        hIGN,  hIGN,  hIGN,  hIGN,  hIGN,    hDPNK, hDPNK, hDPNK, hDPNK, hDPNK,
  // ├───────────────────────────────────┤ ├────────────────────────────────────┤
        hIGN,  hIGN,  hIGN,  hIGN,  hIGN,    hCYAN, hCYAN, hCYAN, hCYAN, hCYAN,
  // ├───────────────────────────────────┤ ├────────────────────────────────────┤
        hIGN,  hIGN,  hIGN,  hIGN,  hIGN,    hOFF, hOFF, hOFF, hOFF, hCYAN,
  // ╰───────────────────────────────────┤ ├────────────────────────────────────╯
                      hOFF,  hOFF,  hOFF,     hCYAN,  hCYAN
  //               ╰─────────────────────╯ ╰──────────────╯
  ),
  [_SYM] = LAYOUT_charybdis_3x5_base_wrapper(
  // ╭───────────────────────────────────╮ ╭────────────────────────────────────╮
        hBLUE,  hBLUE,  hBLUE,  hBLUE,  hBLUE,    hIGN,  hIGN,  hIGN,  hIGN,  hIGN,
  // ├───────────────────────────────────┤ ├────────────────────────────────────┤
        hBLUE,  hBLUE,  hBLUE,  hBLUE,  hBLUE,    hIGN,  hIGN,  hIGN,  hIGN,  hIGN,
  // ├───────────────────────────────────┤ ├────────────────────────────────────┤
        hBLUE,  hBLUE,  hBLUE,  hBLUE,  hBLUE,    hIGN,  hIGN,  hIGN,  hIGN,  hIGN,
  // ╰───────────────────────────────────┤ ├────────────────────────────────────╯
                      hOFF,  hOFF,  hOFF,     hOFF,  hOFF
  //               ╰─────────────────────╯ ╰──────────────╯
  ),
  [_NUM] = LAYOUT_charybdis_3x5_base_wrapper(
  // ╭───────────────────────────────────╮ ╭────────────────────────────────────╮
        hIGN,  hGREN,  hGREN,  hGREN,  hOFF,    hIGN,  hIGN,  hIGN,  hIGN,  hIGN,
  // ├───────────────────────────────────┤ ├────────────────────────────────────┤
        hIGN,  hGREN,  hGREN,  hGREN,  hOFF,    hIGN,  hIGN,  hIGN,  hIGN,  hIGN,
  // ├───────────────────────────────────┤ ├────────────────────────────────────┤
        hIGN,  hGREN,  hGREN,  hGREN,  hOFF,    hIGN,  hIGN,  hIGN,  hIGN,  hIGN,
  // ╰───────────────────────────────────┤ ├────────────────────────────────────╯
                      hOFF,  hGREN,  hOFF,     hOFF,  hOFF
  //               ╰─────────────────────╯ ╰──────────────╯
  ),
  [_FKEYS] = LAYOUT_charybdis_3x5_base_wrapper(
  // ╭───────────────────────────────────╮ ╭────────────────────────────────────╮
        hTEAL,  hTEAL,  hTEAL,  hTEAL,  hOFF,    hIGN,  hIGN,  hIGN,  hIGN,  hIGN,
  // ├───────────────────────────────────┤ ├────────────────────────────────────┤
        hTEAL,  hTEAL,  hTEAL,  hTEAL,  hOFF,    hIGN,  hIGN,  hIGN,  hIGN,  hIGN,
  // ├───────────────────────────────────┤ ├────────────────────────────────────┤
        hTEAL,  hTEAL,  hTEAL,  hTEAL,  hOFF,    hIGN,  hIGN,  hIGN,  hIGN,  hIGN,
  // ╰───────────────────────────────────┤ ├────────────────────────────────────╯
                      hOFF,  hOFF,  hOFF,     hOFF,  hOFF
  //               ╰─────────────────────╯ ╰──────────────╯
  ),
};
// clang-format on
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max){
    pejer_rgb_matrix_per_key_layer_state(led_min, led_max);
    for( uint8_t index = 15; index < 27;++index){
        int layer = get_highest_layer(default_layer_state);
        if (layer == _WORKMAN ){
            rgb_matrix_set_color(index,64,0,0);
        } else {
            rgb_matrix_set_color(index, 0,0,64);
        }
    }
    return false;
}
#endif
#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_QWERTY]  = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_WORKMAN] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_MOUSE]   = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_NAV]     = { ENCODER_CCW_CW(KC_PGDN, KC_PGUP) },
    [_NUM]     = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_OSNAV]   = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_MEDIA]   = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_SYM]     = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_FKEYS]   = { ENCODER_CCW_CW(KC_SCRL, KC_PAUS) },
};
#endif
