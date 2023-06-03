/*******************************************************************************
* File Name: tilt.h  
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

#if !defined(CY_PINS_tilt_H) /* Pins tilt_H */
#define CY_PINS_tilt_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "tilt_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 tilt__PORT == 15 && ((tilt__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    tilt_Write(uint8 value);
void    tilt_SetDriveMode(uint8 mode);
uint8   tilt_ReadDataReg(void);
uint8   tilt_Read(void);
void    tilt_SetInterruptMode(uint16 position, uint16 mode);
uint8   tilt_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the tilt_SetDriveMode() function.
     *  @{
     */
        #define tilt_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define tilt_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define tilt_DM_RES_UP          PIN_DM_RES_UP
        #define tilt_DM_RES_DWN         PIN_DM_RES_DWN
        #define tilt_DM_OD_LO           PIN_DM_OD_LO
        #define tilt_DM_OD_HI           PIN_DM_OD_HI
        #define tilt_DM_STRONG          PIN_DM_STRONG
        #define tilt_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define tilt_MASK               tilt__MASK
#define tilt_SHIFT              tilt__SHIFT
#define tilt_WIDTH              1u

/* Interrupt constants */
#if defined(tilt__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in tilt_SetInterruptMode() function.
     *  @{
     */
        #define tilt_INTR_NONE      (uint16)(0x0000u)
        #define tilt_INTR_RISING    (uint16)(0x0001u)
        #define tilt_INTR_FALLING   (uint16)(0x0002u)
        #define tilt_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define tilt_INTR_MASK      (0x01u) 
#endif /* (tilt__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define tilt_PS                     (* (reg8 *) tilt__PS)
/* Data Register */
#define tilt_DR                     (* (reg8 *) tilt__DR)
/* Port Number */
#define tilt_PRT_NUM                (* (reg8 *) tilt__PRT) 
/* Connect to Analog Globals */                                                  
#define tilt_AG                     (* (reg8 *) tilt__AG)                       
/* Analog MUX bux enable */
#define tilt_AMUX                   (* (reg8 *) tilt__AMUX) 
/* Bidirectional Enable */                                                        
#define tilt_BIE                    (* (reg8 *) tilt__BIE)
/* Bit-mask for Aliased Register Access */
#define tilt_BIT_MASK               (* (reg8 *) tilt__BIT_MASK)
/* Bypass Enable */
#define tilt_BYP                    (* (reg8 *) tilt__BYP)
/* Port wide control signals */                                                   
#define tilt_CTL                    (* (reg8 *) tilt__CTL)
/* Drive Modes */
#define tilt_DM0                    (* (reg8 *) tilt__DM0) 
#define tilt_DM1                    (* (reg8 *) tilt__DM1)
#define tilt_DM2                    (* (reg8 *) tilt__DM2) 
/* Input Buffer Disable Override */
#define tilt_INP_DIS                (* (reg8 *) tilt__INP_DIS)
/* LCD Common or Segment Drive */
#define tilt_LCD_COM_SEG            (* (reg8 *) tilt__LCD_COM_SEG)
/* Enable Segment LCD */
#define tilt_LCD_EN                 (* (reg8 *) tilt__LCD_EN)
/* Slew Rate Control */
#define tilt_SLW                    (* (reg8 *) tilt__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define tilt_PRTDSI__CAPS_SEL       (* (reg8 *) tilt__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define tilt_PRTDSI__DBL_SYNC_IN    (* (reg8 *) tilt__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define tilt_PRTDSI__OE_SEL0        (* (reg8 *) tilt__PRTDSI__OE_SEL0) 
#define tilt_PRTDSI__OE_SEL1        (* (reg8 *) tilt__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define tilt_PRTDSI__OUT_SEL0       (* (reg8 *) tilt__PRTDSI__OUT_SEL0) 
#define tilt_PRTDSI__OUT_SEL1       (* (reg8 *) tilt__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define tilt_PRTDSI__SYNC_OUT       (* (reg8 *) tilt__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(tilt__SIO_CFG)
    #define tilt_SIO_HYST_EN        (* (reg8 *) tilt__SIO_HYST_EN)
    #define tilt_SIO_REG_HIFREQ     (* (reg8 *) tilt__SIO_REG_HIFREQ)
    #define tilt_SIO_CFG            (* (reg8 *) tilt__SIO_CFG)
    #define tilt_SIO_DIFF           (* (reg8 *) tilt__SIO_DIFF)
#endif /* (tilt__SIO_CFG) */

/* Interrupt Registers */
#if defined(tilt__INTSTAT)
    #define tilt_INTSTAT            (* (reg8 *) tilt__INTSTAT)
    #define tilt_SNAP               (* (reg8 *) tilt__SNAP)
    
	#define tilt_0_INTTYPE_REG 		(* (reg8 *) tilt__0__INTTYPE)
#endif /* (tilt__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_tilt_H */


/* [] END OF FILE */
