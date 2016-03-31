/** @file

  Copyright (c) 2015, Intel Corporation. All rights reserved.<BR>
  This program and the accompanying materials
  are licensed and made available under the terms and conditions of the BSD License
  which accompanies this distribution.  The full text of the license may be found at
  http://opensource.org/licenses/bsd-license.php.

  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/

#ifndef _CPU_H_
#define _CPU_H_

#pragma pack (1)

typedef struct {
  UINT16  Offset15To0:16;
  UINT16  SegmentSelector:16;
  UINT8   Rsvd0;
  UINT8   GateType;
  UINT16  Offset31To16;
#ifdef MDE_CPU_X64
  UINT32  Offset63To32;
  UINT32  Rsvd1;
#endif
} INTERRUPT_GATE_DESCRIPTOR;

typedef struct {
  UINT16  LimitLow;
  UINT16  BaseLow;
  UINT8   BaseMid;
  UINT8   Attribute;
  UINT8   LimitHi;
  UINT8   BaseHi;
} GDT_ENTRY;

#define VM86_TSS_IOMAP_SIZE       (0x10000 / 8 + 1)
#define VM86_TSS_INTMAP_SIZE      (0x100 / 8)

typedef struct {
  UINT16  Link;
  UINT16  LinkReserved;
  UINT32  ESP0;
  UINT16  SS0;
  UINT16  SS0Reserved;
  UINT32  ESP1;
  UINT16  SS1;
  UINT16  SS1Reserved;
  UINT32  ESP2;
  UINT16  SS2;
  UINT16  SS2Reserved;
  UINT32  CR3;
  UINT32  EIP;
  UINT32  EFlag;
  UINT32  EAX;
  UINT32  ECX;
  UINT32  EDX;
  UINT32  EBX;
  UINT32  ESP;
  UINT32  EBP;
  UINT32  ESI;
  UINT32  EDI;
  UINT16  ES;
  UINT16  ESReserved;
  UINT16  CS;
  UINT16  CSReserved;
  UINT16  SS;
  UINT16  SSReserved;
  UINT16  DS;
  UINT16  DSReserved;
  UINT16  FS;
  UINT16  FSReserved;
  UINT16  GS;
  UINT16  GSReserved;
  UINT16  LDTSegSelector;
  UINT16  LDTSegSelectorRes;
  UINT16  TrapRegister;
  UINT16  IoMapBase;
  UINT8   IntMap[VM86_TSS_INTMAP_SIZE];
  UINT8   IoMap[VM86_TSS_IOMAP_SIZE];
} TASK_STATE;

typedef struct {
  UINT16  Link;
  UINT16  SP0;
  UINT16  SS0;
  UINT16  SP1;
  UINT16  SS1;
  UINT16  SP2;
  UINT16  SS2;
  UINT16  IP;
  UINT16  Flag;
  UINT16  AX;
  UINT16  CX;
  UINT16  DX;
  UINT16  BX;
  UINT16  SP;
  UINT16  BP;
  UINT16  SI;
  UINT16  DI;
  UINT16  ES;
  UINT16  CS;
  UINT16  SS;
  UINT16  DS;
  UINT16  LDTSegSelector;
} TASK_STATE_16;

typedef struct {
  UINT32  Rsvd0;
  UINT64  RSP0;
  UINT64  RSP1;
  UINT64  RSP2;
  UINT64  Rsvd28;
  UINT64  IST1;
  UINT64  IST2;
  UINT64  IST3;
  UINT64  IST4;
  UINT64  IST5;
  UINT64  IST6;
  UINT64  IST7;
  UINT64  Rsvd92;
  UINT16  Rsvd100;
  UINT16  IoMapBase;
} TASK_STATE_64;

#pragma pack ()

#define MEMORY_TYPE_UC  0
#define MEMORY_TYPE_WC  1
#define MEMORY_TYPE_WT  4
#define MEMORY_TYPE_WP  5
#define MEMORY_TYPE_WB  6

#define IA32_APIC_BASE_MSR_INDEX            0x1B
#define   IA32_APIC_BSP                     (1u << 8)
#define   IA32_APIC_X2_MODE                 (1u << 10)
#define   IA32_APIC_ENABLE                  (1u << 11)
#define IA32_FEATURE_CONTROL_MSR_INDEX      0x3A
#define   IA32_FEATURE_CONTROL_LCK          1u
#define   IA32_FEATURE_CONTROL_SMX          (1u << 1)
#define   IA32_FEATURE_CONTROL_VMX          (1u << 2)
#define IA32_BIOS_UPDT_TRIG_MSR_INDEX       0x79
#define IA32_MTRRCAP_MSR_INDEX              0xFE
#define IA32_SYSENTER_CS_MSR_INDEX          0x174
#define IA32_SYSENTER_ESP_MSR_INDEX         0x175
#define IA32_SYSENTER_EIP_MSR_INDEX         0x176
#define IA32_MISC_ENABLE_MSR_INDEX          0x1A0
#define IA32_DBG_CTL_MSR_INDEX              0x1D9
#define IA32_MTRR_PHYSBASE0_MSR_INDEX       0x200
#define IA32_MTRR_PHYSMASK0_MSR_INDEX       0x201
#define IA32_MTRR_PHYSBASE1_MSR_INDEX       0x202
#define IA32_MTRR_PHYSMASK1_MSR_INDEX       0x203
#define IA32_MTRR_PHYSBASE2_MSR_INDEX       0x204
#define IA32_MTRR_PHYSMASK2_MSR_INDEX       0x205
#define IA32_MTRR_PHYSBASE3_MSR_INDEX       0x206
#define IA32_MTRR_PHYSMASK3_MSR_INDEX       0x207
#define IA32_MTRR_PHYSBASE4_MSR_INDEX       0x208
#define IA32_MTRR_PHYSMASK4_MSR_INDEX       0x209
#define IA32_MTRR_PHYSBASE5_MSR_INDEX       0x20A
#define IA32_MTRR_PHYSMASK5_MSR_INDEX       0x20B
#define IA32_MTRR_PHYSBASE6_MSR_INDEX       0x20C
#define IA32_MTRR_PHYSMASK6_MSR_INDEX       0x20D
#define IA32_MTRR_PHYSBASE7_MSR_INDEX       0x20E
#define IA32_MTRR_PHYSMASK7_MSR_INDEX       0x20F
#define IA32_MTRR_FIX64K_00000_MSR_INDEX    0x250
#define IA32_MTRR_FIX16K_80000_MSR_INDEX    0x258
#define IA32_MTRR_FIX16K_A0000_MSR_INDEX    0x259
#define IA32_MTRR_FIX4K_C0000_MSR_INDEX     0x268
#define IA32_MTRR_FIX4K_C8000_MSR_INDEX     0x269
#define IA32_MTRR_FIX4K_D0000_MSR_INDEX     0x26A
#define IA32_MTRR_FIX4K_D8000_MSR_INDEX     0x26B
#define IA32_MTRR_FIX4K_E0000_MSR_INDEX     0x26C
#define IA32_MTRR_FIX4K_E8000_MSR_INDEX     0x26D
#define IA32_MTRR_FIX4K_F0000_MSR_INDEX     0x26E
#define IA32_MTRR_FIX4K_F8000_MSR_INDEX     0x26F
#define IA32_MTRR_DEF_TYPE_MSR_INDEX        0x2FF
#define   IA32_MTRR_DEF_TYPE_E              (1u << 11)
#define   IA32_MTRR_DEF_TYPE_FE             (1u << 10)

#define EFI_MSR_COREI7_SMRR_PHYS_BASE          0x1F2
#define EFI_MSR_COREI7_SMRR_PHYS_MASK          0x1F3
#define  EFI_MSR_SMRR_PHYS_MASK_VALID          (1u << 11)

#define IA32_EFER_MSR_INDEX                 0xC0000080
#define   IA32_EFER_MSR_SCE                 1u
#define   IA32_EFER_MSR_MLE                 (1u << 8)
#define   IA32_EFER_MSR_MLA                 (1u << 10)
#define   IA32_EFER_MSR_XDE                 (1u << 11)
#define IA32_STAR_MSR_INDEX                 0xC0000081
#define IA32_LSTAR_MSR_INDEX                0xC0000082
#define IA32_FMASK_MSR_INDEX                0xC0000084
#define IA32_FS_BASE_MSR_INDEX              0xC0000100
#define IA32_GS_BASE_MSR_INDEX              0xC0000101
#define IA32_KERNAL_GS_BASE_MSR_INDEX       0xC0000102

#define IA32_PG_P                   1u
#define IA32_PG_RW                  (1u << 1)
#define IA32_PG_USR                 (1u << 2)
#define IA32_PG_WT                  (1u << 3)
#define IA32_PG_CD                  (1u << 4)
#define IA32_PG_A                   (1u << 5)
#define IA32_PG_D                   (1u << 6)
#define IA32_PG_PS                  (1u << 7)
#define IA32_PG_G                   (1u << 8)
#define IA32_PG_PAT_2M              (1u << 12)
#define IA32_PG_PAT_4K              IA32_PG_PS

#define RFLAGS_CF   1u
#define RFLAGS_ZF   (1u << 6)
#define RFLAGS_TF   (1u << 8)
#define RFLAGS_IF   (1u << 9)
#define RFLAGS_DF   (1u << 10)
#define RFLAGS_IOPL (3u << 12)
#define RFLAGS_NT   (1u << 14)
#define RFLAGS_RF   (1u << 16)
#define RFLAGS_VM   (1u << 17)
#define RFLAGS_AC   (1u << 18)
#define RFLAGS_VIF  (1u << 19)
#define RFLAGS_VIP  (1u << 20)

#define CR0_PE    1u
#define CR0_TS    (1u << 3)
#define CR0_NE    (1u << 5)
#define CR0_WP    (1u << 16)
#define CR0_NW    (1u << 29)
#define CR0_CD    (1u << 30)
#define CR0_PG    (1u << 31)

#define CR4_VME   1u
#define CR4_PSE   (1u << 4)
#define CR4_PAE   (1u << 5)
#define CR4_PGE   (1u << 7)
#define CR4_OSFXSR       (1u << 9)
#define CR4_OSXMMEXCPT   (1u << 10)
#define CR4_VMXE  (1u << 13)
#define CR4_SMXE  (1u << 14)
#define CR4_OSXSAVE      (1u << 18)

#define CPUID_BASIC_INFORMATION                   0x0
#define CPUID_FEATURE_INFORMATION                 0x1
#define CPUID_PROCESSOR_EXTENDED_STATE_EMULATION  0xD
#define CPUID_EXTENDED_INFORMATION                0x80000000
#define CPUID_EXTENDED_ADDRESS_SIZE               0x80000008

#define DESCRIPTOR_PRESENT      0x80

#define DESCRIPTOR_SYSTEM_MASK  0x10
#define DESCRIPTOR_SYSTEM       0x00
#define DESCRIPTOR_CODE_DATA    0x10

#define DESCRIPTOR_TYPE_MASK    0x0f

#define DESCRIPTOR_TYPE_DATA    0x00
#define DESCRIPTOR_TYPE_CODE    0x08

#define DESCRIPTOR_DATA_ACCESS       0x01
#define DESCRIPTOR_DATA_WRITE        0x02
#define DESCRIPTOR_DATA_EXPAND_DOWN  0x04

#define DESCRIPTOR_CODE_ACCESS       0x01
#define DESCRIPTOR_CODE_READ         0x02
#define DESCRIPTOR_CODE_CONFORMING   0x04

#define DESCRIPTOR_TSS_16_AVAIL         0x01
#define DESCRIPTOR_LDT                  0x02
#define DESCRIPTOR_TSS_16_BUSY          0x03
#define DESCRIPTOR_CALL_GATE_16         0x04
#define DESCRIPTOR_TASK_GATE            0x05
#define DESCRIPTOR_INTERRUPT_GATE_16    0x06
#define DESCRIPTOR_TRAP_GATE_16         0x07
#define DESCRIPTOR_TSS_N_AVAIL          0x09
#define DESCRIPTOR_TSS_N_BUSY           0x0b
#define DESCRIPTOR_CALL_GATE_N          0x0c
#define DESCRIPTOR_INTERRUPT_GATE_N     0x0e
#define DESCRIPTOR_TRAP_GATE_N          0x0f

#define DESCRIPTOR_TSS_MASK             0x09
#define DESCRIPTOR_TSS_BUSY             0x02

/**

  This function return GDT entry base from GDT entry.

  @param GdtEntry GDT entry

  @return GDT entry Base
**/
UINT32
BaseFromGdtEntry (
  IN GDT_ENTRY *GdtEntry
  );

/**

  This function return GDT entry limit from GDT entry.

  @param GdtEntry GDT entry

  @return GDT entry limit
**/
UINT32
LimitFromGdtEntry (
  IN GDT_ENTRY *GdtEntry
  );

/**

  This function return GDT entry attribute from GDT entry.

  @param GdtEntry GDT entry

  @return GDT entry attribute
**/
UINT32
ArFromGdtEntry (
  IN GDT_ENTRY *GdtEntry
  );

#endif

