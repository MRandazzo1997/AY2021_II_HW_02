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

//Macro guard
#ifndef __RGB_LED_DRIVER_H__
    #define __RGB_LED_DRIVER_H__
    
    #include "project.h"
    
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
