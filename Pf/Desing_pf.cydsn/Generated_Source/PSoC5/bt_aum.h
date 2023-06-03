/*******************************************************************************
* File Name: bt_aum.h  
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

#if !defined(CY_PINS_bt_aum_H) /* Pins bt_aum_H */
#define CY_PINS_bt_aum_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "bt_aum_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 bt_aum__PORT == 15 && ((bt_aum__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    bt_aum_Write(uint8 value);
void    bt_aum_SetDriveMode(uint8 mode);
uint8   bt_aum_ReadDataReg(void);
uint8   bt_aum_Read(void);
void    bt_aum_SetInterruptMode(uint16 position, uint16 mode);
uint8   bt_aum_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the bt_aum_SetDriveMode() function.
     *  @{
     */
        #define bt_aum_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define bt_aum_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define bt_aum_DM_RES_UP          PIN_DM_RES_UP
        #define bt_aum_DM_RES_DWN         PIN_DM_RES_DWN
        #define bt_aum_DM_OD_LO           PIN_DM_OD_LO
        #define bt_aum_DM_OD_HI           PIN_DM_OD_HI
        #define bt_aum_DM_STRONG          PIN_DM_STRONG
        #define bt_aum_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define bt_aum_MASK               bt_aum__MASK
#define bt_aum_SHIFT              bt_aum__SHIFT
#define bt_aum_WIDTH              1u

/* Interrupt constants */
#if defined(bt_aum__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in bt_aum_SetInterruptMode() function.
     *  @{
     */
        #define bt_aum_INTR_NONE      (uint16)(0x0000u)
        #define bt_aum_INTR_RISING    (uint16)(0x0001u)
        #define bt_aum_INTR_FALLING   (uint16)(0x0002u)
        #define bt_aum_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define bt_aum_INTR_MASK      (0x01u) 
#endif /* (bt_aum__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define bt_aum_PS                     (* (reg8 *) bt_aum__PS)
/* Data Register */
#define bt_aum_DR                     (* (reg8 *) bt_aum__DR)
/* Port Number */
#define bt_aum_PRT_NUM                (* (reg8 *) bt_aum__PRT) 
/* Connect to Analog Globals */                                                  
#define bt_aum_AG                     (* (reg8 *) bt_aum__AG)                       
/* Analog MUX bux enable */
#define bt_aum_AMUX                   (* (reg8 *) bt_aum__AMUX) 
/* Bidirectional Enable */                                                        
#define bt_aum_BIE                    (* (reg8 *) bt_aum__BIE)
/* Bit-mask for Aliased Register Access */
#define bt_aum_BIT_MASK               (* (reg8 *) bt_aum__BIT_MASK)
/* Bypass Enable */
#define bt_aum_BYP                    (* (reg8 *) bt_aum__BYP)
/* Port wide control signals */                                                   
#define bt_aum_CTL                    (* (reg8 *) bt_aum__CTL)
/* Drive Modes */
#define bt_aum_DM0                    (* (reg8 *) bt_aum__DM0) 
#define bt_aum_DM1                    (* (reg8 *) bt_aum__DM1)
#define bt_aum_DM2                    (* (reg8 *) bt_aum__DM2) 
/* Input Buffer Disable Override */
#define bt_aum_INP_DIS                (* (reg8 *) bt_aum__INP_DIS)
/* LCD Common or Segment Drive */
#define bt_aum_LCD_COM_SEG            (* (reg8 *) bt_aum__LCD_COM_SEG)
/* Enable Segment LCD */
#define bt_aum_LCD_EN                 (* (reg8 *) bt_aum__LCD_EN)
/* Slew Rate Control */
#define bt_aum_SLW                    (* (reg8 *) bt_aum__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define bt_aum_PRTDSI__CAPS_SEL       (* (reg8 *) bt_aum__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define bt_aum_PRTDSI__DBL_SYNC_IN    (* (reg8 *) bt_aum__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define bt_aum_PRTDSI__OE_SEL0        (* (reg8 *) bt_aum__PRTDSI__OE_SEL0) 
#define bt_aum_PRTDSI__OE_SEL1        (* (reg8 *) bt_aum__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define bt_aum_PRTDSI__OUT_SEL0       (* (reg8 *) bt_aum__PRTDSI__OUT_SEL0) 
#define bt_aum_PRTDSI__OUT_SEL1       (* (reg8 *) bt_aum__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define bt_aum_PRTDSI__SYNC_OUT       (* (reg8 *) bt_aum__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(bt_aum__SIO_CFG)
    #define bt_aum_SIO_HYST_EN        (* (reg8 *) bt_aum__SIO_HYST_EN)
    #define bt_aum_SIO_REG_HIFREQ     (* (reg8 *) bt_aum__SIO_REG_HIFREQ)
    #define bt_aum_SIO_CFG            (* (reg8 *) bt_aum__SIO_CFG)
    #define bt_aum_SIO_DIFF           (* (reg8 *) bt_aum__SIO_DIFF)
#endif /* (bt_aum__SIO_CFG) */

/* Interrupt Registers */
#if defined(bt_aum__INTSTAT)
    #define bt_aum_INTSTAT            (* (reg8 *) bt_aum__INTSTAT)
    #define bt_aum_SNAP               (* (reg8 *) bt_aum__SNAP)
    
	#define bt_aum_0_INTTYPE_REG 		(* (reg8 *) bt_aum__0__INTTYPE)
#endif /* (bt_aum__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_bt_aum_H */


/* [] END OF FILE */
