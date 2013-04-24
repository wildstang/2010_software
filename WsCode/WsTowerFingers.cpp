//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Wildstang
//  @ File Name : WsTowerFingers.cpp
//  @ Date : 2/15/2010
//  @ Author : 
//
//


#include "WsTowerFingers.h"
#include "WsDoubleSolenoid.h"

WsTowerFingers::WsTowerFingers(WsDoubleSolenoid* p_fingerDeploy)
{
    ap_fingerDeploy = p_fingerDeploy;
    a_fingerState = TOWER_FINGER_STATE_IN;
}

WsTowerFingers::~WsTowerFingers()
{

}

void WsTowerFingers::setState(WsTowerFingerStateT state)
{
    WsDoubleSolenoid::DoubleSolenoidStateT fingerOutput = WsDoubleSolenoid::kOnB;
    a_fingerState = state;
    if(ap_fingerDeploy != NULL)
    {
        if(a_fingerState == TOWER_FINGER_STATE_OUT)
        {
            fingerOutput = WsDoubleSolenoid::kOnA;
        }
        else
        {
            fingerOutput = WsDoubleSolenoid::kOnB;
        }
        ap_fingerDeploy->Set(fingerOutput);

        //printf("FINGER: %d\n", fingerOutput);
    }
}

WsTowerFingers::WsTowerFingerStateT WsTowerFingers::getState(void )
{
    return a_fingerState;
}
