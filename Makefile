ARCH ?= x86_64
CROSS_COMPILE ?=

CC ?= $(CROSS_COMPILE)gcc
AR ?= $(CROSS_COMPILE)ar
CP ?= cp
MKDIR ?= mkdir -p
RM = rm -rf

BUILD_DIR = $(CURDIR)/build
TEMP_DIR = $(CURDIR)/temp
SRC_DIR = $(CURDIR)/src
INC_DIR = $(CURDIR)/include

AOSLIB_DIR = $(CURDIR)/aoslib
AOSLIB_INC = $(AOSLIB_DIR)/include
AOSLIB_LIB = $(AOSLIB_DIR)/build/libaos.a

ifeq ($(V),1)
    Q :=
    ECHO := @true
else
    Q := @
    ECHO := @printf
endif

CYAN   := \033[0;36m
YELLOW := \033[1;33m
GREEN  := \033[0;32m
RED    := \033[1;31m
PURPLE := \033[0;35m
LCYAN  := \033[1;36m
DRED   := \033[0;31m
BROWN  := \033[0;33m
GRAY   := \033[0;37m
NC     := \033[0m

ifeq ($(ARCH),x86_64)
    ARCH_CFLAGS ?= -m64 -mno-red-zone
endif

COMMON_CFLAGS = -Wall -Wextra -std=gnu11 -fno-omit-frame-pointer -ffreestanding -fno-pic -fno-pie -fstack-protector
USER_COMMON_CFLAGS = $(COMMON_CFLAGS) -fno-asynchronous-unwind-tables $(ARCH_CFLAGS)

LIB_CFLAGS = $(USER_COMMON_CFLAGS) -nostdinc -I$(INC_DIR) -I$(AOSLIB_INC)

LIN_SRCS = $(filter-out $(SRC_DIR)/libc_start.c, $(wildcard $(SRC_DIR)/*.c))
LIN_OBJS = $(patsubst $(SRC_DIR)/%.c, $(TEMP_DIR)/%.o, $(LIN_SRCS))

START_SRC = $(SRC_DIR)/libc_start.c
START_OBJ = $(TEMP_DIR)/libc_start.o

TARGET_LIB = $(BUILD_DIR)/libaoslin.a
TARGET_START = $(BUILD_DIR)/libc_start.o

.PHONY: all prepare clean check_submodule $(AOSLIB_LIB)

all: check_submodule prepare $(TARGET_LIB) $(TARGET_START)
	@echo "AOSLIBLIN Build Successful for $(ARCH)!"

check_submodule:
	@if [ ! -f "$(AOSLIB_DIR)/Makefile" ]; then \
		printf "${RED}[ ERROR ]${NC} Submodule 'aoslib' not found!\n"; \
		printf "Please run: ${YELLOW}git submodule update --init --recursive${NC}\n"; \
		exit 1; \
	fi

prepare:
	$(ECHO) "${RED}[  MKDIR  ]${NC} ${BUILD_DIR}\n"
	$(Q)$(MKDIR) $(BUILD_DIR)
	$(ECHO) "${RED}[  MKDIR  ]${NC} ${TEMP_DIR}\n"
	$(Q)$(MKDIR) $(TEMP_DIR)
	$(Q)$(MKDIR) $(TEMP_DIR)/aos_extracted

$(AOSLIB_LIB): check_submodule
	$(ECHO) "${PURPLE}[ SUBMAKE ]${NC} Building internal aoslib submodule...\n"
	$(Q)$(MAKE) -C $(AOSLIB_DIR) ARCH=$(ARCH) CROSS_COMPILE=$(CROSS_COMPILE)

$(TARGET_LIB): $(LIN_OBJS) $(AOSLIB_LIB)
	$(ECHO) "${GRAY}[ EXTRACT ]${NC} Unpacking $(AOSLIB_LIB)...\n"
	$(Q)cd $(TEMP_DIR)/aos_extracted && $(AR) x $(AOSLIB_LIB)
	$(ECHO) "${LCYAN}[   AR    ]${NC} $@\n"
	$(Q)$(AR) rcs $@ $(LIN_OBJS) $(TEMP_DIR)/aos_extracted/*.o

$(TARGET_START): $(START_OBJ)
	$(ECHO) "${BROWN}[   CP    ]${NC} $< ${GREEN}->${NC} $@\n"
	$(Q)$(CP) $< $@

$(TEMP_DIR)/%.o: $(SRC_DIR)/%.c | prepare
	$(ECHO) "${CYAN}[   CC    ]${NC} $<\n"
	$(Q)$(CC) $(LIB_CFLAGS) -c $< -o $@

clean:
	$(ECHO) "${DRED}[   RM    ]${NC} ${TEMP_DIR}\n"
	$(Q)$(RM) $(TEMP_DIR)
	$(ECHO) "${DRED}[   RM    ]${NC} ${BUILD_DIR}\n"
	$(Q)$(RM) $(BUILD_DIR)
	@if [ -f "$(AOSLIB_DIR)/Makefile" ]; then \
		$(MAKE) -s -C $(AOSLIB_DIR) clean; \
	fi