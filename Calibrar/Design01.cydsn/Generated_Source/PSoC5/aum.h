/*******************************************************************************
* File Name: aum.h
* Version 1.71
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
#if !defined(CY_ISR_aum_H)
#define CY_ISR_aum_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void aum_Start(void);
void aum_StartEx(cyisraddress address);
void aum_Stop(void);

CY_ISR_PROTO(aum_Interrupt);

void aum_SetVector(cyisraddress address);
cyisraddress aum_GetVector(void);

void aum_SetPriority(uint8 priority);
uint8 aum_GetPriority(void);

void aum_Enable(void);
uint8 aum_GetState(void);
void aum_Disable(void);

void aum_SetPending(void);
void aum_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the aum ISR. */
#define aum_INTC_VECTOR            ((reg32 *) aum__INTC_VECT)

/* Address of the aum ISR priority. */
#define aum_INTC_PRIOR             ((reg8 *) aum__INTC_PRIOR_REG)

/* Priority of the aum interrupt. */
#define aum_INTC_PRIOR_NUMBER      aum__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable aum interrupt. */
#define aum_INTC_SET_EN            ((reg32 *) aum__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the aum interrupt. */
#define aum_INTC_CLR_EN            ((reg32 *) aum__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the aum interrupt state to pending. */
#define aum_INTC_SET_PD            ((reg32 *) aum__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the aum interrupt. */
#define aum_INTC_CLR_PD            ((reg32 *) aum__INTC_CLR_PD_REG)


#endif /* CY_ISR_aum_H */


/* [] END OF FILE */
