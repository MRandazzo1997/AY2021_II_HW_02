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

//Macro guard
#ifndef __INTERRUPT_ROUTINES_H__
    #define __INTERRUPT_ROUTINES_H__
    
    #include "project.h"
    
    CY_ISR_PROTO(UART_ISR);
    CY_ISR_PROTO(Timer_ISR);
#endif

/* [] END OF FILE */
