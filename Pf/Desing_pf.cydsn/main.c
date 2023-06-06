/* ========================================
 *
 * Proyecto final Bioinsttrumentación
 *
 * ========================================
*/
#include "project.h"
#include <stdio.h>
#include <stdlib.h>
// Se inician todas las banderas y varibales
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

//Se hace una secuancia para el encendido de leds de la siguiente forma 
void sec_leds(){
aviso_Write(ledval[ledindx]); //Se toma la posición del index de la lista ledval y se escribe en el conjunto de leds que se llama aviso, recordar que al ser un conjunto lo leds se encienden con binario y ese binario corresponde al numero del led y su posición
switch(ledindx){ //Se hace un switch con el fin de saber la dirección, si el valor es 3 (que es el maximo de la lista) se comenzara a restar y al reves si es 0 en este caso se suma para tener un index de 0123210 y así formar el patrón
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
//Se inician todas las interruociones las cuales activan diferentes banderas
CY_ISR_PROTO(contar);
CY_ISR(contar){
    timer=1;
}

CY_ISR(datos){
    lectura=UART_1_GetChar(); // En este caso al recibir un dato se alamcena en la variable de una vez 
    bandera=1;
}

CY_ISR(aumento){
    band_aumento=1;
}

CY_ISR(disminu){
    band_dismi=1;
}
// La función de LCD la cual dice en que orden imprimir los datos
void EncenderLCD(){
    LCD_ClearDisplay();
    if (band_7seg==1){ //La bandera de 7 segmentos en el caso donde solo se necesite mostrar información en la 7 segmentos
    if (a_seg10==0){ //Este es un reset para que soobrescriba lo que este en la pantalla si se cambia de display así nos aseguramos de solo mostrar la información el el LCS
        LED_Driver_WriteString7Seg(" LCD",0);
    }
    //Se imprime normalmente como siempre en la pantalla, diciendo una posición e imprimiento un string el cual convettimos con sprintf
        char temp[50];
        char fluj[50];
        char tiemp[50];
        LCD_Position(0,0);
        sprintf(temp,"Temperatura:  %.1f",tem);
        LCD_PrintString(temp);
        LCD_Position(0,18);
        LCD_PutChar(LCD_CUSTOM_0); // en este caso así se imprime el simbolo personalizado de grados
        LCD_Position(0,19); 
        LCD_PrintString("C");
        LCD_Position(1,0);
        sprintf(fluj,"Flujo:          %3d%%",fl);
        LCD_PrintString(fluj);
        LCD_Position(3,0);
        sprintf(tiemp,"Tiempo:     %02d:%02d:%02d",h,min,seg);
        LCD_PrintString(tiemp);
    }   
}
//La conversion del ADC lo mismo que hacemos en clase
void con(){
ADC_StartConvert();
ADC_IsEndConversion(ADC_WAIT_FOR_RESULT);
en=ADC_GetResult16();
ADC_StopConvert();
vol=ADC_CountsTo_mVolts(en);
tem=(vol/10.00)-5.00; //En este caso sabemos que un grado esta en cada 10 mv se divide sobre 10.00 porque es flotante y se le resta 5.00 ya que este es el ajuste con la termocupla
}
void print_f(void); //En este caso es prometiendole al sofware que va a existir una variable llamada print_f, esto sirve para que no de errores antes de declarar una función

//Se hace el poderoso reloj como ya sabemos
void reloj(){
    if (timer){
    timer=0;
    mili++;       
    if (mili==1000){ //El contador esta cada ms así que imprime cosas cada segundo
        if (band_aviso==1){ //Si la temperatura esta arriba o abajo se hace una iteración de la función de secuencia de leds
        sec_leds();
        }
        mili=0;     
        con(); // Se hace la conversión cada segundo
        EncenderLCD();  // Se refresca la pantalla LCD cada segundo
        seg++; 
        //El contador que sirve para saber si pasan 5 segundos
        if (a_seg5==1){ //Recibe la información si necesita empezar a contar
            seg5++; //Va sumando hasta 5 segundos
            if (seg5==5){
            seg5=0; //Se reinicia 
            switch (band_5seg){ //El swicht lo que hace es pasar al contrario de donde este la bandera para así intercalar entre F y T
            case 0:
                band_5seg=1;
                break;
            case 1:
                band_5seg=0;
                }
            }
        }
        //Similar al contador de 5 segundos
        if (a_seg10==1){ //Recibe el aviso para inciar a contar
            seg10++;
            print_f(); // Imprime el flujo constantemente en la 7 segmentos
            if (seg10==10){ //Se manda la bandera que pasaron 10 segundos, esta parte se explica mejor en los comentarios del motor
            band_10seg=1;
            seg10=0;
            }
        }
        //Contadores y resets para minutos y horas
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
//Funcion para apagar
void apagado(){
    // Se reicinia el tiempo
    mili=0;
    seg=0;
    min=0;
    h=0;
    //Se cuenta cada segundo como contador auxiliar
    if (timer){
    timer=0;
    c++;
    //Para que el mensaje solo se muestre una vez se le suma 1 y después colocando la variable en 2, esta cada vez que se prenda es devuelta a 0 para asegurarnos que el mensaje solo se muestre una vez
    band_men++;
    if (band_men==1){
    UART_1_PutString("Dispositivo apagado \n");
    LCD_ClearDisplay();
    LED_Driver_ClearDisplayAll();     
    LCD_Position(0,0);
    LCD_PrintString("Dispositivo apagado");
    band_men=2;
    }
    band_men=2;
    if (c==1000){
        tilt_Write(!tilt_Read()); //Se enciende y apaga el led
        c=0;
    } 
    }
    }
// Funcion para manejar el compare del motor 
//Como sabemos el 0° del motor esta en un compare de 999 y el 90° 2000
void con_mot(void){
switch(fl){
    case 0: //En el caso 0° el motor esta en la posición inicial lo cual seria cerrado
    compare=999;
    break;
    case 100: // En el caso 100 el motor esta a 90° lo cual indicaria que este totalmente abierto
    compare=2000;
    break;
    default: 
    compare=999+(fl*10); // En cualquier otro caso teniendo el rango de compare es 1000 se hace una regla de 3 para saber cual es el factor de proporcionalidad de aumento
    break; 
}

}
//Función para imprimir el flujo y temperaturas de manera similar ya que en ambos casos se vuelven strings
void print_f(){
    band_7seg=0;
    LCD_Stop();
    sprintf(seg_7,"F%03d",fl); //En 03 sirve para decirle cuantos digitos quiero
    LED_Driver_WriteString7Seg(seg_7,0);
}

void print_t(){
    sprintf(seg_7,"%f",tem);
    LED_Driver_WriteString7Seg(seg_7,0);
    //Esta es la manera de poner el simbolo de grados diciendo que sementos prender en que posición del 7 segmentos
    LED_Driver_SetRC(6,2); 
    LED_Driver_SetRC(5,2);
    LED_Driver_SetRC(1,2);
    LED_Driver_SetRC(0,2);                       
    LED_Driver_Write7SegDigitHex(0xC,3); //La C mayuscula se imprime como hexadecimal debido a que se encontro más facil por la documentación
}

int main(void)


{
    CyGlobalIntEnable; 
    
// Se inician todos los bloques e interrupciones
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
    // El primer if es en el caso que no se tenga un dato, así si aun el pc no a mandado nada el sistema empieza en apagado
    if (bandera==1){
            switch (lectura){ //Este swtich se implemta debido a la necesidad de poder almacenar el estado de la maquina y así poder recibir otras varibales y que no sobreescriban el estado
        case 'a': //En cada caso "principal" simplemente se guarda en otra variable para usarla más adelante, notemos que si otra letra llega no pasara nada ya que solo se ve afectado por a (encendido) y b (apagado)
            lectura_p=lectura;
            break; 
        case 'b':
            lectura_p=lectura;
            break;
        }
        switch (lectura_p){ //Para esto se usa la variable adicional en este caso se puede comparar la forma de mostrar la información
        case 'a': //Acciones de encendido
            tilt_Write(0); //Se apaga el led intermitente de apagado
            band_men=0; //Se reinicia la bandera de mensaje de apagado para que si se madna una b se mande el mensaje una sola vez 
            switch(lectura){ 
                case 'F': //En este caso solo se muestra el flujo
                    a_seg5=0; //Se reinicia la alerta de 5 segundos lo mismo que el contador respectivo
                    seg5=0;
                    band_7seg=0; //Se desactiva la sobreescritura de LCD en el 7 segmentos 
                    print_f();   //Se imprime el flujo                 
                    break;
                case 'T': //De manera imilar al flujo
                    a_seg5=0; 
                    seg5=0;
                    band_7seg=0;
                    LCD_Stop();
                    if (a_seg10==0){ 
                    //En este caso es dependiente si se unden los botones entonces solo se mostrara una vez acabado la secuencia de ajuste del motor, 
                    //ya que siempre que el motor este en ajuste la variable se mantiene en 1 hasta que pasen los 10 segundos sin cambio   
                    print_t();
                    }
                    break;
                case 'A':
                    a_seg5=1; //Se activa la alerta para contar 5 segundos 
                    band_7seg=0; //Se desactiva la sobreescritura de LCD en el 7 segmentos
                    LCD_Stop(); //Se frena el LCD
                    if (a_seg10==0){ //Lo mismo que en el caso de T, esto con el fin de que si es 1 solo se imprima el flujo
                    if(band_5seg==1){ //Remitirse a la parte de cambio de band_5seg con el switch cada vez que este cuente 5 segundos se establece el contrario a la bandera                      
                        print_t();
                    }
                    else if (band_5seg==0){           
                        print_f();                   
                    }
                    }
                    break;
                default: //Cualqer otra letra reinicia los contadores de 5 segundos y enciende el LCD
                    a_seg5=0;
                    seg5=0;
                    LCD_Start();
                    band_7seg=1; //Se avisa la soobreescritua del LCD          
                    break;                 
            }
            reloj(); //Cada vez se hace un conteo del reloj indpendiete de cualquier suceso o variable ingresada
            //Motor:
            if ((band_aumento==1)|(band_dismi==1)){ //Las interrupciones de los debouncers dan un aviso de si es aumento o disminución en este caso se hace un or para funcionar con cualquiera de los dos
                a_seg10=1; // Se activa la alerta para empezar a contar los 10 segundos
                seg10=0; // si se vuelve a presionar cualquier boton se reinicia el conteo
                if (band_aumento==1&&fl<=100){ // En el caso que aumente y sea menor o igua a 100
                    fl=fl+5; //Se le suma 5 al flujo actual
                    if(fl>100){ //Si la suma da superior a 100 osea 105 el flujo pasa a 0
                        fl=0;
                    }
                }
                if (band_dismi==1&&fl>=0){ //De manera similar a la parte de arriba solo que en este caso se resta y cuando sea menor a 0 osea -5 se pasa a 100
                    fl=fl-5;
                    if(fl<0){
                        fl=100;
                    }
                }
                con_mot(); //Se convierte el flujo en terminos de compare para mover el motor 
                band_aumento=0; //Se reinician las banderas
                band_dismi=0;
                print_f(); //Se imprime el flujo en la 7 segmentos
                           
            }
            if (band_10seg==1){ //Cuando pasen 10 segundos se activa la bandera, revisar la función de reloj() por si acaso
                a_seg10=0; //Se reincia la alerta 
                band_10seg=0; //Se reinicia la bandera 
                PWM_WriteCompare(compare);   //Se escribe la información de flujo al motor, en terminos de compare explicado en la función con_mot()
                }
            //Temperatura
            if ((tem>30.00)|(tem<25.00)){ //Se establece el rango que no esta en el rango en este caso mayor a 30 o menor a 25, recordar que son flotantes.
                band_aviso=1; //Si esta fuera de rango se avisa para empezar la secuencia de leds 
                if (band_tem==0){ //Para imprimir una vez en este caso se usa la band_temp, la cual si entra en el fuera de rango se vuelve un 1 despues de imprimir el mensaje
                //así evitando que vuelva a entrar a este if
                UART_1_PutString("Temperatura fuera de rango \n");
                band_tem=1;
                }
            }
            //En el caso que la temperatura este En el rango normal
            else{
                if (band_tem==1){ //Si la varible de band_tem estaba en 1 lo que significa que imprimió una vez el mensaje de aviso se reinicia.
                band_tem=0;
                }
                band_aviso=0; //Se desactiva el aviso de leds
                aviso_Write(~0x1F); //Se apagan todos los leds con el hexadecimal correspondiente al contrario de 11111 en este caso 00000
            }
            break; //Aqui acaba todo lo que hace cuando esta encendido
            
        case 'b': //En el caso de apagado
            aviso_Write(~0x1F); //Se apagan los leds de aviso como se explico anteriormente
            band_aviso=0; //Se reinicia la bandera de aviso
            LCD_Start(); 
            seg5=0; //Se reinician los contadores adicionales
            seg10=0;
            apagado(); 
            break;
    }
    }
    else{ //En este caso es si no se a recibido información en este caso el equipo siempre inicia apagado
    
    apagado();
    }

}
}
/* [] END OF FILE */
