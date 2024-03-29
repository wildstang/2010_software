//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Wildstang
//  @ File Name : WsHanger.h
//  @ Date : 2/15/2010
//  @ Author : 
//
//


#if !defined(_WSHANGER_H)
#define _WSHANGER_H

#include <stdio.h>

class DigitalInput;
class WsSc;
class WsSolenoid;

class WsHanger
{
public:

    typedef enum
    {
        ARM_STATE_NONE,
        ARM_STATE_IN,
        ARM_STATE_OUT,
    } WsArmStateT;

    static const bool a_armSolStateIn = false;
    static const bool a_armSolStateOut = true;
    static const bool a_winchBrakeInactive = true;
    static const bool a_winchBrakeActive = false;
    static const UINT32 a_switchPressed = 0;
    static const UINT32 a_switchNotPressed = 1;

    WsHanger(WsSc* p_winch, WsSolenoid* p_winchBrake, WsSolenoid* p_armDeploy);
    ~WsHanger();
    void setArmState(WsArmStateT state);
    void setWinchSpeed(float speed);
    WsHanger::WsArmStateT getArmState();
    float getWinchSpeed();
    bool getWinchBrake();
    void assignArmLimitSwitches(DigitalInput* p_armLimit);
    void resetState();
protected:
    WsSc* ap_winch;
    WsSolenoid* ap_winchBrake;
    WsSolenoid* ap_armDeploy;
    DigitalInput* ap_armLimit;

    WsArmStateT a_armState;
    float a_winchSpeed;
    bool a_winchBrake;
};

#endif  //_WSHANGER_H
