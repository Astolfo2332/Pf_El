/*******************************************************************************
* File Name: Linterna.h  
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

#if !defined(CY_PINS_Linterna_H) /* Pins Linterna_H */
#define CY_PINS_Linterna_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Linterna_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Linterna__PORT == 15 && ((Linterna__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Linterna_Write(uint8 value);
void    Linterna_SetDriveMode(uint8 mode);
uint8   Linterna_ReadDataReg(void);
uint8   Linterna_Read(void);
void    Linterna_SetInterruptMode(uint16 position, uint16 mode);
uint8   Linterna_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Linterna_SetDriveMode() function.
     *  @{
     */
        #define Linterna_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Linterna_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Linterna_DM_RES_UP          PIN_DM_RES_UP
        #define Linterna_DM_RES_DWN         PIN_DM_RES_DWN
        #define Linterna_DM_OD_LO           PIN_DM_OD_LO
        #define Linterna_DM_OD_HI           PIN_DM_OD_HI
        #define Linterna_DM_STRONG          PIN_DM_STRONG
        #define Linterna_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Linterna_MASK               Linterna__MASK
#define Linterna_SHIFT              Linterna__SHIFT
#define Linterna_WIDTH              1u

/* Interrupt constants */
#if defined(Linterna__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Linterna_SetInterruptMode() function.
     *  @{
     */
        #define Linterna_INTR_NONE      (uint16)(0x0000u)
        #define Linterna_INTR_RISING    (uint16)(0x0001u)
        #define Linterna_INTR_FALLING   (uint16)(0x0002u)
        #define Linterna_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Linterna_INTR_MASK      (0x01u) 
#endif /* (Linterna__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Linterna_PS                     (* (reg8 *) Linterna__PS)
/* Data Register */
#define Linterna_DR                     (* (reg8 *) Linterna__DR)
/* Port Number */
#define Linterna_PRT_NUM                (* (reg8 *) Linterna__PRT) 
/* Connect to Analog Globals */                                                  
#define Linterna_AG                     (* (reg8 *) Linterna__AG)                       
/* Analog MUX bux enable */
#define Linterna_AMUX                   (* (reg8 *) Linterna__AMUX) 
/* Bidirectional Enable */                                                        
#define Linterna_BIE                    (* (reg8 *) Linterna__BIE)
/* Bit-mask for Aliased Register Access */
#define Linterna_BIT_MASK               (* (reg8 *) Linterna__BIT_MASK)
/* Bypass Enable */
#define Linterna_BYP                    (* (reg8 *) Linterna__BYP)
/* Port wide control signals */                                                   
#define Linterna_CTL                    (* (reg8 *) Linterna__CTL)
/* Drive Modes */
#define Linterna_DM0                    (* (reg8 *) Linterna__DM0) 
#define Linterna_DM1                    (* (reg8 *) Linterna__DM1)
#define Linterna_DM2                    (* (reg8 *) Linterna__DM2) 
/* Input Buffer Disable Override */
#define Linterna_INP_DIS                (* (reg8 *) Linterna__INP_DIS)
/* LCD Common or Segment Drive */
#define Linterna_LCD_COM_SEG            (* (reg8 *) Linterna__LCD_COM_SEG)
/* Enable Segment LCD */
#define Linterna_LCD_EN                 (* (reg8 *) Linterna__LCD_EN)
/* Slew Rate Control */
#define Linterna_SLW                    (* (reg8 *) Linterna__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Linterna_PRTDSI__CAPS_SEL       (* (reg8 *) Linterna__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Linterna_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Linterna__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Linterna_PRTDSI__OE_SEL0        (* (reg8 *) Linterna__PRTDSI__OE_SEL0) 
#define Linterna_PRTDSI__OE_SEL1        (* (reg8 *) Linterna__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Linterna_PRTDSI__OUT_SEL0       (* (reg8 *) Linterna__PRTDSI__OUT_SEL0) 
#define Linterna_PRTDSI__OUT_SEL1       (* (reg8 *) Linterna__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Linterna_PRTDSI__SYNC_OUT       (* (reg8 *) Linterna__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Linterna__SIO_CFG)
    #define Linterna_SIO_HYST_EN        (* (reg8 *) Linterna__SIO_HYST_EN)
    #define Linterna_SIO_REG_HIFREQ     (* (reg8 *) Linterna__SIO_REG_HIFREQ)
    #define Linterna_SIO_CFG            (* (reg8 *) Linterna__SIO_CFG)
    #define Linterna_SIO_DIFF           (* (reg8 *) Linterna__SIO_DIFF)
#endif /* (Linterna__SIO_CFG) */

/* Interrupt Registers */
#if defined(Linterna__INTSTAT)
    #define Linterna_INTSTAT            (* (reg8 *) Linterna__INTSTAT)
    #define Linterna_SNAP               (* (reg8 *) Linterna__SNAP)
    
	#define Linterna_0_INTTYPE_REG 		(* (reg8 *) Linterna__0__INTTYPE)
#endif /* (Linterna__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Linterna_H */


/* [] END OF FILE */
