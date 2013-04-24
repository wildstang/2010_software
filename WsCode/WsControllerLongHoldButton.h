//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Wildstang
//  @ File Name : WsControllerLongHoldButton.h
//  @ Date : 2/4/2010
//  @ Author : 
//
//


#if !defined(_WSCONTROLLERLONGHOLDBUTTON_H)
#define _WSCONTROLLERLONGHOLDBUTTON_H

#include <stdio.h>
#include "WsControllerButton.h"
#include "Timer.h"

class Joystick;
class Gamepad;

/**
* This virtual button returns true if a button has been pressed for a certain amount of contiguous time.
* False is returned at all other times.  If the button is released, the hold time will need to be met again before true is returned.
*/
class WsControllerLongHoldButton : public WsControllerButton
{
public:
    WsControllerLongHoldButton(Joystick* p_js, UINT32 button, double holdTime);
    WsControllerLongHoldButton(Gamepad* p_gamepad, UINT32 button, double holdTime);
    WsControllerLongHoldButton(Gamepad* p_gamepad, Gamepad::DPadDirection dpad, double holdTime);
    WsControllerLongHoldButton(UINT32 channelNum, double holdTime);
    bool getState(void );
protected:
    Timer a_timer;      /*!< The internal timer used to determine the length of a press */
    double a_holdTime;  /*!< The amount of time (in decimal seconds) that the button must be pressed before true is returned */
    bool a_state;       /*!< The internal state of the virtual button */
};

#endif  //_WSCONTROLLERLONGHOLDBUTTON_H
