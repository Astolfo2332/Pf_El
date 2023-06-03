/*******************************************************************************
* File Name: data.h
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
#if !defined(CY_ISR_data_H)
#define CY_ISR_data_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void data_Start(void);
void data_StartEx(cyisraddress address);
void data_Stop(void);

CY_ISR_PROTO(data_Interrupt);

void data_SetVector(cyisraddress address);
cyisraddress data_GetVector(void);

void data_SetPriority(uint8 priority);
uint8 data_GetPriority(void);

void data_Enable(void);
uint8 data_GetState(void);
void data_Disable(void);

void data_SetPending(void);
void data_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the data ISR. */
#define data_INTC_VECTOR            ((reg32 *) data__INTC_VECT)

/* Address of the data ISR priority. */
#define data_INTC_PRIOR             ((reg8 *) data__INTC_PRIOR_REG)

/* Priority of the data interrupt. */
#define data_INTC_PRIOR_NUMBER      data__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable data interrupt. */
#define data_INTC_SET_EN            ((reg32 *) data__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the data interrupt. */
#define data_INTC_CLR_EN            ((reg32 *) data__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the data interrupt state to pending. */
#define data_INTC_SET_PD            ((reg32 *) data__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the data interrupt. */
#define data_INTC_CLR_PD            ((reg32 *) data__INTC_CLR_PD_REG)


#endif /* CY_ISR_data_H */


/* [] END OF FILE */
