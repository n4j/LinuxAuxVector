#ifndef __HWCAP_H__
#define __HWCAP_H__

#include <elf.h>
#include <errno.h>
#include <fcntl.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#if defined (__aarch64__) || defined(_M_ARM64)
#include <asm/hwcap.h>

#define NUM_CPU_FEATURES 48

#define CPU_FEATURE_SIZE 19

static const char* const AARCH_CPU_FEATURES[] = {
	"HWCAP2_DCPODP",
	"HWCAP2_SVE2",
	"HWCAP2_SVEAES",
	"HWCAP2_SVEPMULL",
	"HWCAP2_SVEBITPERM",
	"HWCAP2_SVESHA3",
        "HWCAP2_SVESM4",
        "HWCAP2_FLAGM2",
        "HWCAP2_FRINT",
	"HWCAP2_SVEI8MM",
        "HWCAP2_SVEF32MM",
        "HWCAP2_SVEF64MM",
        "HWCAP2_SVEBF16",
	"HWCAP2_I8MM",
        "HWCAP2_BF16",
        "HWCAP2_DGH",
        "HWCAP2_RNG",
	"HWCAP2_BTI",
        "HWCAP2_MTE",
        "HWCAP2_ECV",
        "HWCAP2_AFP",
	"HWCAP2_RPRES",
        "HWCAP2_MTE3",
        "HWCAP2_SME",
        "HWCAP2_SME_I16I64",
	"HWCAP2_SME_F64F64",
        "HWCAP2_SME_I8I32",
	"HWCAP2_SME_F16F32",
	"HWCAP2_SME_B16F32",
	"HWCAP2_SME_F32F32",
	"HWCAP2_SME_FA64",
	"HWCAP2_WFXT",
	"HWCAP2_EBF16",
	"HWCAP2_SVE_EBF16",
	"HWCAP2_CSSC",
	"HWCAP2_RPRFM",
	"HWCAP2_SVE2P1",
	"HWCAP2_SME2",
	"HWCAP2_SME2P1",
	"HWCAP2_SME_I16I32",
	"HWCAP2_SME_BI32I32",
	"HWCAP2_SME_B16B16",
	"HWCAP2_SME_F16F16",
	"HWCAP2_MOPS",
	"HWCAP2_HBC",
	"HWCAP2_SVE_B16B16",
	"HWCAP2_LRCPC3",
	"HWCAP2_LSE128"
};


#endif

void print_cpu_cap(uint64_t mask);

#if defined (__aarch64__) || defined(_M_ARM64)
	void print_cpu_cap_aarch64(uint64_t mask);
#elif
	void print_cpu_cap_noop(uint64_t);
#endif

#endif //__HWCAP_H__	
