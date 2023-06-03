/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"
#include <stdio.h>
#include <stdlib.h>
uint8 seg=0;
uint8 min=0;
uint16 mili=0;
uint8 timer=0;
char time[4]="0000";
CY_ISR_PROTO(contar);
CY_ISR(contar){
    Counter_1_ReadStatusRegister();
    timer=1;
}


int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    LCD_Char_1_Start();
    Counter_1_Start();
    isr_1_StartEx(contar);

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;)
    {
        if (timer){
        timer=0;
            mili++;
            if (mili==1000){
            mili=0;
            LCD_Char_1_ClearDisplay();
            LCD_Char_1_Position(0,0);
            sprintf(time,"Tiempo=%02d:%02d",min,seg);
            LCD_Char_1_PrintString(time);
            seg++;
            if (seg==60){
            seg=0;
            min++;
            }
            }
            
            
        }
        /* Place your application code here. */
    }
}

/* [] END OF FILE */
