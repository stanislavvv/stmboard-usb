######################################################################
#  Project Makefile
######################################################################
TOP_DIR         := $(dir $(abspath $(lastword $(MAKEFILE_LIST))))

# choose target (stm32f103, stm32f303)
TARGET_CPU ?= stm32f103

TGT_CFLAGS	+= -I./rtos -I./libs -I.
TGT_CXXFLAGS	+= -I./rtos -I./libs -I.

BINARY		= main
SRCFILES	= rtos/heap_4.c rtos/list.c rtos/port.c rtos/tasks.c rtos/opencm3.c rtos/queue.c
SRCFILES	+= hw.c hw_isr.c hw/usb.c
SRCFILES	+= morse.c
SRCFILES	+= shell/shell.c shell/shell_cmds.c
SRCFILES	+= main.c

include mk/Makefile.common.incl

# tests
test: clean
	make -f Makefile.tests
	#make clean
