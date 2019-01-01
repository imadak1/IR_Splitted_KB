/*******************************************************************************
Copyright 2016 Microchip Technology Inc. (www.microchip.com)

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*******************************************************************************/

#include <xc.h>

#include <stdbool.h>

#include "buttons.h"

/*** Button Definitions *********************************************/
#define S1_PORT  (PORTAbits.RA0|1)
#define S2_PORT  (PORTAbits.RA1|1)
#define S3_PORT  (PORTBbits.RB3|1)

#define S1_TRIS  TRISAbits.TRISA0
#define S2_TRIS  TRISAbits.TRISA1
#define S3_TRIS  TRISBbits.TRISB3

#define BUTTON_PRESSED      0
#define BUTTON_NOT_PRESSED  1

#define PIN_INPUT           1
#define PIN_OUTPUT          0

/*********************************************************************
 * Function: bool BUTTON_IsPressed(BUTTON button);
 *
 * Overview: Returns the current state of the requested button
 *
 * PreCondition: button configured via BUTTON_SetConfiguration()
 *
 * Input: BUTTON button - enumeration of the buttons available in
 *        this demo.  They should be meaningful names and not the names
 *        of the buttons on the silk-screen on the board (as the demo
 *        code may be ported to other boards).
 *         i.e. - ButtonIsPressed(BUTTON_SEND_MESSAGE);
 *
 * Output: true if pressed; false if not pressed.
 *
 ********************************************************************/
bool BUTTON_IsPressed ( BUTTON button )
{
    switch(button)
    {
        case BUTTON_S1:
            return ( (S1_PORT == BUTTON_PRESSED) ? true : false);

        case BUTTON_S2:
            return ( (S2_PORT == BUTTON_PRESSED) ? true : false);

        case BUTTON_S3:
            return ( (S3_PORT == BUTTON_PRESSED) ? true : false);

        default:
            return false;
    }
    
    return false;
}

/*********************************************************************
* Function: void BUTTON_Enable(BUTTON button);
*
* Overview: Returns the current state of the requested button
*
* PreCondition: button configured via BUTTON_SetConfiguration()
*
* Input: BUTTON button - enumeration of the buttons available in
*        this demo.  They should be meaningful names and not the names
*        of the buttons on the silk-screen on the board (as the demo
*        code may be ported to other boards).
*         i.e. - ButtonIsPressed(BUTTON_SEND_MESSAGE);
*
* Output: None
*
********************************************************************/
void BUTTON_Enable(BUTTON button)
{
    switch(button)
    {
        case BUTTON_S1:
            S1_TRIS = PIN_INPUT ;
            break ;

        case BUTTON_S2:
            S2_TRIS = PIN_INPUT;
            break;

        case BUTTON_S3:
            S3_TRIS = PIN_INPUT;
            break;

        default:
            break ;
    }
}