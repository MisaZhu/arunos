PROC_DIR = kernel/proc

OBJS += $(PROC_DIR)/proc.o
OBJS += $(PROC_DIR)/scheduler.o
OBJS += $(PROC_DIR)/syscall_exit.o
OBJS += $(PROC_DIR)/syscall_getpid.o
OBJS += $(PROC_DIR)/syscall_fork.o