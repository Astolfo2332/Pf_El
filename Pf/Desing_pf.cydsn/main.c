/* ========================================
 *
 * Proyecto final Bioinsttrumentación
 *
 * ========================================
*/
#include "project.h"
#include <stdio.h>
#include <stdlib.h>

uint8_t lectura=0;
uint8_t bandera=0;
int fl=0;
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
uint16 compare=999;
uint8 band_aumento=0;
uint8 band_dismi=0;
uint8 seg10=0;
uint8 band_10seg=0;
uint8 a_seg10=0;
int16 vol,en; 
float tem;
uint8 band_tem=0; 
uint8 band_aviso=0;
uint8 ledval[] = {0b00011, 0b00111, 0b01111, 0b11111};
uint8 ledindx = 0;
uint8 direc=0;
uint8 band_men=0; 

void sec_leds(){
aviso_Write(ledval[ledindx]);
switch(ledindx){
case 3:
    direc=1;
    break;
case 0:
    direc=0;
    break;
}
switch(direc){
case 1:
    ledindx--;
    break;
case 0:
    ledindx++;
    break;
}

}

CY_ISR_PROTO(contar);
CY_ISR(contar){
    timer=1;
}

CY_ISR(datos){
    lectura=UART_1_GetChar();
    bandera=1;
}

CY_ISR(aumento){
    band_aumento=1;
}

CY_ISR(disminu){
    band_dismi=1;
}

void EncenderLCD(int fl,float32 tem,int h,int min, int sec){
    LCD_ClearDisplay();
    if (band_7seg==1){
    if (a_seg10==0){
        LED_Driver_WriteString7Seg(" LCD",0);
    }
        char temp[50];
        char fluj[50];
        char tiemp[50];
        LCD_Position(0,0);
        sprintf(temp,"Temperatura:  %.1f",tem);
        LCD_PrintString(temp);
        LCD_Position(0,18);
        LCD_PutChar(LCD_CUSTOM_0);
        LCD_Position(0,19);
        LCD_PrintString("C");
        LCD_Position(1,0);
        sprintf(fluj,"Flujo:          %3d%%",fl);
        LCD_PrintString(fluj);
        LCD_Position(3,0);
        sprintf(tiemp,"Tiempo:     %02d:%02d:%02d",h,min,sec);
        LCD_PrintString(tiemp);
    }   
}

void con(){
ADC_StartConvert();
ADC_IsEndConversion(ADC_WAIT_FOR_RESULT);
en=ADC_GetResult16();
ADC_StopConvert();
vol=ADC_CountsTo_mVolts(en);
tem=(vol/10.00)-5.00;
}
void print_f(void);

void reloj(){
    if (timer){
    timer=0;
    mili++;       
    if (mili==1000){
        if (band_aviso==1){
        sec_leds();
        }
        mili=0;     
        con();
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
        if (a_seg10==1){
            seg10++;
            print_f();
            if (seg10==10){
            band_10seg=1;
            seg10=0;
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
    band_men++;
    if (band_men==1){
    UART_1_PutString("Dispositivo apagado \n");
    band_men=2;
    }
    band_men=2;
    if (c==1000){
        LCD_ClearDisplay();
        LED_Driver_ClearDisplayAll();     
        LCD_Position(0,0);
        LCD_PrintString("Dispositivo apagado");
        tilt_Write(!tilt_Read());
        c=0;
    } 
    }
    }

void con_mot(void){
switch(fl){
    case 0:
    compare=999;
    break;
    case 100:
    compare=2000;
    break;
    default:
    compare=999+(fl*10);
    break;
    
    
}

}
void print_f(){
    band_7seg=0;
    LCD_Stop();
    sprintf(seg_7,"F%03d",fl);
    LED_Driver_WriteString7Seg(seg_7,0);
}

void print_t(){
    sprintf(seg_7,"%f",tem);
    LED_Driver_WriteString7Seg(seg_7,0);
    LED_Driver_SetRC(6,2);
    LED_Driver_SetRC(5,2);
    LED_Driver_SetRC(1,2);
    LED_Driver_SetRC(0,2);                       
    LED_Driver_Write7SegDigitHex(0xC,3); 
}

int main(void)


{
    CyGlobalIntEnable; 
LED_Driver_Start();
Counter_1_Start();
isr_contador_StartEx(contar);
data_StartEx(datos);
UART_1_Start();
LCD_Start();
PWM_Start();
aum_StartEx(aumento);
dism_StartEx(disminu);
Opamp_Start();
ADC_Start();
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
            tilt_Write(0);
            band_men=0;
            switch(lectura){
                case 'F':
                    a_seg5=0;
                    band_7seg=0;
                    print_f();                    
                    break;
                case 'T':
                    a_seg5=0;
                    band_7seg=0;
                    LCD_Stop();
                    if (a_seg10==0){                    
                    print_t();
                    }
                    break;
                case 'A':
                    a_seg5=1;
                    band_7seg=0;
                    LCD_Stop();
                    if (a_seg10==0){
                    if(band_5seg==1){          
                        print_t();
                    }
                    else if (band_5seg==0){           
                        print_f();                   
                    }
                    }
                    break;
                default:
                    a_seg5=0;
                    LCD_Start();
                    band_7seg=1;           
                    break;                 
            }
            reloj();
            if ((band_aumento==1)|(band_dismi==1)){
                a_seg10=1;
                seg10=0;
                if (band_aumento==1&&fl<=100){
                    fl=fl+5;
                    if(fl>100){
                        fl=0;
                    }
                }
                if (band_dismi==1&&fl>=0){
                    fl=fl-5;
                    if(fl<0){
                        fl=100;
                    }
                }
                con_mot();
                band_aumento=0;
                band_dismi=0;
                print_f();
                
            
            }
            if (band_10seg==1){
                a_seg10=0;
                band_10seg=0;
                PWM_WriteCompare(compare);   
                }
            if ((tem>30.00)|(tem<25.00)){
                band_aviso=1;
                if (band_tem==0){
                UART_1_PutString("Temperatura fuera de rango \n");
                band_tem=1;
                }
            }
            else{
                if (band_tem==1){
                band_tem=0;
                band_aviso=0;
                aviso_Write(~0x1F);
                }
            }
            break;
            
        case 'b':
            aviso_Write(~0x1F);
            band_aviso=0;
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
