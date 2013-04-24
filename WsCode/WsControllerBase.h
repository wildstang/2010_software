//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Wildstang 2009
//  @ File Name : WsControllerBase.h
//  @ Date : 1/14/2009
//  @ Author : 
//
//


#if !defined(_WSCONTROLLERBASE_H)
#define _WSCONTROLLERBASE_H

#include <stdio.h>
#include "Gamepad.h"

class Joystick;
class DriverStation;

/**
* This is the base class for all derived input controller types (analog/digital)
*/
class WsControllerBase
{
public:
    /**
     * Initializes all parameters to a default state
     */
    WsControllerBase()
    {
        a_axisNum = 0;
        a_buttonNum = 0;
        a_channelNum = 0;
        a_dpadDir = Gamepad::kCenter;
        ap_joystick = NULL;
        ap_gamepad = NULL;
        ap_ds = NULL;
        a_invert = false;
    };
protected:
    UINT32 a_axisNum;     /*!< An axis number that can be used for analog input*/
    UINT32 a_buttonNum;   /*!< A button number that can be used for digital input*/
    UINT32 a_channelNum;  /*!< A channel number that can be used for analog input from the driver station */
    Gamepad::DPadDirection a_dpadDir; /*!< A D-pad direction from a gamepad */
    Joystick *ap_joystick; /*!< A joystick that can be used for input */
    Gamepad *ap_gamepad;   /*!< A gamepad that can be used for input */
    DriverStation *ap_ds;  /*!< A driver station that can be used for input */

    bool a_invert; /*!< A flag to denote whether analog inversion should be performed in software */
};

#endif  //_WSCONTROLLERBASE_H
