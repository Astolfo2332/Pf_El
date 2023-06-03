/*******************************************************************************
* File Name: tem.h  
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

#if !defined(CY_PINS_tem_H) /* Pins tem_H */
#define CY_PINS_tem_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "tem_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 tem__PORT == 15 && ((tem__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    tem_Write(uint8 value);
void    tem_SetDriveMode(uint8 mode);
uint8   tem_ReadDataReg(void);
uint8   tem_Read(void);
void    tem_SetInterruptMode(uint16 position, uint16 mode);
uint8   tem_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the tem_SetDriveMode() function.
     *  @{
     */
        #define tem_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define tem_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define tem_DM_RES_UP          PIN_DM_RES_UP
        #define tem_DM_RES_DWN         PIN_DM_RES_DWN
        #define tem_DM_OD_LO           PIN_DM_OD_LO
        #define tem_DM_OD_HI           PIN_DM_OD_HI
        #define tem_DM_STRONG          PIN_DM_STRONG
        #define tem_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define tem_MASK               tem__MASK
#define tem_SHIFT              tem__SHIFT
#define tem_WIDTH              1u

/* Interrupt constants */
#if defined(tem__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in tem_SetInterruptMode() function.
     *  @{
     */
        #define tem_INTR_NONE      (uint16)(0x0000u)
        #define tem_INTR_RISING    (uint16)(0x0001u)
        #define tem_INTR_FALLING   (uint16)(0x0002u)
        #define tem_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define tem_INTR_MASK      (0x01u) 
#endif /* (tem__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define tem_PS                     (* (reg8 *) tem__PS)
/* Data Register */
#define tem_DR                     (* (reg8 *) tem__DR)
/* Port Number */
#define tem_PRT_NUM                (* (reg8 *) tem__PRT) 
/* Connect to Analog Globals */                                                  
#define tem_AG                     (* (reg8 *) tem__AG)                       
/* Analog MUX bux enable */
#define tem_AMUX                   (* (reg8 *) tem__AMUX) 
/* Bidirectional Enable */                                                        
#define tem_BIE                    (* (reg8 *) tem__BIE)
/* Bit-mask for Aliased Register Access */
#define tem_BIT_MASK               (* (reg8 *) tem__BIT_MASK)
/* Bypass Enable */
#define tem_BYP                    (* (reg8 *) tem__BYP)
/* Port wide control signals */                                                   
#define tem_CTL                    (* (reg8 *) tem__CTL)
/* Drive Modes */
#define tem_DM0                    (* (reg8 *) tem__DM0) 
#define tem_DM1                    (* (reg8 *) tem__DM1)
#define tem_DM2                    (* (reg8 *) tem__DM2) 
/* Input Buffer Disable Override */
#define tem_INP_DIS                (* (reg8 *) tem__INP_DIS)
/* LCD Common or Segment Drive */
#define tem_LCD_COM_SEG            (* (reg8 *) tem__LCD_COM_SEG)
/* Enable Segment LCD */
#define tem_LCD_EN                 (* (reg8 *) tem__LCD_EN)
/* Slew Rate Control */
#define tem_SLW                    (* (reg8 *) tem__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define tem_PRTDSI__CAPS_SEL       (* (reg8 *) tem__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define tem_PRTDSI__DBL_SYNC_IN    (* (reg8 *) tem__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define tem_PRTDSI__OE_SEL0        (* (reg8 *) tem__PRTDSI__OE_SEL0) 
#define tem_PRTDSI__OE_SEL1        (* (reg8 *) tem__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define tem_PRTDSI__OUT_SEL0       (* (reg8 *) tem__PRTDSI__OUT_SEL0) 
#define tem_PRTDSI__OUT_SEL1       (* (reg8 *) tem__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define tem_PRTDSI__SYNC_OUT       (* (reg8 *) tem__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(tem__SIO_CFG)
    #define tem_SIO_HYST_EN        (* (reg8 *) tem__SIO_HYST_EN)
    #define tem_SIO_REG_HIFREQ     (* (reg8 *) tem__SIO_REG_HIFREQ)
    #define tem_SIO_CFG            (* (reg8 *) tem__SIO_CFG)
    #define tem_SIO_DIFF           (* (reg8 *) tem__SIO_DIFF)
#endif /* (tem__SIO_CFG) */

/* Interrupt Registers */
#if defined(tem__INTSTAT)
    #define tem_INTSTAT            (* (reg8 *) tem__INTSTAT)
    #define tem_SNAP               (* (reg8 *) tem__SNAP)
    
	#define tem_0_INTTYPE_REG 		(* (reg8 *) tem__0__INTTYPE)
#endif /* (tem__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_tem_H */


/* [] END OF FILE */
