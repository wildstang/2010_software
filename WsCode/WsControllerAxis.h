//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Wildstang 2009
//  @ File Name : WsControllerAxis.h
//  @ Date : 1/14/2009
//  @ Author : 
//
//


#if !defined(_WSCONTROLLERAXIS_H)
#define _WSCONTROLLERAXIS_H

#include <stdio.h>
#include "WsControllerBase.h"

/**
* The WsControllerAxis represents an analog axis that belongs to a joystick or gamepad.
*/
class WsControllerAxis : public WsControllerBase
{
public:
    WsControllerAxis(Joystick* p_js, UINT32 axis, bool invert = false);
    WsControllerAxis(Gamepad* p_js, UINT32 axis, bool invert = false);
    virtual ~WsControllerAxis();
    virtual float getValue(void );
    virtual float applyInvert(float value);
};

#endif  //_WSCONTROLLERAXIS_H