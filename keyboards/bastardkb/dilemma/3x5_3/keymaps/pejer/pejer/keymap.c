#include "pejer.h"

// clang-format off
#define LAYOUT_split_3x5_3_wrapper(...) LAYOUT_split_3x5_3(__VA_ARGS__)

#define LAYOUT_split_3x5_3_base( \
    K01 ,K02 ,K03 ,K04 ,K05 , K06 ,K07 ,K08 ,K09 ,K0A , \
    K11 ,K12 ,K13 ,K14 ,K15 , K16 ,K17 ,K18 ,K19 ,K1A , \
    K21 ,K22 ,K23 ,K24 ,K25 , K26 ,K27 ,K28 ,K29 ,K2A , \
              K30 ,K31 ,K32 , K33 ,K34 ,K35 \
    ) \
    LAYOUT_split_3x5_3 ( \
    K01        , K02        , K03        , K04        , K05   , K06   , K07        , K08        , K09        , K0A        , \
    K11, K12, K13, K14, K15   , K16   , K17, K18, K19, K1A, \
    K21        , K22        , K23        , K24        , K25   , K26   , K27        , K28        , K29        , K2A        , \
                              K30        , K31        , K32   , K33   , K34        , K35\
    )

#define LAYOUT_split_3x5_3_base_wrapper(...)       LAYOUT_split_3x5_3_base(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = LAYOUT_split_3x5_3_base_wrapper(
        ________________________________3x5_QWERTY________________________________, \
        KC_ESC, LT(_NAV,KC_SPC), LT(_OSNAV,KC_TAB), LT(_SYM,KC_ENT), LT(_NUM,KC_BSPC), KC_DEL
    ),
    [_WORKMAN] = LAYOUT_split_3x5_3_base_wrapper(
        ________________________________3x5_WORKMN________________________________, \
        KC_ESC, LT(_NAV,KC_SPC), LT(_OSNAV,KC_TAB), LT(_SYM,KC_ENT), LT(_NUM,KC_BSPC), KC_DEL
    ),
    [_MOUSE] = LAYOUT_split_3x5_3_base_wrapper(
        ______________MOUSE_L1_______________, ______________MOUSE_R1_______________, \
        ______________MOUSE_L2_______________, ______________MOUSE_R2_______________, \
        ______________MOUSE_L3_______________, ______________MOUSE_R3_______________, \
                   KC_BTN3, KC_BTN1, KC_BTN2, _______, _______, _______
    ),
    [_MEDIA] = LAYOUT_split_3x5_3_base_wrapper(
        ______________MEDIA_L1_______________, ______________MEDIA_R1_______________, \
        ______________MEDIA_L2_______________, ______________MEDIA_R2_______________, \
        ______________MEDIA_L3_______________, ______________MEDIA_R3_______________, \
                   _______, _______, _______, KC_MSTP, KC_MPLY, KC_MUTE
    ),
    [_NAV] = LAYOUT_split_3x5_3_base_wrapper(
        ______________NAV___L1_______________, ______________NAV___R1_______________, \
        ______________NAV___L2_______________, ______________NAV___R2_______________, \
        ______________NAV___L3_______________, ______________NAV___R3_______________, \
                   _______, _______, _______, KC_ENT, KC_BSPC, KC_DEL
    ),
    [_NUM] = LAYOUT_split_3x5_3_base_wrapper(
        ______________NUMBER_L1______________, ______________NUMBER_R1______________, \
        ______________NUMBER_L2______________, ______________NUMBER_R2______________, \
        ______________NUMBER_L3______________, ______________NUMBER_R3______________, \
                       _______, KC_0, SE_MINS, _______, _______, _______
    ),
    [_SYM] = LAYOUT_split_3x5_3_base_wrapper(
        ______________SYMBL_L1_______________, ______________SYMBL_R1_______________, \
        ______________SYMBL_L2_______________, ______________SYMBL_R2_______________, \
        ______________SYMBL_L3_______________, ______________SYMBL_R3_______________, \
                   _______, SE_RPRN, SE_UNDS, _______, _______, _______
    ),
    [_FKEYS] = LAYOUT_split_3x5_3_base_wrapper(
        ______________FKEYS_L1_______________, ______________FKEYS_R1_______________, \
        ______________FKEYS_L2_______________, ______________FKEYS_R2_______________, \
        ______________FKEYS_L3_______________, ______________FKEYS_R3_______________, \
                   _______, _______, _______, KC_MSTP, KC_MPLY, KC_MUTE
    ),
    [_OSNAV] = LAYOUT_split_3x5_3_base_wrapper(
        ______________OSNAV_L1_______________, ______________OSNAV_R1_______________, \
        ______________OSNAV_L2_______________, ______________OSNAV_R2_______________, \
        ______________OSNAV_L3_______________, ______________OSNAV_R3_______________, \
                   _______, _______, _______, _______, _______, _______
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
  // MOUSE_BUTTON3_COMBO,
  COMBO_LENGTH
};

uint16_t COMBO_LEN = COMBO_LENGTH; // remove the COMBO_COUNT define and use this instead!

const uint16_t PROGMEM th_left_combo[]      = {LT(_NAV,      KC_SPC),         LT(_OSNAV, KC_TAB),  COMBO_END};
const uint16_t PROGMEM th_right_combo[]     = {LT(_SYM,      KC_ENT),         LT(_NUM,   KC_BSPC), COMBO_END};
const uint16_t PROGMEM th_right_sym_combo[] = {SE_RPRN,      SE_UNDS,         COMBO_END};
const uint16_t PROGMEM th_right_num_combo[] = {KC_0,         SE_MINS,         COMBO_END};
const uint16_t PROGMEM aeuml_combo[]        = {RALT_T(SE_L), RSFT_T(SE_ODIA), COMBO_END};
const uint16_t PROGMEM aering_combo[]       = {KC_O,         KC_P,            COMBO_END};

const uint16_t PROGMEM mouse_btn1_combo[]   = {LALT_T(SE_S), LCTL_T(SE_D),    COMBO_END};
const uint16_t PROGMEM mouse_btn2_combo[]   = {LCTL_T(SE_D), LGUI_T(SE_F),    COMBO_END};
// const uint16_t PROGMEM mouse_btn3_combo[]   = {LSFT_T(SE_A), LALT_T(SE_S),    COMBO_END};
const uint16_t PROGMEM mouse_drag_combo[]   = {LSFT_T(SE_A), LALT_T(SE_S),            COMBO_END};
combo_t key_combos[] = {
  [TH_LEFT_COMBO]       = COMBO(th_left_combo,      LT(_MEDIA, KC_ESC)),
  [TH_RIGHT_COMBO]      = COMBO(th_right_combo,     LT(_FKEYS, KC_DEL)),
  [TH_RIGHT_SYM_COMBO]  = COMBO(th_right_sym_combo, SE_QUES),
  [TH_RIGHT_NUM_COMBO]  = COMBO(th_right_num_combo, SE_LABK),
  [AEUML_COMBO]         = COMBO(aeuml_combo,        SE_ADIA),
  [AERING_COMBO]        = COMBO(aering_combo,       SE_ARNG),
  [MOUSE_DRAG_COMBO]    = COMBO(mouse_drag_combo,  DRGSCRL),
  [MOUSE_BUTTON1_COMBO] = COMBO(mouse_btn1_combo,   KC_BTN1),
  [MOUSE_BUTTON2_COMBO] = COMBO(mouse_btn2_combo,   KC_BTN2),
  // [MOUSE_BUTTON3_COMBO] = COMBO(mouse_btn3_combo,   KC_BTN3),
};

void pointing_device_init_user(void) {
    set_auto_mouse_layer(_MOUSE);
    set_auto_mouse_enable(true);
}
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

report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    mouse_report.v = -mouse_report.v;
    return mouse_report;
}
#ifdef RGB_MATRIX_ENABLE
// clang-format off
const uint8_t PROGMEM ledmaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_split_3x5_3(
  // ╭────────────────────────────────────╮ ╭───────────────────────────────────────╮
        hIGN,  hIGN,  hIGN,  hIGN,  hIGN,     hIGN,  hIGN,  hIGN,  hIGN,  hIGN,
  // ├────────────────────────────────────┤ ├───────────────────────────────────────┤
        hIGN,  hIGN,  hIGN,  hIGN,  hIGN,     hIGN,  hIGN,  hIGN,  hIGN,  hIGN,
  // ├────────────────────────────────────┤ ├───────────────────────────────────────┤
        hIGN,  hIGN,  hIGN,  hIGN,  hIGN,     hIGN,  hIGN,  hIGN,  hIGN,  hIGN,
  // ╰────────────────────────────────────┤ ├───────────────────────────────────────╯
                           hMGTA, hCYAN, hYELO,    hBLUE, hGREN, hGREN
  //                     ╰─────────────────────╯ ╰──────────────╯
  ),
  [_WORKMAN] = LAYOUT_split_3x5_3(
  // ╭────────────────────────────────────╮ ╭───────────────────────────────────────╮
        hMGTA,  hMGTA,  hMGTA,  hMGTA,  hMGTA,     hMGTA,  hMGTA,  hMGTA,  hMGTA,  hMGTA,
  // ├────────────────────────────────────┤ ├───────────────────────────────────────┤
        hMGTA,  hMGTA,  hMGTA,  hMGTA,  hMGTA,     hMGTA,  hMGTA,  hMGTA,  hMGTA,  hMGTA,
  // ├────────────────────────────────────┤ ├───────────────────────────────────────┤
        hMGTA,  hMGTA,  hMGTA,  hMGTA,  hMGTA,     hMGTA,  hMGTA,  hMGTA,  hMGTA,  hMGTA,
  // ╰────────────────────────────────────┤ ├───────────────────────────────────────╯
                           hMGTA, hCYAN, hYELO,    hBLUE, hGREN, hGREN
  //                     ╰─────────────────────╯ ╰──────────────╯
  ),
   [_MOUSE] = LAYOUT_split_3x5_3(
   // ╭─────────────────────────────────────────╮ ╭───────────────────────────────────────╮
         hOFF,  hOFF,  hGREN,  hGREN,  hOFF,     hIGN,  hIGN,  hIGN,  hIGN,  hIGN,
   // ├─────────────────────────────────────────┤ ├───────────────────────────────────────┤
         hOFF,  hOFF,  hOFF,  hOFF,  hOFF,     hIGN,  hIGN,  hIGN,  hIGN,  hIGN,
   // ├─────────────────────────────────────────┤ ├───────────────────────────────────────┤
         hOFF,  hOFF,  hGREN,  hGREN,  hOFF,     hIGN,  hIGN,  hIGN,  hIGN,  hIGN,
   // ╰─────────────────────────────────────────┤ ├───────────────────────────────────────╯
                              hRED, hRED, hRED,    hOFF, hOFF, hOFF
   //                     ╰─────────────────────╯ ╰──────────────╯
   ),
   [_NAV] = LAYOUT_split_3x5_3(
   // ╭───────────────────────────────────╮ ╭────────────────────────────────────╮
         hIGN,  hIGN,  hIGN,  hIGN,  hIGN,     hOFF,  hOFF,  hOFF,  hOFF,  hOFF,
   // ├───────────────────────────────────┤ ├────────────────────────────────────┤
         hIGN,  hIGN,  hIGN,  hIGN,  hIGN,     hCYAN,  hCYAN,  hCYAN,  hCYAN,  hOFF,
   // ├───────────────────────────────────┤ ├────────────────────────────────────┤
         hIGN,  hIGN,  hIGN,  hIGN,  hIGN,     hOFF,  hCYAN,  hCYAN,  hCYAN,  hCYAN,
   // ╰───────────────────────────────────┤ ├────────────────────────────────────╯
                      hMGTA, hCYAN, hYELO,    hBLUE, hGREN, hGREN
   //               ╰─────────────────────╯ ╰──────────────╯
  ),
  [_OSNAV] = LAYOUT_split_3x5_3(
  // ╭───────────────────────────────────╮ ╭────────────────────────────────────╮
        hIGN,  hIGN,  hIGN,  hIGN,  hIGN,    hYELO, hYELO, hYELO, hYELO, hYELO,
  // ├───────────────────────────────────┤ ├────────────────────────────────────┤
        hIGN,  hIGN,  hIGN,  hIGN,  hIGN,    hYELO, hYELO, hYELO, hYELO, hYELO,
  // ├───────────────────────────────────┤ ├────────────────────────────────────┤
        hIGN,  hIGN,  hIGN,  hIGN,  hIGN,    hOFF, hOFF, hOFF, hOFF, hOFF,
  // ╰───────────────────────────────────┤ ├────────────────────────────────────╯
                      hOFF,  hOFF,  hOFF,     hOFF,  hOFF,  hOFF
  //               ╰─────────────────────╯ ╰──────────────╯
  ),

  [_MEDIA] = LAYOUT_split_3x5_3(
  // ╭───────────────────────────────────╮ ╭────────────────────────────────────╮
        hIGN,  hIGN,  hIGN,  hIGN,  hIGN,    hDPNK, hDPNK, hDPNK, hDPNK, hDPNK,
  // ├───────────────────────────────────┤ ├────────────────────────────────────┤
        hIGN,  hIGN,  hIGN,  hIGN,  hIGN,    hCYAN, hCYAN, hCYAN, hCYAN, hCYAN,
  // ├───────────────────────────────────┤ ├────────────────────────────────────┤
        hIGN,  hIGN,  hIGN,  hIGN,  hIGN,    hOFF, hOFF, hOFF, hOFF, hCYAN,
  // ╰───────────────────────────────────┤ ├────────────────────────────────────╯
                      hOFF,  hOFF,  hOFF,     hCYAN,  hCYAN,  hCYAN
  //               ╰─────────────────────╯ ╰──────────────╯
  ),
  [_SYM] = LAYOUT_split_3x5_3(
  // ╭───────────────────────────────────╮ ╭────────────────────────────────────╮
        hBLUE,  hBLUE,  hBLUE,  hBLUE,  hBLUE,    hIGN,  hIGN,  hIGN,  hIGN,  hIGN,
  // ├───────────────────────────────────┤ ├────────────────────────────────────┤
        hBLUE,  hBLUE,  hBLUE,  hBLUE,  hBLUE,    hIGN,  hIGN,  hIGN,  hIGN,  hIGN,
  // ├───────────────────────────────────┤ ├────────────────────────────────────┤
        hBLUE,  hBLUE,  hBLUE,  hBLUE,  hBLUE,    hIGN,  hIGN,  hIGN,  hIGN,  hIGN,
  // ╰───────────────────────────────────┤ ├────────────────────────────────────╯
                      hOFF,  hOFF,  hOFF,     hOFF,  hOFF,  hOFF
  //               ╰─────────────────────╯ ╰──────────────╯
  ),
  [_NUM] = LAYOUT_split_3x5_3(
  // ╭───────────────────────────────────╮ ╭────────────────────────────────────╮
        hIGN,  hGREN,  hGREN,  hGREN,  hOFF,    hIGN,  hIGN,  hIGN,  hIGN,  hIGN,
  // ├───────────────────────────────────┤ ├────────────────────────────────────┤
        hIGN,  hGREN,  hGREN,  hGREN,  hOFF,    hIGN,  hIGN,  hIGN,  hIGN,  hIGN,
  // ├───────────────────────────────────┤ ├────────────────────────────────────┤
        hIGN,  hGREN,  hGREN,  hGREN,  hOFF,    hIGN,  hIGN,  hIGN,  hIGN,  hIGN,
  // ╰───────────────────────────────────┤ ├────────────────────────────────────╯
                      hOFF,  hGREN,  hOFF,     hOFF,  hOFF,  hOFF
  //               ╰─────────────────────╯ ╰──────────────╯
  ),
  [_FKEYS] = LAYOUT_split_3x5_3(
  // ╭───────────────────────────────────╮ ╭────────────────────────────────────╮
        hTEAL,  hTEAL,  hTEAL,  hTEAL,  hOFF,    hIGN,  hIGN,  hIGN,  hIGN,  hIGN,
  // ├───────────────────────────────────┤ ├────────────────────────────────────┤
        hTEAL,  hTEAL,  hTEAL,  hTEAL,  hOFF,    hIGN,  hIGN,  hIGN,  hIGN,  hIGN,
  // ├───────────────────────────────────┤ ├────────────────────────────────────┤
        hTEAL,  hTEAL,  hTEAL,  hTEAL,  hOFF,    hIGN,  hIGN,  hIGN,  hIGN,  hIGN,
  // ╰───────────────────────────────────┤ ├────────────────────────────────────╯
                      hOFF,  hOFF,  hOFF,     hOFF,  hOFF,  hOFF
  //               ╰─────────────────────╯ ╰──────────────╯
  ),
};
// clang-format on
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max){
    pejer_rgb_matrix_per_key_layer_state(led_min, led_max);
    return false;
}
#endif

