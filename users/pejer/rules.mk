-include $(USER_PATH)/features/rules.mk

SRC += $(USER_PATH)/pejer.c

ifeq ($(strip $(OLED_ENABLE)), yes)
    SRC += oled.c
endif
