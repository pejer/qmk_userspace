# IMPORTANT!!!

-   Leds _needs some work_
-   figure out the correct constants to handle num RGBs & split count
-   ... add some nifty encoder led handle thinge

Checkout kyria rev3s matrix in its json definition file.

```json
    "rgb_matrix": {
        "driver": "ws2812",
        "layout": [
            {"flags": 2, "x": 75, "y": 2},                     // L RGB1
            {"flags": 2, "x": 50, "y": 1},                     // L RGB2
            {"flags": 2, "x": 14, "y": 4},                     // L RGB3
            {"flags": 2, "x": 25, "y": 45},                    // L RGB4
            {"flags": 2, "x": 58, "y": 49},                    // L RGB5
            {"flags": 2, "x": 94, "y": 53},                    // L RGB6
            {"flags": 4, "matrix": [3, 0], "x": 94, "y": 64},  // L SW21
            {"flags": 4, "matrix": [3, 5], "x": 79, "y": 60},  // L SW22
            {"flags": 4, "matrix": [3, 1], "x": 65, "y": 53},  // L SW23
            {"flags": 4, "matrix": [3, 2], "x": 51, "y": 49},  // L SW24
            {"flags": 4, "matrix": [3, 4], "x": 36, "y": 49},  // L SW25
            {"flags": 4, "matrix": [2, 0], "x": 101, "y": 49}, // L SW13
            {"flags": 4, "matrix": [3, 3], "x": 87, "y": 45},  // L SW14
            {"flags": 4, "matrix": [2, 1], "x": 72, "y": 38},  // L SW15
            {"flags": 4, "matrix": [2, 2], "x": 58, "y": 34},  // L SW16
            {"flags": 4, "matrix": [2, 3], "x": 43, "y": 30},  // L SW17
            {"flags": 4, "matrix": [2, 4], "x": 29, "y": 34},  // L SW18
            {"flags": 4, "matrix": [2, 5], "x": 14, "y": 41},  // L SW19
            {"flags": 4, "matrix": [2, 6], "x": 0, "y": 41},   // L SW20
            {"flags": 4, "matrix": [1, 1], "x": 72, "y": 23},  // L SW07
            {"flags": 4, "matrix": [1, 2], "x": 58, "y": 19},  // L SW08
            {"flags": 4, "matrix": [1, 3], "x": 43, "y": 15},  // L SW09
            {"flags": 4, "matrix": [1, 4], "x": 29, "y": 19},  // L SW10
            {"flags": 4, "matrix": [1, 5], "x": 14, "y": 26},  // L SW11
            {"flags": 4, "matrix": [1, 6], "x": 0, "y": 26},   // L SW12
            {"flags": 4, "matrix": [0, 1], "x": 72, "y": 8},   // L SW01
            {"flags": 4, "matrix": [0, 2], "x": 58, "y": 4},   // L SW02
            {"flags": 4, "matrix": [0, 3], "x": 43, "y": 0},   // L SW03
            {"flags": 4, "matrix": [0, 4], "x": 29, "y": 4},   // L SW04
            {"flags": 4, "matrix": [0, 5], "x": 14, "y": 11},  // L SW05
            {"flags": 4, "matrix": [0, 6], "x": 0, "y": 11},   // L SW06
            {"flags": 2, "x": 149, "y": 2},                    // R RGB1
            {"flags": 2, "x": 174, "y": 1},                    // R RGB2
            {"flags": 2, "x": 210, "y": 4},                    // R RGB3
            {"flags": 2, "x": 199, "y": 45},                   // R RGB4
            {"flags": 2, "x": 166, "y": 49},                   // R RGB5
            {"flags": 2, "x": 130, "y": 53},                   // R RGB6
            {"flags": 4, "matrix": [7, 0], "x": 130, "y": 64}, // R SW21
            {"flags": 4, "matrix": [7, 5], "x": 145, "y": 60}, // R SW22
            {"flags": 4, "matrix": [7, 1], "x": 159, "y": 53}, // R SW23
            {"flags": 4, "matrix": [7, 2], "x": 173, "y": 49}, // R SW24
            {"flags": 4, "matrix": [7, 4], "x": 188, "y": 49}, // R SW25
            {"flags": 4, "matrix": [6, 0], "x": 123, "y": 49}, // R SW13
            {"flags": 4, "matrix": [7, 3], "x": 137, "y": 45}, // R SW14
            {"flags": 4, "matrix": [6, 1], "x": 152, "y": 38}, // R SW15
            {"flags": 4, "matrix": [6, 2], "x": 166, "y": 34}, // R SW16
            {"flags": 4, "matrix": [6, 3], "x": 181, "y": 30}, // R SW17
            {"flags": 4, "matrix": [6, 4], "x": 195, "y": 34}, // R SW18
            {"flags": 4, "matrix": [6, 5], "x": 210, "y": 41}, // R SW19
            {"flags": 4, "matrix": [6, 6], "x": 224, "y": 41}, // R SW20
            {"flags": 4, "matrix": [5, 1], "x": 152, "y": 23}, // R SW07
            {"flags": 4, "matrix": [5, 2], "x": 166, "y": 19}, // R SW08
            {"flags": 4, "matrix": [5, 3], "x": 181, "y": 15}, // R SW09
            {"flags": 4, "matrix": [5, 4], "x": 195, "y": 19}, // R SW10
            {"flags": 4, "matrix": [5, 5], "x": 210, "y": 26}, // R SW11
            {"flags": 4, "matrix": [5, 6], "x": 224, "y": 26}, // R SW12
            {"flags": 4, "matrix": [4, 1], "x": 152, "y": 8},  // R SW01
            {"flags": 4, "matrix": [4, 2], "x": 166, "y": 4},  // R SW02
            {"flags": 4, "matrix": [4, 3], "x": 181, "y": 0},  // R SW03
            {"flags": 4, "matrix": [4, 4], "x": 195, "y": 4},  // R SW04
            {"flags": 4, "matrix": [4, 5], "x": 210, "y": 11}, // R SW05
            {"flags": 4, "matrix": [4, 6], "x": 224, "y": 11}  // R SW06
        ],

```

Encoder: <https://github.com/casuanoob/qmk_firmware/tree/casua-dev-lencoder/keyboards/bastardkb/charybdis/3x5/keymaps/casuanoob-left-encoder>

# Charybdis (3x5) pejer keymap

This is how you build it:
`qmk compile -kb  bastardkb/charybdis/3x5/v2/splinky_3 -km pejer`

Also waiting on this PR: https://github.com/qmk/qmk_firmware/pull/21398

ALSO checkout this: https://github.com/finrod09/qmk_userspace/blob/fbfd5e364d319cc9d04549e135ee772d318129df/users/burkfers/features/rgb/rgb.c#L23

With that we could have rgb-colors for certain keys, indicating which ones are "active" or "important" when that layer is active.

This is what we should have instead, much more fun.

OLEDs?

-   [https://discord.com/channels/681309835135811648/872183402579767317/1166813792122978394](https://discord.com/channels/681309835135811648/872183402579767317/1166813792122978394)
-   [https://docs.qmk.fm/#/feature_oled_driver](https://docs.qmk.fm/#/feature_oled_driver)
-   [https://docs.qmk.fm/#/platformdev_rp2040](https://docs.qmk.fm/#/platformdev_rp2040)
-   [https://docs.qmk.fm/#/i2c_driver?id=arm-configuration](https://docs.qmk.fm/#/i2c_driver?id=arm-configuration)
-   [https://github.com/drashna/qmk_userspace/tree/master/keyboards/bastardkb/dilemma/4x6_4/keymaps/drashna](https://github.com/drashna/qmk_userspace/tree/master/keyboards/bastardkb/dilemma/4x6_4/keymaps/drashna)
