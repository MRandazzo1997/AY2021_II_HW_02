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
#ifndef __RGB_LED_DRIVER_H__
    #define __RGB_LED_DRIVER_H__
    
    #include "project.h"
    
    //Defining what is a color
    typedef struct {
        uint8_t red;
        uint8_t green;
        uint8_t blue;
    } Color;
    
    void RGB_Led_Start();
    
    void RGB_Led_Stop();
    
    void RGB_Led_Write(Color c);
#endif

/* [] END OF FILE */
