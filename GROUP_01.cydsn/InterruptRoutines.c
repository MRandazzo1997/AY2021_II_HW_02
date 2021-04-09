/* ========================================
 *
 * ASSIGNMENT 02 - PSoC Creator
 * Group 01
 * Beatrice Pedretti, Mattia Randazzo
 *
 * UART controlling color of RGB led
 *
 * ========================================
*/

//Include header files
#include "InterruptRoutines.h"
#include "stdio.h"
#include "RGB_Led_Driver.h"

//Variables
extern uint8_t counterTimer;
extern uint8_t state;
extern uint8_t timerConfig;
extern uint8_t data[5];
extern int i;
uint8_t byte;



CY_ISR(UART_ISR){
    if(UART_ReadRxStatus() == UART_RX_STS_FIFO_NOTEMPTY)
    {
        //counterTimer initialization
        counterTimer = 0;
        //Read data
        byte = UART_ReadRxData();
        //Required for testing: upon receiving character "v", send "RGB LED Program $$$" to serial port
        if(byte == 118)
            UART_PutString("RGB LED Program $$$\r\n");
        else
        {
            //Store the byte received
            data[i] = byte;
            i++;
            //Color header byte
            if(byte == 160)
                state = 1;
            //Timer header byte
            if(byte == 161)
                timerConfig = 1;
            //Tail byte
            if(byte == 192)
            {
                i = 0;
                state = 0;
                timerConfig = 0;
            }
        }
    }    
}

CY_ISR(Timer_ISR)
{
    //Clear isr line
    Timer_ReadStatusRegister();
    //1s has passed
    counterTimer++;
    
}

/* [] END OF FILE */
