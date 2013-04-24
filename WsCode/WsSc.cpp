//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Wildstang 2010
//  @ File Name : WsSc.cpp
//  @ Date : 1/14/2009
//  @ Author : 
//
//


#include "WsSc.h"
#include "WsOutput.h"
#include "SpeedController.h"
#include "Victor.h"
#include "Jaguar.h"

WsSc::WsSc(WsScT type, UINT32 channel)
    : WsOutput()
{
    ap_sc = NULL;

    if (type == WS_SC_VICTOR)
    {
        ap_sc = new Victor(channel);
    }
    else if (type == WS_SC_JAGUAR)
    {
        ap_sc = new Jaguar(channel);
    }
}

WsSc::WsSc(WsScT type, UINT32 slot, UINT32 channel)
    : WsOutput()
{
    ap_sc = NULL;

    if (type == WS_SC_VICTOR)
    {
        ap_sc = new Victor(slot, channel);
    }
    else if (type == WS_SC_JAGUAR)
    {
        ap_sc = new Jaguar(slot, channel);
    }
}

WsSc::~WsSc()
{
    if (ap_sc != NULL)
    {
        delete ap_sc;
    }
}

float WsSc::Get(void)
{
    if (ap_sc != NULL)
    {
        if (a_enabled == true)
        {
            return ap_sc->Get();
        }
    }

    return 0;
}


void WsSc::Set(float speed)
{
    if (ap_sc != NULL)
    {
        if (a_enabled == true)
        {
            ap_sc->Set(speed);
        }
        else
        {
            ap_sc->Set(0);
        }
    }
}

