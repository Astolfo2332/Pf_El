
#include "project.h"
#include <stdio.h>
#include <stdlib.h>
uint8_t lectura=0;
uint8_t bandera=0;
int fl=50;
int tem=26;
#include "project.h"
uint8 seg=0;
uint8 h=0;
uint8 min=0;
uint16 mili=0;
uint8 timer=0;
uint16 c=0;
char time[4]="0000";
CY_ISR_PROTO(contar);
CY_ISR(contar){
    timer=1;
}
CY_ISR(dato){
    lectura=UART_GetChar();
    bandera=1;
}
void ApagarLCD(){
    LCD_Stop();
}

void EncenderLCD(int fl,int tem,int h,int min, int sec){
    Linterna_Write(0);
    LCD_DisplayOn();
    LCD_ClearDisplay();
    char temp[50];
    char fluj[50];
    char tiemp[50];
    LCD_Position(0,0);
    sprintf(temp,"Temperatura:    %2d",tem);
    LCD_PrintString(temp);
    LCD_Position(1,0);
    sprintf(fluj,"Flujo:           %2d%%",fl);
    LCD_PrintString(fluj);
    LCD_Position(3,0);
    sprintf(tiemp,"Tiempo:     %02d:%02d:%02d",h,min,sec);
    LCD_PrintString(tiemp);
}
int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    LCD_Start();
    UART_Start();
    isr_1_StartEx(dato);
    Counter_1_Start();
    isr_2_StartEx(contar);
    for(;;)
    {  
        if (bandera){
            if (lectura=='a'){ 
                if (timer){
                    timer=0;
                    mili++;
                    if (mili==1000){
                        mili=0;                 
                        EncenderLCD(fl,tem,h,min,seg);  
                        seg++;
                        if (seg==60){
                            seg=0;
                            min++;
                            if (min==60){
                                min=0;
                                h++;
                            }
                            
                            }
                        }                   
                  }
                    }
            if (lectura=='b'){
                //bandera=0;
                mili=0;
                seg=0;
                min=0;
                h=0;
                if (timer){
                    timer=0;
                    c++;
                    if (c==1000){
                        Linterna_Write(!Linterna_Read());
                        ApagarLCD();
                        c=0;
                    }
                    if (c==500){
                       LCD_ClearDisplay();
                       LCD_PrintString("Dispositivo apagado");
                    }
                
                    
                }
                    
                
            }
                
        } 
        
    }
}

