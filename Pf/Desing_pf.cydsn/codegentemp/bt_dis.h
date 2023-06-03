/*******************************************************************************
* File Name: bt_dis.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_bt_dis_H) /* Pins bt_dis_H */
#define CY_PINS_bt_dis_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "bt_dis_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 bt_dis__PORT == 15 && ((bt_dis__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    bt_dis_Write(uint8 value);
void    bt_dis_SetDriveMode(uint8 mode);
uint8   bt_dis_ReadDataReg(void);
uint8   bt_dis_Read(void);
void    bt_dis_SetInterruptMode(uint16 position, uint16 mode);
uint8   bt_dis_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the bt_dis_SetDriveMode() function.
     *  @{
     */
        #define bt_dis_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define bt_dis_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define bt_dis_DM_RES_UP          PIN_DM_RES_UP
        #define bt_dis_DM_RES_DWN         PIN_DM_RES_DWN
        #define bt_dis_DM_OD_LO           PIN_DM_OD_LO
        #define bt_dis_DM_OD_HI           PIN_DM_OD_HI
        #define bt_dis_DM_STRONG          PIN_DM_STRONG
        #define bt_dis_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define bt_dis_MASK               bt_dis__MASK
#define bt_dis_SHIFT              bt_dis__SHIFT
#define bt_dis_WIDTH              1u

/* Interrupt constants */
#if defined(bt_dis__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in bt_dis_SetInterruptMode() function.
     *  @{
     */
        #define bt_dis_INTR_NONE      (uint16)(0x0000u)
        #define bt_dis_INTR_RISING    (uint16)(0x0001u)
        #define bt_dis_INTR_FALLING   (uint16)(0x0002u)
        #define bt_dis_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define bt_dis_INTR_MASK      (0x01u) 
#endif /* (bt_dis__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define bt_dis_PS                     (* (reg8 *) bt_dis__PS)
/* Data Register */
#define bt_dis_DR                     (* (reg8 *) bt_dis__DR)
/* Port Number */
#define bt_dis_PRT_NUM                (* (reg8 *) bt_dis__PRT) 
/* Connect to Analog Globals */                                                  
#define bt_dis_AG                     (* (reg8 *) bt_dis__AG)                       
/* Analog MUX bux enable */
#define bt_dis_AMUX                   (* (reg8 *) bt_dis__AMUX) 
/* Bidirectional Enable */                                                        
#define bt_dis_BIE                    (* (reg8 *) bt_dis__BIE)
/* Bit-mask for Aliased Register Access */
#define bt_dis_BIT_MASK               (* (reg8 *) bt_dis__BIT_MASK)
/* Bypass Enable */
#define bt_dis_BYP                    (* (reg8 *) bt_dis__BYP)
/* Port wide control signals */                                                   
#define bt_dis_CTL                    (* (reg8 *) bt_dis__CTL)
/* Drive Modes */
#define bt_dis_DM0                    (* (reg8 *) bt_dis__DM0) 
#define bt_dis_DM1                    (* (reg8 *) bt_dis__DM1)
#define bt_dis_DM2                    (* (reg8 *) bt_dis__DM2) 
/* Input Buffer Disable Override */
#define bt_dis_INP_DIS                (* (reg8 *) bt_dis__INP_DIS)
/* LCD Common or Segment Drive */
#define bt_dis_LCD_COM_SEG            (* (reg8 *) bt_dis__LCD_COM_SEG)
/* Enable Segment LCD */
#define bt_dis_LCD_EN                 (* (reg8 *) bt_dis__LCD_EN)
/* Slew Rate Control */
#define bt_dis_SLW                    (* (reg8 *) bt_dis__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define bt_dis_PRTDSI__CAPS_SEL       (* (reg8 *) bt_dis__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define bt_dis_PRTDSI__DBL_SYNC_IN    (* (reg8 *) bt_dis__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define bt_dis_PRTDSI__OE_SEL0        (* (reg8 *) bt_dis__PRTDSI__OE_SEL0) 
#define bt_dis_PRTDSI__OE_SEL1        (* (reg8 *) bt_dis__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define bt_dis_PRTDSI__OUT_SEL0       (* (reg8 *) bt_dis__PRTDSI__OUT_SEL0) 
#define bt_dis_PRTDSI__OUT_SEL1       (* (reg8 *) bt_dis__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define bt_dis_PRTDSI__SYNC_OUT       (* (reg8 *) bt_dis__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(bt_dis__SIO_CFG)
    #define bt_dis_SIO_HYST_EN        (* (reg8 *) bt_dis__SIO_HYST_EN)
    #define bt_dis_SIO_REG_HIFREQ     (* (reg8 *) bt_dis__SIO_REG_HIFREQ)
    #define bt_dis_SIO_CFG            (* (reg8 *) bt_dis__SIO_CFG)
    #define bt_dis_SIO_DIFF           (* (reg8 *) bt_dis__SIO_DIFF)
#endif /* (bt_dis__SIO_CFG) */

/* Interrupt Registers */
#if defined(bt_dis__INTSTAT)
    #define bt_dis_INTSTAT            (* (reg8 *) bt_dis__INTSTAT)
    #define bt_dis_SNAP               (* (reg8 *) bt_dis__SNAP)
    
	#define bt_dis_0_INTTYPE_REG 		(* (reg8 *) bt_dis__0__INTTYPE)
#endif /* (bt_dis__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_bt_dis_H */


/* [] END OF FILE */
