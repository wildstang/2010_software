//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Wildstang
//  @ File Name : WsTunableController.h
//  @ Date : 1/26/2010
//  @ Author : 
//
//


#if !defined(_WSTUNABLECONTROLLER_H)
#define _WSTUNABLECONTROLLER_H

#include <stdio.h>

class WsPid;

class WsTunableController
{
public:
    virtual WsPid* getPid(void );
    virtual void runStepTest(float input, UINT32& currentVal, float& speed);
    virtual void endStepTest(void);
    virtual void runPidTest(float input);
};

#endif  //_WSTUNABLECONTROLLER_H
