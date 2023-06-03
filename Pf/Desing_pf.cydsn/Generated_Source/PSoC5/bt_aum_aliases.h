/*******************************************************************************
* File Name: bt_aum.h  
* Version 2.20
*
* Description:
*  This file contains the Alias definitions for Per-Pin APIs in cypins.h. 
*  Information on using these APIs can be found in the System Reference Guide.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_bt_aum_ALIASES_H) /* Pins bt_aum_ALIASES_H */
#define CY_PINS_bt_aum_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*              Constants        
***************************************/
#define bt_aum_0			(bt_aum__0__PC)
#define bt_aum_0_INTR	((uint16)((uint16)0x0001u << bt_aum__0__SHIFT))

#define bt_aum_INTR_ALL	 ((uint16)(bt_aum_0_INTR))

#endif /* End Pins bt_aum_ALIASES_H */


/* [] END OF FILE */
