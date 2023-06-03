/*******************************************************************************
* File Name: dism.h
* Version 1.70
*
*  Description:
*   Provides the function definitions for the Interrupt Controller.
*
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/
#if !defined(CY_ISR_dism_H)
#define CY_ISR_dism_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void dism_Start(void);
void dism_StartEx(cyisraddress address);
void dism_Stop(void);

CY_ISR_PROTO(dism_Interrupt);

void dism_SetVector(cyisraddress address);
cyisraddress dism_GetVector(void);

void dism_SetPriority(uint8 priority);
uint8 dism_GetPriority(void);

void dism_Enable(void);
uint8 dism_GetState(void);
void dism_Disable(void);

void dism_SetPending(void);
void dism_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the dism ISR. */
#define dism_INTC_VECTOR            ((reg32 *) dism__INTC_VECT)

/* Address of the dism ISR priority. */
#define dism_INTC_PRIOR             ((reg8 *) dism__INTC_PRIOR_REG)

/* Priority of the dism interrupt. */
#define dism_INTC_PRIOR_NUMBER      dism__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable dism interrupt. */
#define dism_INTC_SET_EN            ((reg32 *) dism__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the dism interrupt. */
#define dism_INTC_CLR_EN            ((reg32 *) dism__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the dism interrupt state to pending. */
#define dism_INTC_SET_PD            ((reg32 *) dism__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the dism interrupt. */
#define dism_INTC_CLR_PD            ((reg32 *) dism__INTC_CLR_PD_REG)


#endif /* CY_ISR_dism_H */


/* [] END OF FILE */
