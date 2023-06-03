/*******************************************************************************
* File Name: sui.h  
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

#if !defined(CY_PINS_sui_H) /* Pins sui_H */
#define CY_PINS_sui_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "sui_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 sui__PORT == 15 && ((sui__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    sui_Write(uint8 value);
void    sui_SetDriveMode(uint8 mode);
uint8   sui_ReadDataReg(void);
uint8   sui_Read(void);
void    sui_SetInterruptMode(uint16 position, uint16 mode);
uint8   sui_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the sui_SetDriveMode() function.
     *  @{
     */
        #define sui_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define sui_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define sui_DM_RES_UP          PIN_DM_RES_UP
        #define sui_DM_RES_DWN         PIN_DM_RES_DWN
        #define sui_DM_OD_LO           PIN_DM_OD_LO
        #define sui_DM_OD_HI           PIN_DM_OD_HI
        #define sui_DM_STRONG          PIN_DM_STRONG
        #define sui_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define sui_MASK               sui__MASK
#define sui_SHIFT              sui__SHIFT
#define sui_WIDTH              1u

/* Interrupt constants */
#if defined(sui__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in sui_SetInterruptMode() function.
     *  @{
     */
        #define sui_INTR_NONE      (uint16)(0x0000u)
        #define sui_INTR_RISING    (uint16)(0x0001u)
        #define sui_INTR_FALLING   (uint16)(0x0002u)
        #define sui_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define sui_INTR_MASK      (0x01u) 
#endif /* (sui__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define sui_PS                     (* (reg8 *) sui__PS)
/* Data Register */
#define sui_DR                     (* (reg8 *) sui__DR)
/* Port Number */
#define sui_PRT_NUM                (* (reg8 *) sui__PRT) 
/* Connect to Analog Globals */                                                  
#define sui_AG                     (* (reg8 *) sui__AG)                       
/* Analog MUX bux enable */
#define sui_AMUX                   (* (reg8 *) sui__AMUX) 
/* Bidirectional Enable */                                                        
#define sui_BIE                    (* (reg8 *) sui__BIE)
/* Bit-mask for Aliased Register Access */
#define sui_BIT_MASK               (* (reg8 *) sui__BIT_MASK)
/* Bypass Enable */
#define sui_BYP                    (* (reg8 *) sui__BYP)
/* Port wide control signals */                                                   
#define sui_CTL                    (* (reg8 *) sui__CTL)
/* Drive Modes */
#define sui_DM0                    (* (reg8 *) sui__DM0) 
#define sui_DM1                    (* (reg8 *) sui__DM1)
#define sui_DM2                    (* (reg8 *) sui__DM2) 
/* Input Buffer Disable Override */
#define sui_INP_DIS                (* (reg8 *) sui__INP_DIS)
/* LCD Common or Segment Drive */
#define sui_LCD_COM_SEG            (* (reg8 *) sui__LCD_COM_SEG)
/* Enable Segment LCD */
#define sui_LCD_EN                 (* (reg8 *) sui__LCD_EN)
/* Slew Rate Control */
#define sui_SLW                    (* (reg8 *) sui__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define sui_PRTDSI__CAPS_SEL       (* (reg8 *) sui__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define sui_PRTDSI__DBL_SYNC_IN    (* (reg8 *) sui__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define sui_PRTDSI__OE_SEL0        (* (reg8 *) sui__PRTDSI__OE_SEL0) 
#define sui_PRTDSI__OE_SEL1        (* (reg8 *) sui__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define sui_PRTDSI__OUT_SEL0       (* (reg8 *) sui__PRTDSI__OUT_SEL0) 
#define sui_PRTDSI__OUT_SEL1       (* (reg8 *) sui__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define sui_PRTDSI__SYNC_OUT       (* (reg8 *) sui__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(sui__SIO_CFG)
    #define sui_SIO_HYST_EN        (* (reg8 *) sui__SIO_HYST_EN)
    #define sui_SIO_REG_HIFREQ     (* (reg8 *) sui__SIO_REG_HIFREQ)
    #define sui_SIO_CFG            (* (reg8 *) sui__SIO_CFG)
    #define sui_SIO_DIFF           (* (reg8 *) sui__SIO_DIFF)
#endif /* (sui__SIO_CFG) */

/* Interrupt Registers */
#if defined(sui__INTSTAT)
    #define sui_INTSTAT            (* (reg8 *) sui__INTSTAT)
    #define sui_SNAP               (* (reg8 *) sui__SNAP)
    
	#define sui_0_INTTYPE_REG 		(* (reg8 *) sui__0__INTTYPE)
#endif /* (sui__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_sui_H */


/* [] END OF FILE */
