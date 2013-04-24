//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Wildstang
//  @ File Name : WsSolenoid.h
//  @ Date : 1/27/2010
//  @ Author : 
//
//


#if !defined(_WSSOLENOID_H)
#define _WSSOLENOID_H

#include "WsOutput.h"

class Solenoid;

class WsSolenoid : public WsOutput {
public:
    WsSolenoid(Solenoid* p_solenoid);
    WsSolenoid(UINT32 channel);
    WsSolenoid(UINT32 slot, UINT32 channel);
    ~WsSolenoid();
    void Set(bool on);
protected:
    Solenoid* ap_solenoid;
};

#endif  //_WSSOLENOID_H