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
uint32 comparar=400;
uint32 angulo=0;

CY_ISR(aumento){
    lcd_ClearDisplay();
    comparar=comparar+50;
    PWM_WriteCompare(comparar);
}

CY_ISR(disminuye){
    lcd_ClearDisplay();
    comparar=comparar-50;
    PWM_WriteCompare(comparar);
}

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    PWM_Start();
    aum_StartEx(aumento);
    dis_StartEx(disminuye);
    lcd_Start();
    
    for(;;)
    {
        /* Place your application code here. */
        angulo=((comparar-400)*9/100);
        lcd_Position(0,0);
        lcd_PrintNumber(comparar);
        lcd_Position(01,0);
        lcd_PrintNumber(angulo);
    }
}

/* [] END OF FILE */
