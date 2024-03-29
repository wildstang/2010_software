//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Wildstang
//  @ File Name : WsAccumulator.cpp
//  @ Date : 1/30/2010
//  @ Author : 
//
//


#include "WsAccumulator.h"
#include "WsSc.h"
#include "WsSolenoid.h"
#include "DigitalInput.h"

/**
* Constructs a WsAccumulator
* @param p_sc A pointer to the speed controller for the accumulator
*/
WsAccumulator::WsAccumulator(WsSc* p_sc1, WsSc* p_sc2)
{
    ap_sc1 = p_sc1;
    ap_sc2 = p_sc2;
    ap_barSol = NULL;
    ap_ballPossessedSensor = NULL;
    a_speedIn = 1.0;
    a_speedInSlow = 1.0;
    a_speedOut = -1;
    a_state = ACCUM_OFF;
}

/**
* Destructs a WsAccumulator
*/
WsAccumulator::~WsAccumulator()
{

}

void WsAccumulator::assignAccumulatorSensors(DigitalInput* p_ballPossessedSensor)
{
    ap_ballPossessedSensor = p_ballPossessedSensor;
}


void WsAccumulator::assignBarSolenoid(WsSolenoid* p_barSol)
{
    ap_barSol = p_barSol;
}

/**
* Sets the state of the accumulator
* @param state The state to set to
*/
void WsAccumulator::setState(WsAccumStateT state, bool overrideState)
{
    float speed = 0;
    if (ap_sc1 != NULL)
    {
        if(overrideState == true)
        {
            state = ACCUM_OFF;
        }

        if (state == ACCUM_OUT)
        {
            speed = a_speedOut;
        }
        else if (state == ACCUM_IN)
        {
            speed = a_speedIn;
            if( ap_ballPossessedSensor != NULL )
            {
                if( ap_ballPossessedSensor->Get() == true)
                {
                    speed = a_speedInSlow;
                }
            }
        }
        else
        {
            speed = 0;
        }

        ap_sc1->Set(speed);

        if(ap_sc2 != NULL)
        {
            ap_sc2->Set(speed);
        }
    }

    a_state = state;
}

/**
* Gets the state of the accumulator
* @return The current state of the accumulator
*/
WsAccumulator::WsAccumStateT WsAccumulator::getState(void )
{
    return a_state;
}

void WsAccumulator::setBarState(WsBarStateT state, bool overrideState)
{
    if(ap_barSol != NULL)
    {
        if(overrideState == true)
        {
            state = WsAccumulator::BAR_UP;
        }

        if(state == WsAccumulator::BAR_UP)
        {
            ap_barSol->Set(true);
        }
        else
        {
            ap_barSol->Set(false);
        }
    }

    a_barState = state;
}

WsAccumulator::WsBarStateT WsAccumulator::getBarState(void )
{
    return a_barState;
}

bool WsAccumulator::isBarUp(void )
{
    return (a_barState == WsAccumulator::BAR_UP);
}
