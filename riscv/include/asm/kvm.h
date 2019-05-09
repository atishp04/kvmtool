/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Copyright (C) 2019 Western Digital Corporation or its affiliates.
 *
 * Authors:
 *     Anup Patel <anup.patel@wdc.com>
 */

#ifndef __LINUX_KVM_RISCV_H
#define __LINUX_KVM_RISCV_H

#ifndef __ASSEMBLY__

#include <linux/types.h>
#include <asm/ptrace.h>

#define __KVM_HAVE_READONLY_MEM

#define KVM_COALESCED_MMIO_PAGE_OFFSET 1

#define KVM_INTERRUPT_SET	-1U
#define KVM_INTERRUPT_UNSET	-2U

/* for KVM_GET_REGS and KVM_SET_REGS */
struct kvm_regs {
	/* out (KVM_GET_REGS) / in (KVM_SET_REGS) */
	struct user_regs_struct regs;
	unsigned long mode;
};

/* Possible privilege modes for kvm_regs */
#define KVM_RISCV_MODE_S	1
#define KVM_RISCV_MODE_U	0

/* for KVM_GET_FPU and KVM_SET_FPU */
struct kvm_fpu {
};

/* KVM Debug exit structure */
struct kvm_debug_exit_arch {
};

/* for KVM_SET_GUEST_DEBUG */
struct kvm_guest_debug_arch {
};

/* definition of registers in kvm_run */
struct kvm_sync_regs {
};

/* dummy definition */
struct kvm_sregs {
};

#define KVM_REG_SIZE(id)		\
	(1U << (((id) & KVM_REG_SIZE_MASK) >> KVM_REG_SIZE_SHIFT))

/* If you need to interpret the index values, here is the key: */
#define KVM_REG_RISCV_TYPE_MASK		0x00000000FF000000
#define KVM_REG_RISCV_TYPE_SHIFT	24

/* Config registers are mapped as type 1 */
#define KVM_REG_RISCV_CONFIG		(0x01 << KVM_REG_RISCV_TYPE_SHIFT)
#define KVM_REG_RISCV_CONFIG_ISA	0x0
#define KVM_REG_RISCV_CONFIG_TIMEBASE	0x1

/* Core registers are mapped as type 2 */
#define KVM_REG_RISCV_CORE		(0x02 << KVM_REG_RISCV_TYPE_SHIFT)
#define KVM_REG_RISCV_CORE_REG(name)	\
		(offsetof(struct kvm_regs, name) / sizeof(unsigned long))

/* Control and status registers are mapped as type 3 */
#define KVM_REG_RISCV_CSR		(0x03 << KVM_REG_RISCV_TYPE_SHIFT)
#define KVM_REG_RISCV_CSR_REG(csr_num)	((csr_num) & 0xFFF)
#define KVM_REG_RISCV_CSR_SSTATUS	0x100
#define KVM_REG_RISCV_CSR_SIE		0x104
#define KVM_REG_RISCV_CSR_STVEC		0x105
#define KVM_REG_RISCV_CSR_SCOUNTEREN	0x106
#define KVM_REG_RISCV_CSR_SSCRATCH	0x140
#define KVM_REG_RISCV_CSR_SEPC		0x141
#define KVM_REG_RISCV_CSR_SCAUSE	0x142
#define KVM_REG_RISCV_CSR_STVAL		0x143
#define KVM_REG_RISCV_CSR_SIP		0x144
#define KVM_REG_RISCV_CSR_SATP		0x180

#endif

#endif /* __LINUX_KVM_RISCV_H */
