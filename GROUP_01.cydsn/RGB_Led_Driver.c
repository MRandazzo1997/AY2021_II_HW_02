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

#include "RGB_Led_Driver.h"

//private functions declaration
static void RGB_Led_UpdateRed(uint8_t red);
static void RGB_Led_UpdateGreen(uint8_t green);
static void RGB_Led_UpdateBlue(uint8_t blue);

//Function to start PWM components
void RGB_Led_Start()
{
    PWM_RG_Start();
    PWM_B_Start();
}

//Function to stop PWM components
void RGB_Led_Stop()
{
    PWM_RG_Stop();
    PWM_B_Stop();
}

//Update all 3 colors
void RGB_Led_Write(Color c)
{
    RGB_Led_UpdateRed(c.red);
    RGB_Led_UpdateGreen(c.green);
    RGB_Led_UpdateBlue(c.blue);
}

//Private function to update red color
static void RGB_Led_UpdateRed(uint8_t red)
{
    PWM_RG_WriteCompare1(red);
}

//Private function to update green color
static void RGB_Led_UpdateGreen(uint8_t green)
{
    PWM_RG_WriteCompare2(green);
}

//Private function to update blue color
static void RGB_Led_UpdateBlue(uint8_t blue)
{
    PWM_B_WriteCompare(blue);
}
/* [] END OF FILE */
