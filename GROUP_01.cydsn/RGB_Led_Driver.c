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

#include "RGB_Led_Driver.h"

static void RGB_Led_UpdateRed(uint8_t red);
static void RGB_Led_UpdateGreen(uint8_t green);
static void RGB_Led_UpdateBlue(uint8_t Blue);

void RGB_Led_Start()
{
    PWM_RG_Start();
    PWM_B_Start();
}

void RGB_Led_Stop()
{
    PWM_RG_Stop();
    PWM_B_Stop();
}

void RGB_Led_Write(Color c)
{
    RGB_Led_UpdateRed(c.red);
    RGB_Led_UpdateGreen(c.green);
    RGB_Led_UpdateBlue(c.blue);
}

static void RGB_Led_UpdateRed(uint8_t red)
{
    PWM_RG_WriteCompare1(red);
}

static void RGB_Led_UpdateGreen(uint8_t green)
{
    PWM_RG_WriteCompare2(green);
}

static void RGB_Led_UpdateBlue(uint8_t blue)
{
    PWM_B_WriteCompare(blue);
}
/* [] END OF FILE */
