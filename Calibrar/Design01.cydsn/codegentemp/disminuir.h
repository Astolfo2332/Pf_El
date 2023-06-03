/*******************************************************************************
* File Name: disminuir.h  
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

#if !defined(CY_PINS_disminuir_H) /* Pins disminuir_H */
#define CY_PINS_disminuir_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "disminuir_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 disminuir__PORT == 15 && ((disminuir__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    disminuir_Write(uint8 value);
void    disminuir_SetDriveMode(uint8 mode);
uint8   disminuir_ReadDataReg(void);
uint8   disminuir_Read(void);
void    disminuir_SetInterruptMode(uint16 position, uint16 mode);
uint8   disminuir_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the disminuir_SetDriveMode() function.
     *  @{
     */
        #define disminuir_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define disminuir_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define disminuir_DM_RES_UP          PIN_DM_RES_UP
        #define disminuir_DM_RES_DWN         PIN_DM_RES_DWN
        #define disminuir_DM_OD_LO           PIN_DM_OD_LO
        #define disminuir_DM_OD_HI           PIN_DM_OD_HI
        #define disminuir_DM_STRONG          PIN_DM_STRONG
        #define disminuir_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define disminuir_MASK               disminuir__MASK
#define disminuir_SHIFT              disminuir__SHIFT
#define disminuir_WIDTH              1u

/* Interrupt constants */
#if defined(disminuir__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in disminuir_SetInterruptMode() function.
     *  @{
     */
        #define disminuir_INTR_NONE      (uint16)(0x0000u)
        #define disminuir_INTR_RISING    (uint16)(0x0001u)
        #define disminuir_INTR_FALLING   (uint16)(0x0002u)
        #define disminuir_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define disminuir_INTR_MASK      (0x01u) 
#endif /* (disminuir__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define disminuir_PS                     (* (reg8 *) disminuir__PS)
/* Data Register */
#define disminuir_DR                     (* (reg8 *) disminuir__DR)
/* Port Number */
#define disminuir_PRT_NUM                (* (reg8 *) disminuir__PRT) 
/* Connect to Analog Globals */                                                  
#define disminuir_AG                     (* (reg8 *) disminuir__AG)                       
/* Analog MUX bux enable */
#define disminuir_AMUX                   (* (reg8 *) disminuir__AMUX) 
/* Bidirectional Enable */                                                        
#define disminuir_BIE                    (* (reg8 *) disminuir__BIE)
/* Bit-mask for Aliased Register Access */
#define disminuir_BIT_MASK               (* (reg8 *) disminuir__BIT_MASK)
/* Bypass Enable */
#define disminuir_BYP                    (* (reg8 *) disminuir__BYP)
/* Port wide control signals */                                                   
#define disminuir_CTL                    (* (reg8 *) disminuir__CTL)
/* Drive Modes */
#define disminuir_DM0                    (* (reg8 *) disminuir__DM0) 
#define disminuir_DM1                    (* (reg8 *) disminuir__DM1)
#define disminuir_DM2                    (* (reg8 *) disminuir__DM2) 
/* Input Buffer Disable Override */
#define disminuir_INP_DIS                (* (reg8 *) disminuir__INP_DIS)
/* LCD Common or Segment Drive */
#define disminuir_LCD_COM_SEG            (* (reg8 *) disminuir__LCD_COM_SEG)
/* Enable Segment LCD */
#define disminuir_LCD_EN                 (* (reg8 *) disminuir__LCD_EN)
/* Slew Rate Control */
#define disminuir_SLW                    (* (reg8 *) disminuir__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define disminuir_PRTDSI__CAPS_SEL       (* (reg8 *) disminuir__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define disminuir_PRTDSI__DBL_SYNC_IN    (* (reg8 *) disminuir__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define disminuir_PRTDSI__OE_SEL0        (* (reg8 *) disminuir__PRTDSI__OE_SEL0) 
#define disminuir_PRTDSI__OE_SEL1        (* (reg8 *) disminuir__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define disminuir_PRTDSI__OUT_SEL0       (* (reg8 *) disminuir__PRTDSI__OUT_SEL0) 
#define disminuir_PRTDSI__OUT_SEL1       (* (reg8 *) disminuir__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define disminuir_PRTDSI__SYNC_OUT       (* (reg8 *) disminuir__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(disminuir__SIO_CFG)
    #define disminuir_SIO_HYST_EN        (* (reg8 *) disminuir__SIO_HYST_EN)
    #define disminuir_SIO_REG_HIFREQ     (* (reg8 *) disminuir__SIO_REG_HIFREQ)
    #define disminuir_SIO_CFG            (* (reg8 *) disminuir__SIO_CFG)
    #define disminuir_SIO_DIFF           (* (reg8 *) disminuir__SIO_DIFF)
#endif /* (disminuir__SIO_CFG) */

/* Interrupt Registers */
#if defined(disminuir__INTSTAT)
    #define disminuir_INTSTAT            (* (reg8 *) disminuir__INTSTAT)
    #define disminuir_SNAP               (* (reg8 *) disminuir__SNAP)
    
	#define disminuir_0_INTTYPE_REG 		(* (reg8 *) disminuir__0__INTTYPE)
#endif /* (disminuir__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_disminuir_H */


/* [] END OF FILE */
