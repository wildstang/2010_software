//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Wildstang
//  @ File Name : WsKickerLatch.cpp
//  @ Date : 1/27/2010
//  @ Author : 
//
//

#include <stdio.h>

#include "WsKickerLatch.h"
#include "WsSolenoid.h"

WsKickerLatch::WsKickerLatch(WsSolenoid* p_solenoid)
{
    ap_solenoid = p_solenoid;
    a_defaultState = KICKER_LATCH_HOLD;
    a_state = a_defaultState;
}

WsKickerLatch::~WsKickerLatch()
{

}

void WsKickerLatch::setState(WsKickerLatchStateT state)
{
    if (ap_solenoid != NULL)
    {
        if (state != KICKER_LATCH_NONE)
        {
            a_state = state;
        }

        if (a_state == KICKER_LATCH_HOLD)
        {
            ap_solenoid->Set(false);
        }
        else if (a_state == KICKER_LATCH_RELEASE)
        {
            ap_solenoid->Set(true);
        }
    }
}

WsKickerLatch::WsKickerLatchStateT WsKickerLatch::getState(void )
{
    return a_state;
}

void WsKickerLatch::resetState(void )
{
    setState(a_defaultState);
}

