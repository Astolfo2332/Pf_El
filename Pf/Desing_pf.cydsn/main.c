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

uint8_t lectura=0;
uint8_t bandera=0;
int fl=50;
int tem=26;
uint8 seg=0;
uint8 h=0;
uint8 min=0;
uint16 mili=0;
uint8 timer=0;
uint16 c=0;
uint8 seg5=0;
uint8 band_7seg=0;
uint8 band_5seg=0;
uint8 band_lcd=0;
uint8 a_seg5=0;
char time[4]="0000";
char seg_7[4];
uint8_t lectura_p='b';
char seggs[50];


CY_ISR_PROTO(contar);
CY_ISR(contar){
    timer=1;
}

CY_ISR(datos){
    lectura=UART_1_GetChar();
    bandera=1;
}



void EncenderLCD(int fl,int tem,int h,int min, int sec){
    LCD_ClearDisplay();
    if (band_7seg==1){
        LED_Driver_WriteString7Seg(" LCD",0);
    }
    char temp[50];
    char fluj[50];
    char tiemp[50];
    LCD_Position(0,0);
    sprintf(temp,"Temperatura:     %2dC",tem);
    LCD_PrintString(temp);
    LCD_Position(1,0);
    sprintf(fluj,"Flujo:           %2d%%",fl);
    LCD_PrintString(fluj);
    LCD_Position(3,0);
    sprintf(tiemp,"Tiempo:     %02d:%02d:%02d",h,min,sec);
    LCD_PrintString(tiemp);
}

void reloj(){
    if (timer){
    timer=0;
    mili++;
    if (mili==1000){
        mili=0;                 
        EncenderLCD(fl,tem,h,min,seg);  
        seg++;
        if (a_seg5==1){
            seg5++;
            if (seg5==5){
            seg5=0;
            switch (band_5seg){
            case 0:
                band_5seg=1;
                break;
            case 1:
                band_5seg=0;
                }
            }
        }
        if (seg==60){
            seg=0;
            min++;
            if (min==60){
                min=0;
                h++;
            }
}
}}}
void apagado(){
     
    mili=0;
    seg=0;
    min=0;
    h=0;
    if (timer){
    timer=0;
    c++;
    if (c==1000){
        LCD_ClearDisplay();
        LED_Driver_ClearDisplayAll();
        UART_1_PutString("Dispositivo apagado \n");
        LCD_Position(0,0);
        LCD_PrintString("Dispositivo apagado");
        tilt_Write(!tilt_Read());
        c=0;
    } 
    }
    }



int main(void)


{
    CyGlobalIntEnable; /* Enable global interrupts. */
LED_Driver_Start();
Counter_1_Start();
isr_contador_StartEx(contar);
data_StartEx(datos);
UART_1_Start();
LCD_Start();
    for(;;)
    {
    if (bandera==1){
            switch (lectura){
        case 'a':
            lectura_p=lectura;
            break; 
            case 'b':
            lectura_p=lectura;
            break;
        }
        switch (lectura_p){
        case 'a':
            switch(lectura){
                case 'F':
                a_seg5=0;
                band_7seg=0;
                LCD_Stop();
                sprintf(seg_7,"F%03d",fl);
                LED_Driver_WriteString7Seg(seg_7,0);
                reloj();
                break;
                case 'T':
                a_seg5=0;
                band_7seg=0;
                LCD_Stop();
                sprintf(seg_7,"%02d",tem);
                LED_Driver_WriteString7Seg(seg_7,0);
                LED_Driver_PutChar7Seg('o',2);
                LED_Driver_Write7SegDigitHex(0xC,3);
                reloj();
                break;
                case 'A':
                a_seg5=1;
                band_7seg=0;
                LCD_Stop();
                if(band_5seg==1){          
                sprintf(seg_7,"%02d",tem);
                LED_Driver_WriteString7Seg(seg_7,0);
                LED_Driver_PutChar7Seg('o',2);
                LED_Driver_Write7SegDigitHex(0xC,3);
                reloj();
                }
                else if (band_5seg==0){           
                sprintf(seg_7,"F%03d",fl);
                LED_Driver_WriteString7Seg(seg_7,0);
                reloj();
                }
                
                default:
                    a_seg5=0;
                    LCD_Start();
                    band_7seg=1;
                    reloj();
                    break;                 
            }
            break;
        case 'b':
            LCD_Start();
            apagado();
            break;
    }
    }
    else{
    apagado();
    }

}
}
/* [] END OF FILE */
