//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Wildstang
//  @ File Name : WsDsAnalog.h
//  @ Date : 2/7/2009
//  @ Author : 
//
//


#if !defined(_WSDSANALOG_H)
#define _WSDSANALOG_H

#include <stdio.h>
#include "WsControllerBase.h"

class WsDsAnalog : public WsControllerBase
{
public:
    WsDsAnalog(UINT32 channel);
    float getValue();
};

#endif  //_WSDSANALOG_H
