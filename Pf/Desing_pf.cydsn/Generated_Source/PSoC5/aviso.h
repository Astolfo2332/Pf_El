/*******************************************************************************
* File Name: aviso.h  
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

#if !defined(CY_PINS_aviso_H) /* Pins aviso_H */
#define CY_PINS_aviso_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "aviso_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 aviso__PORT == 15 && ((aviso__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    aviso_Write(uint8 value);
void    aviso_SetDriveMode(uint8 mode);
uint8   aviso_ReadDataReg(void);
uint8   aviso_Read(void);
void    aviso_SetInterruptMode(uint16 position, uint16 mode);
uint8   aviso_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the aviso_SetDriveMode() function.
     *  @{
     */
        #define aviso_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define aviso_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define aviso_DM_RES_UP          PIN_DM_RES_UP
        #define aviso_DM_RES_DWN         PIN_DM_RES_DWN
        #define aviso_DM_OD_LO           PIN_DM_OD_LO
        #define aviso_DM_OD_HI           PIN_DM_OD_HI
        #define aviso_DM_STRONG          PIN_DM_STRONG
        #define aviso_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define aviso_MASK               aviso__MASK
#define aviso_SHIFT              aviso__SHIFT
#define aviso_WIDTH              5u

/* Interrupt constants */
#if defined(aviso__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in aviso_SetInterruptMode() function.
     *  @{
     */
        #define aviso_INTR_NONE      (uint16)(0x0000u)
        #define aviso_INTR_RISING    (uint16)(0x0001u)
        #define aviso_INTR_FALLING   (uint16)(0x0002u)
        #define aviso_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define aviso_INTR_MASK      (0x01u) 
#endif /* (aviso__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define aviso_PS                     (* (reg8 *) aviso__PS)
/* Data Register */
#define aviso_DR                     (* (reg8 *) aviso__DR)
/* Port Number */
#define aviso_PRT_NUM                (* (reg8 *) aviso__PRT) 
/* Connect to Analog Globals */                                                  
#define aviso_AG                     (* (reg8 *) aviso__AG)                       
/* Analog MUX bux enable */
#define aviso_AMUX                   (* (reg8 *) aviso__AMUX) 
/* Bidirectional Enable */                                                        
#define aviso_BIE                    (* (reg8 *) aviso__BIE)
/* Bit-mask for Aliased Register Access */
#define aviso_BIT_MASK               (* (reg8 *) aviso__BIT_MASK)
/* Bypass Enable */
#define aviso_BYP                    (* (reg8 *) aviso__BYP)
/* Port wide control signals */                                                   
#define aviso_CTL                    (* (reg8 *) aviso__CTL)
/* Drive Modes */
#define aviso_DM0                    (* (reg8 *) aviso__DM0) 
#define aviso_DM1                    (* (reg8 *) aviso__DM1)
#define aviso_DM2                    (* (reg8 *) aviso__DM2) 
/* Input Buffer Disable Override */
#define aviso_INP_DIS                (* (reg8 *) aviso__INP_DIS)
/* LCD Common or Segment Drive */
#define aviso_LCD_COM_SEG            (* (reg8 *) aviso__LCD_COM_SEG)
/* Enable Segment LCD */
#define aviso_LCD_EN                 (* (reg8 *) aviso__LCD_EN)
/* Slew Rate Control */
#define aviso_SLW                    (* (reg8 *) aviso__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define aviso_PRTDSI__CAPS_SEL       (* (reg8 *) aviso__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define aviso_PRTDSI__DBL_SYNC_IN    (* (reg8 *) aviso__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define aviso_PRTDSI__OE_SEL0        (* (reg8 *) aviso__PRTDSI__OE_SEL0) 
#define aviso_PRTDSI__OE_SEL1        (* (reg8 *) aviso__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define aviso_PRTDSI__OUT_SEL0       (* (reg8 *) aviso__PRTDSI__OUT_SEL0) 
#define aviso_PRTDSI__OUT_SEL1       (* (reg8 *) aviso__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define aviso_PRTDSI__SYNC_OUT       (* (reg8 *) aviso__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(aviso__SIO_CFG)
    #define aviso_SIO_HYST_EN        (* (reg8 *) aviso__SIO_HYST_EN)
    #define aviso_SIO_REG_HIFREQ     (* (reg8 *) aviso__SIO_REG_HIFREQ)
    #define aviso_SIO_CFG            (* (reg8 *) aviso__SIO_CFG)
    #define aviso_SIO_DIFF           (* (reg8 *) aviso__SIO_DIFF)
#endif /* (aviso__SIO_CFG) */

/* Interrupt Registers */
#if defined(aviso__INTSTAT)
    #define aviso_INTSTAT            (* (reg8 *) aviso__INTSTAT)
    #define aviso_SNAP               (* (reg8 *) aviso__SNAP)
    
	#define aviso_0_INTTYPE_REG 		(* (reg8 *) aviso__0__INTTYPE)
	#define aviso_1_INTTYPE_REG 		(* (reg8 *) aviso__1__INTTYPE)
	#define aviso_2_INTTYPE_REG 		(* (reg8 *) aviso__2__INTTYPE)
	#define aviso_3_INTTYPE_REG 		(* (reg8 *) aviso__3__INTTYPE)
	#define aviso_4_INTTYPE_REG 		(* (reg8 *) aviso__4__INTTYPE)
#endif /* (aviso__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_aviso_H */


/* [] END OF FILE */
