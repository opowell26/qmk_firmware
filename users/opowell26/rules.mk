SRC += opowell26.c \
       process_records.c

ifneq ($(PLATFORM),CHIBIOS)
    LTO_ENABLE        = yes
endif

ifdef CONSOLE_ENABLE
    ifeq ($(strip $(KEYLOGGER_ENABLE)), yes)
        OPT_DEFS += -DKEYLOGGER_ENABLE
    endif
endif

RGB_MATRIX_ENABLE ?= no
ifneq ($(strip $(RGB_MATRIX_ENABLE)), no)
    SRC += rgb_matrix_stuff.c
endif

ifeq ($(strip $(OLED_DRIVER_ENABLE)), yes)
    SRC += oled_stuff.c
endif
