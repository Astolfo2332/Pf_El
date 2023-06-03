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
uint8 pasito=0;
uint16 compare=999;
uint8 pasos=0;
CY_ISR(dar_paso){
pasito=1;

}
int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
paso_StartEx(dar_paso);
PWM_1_Start();
LCD_Start();
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;)
    {
        if (pasito==1){
        if (compare>2000){
        compare=999;
        pasos=0;
        }
        pasito=0;
        pasos++;
        compare=compare+56;
        PWM_1_WriteCompare(compare);
        LCD_ClearDisplay();
        LCD_Position(0,0);
        LCD_PrintNumber(compare);
        LCD_Position(1,0);
        LCD_PrintNumber(pasos);
       
        }
        
        /* Place your application code here. */
    }
}

/* [] END OF FILE */
