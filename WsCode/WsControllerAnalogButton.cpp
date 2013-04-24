//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Wildstang 2010
//  @ File Name : WsControllerAnalogButton.cpp
//  @ Date : 1/14/2009
//  @ Author : 
//
//


#include "WsControllerAnalogButton.h"
#include "Joystick.h"

/**
* Constructs a WsControllerAnalogButton
* @param p_js The joystick to read the axis from
* @param axis The axis to read
* @param thresh The threshold that true will be returned on one side, and false on the other
* @param aboveOn If set to true, values above the threshold will cause the button to be true.  If false, values below the threshold will cause the button to be true.
*/
WsControllerAnalogButton::WsControllerAnalogButton(Joystick* p_js, UINT32 axis, float thresh, bool aboveOn) :
                          WsControllerButton(p_js, 0)
{
}

/**
* Destructs a WsControllerAnalogButton
*/
WsControllerAnalogButton::~WsControllerAnalogButton()
{
}

/**
*  Compares the axis value to the threshold and returns the state of the virtual button
*  @returns The value of the virtual button
*/
bool WsControllerAnalogButton::getState(void )
{
    bool state = false;

    return state;
}
