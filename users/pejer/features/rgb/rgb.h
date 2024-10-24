#pragma once
#include "pejer.h"
enum colors {
    hOFF = 0,
    hPRPL,
    hDPRP,
    hPINK,
    hDPNK,
    hCYAN,
    hLRED,
    hBLUE,
    hORNG,
    hRED,
    hMGTA,
    hYELO,
    hGREN,
    hIGN,
    hDIM,
    hTEAL,
};
extern const uint8_t PROGMEM ledmaps[][MATRIX_ROWS][MATRIX_COLS];

const extern HSV hsv_colors[];
bool pejer_rgb_matrix_per_key_layer_state(uint8_t, uint8_t);
