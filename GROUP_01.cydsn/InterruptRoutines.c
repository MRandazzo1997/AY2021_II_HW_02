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

#include "InterruptRoutines.h"
#include "stdio.h"
#include "RGB_Led_Driver.h"

extern uint8_t counterTimer;
uint8_t state = 0;
uint8_t timerConfig = 0;
uint8_t color;
int i = 0;
uint8_t colors[5];


CY_ISR(UART_ISR){
    if(UART_ReadRxStatus() == UART_RX_STS_FIFO_NOTEMPTY)
    {
        counterTimer = 0;
        color = UART_ReadRxData();
        if(color == 118)
            UART_PutString("RGB LED Program $$$");
        else
        {
            colors[i] = color;
            i++;
            if(color == 160)
                state = 1;
            if(color == 161)
                timerConfig = 1;
            if(color == 192)
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
    counterTimer++;
    
}

/* [] END OF FILE */
