/*******************************************************************************
* File Name: cyfitter.h
* 
* PSoC Creator  4.4
*
* Description:
* 
* This file is automatically generated by PSoC Creator.
*
********************************************************************************
* Copyright (c) 2007-2020 Cypress Semiconductor.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/

#ifndef INCLUDED_CYFITTER_H
#define INCLUDED_CYFITTER_H
#include "cydevice.h"
#include "cydevice_trm.h"

/* LCD */
#define LCD_LCDPort__0__INTTYPE CYREG_PICU2_INTTYPE0
#define LCD_LCDPort__0__MASK 0x01u
#define LCD_LCDPort__0__PC CYREG_PRT2_PC0
#define LCD_LCDPort__0__PORT 2u
#define LCD_LCDPort__0__SHIFT 0u
#define LCD_LCDPort__1__INTTYPE CYREG_PICU2_INTTYPE1
#define LCD_LCDPort__1__MASK 0x02u
#define LCD_LCDPort__1__PC CYREG_PRT2_PC1
#define LCD_LCDPort__1__PORT 2u
#define LCD_LCDPort__1__SHIFT 1u
#define LCD_LCDPort__2__INTTYPE CYREG_PICU2_INTTYPE2
#define LCD_LCDPort__2__MASK 0x04u
#define LCD_LCDPort__2__PC CYREG_PRT2_PC2
#define LCD_LCDPort__2__PORT 2u
#define LCD_LCDPort__2__SHIFT 2u
#define LCD_LCDPort__3__INTTYPE CYREG_PICU2_INTTYPE3
#define LCD_LCDPort__3__MASK 0x08u
#define LCD_LCDPort__3__PC CYREG_PRT2_PC3
#define LCD_LCDPort__3__PORT 2u
#define LCD_LCDPort__3__SHIFT 3u
#define LCD_LCDPort__4__INTTYPE CYREG_PICU2_INTTYPE4
#define LCD_LCDPort__4__MASK 0x10u
#define LCD_LCDPort__4__PC CYREG_PRT2_PC4
#define LCD_LCDPort__4__PORT 2u
#define LCD_LCDPort__4__SHIFT 4u
#define LCD_LCDPort__5__INTTYPE CYREG_PICU2_INTTYPE5
#define LCD_LCDPort__5__MASK 0x20u
#define LCD_LCDPort__5__PC CYREG_PRT2_PC5
#define LCD_LCDPort__5__PORT 2u
#define LCD_LCDPort__5__SHIFT 5u
#define LCD_LCDPort__6__INTTYPE CYREG_PICU2_INTTYPE6
#define LCD_LCDPort__6__MASK 0x40u
#define LCD_LCDPort__6__PC CYREG_PRT2_PC6
#define LCD_LCDPort__6__PORT 2u
#define LCD_LCDPort__6__SHIFT 6u
#define LCD_LCDPort__AG CYREG_PRT2_AG
#define LCD_LCDPort__AMUX CYREG_PRT2_AMUX
#define LCD_LCDPort__BIE CYREG_PRT2_BIE
#define LCD_LCDPort__BIT_MASK CYREG_PRT2_BIT_MASK
#define LCD_LCDPort__BYP CYREG_PRT2_BYP
#define LCD_LCDPort__CTL CYREG_PRT2_CTL
#define LCD_LCDPort__DM0 CYREG_PRT2_DM0
#define LCD_LCDPort__DM1 CYREG_PRT2_DM1
#define LCD_LCDPort__DM2 CYREG_PRT2_DM2
#define LCD_LCDPort__DR CYREG_PRT2_DR
#define LCD_LCDPort__INP_DIS CYREG_PRT2_INP_DIS
#define LCD_LCDPort__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU2_BASE
#define LCD_LCDPort__LCD_COM_SEG CYREG_PRT2_LCD_COM_SEG
#define LCD_LCDPort__LCD_EN CYREG_PRT2_LCD_EN
#define LCD_LCDPort__MASK 0x7Fu
#define LCD_LCDPort__PORT 2u
#define LCD_LCDPort__PRT CYREG_PRT2_PRT
#define LCD_LCDPort__PRTDSI__CAPS_SEL CYREG_PRT2_CAPS_SEL
#define LCD_LCDPort__PRTDSI__DBL_SYNC_IN CYREG_PRT2_DBL_SYNC_IN
#define LCD_LCDPort__PRTDSI__OE_SEL0 CYREG_PRT2_OE_SEL0
#define LCD_LCDPort__PRTDSI__OE_SEL1 CYREG_PRT2_OE_SEL1
#define LCD_LCDPort__PRTDSI__OUT_SEL0 CYREG_PRT2_OUT_SEL0
#define LCD_LCDPort__PRTDSI__OUT_SEL1 CYREG_PRT2_OUT_SEL1
#define LCD_LCDPort__PRTDSI__SYNC_OUT CYREG_PRT2_SYNC_OUT
#define LCD_LCDPort__PS CYREG_PRT2_PS
#define LCD_LCDPort__SHIFT 0u
#define LCD_LCDPort__SLW CYREG_PRT2_SLW

/* paso */
#define paso__INTC_CLR_EN_REG CYREG_NVIC_CLRENA0
#define paso__INTC_CLR_PD_REG CYREG_NVIC_CLRPEND0
#define paso__INTC_MASK 0x01u
#define paso__INTC_NUMBER 0u
#define paso__INTC_PRIOR_NUM 7u
#define paso__INTC_PRIOR_REG CYREG_NVIC_PRI_0
#define paso__INTC_SET_EN_REG CYREG_NVIC_SETENA0
#define paso__INTC_SET_PD_REG CYREG_NVIC_SETPEND0

/* PWM_1 */
#define PWM_1_PWMUDB_genblk1_ctrlreg__16BIT_CONTROL_AUX_CTL_REG CYREG_B1_UDB05_06_ACTL
#define PWM_1_PWMUDB_genblk1_ctrlreg__16BIT_CONTROL_CONTROL_REG CYREG_B1_UDB05_06_CTL
#define PWM_1_PWMUDB_genblk1_ctrlreg__16BIT_CONTROL_COUNT_REG CYREG_B1_UDB05_06_CTL
#define PWM_1_PWMUDB_genblk1_ctrlreg__16BIT_COUNT_CONTROL_REG CYREG_B1_UDB05_06_CTL
#define PWM_1_PWMUDB_genblk1_ctrlreg__16BIT_COUNT_COUNT_REG CYREG_B1_UDB05_06_CTL
#define PWM_1_PWMUDB_genblk1_ctrlreg__16BIT_MASK_MASK_REG CYREG_B1_UDB05_06_MSK
#define PWM_1_PWMUDB_genblk1_ctrlreg__16BIT_MASK_PERIOD_REG CYREG_B1_UDB05_06_MSK
#define PWM_1_PWMUDB_genblk1_ctrlreg__16BIT_PERIOD_MASK_REG CYREG_B1_UDB05_06_MSK
#define PWM_1_PWMUDB_genblk1_ctrlreg__16BIT_PERIOD_PERIOD_REG CYREG_B1_UDB05_06_MSK
#define PWM_1_PWMUDB_genblk1_ctrlreg__7__MASK 0x80u
#define PWM_1_PWMUDB_genblk1_ctrlreg__7__POS 7
#define PWM_1_PWMUDB_genblk1_ctrlreg__CONTROL_AUX_CTL_REG CYREG_B1_UDB05_ACTL
#define PWM_1_PWMUDB_genblk1_ctrlreg__CONTROL_REG CYREG_B1_UDB05_CTL
#define PWM_1_PWMUDB_genblk1_ctrlreg__CONTROL_ST_REG CYREG_B1_UDB05_ST_CTL
#define PWM_1_PWMUDB_genblk1_ctrlreg__COUNT_REG CYREG_B1_UDB05_CTL
#define PWM_1_PWMUDB_genblk1_ctrlreg__COUNT_ST_REG CYREG_B1_UDB05_ST_CTL
#define PWM_1_PWMUDB_genblk1_ctrlreg__MASK 0x80u
#define PWM_1_PWMUDB_genblk1_ctrlreg__MASK_CTL_AUX_CTL_REG CYREG_B1_UDB05_MSK_ACTL
#define PWM_1_PWMUDB_genblk1_ctrlreg__PER_CTL_AUX_CTL_REG CYREG_B1_UDB05_MSK_ACTL
#define PWM_1_PWMUDB_genblk1_ctrlreg__PERIOD_REG CYREG_B1_UDB05_MSK
#define PWM_1_PWMUDB_genblk8_stsreg__0__MASK 0x01u
#define PWM_1_PWMUDB_genblk8_stsreg__0__POS 0
#define PWM_1_PWMUDB_genblk8_stsreg__16BIT_STATUS_AUX_CTL_REG CYREG_B1_UDB05_06_ACTL
#define PWM_1_PWMUDB_genblk8_stsreg__16BIT_STATUS_REG CYREG_B1_UDB05_06_ST
#define PWM_1_PWMUDB_genblk8_stsreg__2__MASK 0x04u
#define PWM_1_PWMUDB_genblk8_stsreg__2__POS 2
#define PWM_1_PWMUDB_genblk8_stsreg__3__MASK 0x08u
#define PWM_1_PWMUDB_genblk8_stsreg__3__POS 3
#define PWM_1_PWMUDB_genblk8_stsreg__MASK 0x0Du
#define PWM_1_PWMUDB_genblk8_stsreg__MASK_REG CYREG_B1_UDB05_MSK
#define PWM_1_PWMUDB_genblk8_stsreg__MASK_ST_AUX_CTL_REG CYREG_B1_UDB05_MSK_ACTL
#define PWM_1_PWMUDB_genblk8_stsreg__PER_ST_AUX_CTL_REG CYREG_B1_UDB05_MSK_ACTL
#define PWM_1_PWMUDB_genblk8_stsreg__STATUS_AUX_CTL_REG CYREG_B1_UDB05_ACTL
#define PWM_1_PWMUDB_genblk8_stsreg__STATUS_CNT_REG CYREG_B1_UDB05_ST_CTL
#define PWM_1_PWMUDB_genblk8_stsreg__STATUS_CONTROL_REG CYREG_B1_UDB05_ST_CTL
#define PWM_1_PWMUDB_genblk8_stsreg__STATUS_REG CYREG_B1_UDB05_ST
#define PWM_1_PWMUDB_sP16_pwmdp_u0__16BIT_A0_REG CYREG_B1_UDB04_05_A0
#define PWM_1_PWMUDB_sP16_pwmdp_u0__16BIT_A1_REG CYREG_B1_UDB04_05_A1
#define PWM_1_PWMUDB_sP16_pwmdp_u0__16BIT_D0_REG CYREG_B1_UDB04_05_D0
#define PWM_1_PWMUDB_sP16_pwmdp_u0__16BIT_D1_REG CYREG_B1_UDB04_05_D1
#define PWM_1_PWMUDB_sP16_pwmdp_u0__16BIT_DP_AUX_CTL_REG CYREG_B1_UDB04_05_ACTL
#define PWM_1_PWMUDB_sP16_pwmdp_u0__16BIT_F0_REG CYREG_B1_UDB04_05_F0
#define PWM_1_PWMUDB_sP16_pwmdp_u0__16BIT_F1_REG CYREG_B1_UDB04_05_F1
#define PWM_1_PWMUDB_sP16_pwmdp_u0__A0_A1_REG CYREG_B1_UDB04_A0_A1
#define PWM_1_PWMUDB_sP16_pwmdp_u0__A0_REG CYREG_B1_UDB04_A0
#define PWM_1_PWMUDB_sP16_pwmdp_u0__A1_REG CYREG_B1_UDB04_A1
#define PWM_1_PWMUDB_sP16_pwmdp_u0__D0_D1_REG CYREG_B1_UDB04_D0_D1
#define PWM_1_PWMUDB_sP16_pwmdp_u0__D0_REG CYREG_B1_UDB04_D0
#define PWM_1_PWMUDB_sP16_pwmdp_u0__D1_REG CYREG_B1_UDB04_D1
#define PWM_1_PWMUDB_sP16_pwmdp_u0__DP_AUX_CTL_REG CYREG_B1_UDB04_ACTL
#define PWM_1_PWMUDB_sP16_pwmdp_u0__F0_F1_REG CYREG_B1_UDB04_F0_F1
#define PWM_1_PWMUDB_sP16_pwmdp_u0__F0_REG CYREG_B1_UDB04_F0
#define PWM_1_PWMUDB_sP16_pwmdp_u0__F1_REG CYREG_B1_UDB04_F1
#define PWM_1_PWMUDB_sP16_pwmdp_u1__16BIT_A0_REG CYREG_B1_UDB05_06_A0
#define PWM_1_PWMUDB_sP16_pwmdp_u1__16BIT_A1_REG CYREG_B1_UDB05_06_A1
#define PWM_1_PWMUDB_sP16_pwmdp_u1__16BIT_D0_REG CYREG_B1_UDB05_06_D0
#define PWM_1_PWMUDB_sP16_pwmdp_u1__16BIT_D1_REG CYREG_B1_UDB05_06_D1
#define PWM_1_PWMUDB_sP16_pwmdp_u1__16BIT_DP_AUX_CTL_REG CYREG_B1_UDB05_06_ACTL
#define PWM_1_PWMUDB_sP16_pwmdp_u1__16BIT_F0_REG CYREG_B1_UDB05_06_F0
#define PWM_1_PWMUDB_sP16_pwmdp_u1__16BIT_F1_REG CYREG_B1_UDB05_06_F1
#define PWM_1_PWMUDB_sP16_pwmdp_u1__A0_A1_REG CYREG_B1_UDB05_A0_A1
#define PWM_1_PWMUDB_sP16_pwmdp_u1__A0_REG CYREG_B1_UDB05_A0
#define PWM_1_PWMUDB_sP16_pwmdp_u1__A1_REG CYREG_B1_UDB05_A1
#define PWM_1_PWMUDB_sP16_pwmdp_u1__D0_D1_REG CYREG_B1_UDB05_D0_D1
#define PWM_1_PWMUDB_sP16_pwmdp_u1__D0_REG CYREG_B1_UDB05_D0
#define PWM_1_PWMUDB_sP16_pwmdp_u1__D1_REG CYREG_B1_UDB05_D1
#define PWM_1_PWMUDB_sP16_pwmdp_u1__DP_AUX_CTL_REG CYREG_B1_UDB05_ACTL
#define PWM_1_PWMUDB_sP16_pwmdp_u1__F0_F1_REG CYREG_B1_UDB05_F0_F1
#define PWM_1_PWMUDB_sP16_pwmdp_u1__F0_REG CYREG_B1_UDB05_F0
#define PWM_1_PWMUDB_sP16_pwmdp_u1__F1_REG CYREG_B1_UDB05_F1
#define PWM_1_PWMUDB_sP16_pwmdp_u1__MSK_DP_AUX_CTL_REG CYREG_B1_UDB05_MSK_ACTL
#define PWM_1_PWMUDB_sP16_pwmdp_u1__PER_DP_AUX_CTL_REG CYREG_B1_UDB05_MSK_ACTL

/* Pin_1 */
#define Pin_1__0__INTTYPE CYREG_PICU3_INTTYPE1
#define Pin_1__0__MASK 0x02u
#define Pin_1__0__PC CYREG_PRT3_PC1
#define Pin_1__0__PORT 3u
#define Pin_1__0__SHIFT 1u
#define Pin_1__AG CYREG_PRT3_AG
#define Pin_1__AMUX CYREG_PRT3_AMUX
#define Pin_1__BIE CYREG_PRT3_BIE
#define Pin_1__BIT_MASK CYREG_PRT3_BIT_MASK
#define Pin_1__BYP CYREG_PRT3_BYP
#define Pin_1__CTL CYREG_PRT3_CTL
#define Pin_1__DM0 CYREG_PRT3_DM0
#define Pin_1__DM1 CYREG_PRT3_DM1
#define Pin_1__DM2 CYREG_PRT3_DM2
#define Pin_1__DR CYREG_PRT3_DR
#define Pin_1__INP_DIS CYREG_PRT3_INP_DIS
#define Pin_1__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU3_BASE
#define Pin_1__LCD_COM_SEG CYREG_PRT3_LCD_COM_SEG
#define Pin_1__LCD_EN CYREG_PRT3_LCD_EN
#define Pin_1__MASK 0x02u
#define Pin_1__PORT 3u
#define Pin_1__PRT CYREG_PRT3_PRT
#define Pin_1__PRTDSI__CAPS_SEL CYREG_PRT3_CAPS_SEL
#define Pin_1__PRTDSI__DBL_SYNC_IN CYREG_PRT3_DBL_SYNC_IN
#define Pin_1__PRTDSI__OE_SEL0 CYREG_PRT3_OE_SEL0
#define Pin_1__PRTDSI__OE_SEL1 CYREG_PRT3_OE_SEL1
#define Pin_1__PRTDSI__OUT_SEL0 CYREG_PRT3_OUT_SEL0
#define Pin_1__PRTDSI__OUT_SEL1 CYREG_PRT3_OUT_SEL1
#define Pin_1__PRTDSI__SYNC_OUT CYREG_PRT3_SYNC_OUT
#define Pin_1__PS CYREG_PRT3_PS
#define Pin_1__SHIFT 1u
#define Pin_1__SLW CYREG_PRT3_SLW

/* motor */
#define motor__0__INTTYPE CYREG_PICU3_INTTYPE0
#define motor__0__MASK 0x01u
#define motor__0__PC CYREG_PRT3_PC0
#define motor__0__PORT 3u
#define motor__0__SHIFT 0u
#define motor__AG CYREG_PRT3_AG
#define motor__AMUX CYREG_PRT3_AMUX
#define motor__BIE CYREG_PRT3_BIE
#define motor__BIT_MASK CYREG_PRT3_BIT_MASK
#define motor__BYP CYREG_PRT3_BYP
#define motor__CTL CYREG_PRT3_CTL
#define motor__DM0 CYREG_PRT3_DM0
#define motor__DM1 CYREG_PRT3_DM1
#define motor__DM2 CYREG_PRT3_DM2
#define motor__DR CYREG_PRT3_DR
#define motor__INP_DIS CYREG_PRT3_INP_DIS
#define motor__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU3_BASE
#define motor__LCD_COM_SEG CYREG_PRT3_LCD_COM_SEG
#define motor__LCD_EN CYREG_PRT3_LCD_EN
#define motor__MASK 0x01u
#define motor__PORT 3u
#define motor__PRT CYREG_PRT3_PRT
#define motor__PRTDSI__CAPS_SEL CYREG_PRT3_CAPS_SEL
#define motor__PRTDSI__DBL_SYNC_IN CYREG_PRT3_DBL_SYNC_IN
#define motor__PRTDSI__OE_SEL0 CYREG_PRT3_OE_SEL0
#define motor__PRTDSI__OE_SEL1 CYREG_PRT3_OE_SEL1
#define motor__PRTDSI__OUT_SEL0 CYREG_PRT3_OUT_SEL0
#define motor__PRTDSI__OUT_SEL1 CYREG_PRT3_OUT_SEL1
#define motor__PRTDSI__SYNC_OUT CYREG_PRT3_SYNC_OUT
#define motor__PS CYREG_PRT3_PS
#define motor__SHIFT 0u
#define motor__SLW CYREG_PRT3_SLW

/* Clock_1 */
#define Clock_1__CFG0 CYREG_CLKDIST_DCFG0_CFG0
#define Clock_1__CFG1 CYREG_CLKDIST_DCFG0_CFG1
#define Clock_1__CFG2 CYREG_CLKDIST_DCFG0_CFG2
#define Clock_1__CFG2_SRC_SEL_MASK 0x07u
#define Clock_1__INDEX 0x00u
#define Clock_1__PM_ACT_CFG CYREG_PM_ACT_CFG2
#define Clock_1__PM_ACT_MSK 0x01u
#define Clock_1__PM_STBY_CFG CYREG_PM_STBY_CFG2
#define Clock_1__PM_STBY_MSK 0x01u

/* Clock_2 */
#define Clock_2__CFG0 CYREG_CLKDIST_DCFG1_CFG0
#define Clock_2__CFG1 CYREG_CLKDIST_DCFG1_CFG1
#define Clock_2__CFG2 CYREG_CLKDIST_DCFG1_CFG2
#define Clock_2__CFG2_SRC_SEL_MASK 0x07u
#define Clock_2__INDEX 0x01u
#define Clock_2__PM_ACT_CFG CYREG_PM_ACT_CFG2
#define Clock_2__PM_ACT_MSK 0x02u
#define Clock_2__PM_STBY_CFG CYREG_PM_STBY_CFG2
#define Clock_2__PM_STBY_MSK 0x02u

/* Miscellaneous */
#define BCLK__BUS_CLK__HZ 24000000U
#define BCLK__BUS_CLK__KHZ 24000U
#define BCLK__BUS_CLK__MHZ 24U
#define CY_PROJECT_NAME "Design01"
#define CY_VERSION "PSoC Creator  4.4"
#define CYDEV_CHIP_DIE_LEOPARD 1u
#define CYDEV_CHIP_DIE_PSOC4A 26u
#define CYDEV_CHIP_DIE_PSOC5LP 2u
#define CYDEV_CHIP_DIE_PSOC5TM 3u
#define CYDEV_CHIP_DIE_TMA4 4u
#define CYDEV_CHIP_DIE_UNKNOWN 0u
#define CYDEV_CHIP_FAMILY_FM0P 5u
#define CYDEV_CHIP_FAMILY_FM3 6u
#define CYDEV_CHIP_FAMILY_FM4 7u
#define CYDEV_CHIP_FAMILY_PSOC3 1u
#define CYDEV_CHIP_FAMILY_PSOC4 2u
#define CYDEV_CHIP_FAMILY_PSOC5 3u
#define CYDEV_CHIP_FAMILY_PSOC6 4u
#define CYDEV_CHIP_FAMILY_UNKNOWN 0u
#define CYDEV_CHIP_FAMILY_USED CYDEV_CHIP_FAMILY_PSOC5
#define CYDEV_CHIP_JTAG_ID 0x2E161069u
#define CYDEV_CHIP_MEMBER_3A 1u
#define CYDEV_CHIP_MEMBER_4A 26u
#define CYDEV_CHIP_MEMBER_4AA 25u
#define CYDEV_CHIP_MEMBER_4AB 30u
#define CYDEV_CHIP_MEMBER_4AC 14u
#define CYDEV_CHIP_MEMBER_4AD 15u
#define CYDEV_CHIP_MEMBER_4AE 16u
#define CYDEV_CHIP_MEMBER_4D 20u
#define CYDEV_CHIP_MEMBER_4E 6u
#define CYDEV_CHIP_MEMBER_4F 27u
#define CYDEV_CHIP_MEMBER_4G 4u
#define CYDEV_CHIP_MEMBER_4H 24u
#define CYDEV_CHIP_MEMBER_4I 32u
#define CYDEV_CHIP_MEMBER_4J 21u
#define CYDEV_CHIP_MEMBER_4K 22u
#define CYDEV_CHIP_MEMBER_4L 31u
#define CYDEV_CHIP_MEMBER_4M 29u
#define CYDEV_CHIP_MEMBER_4N 11u
#define CYDEV_CHIP_MEMBER_4O 8u
#define CYDEV_CHIP_MEMBER_4P 28u
#define CYDEV_CHIP_MEMBER_4Q 17u
#define CYDEV_CHIP_MEMBER_4R 9u
#define CYDEV_CHIP_MEMBER_4S 12u
#define CYDEV_CHIP_MEMBER_4T 10u
#define CYDEV_CHIP_MEMBER_4U 5u
#define CYDEV_CHIP_MEMBER_4V 23u
#define CYDEV_CHIP_MEMBER_4W 13u
#define CYDEV_CHIP_MEMBER_4X 7u
#define CYDEV_CHIP_MEMBER_4Y 18u
#define CYDEV_CHIP_MEMBER_4Z 19u
#define CYDEV_CHIP_MEMBER_5A 3u
#define CYDEV_CHIP_MEMBER_5B 2u
#define CYDEV_CHIP_MEMBER_6A 33u
#define CYDEV_CHIP_MEMBER_FM3 37u
#define CYDEV_CHIP_MEMBER_FM4 38u
#define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE1 34u
#define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE2 35u
#define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE3 36u
#define CYDEV_CHIP_MEMBER_UNKNOWN 0u
#define CYDEV_CHIP_MEMBER_USED CYDEV_CHIP_MEMBER_5B
#define CYDEV_CHIP_DIE_EXPECT CYDEV_CHIP_MEMBER_USED
#define CYDEV_CHIP_DIE_ACTUAL CYDEV_CHIP_DIE_EXPECT
#define CYDEV_CHIP_REV_LEOPARD_ES1 0u
#define CYDEV_CHIP_REV_LEOPARD_ES2 1u
#define CYDEV_CHIP_REV_LEOPARD_ES3 3u
#define CYDEV_CHIP_REV_LEOPARD_PRODUCTION 3u
#define CYDEV_CHIP_REV_PSOC4A_ES0 17u
#define CYDEV_CHIP_REV_PSOC4A_PRODUCTION 17u
#define CYDEV_CHIP_REV_PSOC5LP_ES0 0u
#define CYDEV_CHIP_REV_PSOC5LP_PRODUCTION 0u
#define CYDEV_CHIP_REV_PSOC5TM_ES0 0u
#define CYDEV_CHIP_REV_PSOC5TM_ES1 1u
#define CYDEV_CHIP_REV_PSOC5TM_PRODUCTION 1u
#define CYDEV_CHIP_REV_TMA4_ES 17u
#define CYDEV_CHIP_REV_TMA4_ES2 33u
#define CYDEV_CHIP_REV_TMA4_PRODUCTION 17u
#define CYDEV_CHIP_REVISION_3A_ES1 0u
#define CYDEV_CHIP_REVISION_3A_ES2 1u
#define CYDEV_CHIP_REVISION_3A_ES3 3u
#define CYDEV_CHIP_REVISION_3A_PRODUCTION 3u
#define CYDEV_CHIP_REVISION_4A_ES0 17u
#define CYDEV_CHIP_REVISION_4A_PRODUCTION 17u
#define CYDEV_CHIP_REVISION_4AA_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4AB_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4AC_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4AD_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4AE_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4D_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4E_CCG2_NO_USBPD 0u
#define CYDEV_CHIP_REVISION_4E_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4F_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4F_PRODUCTION_256DMA 0u
#define CYDEV_CHIP_REVISION_4F_PRODUCTION_256K 0u
#define CYDEV_CHIP_REVISION_4G_ES 17u
#define CYDEV_CHIP_REVISION_4G_ES2 33u
#define CYDEV_CHIP_REVISION_4G_PRODUCTION 17u
#define CYDEV_CHIP_REVISION_4H_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4I_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4J_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4K_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4L_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4M_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4N_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4O_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4P_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4Q_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4R_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4S_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4T_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4U_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4V_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4W_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4X_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4Y_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4Z_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_5A_ES0 0u
#define CYDEV_CHIP_REVISION_5A_ES1 1u
#define CYDEV_CHIP_REVISION_5A_PRODUCTION 1u
#define CYDEV_CHIP_REVISION_5B_ES0 0u
#define CYDEV_CHIP_REVISION_5B_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_6A_ES 17u
#define CYDEV_CHIP_REVISION_6A_NO_UDB 33u
#define CYDEV_CHIP_REVISION_6A_PRODUCTION 33u
#define CYDEV_CHIP_REVISION_FM3_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_FM4_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE1_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE2_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE3_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_USED CYDEV_CHIP_REVISION_5B_PRODUCTION
#define CYDEV_CHIP_REV_EXPECT CYDEV_CHIP_REVISION_USED
#define CYDEV_CONFIG_FASTBOOT_ENABLED 1
#define CYDEV_CONFIG_UNUSED_IO_AllowButWarn 0
#define CYDEV_CONFIG_UNUSED_IO CYDEV_CONFIG_UNUSED_IO_AllowButWarn
#define CYDEV_CONFIG_UNUSED_IO_AllowWithInfo 1
#define CYDEV_CONFIG_UNUSED_IO_Disallowed 2
#define CYDEV_CONFIGURATION_COMPRESSED 1
#define CYDEV_CONFIGURATION_DMA 0
#define CYDEV_CONFIGURATION_ECC 1
#define CYDEV_CONFIGURATION_IMOENABLED CYDEV_CONFIG_FASTBOOT_ENABLED
#define CYDEV_CONFIGURATION_MODE_COMPRESSED 0
#define CYDEV_CONFIGURATION_MODE CYDEV_CONFIGURATION_MODE_COMPRESSED
#define CYDEV_CONFIGURATION_MODE_DMA 2
#define CYDEV_CONFIGURATION_MODE_UNCOMPRESSED 1
#define CYDEV_DEBUG_ENABLE_MASK 0x20u
#define CYDEV_DEBUG_ENABLE_REGISTER CYREG_MLOGIC_DEBUG
#define CYDEV_DEBUGGING_DPS_Disable 3
#define CYDEV_DEBUGGING_DPS_JTAG_4 1
#define CYDEV_DEBUGGING_DPS_JTAG_5 0
#define CYDEV_DEBUGGING_DPS_SWD 2
#define CYDEV_DEBUGGING_DPS_SWD_SWV 6
#define CYDEV_DEBUGGING_DPS CYDEV_DEBUGGING_DPS_SWD_SWV
#define CYDEV_DEBUGGING_ENABLE 1
#define CYDEV_DEBUGGING_XRES 0
#define CYDEV_DMA_CHANNELS_AVAILABLE 24u
#define CYDEV_ECC_ENABLE 0
#define CYDEV_HEAP_SIZE 0x80
#define CYDEV_INSTRUCT_CACHE_ENABLED 1
#define CYDEV_INTR_RISING 0x00000001u
#define CYDEV_IS_EXPORTING_CODE 0
#define CYDEV_IS_IMPORTING_CODE 0
#define CYDEV_PROJ_TYPE 0
#define CYDEV_PROJ_TYPE_BOOTLOADER 1
#define CYDEV_PROJ_TYPE_LAUNCHER 5
#define CYDEV_PROJ_TYPE_LOADABLE 2
#define CYDEV_PROJ_TYPE_LOADABLEANDBOOTLOADER 4
#define CYDEV_PROJ_TYPE_MULTIAPPBOOTLOADER 3
#define CYDEV_PROJ_TYPE_STANDARD 0
#define CYDEV_PROTECTION_ENABLE 0
#define CYDEV_STACK_SIZE 0x0800
#define CYDEV_USE_BUNDLED_CMSIS 1
#define CYDEV_VARIABLE_VDDA 0
#define CYDEV_VDDA 5.0
#define CYDEV_VDDA_MV 5000
#define CYDEV_VDDD 5.0
#define CYDEV_VDDD_MV 5000
#define CYDEV_VDDIO0 5.0
#define CYDEV_VDDIO0_MV 5000
#define CYDEV_VDDIO1 5.0
#define CYDEV_VDDIO1_MV 5000
#define CYDEV_VDDIO2 5.0
#define CYDEV_VDDIO2_MV 5000
#define CYDEV_VDDIO3 5.0
#define CYDEV_VDDIO3_MV 5000
#define CYDEV_VIO0 5.0
#define CYDEV_VIO0_MV 5000
#define CYDEV_VIO1 5.0
#define CYDEV_VIO1_MV 5000
#define CYDEV_VIO2 5.0
#define CYDEV_VIO2_MV 5000
#define CYDEV_VIO3 5.0
#define CYDEV_VIO3_MV 5000
#define CYIPBLOCK_ARM_CM3_VERSION 0
#define CYIPBLOCK_P3_ANAIF_VERSION 0
#define CYIPBLOCK_P3_CAN_VERSION 0
#define CYIPBLOCK_P3_CAPSENSE_VERSION 0
#define CYIPBLOCK_P3_COMP_VERSION 0
#define CYIPBLOCK_P3_DECIMATOR_VERSION 0
#define CYIPBLOCK_P3_DFB_VERSION 0
#define CYIPBLOCK_P3_DMA_VERSION 0
#define CYIPBLOCK_P3_DRQ_VERSION 0
#define CYIPBLOCK_P3_DSM_VERSION 0
#define CYIPBLOCK_P3_EMIF_VERSION 0
#define CYIPBLOCK_P3_I2C_VERSION 0
#define CYIPBLOCK_P3_LCD_VERSION 0
#define CYIPBLOCK_P3_LPF_VERSION 0
#define CYIPBLOCK_P3_OPAMP_VERSION 0
#define CYIPBLOCK_P3_PM_VERSION 0
#define CYIPBLOCK_P3_SCCT_VERSION 0
#define CYIPBLOCK_P3_TIMER_VERSION 0
#define CYIPBLOCK_P3_USB_VERSION 0
#define CYIPBLOCK_P3_VIDAC_VERSION 0
#define CYIPBLOCK_P3_VREF_VERSION 0
#define CYIPBLOCK_S8_GPIO_VERSION 0
#define CYIPBLOCK_S8_IRQ_VERSION 0
#define CYIPBLOCK_S8_SAR_VERSION 0
#define CYIPBLOCK_S8_SIO_VERSION 0
#define CYIPBLOCK_S8_UDB_VERSION 0
#define DMA_CHANNELS_USED__MASK0 0x00000000u
#define CYDEV_BOOTLOADER_ENABLE 0

#endif /* INCLUDED_CYFITTER_H */
