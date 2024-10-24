// Henrik Pejers futile attempt at QMK.
#pragma once
enum keyb_layers {
    _QWERTY = 0,
    _WORKMAN,
    _MOUSE,
    _MEDIA,
    _NAV,
    _NUM,
    _SYM,
    _FKEYS,
    _OSNAV,
    _ADJUST,
};

#include "keymap_swedish_pro_mac_ansi.h"
// Utility rows
#define ________________BLANK________________   _______,       _______,       _______,      _______,        _______
#define __________SAME_THUMB_MOD_L1__________   QK_REBOOT,     DF(_QWERTY),   DF(_WORKMAN), KC_NO,          QK_BOOT
#define __________SAME_THUMB_MOD_L3__________   RGB_TOG,       RGB_MOD,       RGB_HUI,      RGB_SAI,        RGB_VAI

#define __________SAME_THUMB_MOD_R1__________   QK_BOOT,       KC_NO,         DF(_WORKMAN), DF(_QWERTY),    QK_REBOOT
#define __________SAME_THUMB_MOD_R3__________   RGB_VAI,       RGB_SAI,       RGB_HUI,      RGB_MOD,        RGB_TOG


// QWERTY
#define ______________QWERTY_L1______________   SE_Q,          SE_W,          SE_E,         SE_R,           SE_T
#define ______________QWERTY_L2______________   LSFT_T(SE_A),  LALT_T(SE_S),  LCTL_T(SE_D), LGUI_T(SE_F),   SE_G
#define ______________QWERTY_L3______________   SE_Z,          SE_X,          SE_C,         SE_V,           SE_B

#define ______________QWERTY_R1______________   SE_Y,          SE_U,          SE_I,         SE_O,           SE_P
#define ______________QWERTY_R2______________   LT(_MOUSE,SE_H), RGUI_T(SE_J),  RCTL_T(SE_K), RALT_T(SE_L),   RSFT_T(SE_ODIA)
#define ______________QWERTY_R3______________   SE_N,          SE_M,          SE_COMM,      SE_DOT,         SE_SLSH

// WORKERMAN
#define ______________WORKMN_L1______________   SE_Q,          SE_D,          SE_R,         SE_W,           SE_B
#define ______________WORKMN_L2______________   LSFT_T(SE_A),  LALT_T(SE_S),  LCTL_T(SE_H), LGUI_T(SE_T),   SE_G
#define ______________WORKMN_L3______________   SE_Z,          SE_X,          SE_M,         SE_C,           SE_V

#define ______________WORKMN_R1______________   SE_J,          SE_F,          SE_U,         SE_P,           SE_ODIA
#define ______________WORKMN_R2______________   SE_Y,          RGUI_T(SE_N),  RCTL_T(SE_E), RALT_T(SE_O),   RSFT_T(SE_I)
#define ______________WORKMN_R3______________   SE_K,          SE_L,          SE_COMM,      SE_DOT,         SE_SLSH

#define ______________NUMBER_L1______________   SE_LBRC,       SE_7,          SE_8,         SE_9,           SE_RBRC
#define ______________NUMBER_L2______________   S(KC_2),       SE_4,          SE_5,         SE_6,           SE_EQL
#define ______________NUMBER_L3______________   SE_GRV,        SE_1,          SE_2,         SE_3,           SE_BSLS

#define ______________NUMBER_R1______________   ________________BLANK________________
#define ______________NUMBER_R2______________   ________________BLANK________________
#define ______________NUMBER_R3______________   ________________BLANK________________


#define ______________FKEYS_L1_______________   KC_F12,        KC_F7,         KC_F8,        KC_F9,          KC_PSCR
#define ______________FKEYS_L2_______________   KC_F11,        KC_F4,         KC_F5,        KC_F6,          KC_SCRL
#define ______________FKEYS_L3_______________   KC_F10,        KC_F1,         KC_F2,        KC_F3,          KC_PAUS

#define ______________FKEYS_R1_______________   ________________BLANK________________
#define ______________FKEYS_R2_______________   ________________BLANK________________
#define ______________FKEYS_R3_______________   ________________BLANK________________

#define ______________MEDIA_R1_______________   RGB_MOD,       RGB_HUI,       RGB_SAI,      RGB_VAI,        RGB_TOG
#define ______________MEDIA_R2_______________   KC_MPRV,       KC_VOLD,       KC_VOLU,      KC_MNXT,        KC_MUTE
#define ______________MEDIA_R3_______________   KC_NO,         KC_NO,         KC_NO,        KC_NO,          OU_AUTO

#define ______________MEDIA_L1_______________   ________________BLANK________________
#define ______________MEDIA_L2_______________   ________________BLANK________________
#define ______________MEDIA_L3_______________   ________________BLANK________________

#define ______________SYMBL_L1_______________   SE_LCBR,       SE_AMPR,       SE_ASTR,      SE_LPRN,        SE_RCBR
#define ______________SYMBL_L2_______________   SE_QUOT,       SE_DLR,        SE_PERC,      SE_CIRC,        SE_PLUS
#define ______________SYMBL_L3_______________   SE_TILD,       SE_EXLM,       SE_AT,        SE_HASH,        SE_PIPE

#define ______________SYMBL_R1_______________   __________SAME_THUMB_MOD_R1__________
#define ______________SYMBL_R2_______________   ________________BLANK________________
#define ______________SYMBL_R3_______________   __________SAME_THUMB_MOD_R3__________

#define ______________NAV___L1_______________   ________________BLANK________________
#define ______________NAV___L2_______________   ________________BLANK________________
#define ______________NAV___L3_______________   ________________BLANK________________

#define ______________NAV___R1_______________   KC_AGIN,       LCMD(KC_C),    LCMD(KC_V),   LCMD(KC_X),     LCMD(KC_Z)
#define ______________NAV___R2_______________   KC_LEFT,       KC_DOWN,       KC_UP,        KC_RGHT,        CW_TOGG
#define ______________NAV___R3_______________   KC_HOME,       KC_PGDN,       KC_PGUP,      KC_END,         KC_INS

#define ______________MOUSE_L1_______________   KC_NO,         KC_NO,         DPI_MOD,      S_D_MOD,        KC_NO
#define ______________MOUSE_L2_______________   ________________BLANK________________
#define ______________MOUSE_L3_______________   DRGSCRL,       KC_NO,         SNIPING,      KC_BTN3,        QK_MAKE

#define ______________MOUSE_R1_______________   ________________BLANK________________
#define ______________MOUSE_R2_______________   ________________BLANK________________
#define ______________MOUSE_R3_______________   ________________BLANK________________

#define ______________OSNAV_L1_______________   __________SAME_THUMB_MOD_L1__________
#define ______________OSNAV_L2_______________   ________________BLANK________________
#define ______________OSNAV_L3_______________   __________SAME_THUMB_MOD_L3__________

#define ______________OSNAV_R1_______________   LCTL(KC_1),    LCTL(KC_2),    LCTL(KC_3),   LCTL(KC_4),     LCTL(KC_5)
#define ______________OSNAV_R2_______________   LCTL(KC_LEFT), LCTL(KC_DOWN), LCTL(KC_UP),  LCTL(KC_RIGHT), KC_F11
#define ______________OSNAV_R3_______________   ________________BLANK________________

#define ________________________________3x5_QWERTY________________________________   \
        ______________QWERTY_L1______________, ______________QWERTY_R1______________,\
        ______________QWERTY_L2______________, ______________QWERTY_R2______________,\
        ______________QWERTY_L3______________, ______________QWERTY_R3______________
#define ________________________________3x5_WORKMN________________________________   \
        ______________WORKMN_L1______________, ______________WORKMN_R1______________,\
        ______________WORKMN_L2______________, ______________WORKMN_R2______________,\
        ______________WORKMN_L3______________, ______________WORKMN_R3______________

