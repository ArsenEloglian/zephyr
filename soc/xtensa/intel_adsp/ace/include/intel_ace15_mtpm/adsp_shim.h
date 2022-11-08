/*
 * Copyright (c) 2021 Intel Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */
#ifndef ZEPHYR_SOC_INTEL_ADSP_SHIM_H_
#define ZEPHYR_SOC_INTEL_ADSP_SHIM_H_

#ifndef _ASMLANGUAGE

/**
 * DfPMCCU
 * Power Management / Clock Control (HST) Registers
 *
 * Offset: 0x0007 1AC0h + 400 0000h * f
 * These registers block (HST domain) are for general power management
 * and clock control operation for DSP FW.
 */
struct ace_dfpmcch {
	uint32_t dfspsreq;	/* Offset: 0xc0 */
	uint32_t _unused0[3];
	uint32_t dfspsrsp;	/* Offset: 0xd0 */
	uint32_t _unused1[1];
	uint32_t svcfg;		/* Offset: 0xd8 */
	uint32_t dfltrc;	/* Offset: 0xdc */
	uint32_t _unused2[8];
};

/**
 * DfPMCCU
 * Power Management / Clock Control (ULP) Registers
 *
 * Offset: 0x0007 1B00h + 400 0000h * f
 * These registers block (ULP domain) are for general power management
 * and clock control operation for DSP FW.
 */
struct ace_dfpmccu {
	uint32_t dfpmccap;	/* Offset: 0x00 */
	uint32_t dfhrosccf;	/* Offset: 0x04 */
	uint32_t dfxosccf;	/* Offset: 0x08 */
	uint32_t dflrosccf;	/* Offset: 0x0c */
	uint32_t dfsiorosccf;	/* Offset: 0x10 */
	uint32_t dfhsiorosccf;	/* Offset: 0x14 */
	uint32_t dfipllrosccf;	/* Offset: 0x18 */
	uint32_t dfirosccv;	/* Offset: 0x1c */
	uint32_t dffbrcfd;	/* Offset: 0x20 */
	uint32_t dfapllptr;	/* Offset: 0x24 */
	uint32_t dfclkctl;	/* Offset: 0x78 */
	uint32_t dfclksts;	/* Offset: 0x7c */
	uint32_t dfintclkctl;	/* Offset: 0x80 */
	uint32_t dfcrosts;	/* Offset: 0x84 */
	uint32_t dfcrodiv;	/* Offset: 0x88 */
	uint16_t dfpwrctl;	/* Offset: 0x90 */
	uint16_t dfpwrsts;	/* Offset: 0x92 */
	uint32_t _unused0[1];
	uint32_t dflpsdmas0;	/* Offset: 0x98 */
	uint32_t dflpsdmas1;	/* Offset: 0x9c */
	uint32_t _unused1[1];
	uint32_t dfldoctl; 	/* Offset: 0xa4 */
	uint32_t _unused2[2];
	uint32_t dflpsalhsso;	/* Offset: 0xb0 */
	uint32_t dflpsalhss1;	/* Offset: 0xb4 */
	uint32_t dflpsalhss2;	/* Offset: 0xb8 */
	uint32_t dflpsalhss3;	/* Offset: 0xbc */
	uint32_t _unused3[10];	/* Offset: 0xc0 */
};

#define CAVS_SHIM (*((volatile struct cavs_shim *)DT_REG_ADDR(DT_NODELABEL(shim))))
#define ACE_DfPMCCH (*((volatile struct ace_dfpmcch *)DT_REG_ADDR(DT_NODELABEL(dfpmcch))))
#define ACE_DfPMCCU (*((volatile struct ace_dfpmccu *)DT_REG_ADDR(DT_NODELABEL(dfpmccu))))


#define ADSP_TTSCAP_OFFSET	0x00
#define ADSP_RTCWC_OFFSET	0x08
#define ADSP_DSPWCCTL_OFFSET	0x10
#define ADSP_DSPWCSTS_OFFSET	0x12
#define ADSP_DSPWCAV_OFFSET	0x18
#define ADSP_DSPWC_OFFSET	0x20
#define ADSP_DSPWCTCS_OFFSET	0x28
#define ADSP_DSPWCT0C_OFFSET	0x30
#define ADSP_DSPWCT1C_OFFSET	0x38
#define ADSP_TSCTRL_OFFSET	0x40
#define ADSP_ISCS_OFFSET	0x44
#define ADSP_LSCS_OFFSET	0x48
#define ADSP_DWCCS_OFFSET	0x50
#define ADSP_ARTCS_OFFSET	0x58
#define ADSP_LWCCS_OFFSET	0x60
#define ADSP_CLTSYNC_OFFSET	0x70



#define ADSP_SHIM_DSPWCTCS_TTIE(c) BIT(8 + (c))

/* Host memory window control.  Not strictly part of the shim block. */
struct cavs_win {
	uint32_t dmwba;
	uint32_t dmwlo;
};

#define CAVS_WIN ((volatile struct cavs_win *)DT_REG_ADDR(DT_NODELABEL(win)))

#endif /* _ASMLANGUAGE */



/* cAVS 1.8+ CLKCTL bits */
#define CAVS_CLKCTL_RHROSCC   BIT(31)	  /* Request HP RING oscillator */
#define CAVS_CLKCTL_RXOSCC    BIT(30)	  /* Request XTAL oscillator */
#define CAVS_CLKCTL_RLROSCC   BIT(29)	  /* Request LP RING oscillator */
#define CAVS_CLKCTL_SLIMFDCGB BIT(25)	  /* Slimbus force dynamic clock gating*/
#define CAVS_CLKCTL_TCPLCG(x) BIT(16 + x) /* Set bit: prevent clock gating on core x */
#define CAVS_CLKCTL_SLIMCSS   BIT(6)	  /* Slimbus clock (0: XTAL, 1: Audio) */
#define CAVS_CLKCTL_WOVCRO    BIT(4)	  /* Request WOVCRO clock */
#define CAVS_CLKCTL_WOVCROSC  BIT(3)	  /* WOVCRO select */
#define CAVS_CLKCTL_OCS	      BIT(2)	  /* Oscillator clock (0: LP, 1: HP) */
#define CAVS_CLKCTL_LMCS      BIT(1)	  /* LP mem divisor (0: div/2, 1: div/4) */
#define CAVS_CLKCTL_HMCS      BIT(0)	  /* HP mem divisor (0: div/2, 1: div/4) */

#define CAVS_PWRCTL_TCPDSPPG(x) BIT(x)
#define CAVS_PWRSTS_PDSPPGS(x)	BIT(x)

#define SHIM_LDOCTL_HPSRAM_LDO_ON     (3 << 0)
#define SHIM_LDOCTL_HPSRAM_LDO_BYPASS BIT(0)

#define SHIM_LDOCTL_LPSRAM_LDO_ON     (3 << 2)
#define SHIM_LDOCTL_LPSRAM_LDO_BYPASS BIT(2)

#define ADSP_DMWBA_ENABLE   BIT(0)
#define ADSP_DMWBA_READONLY BIT(1)

#define CAVS_CLKCTL_OSC_SOURCE_MASK  BIT_MASK(2)
#define CAVS_CLKCTL_OSC_REQUEST_MASK (~BIT_MASK(28))

/** LDO Control */
#define ADSP_DSPRA_ADDRESS        (0x71A60)
#define ADSP_LPGPDMACxO_ADDRESS(x) (ADSP_DSPRA_ADDRESS + 0x0000 + 0x0002*(x))
#define ADSP_DSPIOPO_ADDRESS      (ADSP_DSPRA_ADDRESS + 0x0008)
#define ADSP_GENO_ADDRESS         (ADSP_DSPRA_ADDRESS + 0x000C)
#define ADSP_DSPALHO_ADDRESS      (ADSP_DSPRA_ADDRESS + 0x0010)


#define DSP_INIT_IOPO   ADSP_DSPIOPO_ADDRESS
#define IOPO_DMIC_FLAG          BIT(0)
#define IOPO_DSPKOSEL_FLAG      BIT(1)
#define IOPO_ANCOSEL_FLAG       BIT(2)
#define IOPO_DMIXOSEL_FLAG      BIT(3)
#define IOPO_SLIMOSEL_FLAG      BIT(4)
#define IOPO_SNDWOSEL_FLAG      BIT(5)
#define IOPO_SLIMDOSEL_FLAG     BIT(20)
#define IOPO_I2SSEL_MASK	(0x7 << 0x8)

#define DSP_INIT_GENO   ADSP_GENO_ADDRESS
#define GENO_MDIVOSEL           BIT(1)
#define GENO_DIOPTOSEL          BIT(2)

#endif /* ZEPHYR_SOC_INTEL_ADSP_SHIM_H_ */
