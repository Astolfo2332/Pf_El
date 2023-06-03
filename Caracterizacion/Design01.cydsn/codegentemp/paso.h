/*******************************************************************************
* File Name: paso.h
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
#if !defined(CY_ISR_paso_H)
#define CY_ISR_paso_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void paso_Start(void);
void paso_StartEx(cyisraddress address);
void paso_Stop(void);

CY_ISR_PROTO(paso_Interrupt);

void paso_SetVector(cyisraddress address);
cyisraddress paso_GetVector(void);

void paso_SetPriority(uint8 priority);
uint8 paso_GetPriority(void);

void paso_Enable(void);
uint8 paso_GetState(void);
void paso_Disable(void);

void paso_SetPending(void);
void paso_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the paso ISR. */
#define paso_INTC_VECTOR            ((reg32 *) paso__INTC_VECT)

/* Address of the paso ISR priority. */
#define paso_INTC_PRIOR             ((reg8 *) paso__INTC_PRIOR_REG)

/* Priority of the paso interrupt. */
#define paso_INTC_PRIOR_NUMBER      paso__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable paso interrupt. */
#define paso_INTC_SET_EN            ((reg32 *) paso__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the paso interrupt. */
#define paso_INTC_CLR_EN            ((reg32 *) paso__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the paso interrupt state to pending. */
#define paso_INTC_SET_PD            ((reg32 *) paso__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the paso interrupt. */
#define paso_INTC_CLR_PD            ((reg32 *) paso__INTC_CLR_PD_REG)


#endif /* CY_ISR_paso_H */


/* [] END OF FILE */
