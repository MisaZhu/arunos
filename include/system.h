/*
 * system.h
 *
 * Type and function declarations for system functions.
 *
 * (c) 2014 Hadi Moshayedi <hadi@moshayedi.net>
 */

#ifndef SYSTEM_H
#define SYSTEM_H

enum {
	CPSR_CPU_MODE        = 0x1f,
	CPSR_INSTRUCTION_SET = 0x1000020,
	CPSR_FIQ_DISABLED    = 0x40,
	CPSR_IRQ_DISABLED    = 0x80
};

enum {
	CPU_MODE_USER       = 0x10,
	CPU_MODE_FIQ        = 0x11,
	CPU_MODE_IRQ        = 0x12,
	CPU_MODE_SUPERVISOR = 0x13,
	CPU_MODE_ABORT      = 0x17,
	CPU_MODE_UNDEFINED  = 0x1b,
	CPU_MODE_SYSTEM     = 0x1f,
	CPU_MODE_MAX
};

enum {
	INSTRUCTION_SET_THUMB   = 1,
	INSTRUCTION_SET_JAZELLE = 2
};

enum {
	CPU_ID_REVISION     = 0x0000000f,
	CPU_ID_PART_NUMBER  = 0x0000fff0,
	CPU_ID_ARCH_CODE    = 0x000f0000,
	CPU_ID_VARIANT      = 0x00f00000,
	CPU_ID_IMPLEMENTOR  = 0x7f000000,
};

enum {
	CACHE_TYPE_SEPARATE         = 0x1000000,
	CACHE_TYPE_DATA_SIZE        = 0x0fff000,
	CACHE_TYPE_INSTRUCTION_SIZE = 0x0000fff
};

static char * const cpu_mode_string[CPU_MODE_MAX] = {
	[CPU_MODE_USER] = "user",
	[CPU_MODE_SUPERVISOR] = "supervisor",
	[CPU_MODE_FIQ] = "fiq",
	[CPU_MODE_IRQ] = "irq",
	[CPU_MODE_ABORT] = "abort",
	[CPU_MODE_UNDEFINED] = "undefined",
	[CPU_MODE_SYSTEM] = "system"
};

static char * const instruction_set_string[4] = {
	[0] = "arm",
	[INSTRUCTION_SET_THUMB] = "thumb",
	[INSTRUCTION_SET_JAZELLE] = "jazelle",
	[INSTRUCTION_SET_THUMB | INSTRUCTION_SET_JAZELLE] = "N/A"
};

static char * const architecture_code_string[16] = {
	[0x1] = "ARM v4",
	[0x2] = "ARM v4T",
	[0x3] = "ARM v5",
	[0x4] = "ARM v5T",
	[0x5] = "ARM v5TE",
	[0x6] = "ARM v5TEJ",
	[0x7] = "ARM v6"
};

static char * const implementor_string[128] = {
	[0x41] = "ARM Limited",
	[0x44] = "Digital Equipment Corporation",
	[0x4d] = "Motorola - Freescale Semiconductor Inc.",
	[0x56] = "Marvell Semiconductor Inc.",
	[0x69] = "Intel Corporation"
};

void enable_interrupts(void);
char *get_stack_pointer(int cpu_mode);
int read_cpsr(void);
int *read_fp(void);
int read_cpu_id(void);
int read_cache_type(void);

#endif
