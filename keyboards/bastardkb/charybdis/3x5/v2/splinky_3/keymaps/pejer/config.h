#undef PRODUCT
#define PRODUCT "Pejer Charybdis NANO"
#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_MODS_ENABLE
#define SPLIT_ACTIVITY_ENABLE
#define RGB_DISABLE_WHEN_USB_SUSPENDED

#define COMBO_TERM 14
#define COMBO_STRICT_TIMER
#define AUTO_MOUSE_THRESHOLD 10
#define CHARYBDIS_MINIMUM_DEFAULT_DPI 1200


/* Override RGB settings.
 * \brief 12 LEDs are added by the falcon PCB to the original 36
*/
#undef RGBLED_NUM
#undef RGBLED_LED_COUNT
#undef RGBLED_SPLIT
#define RGBLIGHT_LED_COUNT 48
/*#define RGBLIGHT_LED_MAP { \
    0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12, 13, 14, \
    27, 28, \
    29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, \
    44, 45, \
    15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26\
}
*/

// this should be correct, me thinks
// #define RGBLED_SPLIT { 30, 18 }
#undef RGB_MATRIX_SPLIT
#define RGB_MATRIX_SPLIT { 30, 18 }
/* Define encoder pads.
 * \brief Encoder pads wired to MISO and MOSI
*/
#define ENCODER_DEFAULT_POS 0x3
#define ENCODER_A_PINS { SPI_MISO_PIN }
#define ENCODER_B_PINS { SPI_MOSI_PIN }


#define ENCODER_A_PINS_RIGHT {  }
#define ENCODER_B_PINS_RIGHT {  }

// #undef MASTER_RIGHT
// #define MASTER_LEFT
//Encoders right define is required to prevent the trackball SPI pins from being overridden
// #define ENCODERS_PAD_A_RIGHT { B12 } //completely unused pin
// #define ENCODERS_PAD_B_RIGHT { B13 } //completely unused pin

// #define OLED_ENABLE
// #define I2C1_CLOCK_SPEED 400000
// #define I2C1_DUTY_CYCLE FAST_DUTY_CYCLE_16_9
// #define OLED_DISPLAY_HEIGHT 128
// #    define OLED_DISPLAY_128X64
// #    define SPLIT_OLED_ENABLE

// AUTO_MOUSE_DELAY
// AUTO_MOUSE_DEBOUNCE
