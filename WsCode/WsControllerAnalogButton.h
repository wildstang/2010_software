//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Wildstang 2010
//  @ File Name : WsControllerAnalogButton.h
//  @ Date : 1/14/2009
//  @ Author : 
//
//


#if !defined(_WSCONTROLLERANALOGBUTTON_H)
#define _WSCONTROLLERANALOGBUTTON_H

#include <stdio.h>
#include "WsControllerButton.h"

/**
* The WsControllerAnalogButton is a virtual button type that returns true when the axis is above the threshold, and false otherwise.
*/
class WsControllerAnalogButton : public WsControllerButton
{
public:
    WsControllerAnalogButton(Joystick* p_js, UINT32 axis, float thresh, bool aboveOn);
    virtual ~WsControllerAnalogButton();
    virtual bool getState(void );
protected:
    float a_threshold; /*!< The threshold that will be used for comparison against the axis */
    bool a_aboveOn;    /*!< If this flag is true, axis values greater than the threshold will return true.  If this is false, values less than the threshold will return a true */
};

#endif  //_WSCONTROLLERANALOGBUTTON_H
