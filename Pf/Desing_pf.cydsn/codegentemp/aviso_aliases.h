/*******************************************************************************
* File Name: aviso.h  
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

#if !defined(CY_PINS_aviso_ALIASES_H) /* Pins aviso_ALIASES_H */
#define CY_PINS_aviso_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*              Constants        
***************************************/
#define aviso_0			(aviso__0__PC)
#define aviso_0_INTR	((uint16)((uint16)0x0001u << aviso__0__SHIFT))

#define aviso_1			(aviso__1__PC)
#define aviso_1_INTR	((uint16)((uint16)0x0001u << aviso__1__SHIFT))

#define aviso_2			(aviso__2__PC)
#define aviso_2_INTR	((uint16)((uint16)0x0001u << aviso__2__SHIFT))

#define aviso_3			(aviso__3__PC)
#define aviso_3_INTR	((uint16)((uint16)0x0001u << aviso__3__SHIFT))

#define aviso_INTR_ALL	 ((uint16)(aviso_0_INTR| aviso_1_INTR| aviso_2_INTR| aviso_3_INTR))

#endif /* End Pins aviso_ALIASES_H */


/* [] END OF FILE */
