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

#include "project.h"
#include "InterruptRoutines.h"
#include "RGB_Led_Driver.h"
#include "stdio.h"
#include "string.h"

//Variables
uint8_t state = 0;
uint8_t timerConfig = 0;
uint8_t data[5];
uint8_t counterTimer = 0;
uint8_t timerPeriod = 5;
Color c_new, c_old;
int i = 0;

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    //Enable ISRs and Components
    UART_Start();
    RGB_Led_Start();
    isr_UART_StartEx(UART_ISR);
    isr_Timer_StartEx(Timer_ISR);
    
    for(;;)
    {
        //Color header byte received, start to update colors
        while(state)
        {
            //Start Timer for timeout
            if(state == 1 && counterTimer == 0)
                Timer_Start();
            //Too much time has passed without receiving any byte, back to previous color
            if(counterTimer >= timerPeriod)
            {
                i = 0;
                counterTimer = 0;
                state = 0;
                c_new = c_old;
                break;
            }
            c_new.red = data[1];
            c_new.green = data[2];
            c_new.blue = data[3];
        }
        //Timer header byte received, change timeout duration
        while(timerConfig)
        {
            timerPeriod = data[1];
        }
        //No need of timer anymore --> color has been updated or too much time has passed
        Timer_Stop();
        RGB_Led_Write(c_new);
        //Backup of the current color
        c_old = c_new;
    }
}

/* [] END OF FILE */
