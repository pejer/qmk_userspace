ifeq ($(strip $(RGB_MATRIX_ENABLE)), yes)
	SRC += $(USER_PATH)/features/rgb/rgb.c
endif

