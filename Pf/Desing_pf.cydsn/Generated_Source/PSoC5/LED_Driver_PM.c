/*******************************************************************************
* File Name: LED_Driver_PM.c
* Version 1.10
*
* Description:
*  This file provides the power management source code to API for the
*  LED_Driver component.
*
* Note:
*  None
*
*******************************************************************************
* Copyright 2013-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
********************************************************************************/

#include "LED_Driver.h"
static LED_Driver_backupStruct LED_Driver_backup;


/*******************************************************************************
* Function Name: LED_Driver_Sleep
********************************************************************************
*
* Summary:
*  Stop and Save the user configuration
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void LED_Driver_Sleep(void) 
{
    uint8 i;
    
    /* Store the component enable state */
    LED_Driver_backup.ledEnableState = LED_Driver_enableVar;
    
    /* Save the segment buffers */
    for(i = 0u; i < LED_Driver_NUM_COM; i++)
    {
        LED_Driver_backup.segLBackup[i] = LED_Driver_segLBuffer[i];
        #if (LED_Driver_NUM_SEG > 8u) 
            LED_Driver_backup.segMBackup[i] = LED_Driver_segMBuffer[i];
        #endif /* (LED_Driver_NUM_SEG > 8u) */
        #if (LED_Driver_NUM_SEG > 16u) 
            LED_Driver_backup.segHBackup[i] = LED_Driver_segHBuffer[i];
        #endif /* (LED_Driver_NUM_SEG > 16u) */
    }
    
    LED_Driver_Stop();
}


/*******************************************************************************
* Function Name: LED_Driver_Wakeup
********************************************************************************
*
* Summary:
*  Restores and enables the user configuration
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void LED_Driver_Wakeup(void) 
{
    uint8 i;
    
    /* Restore the segment buffers */
    for(i = 0u; i < LED_Driver_NUM_COM; i++)
    {
        LED_Driver_segLBuffer[i] = LED_Driver_backup.segLBackup[i];
        #if (LED_Driver_NUM_SEG > 8u) 
            LED_Driver_segMBuffer[i] = LED_Driver_backup.segMBackup[i];
        #endif /* (LED_Driver_NUM_SEG > 8u) */
        #if (LED_Driver_NUM_SEG > 16u) 
            LED_Driver_segHBuffer[i] = LED_Driver_backup.segHBackup[i];
        #endif /* (LED_Driver_NUM_SEG > 16u) */
    }
    
    if(LED_Driver_backup.ledEnableState == LED_Driver_ENABLED)
    {
        /* Enable the component */
        LED_Driver_Enable();
    }
}


/* [] END OF FILE */

