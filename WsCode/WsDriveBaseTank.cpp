//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Wildstang 2010
//  @ File Name : WsDriveBaseTank.cpp
//  @ Date : 1/14/2009
//  @ Author : 
//
//


#include <math.h>
#include "WsDriveBaseTank.h"
#include "WsSc.h"
#include "WsDriveVector.h"
#include "WsTrig.h"
#include "WsDashboard.h"

WsDriveBaseTank::WsDriveBaseTank(WsSc* p_lf, WsSc* p_lb,
                                 WsSc* p_rf, WsSc* p_rb)
{
    ap_scLF = p_lf;
    ap_scLB = p_lb;
    ap_scRF = p_rf;
    ap_scRB = p_rb;
}

WsDriveBaseTank::WsDriveBaseTank(WsSc* p_l, WsSc* p_r)
{
    ap_scLF = p_l;
    ap_scLB = p_l;
    ap_scRF = p_r;
    ap_scRB = p_r;
}

WsDriveBaseTank::~WsDriveBaseTank()
{
}

void WsDriveBaseTank::setVector(WsDriveVector* p_vector)
{
    float left_speed = 0;
    float right_speed = 0;

    calcTankOutput(p_vector, &left_speed, &right_speed);
    setTankOutput(left_speed, left_speed, right_speed, right_speed);
}

void WsDriveBaseTank::calcTankOutput(WsDriveVector* p_vector,
                                     float* p_lSpeed,
                                     float* p_rSpeed)
{

    float l_speed = 0;
    float r_speed = 0;
    float speed = 0;
    float direction =  0;

    if(p_vector != NULL)
    {
        speed = p_vector->a_speed;
        direction = p_vector->a_direction;
    }

    l_speed = (speed * (COSDEG(direction) + SINDEG(direction)));
    r_speed = (speed * (COSDEG(direction) - SINDEG(direction)));

    if(l_speed > 1)
    {
        l_speed = 1;
    }
    if(r_speed > 1)
    {
        r_speed = 1;
    }

    if(l_speed < -1)
    {
        l_speed = -1;
    }
    if(r_speed < -1)
    {
        r_speed = -1;
    }

    *p_lSpeed = l_speed;
    *p_rSpeed = r_speed;
}

void WsDriveBaseTank::setTankOutput(float lfSpeed, float lbSpeed,
                                    float rfSpeed, float rbSpeed)
{
    ap_scLF->Set(lfSpeed);
    ap_scLB->Set(lbSpeed);
    ap_scRF->Set(rfSpeed);
    ap_scRB->Set(rbSpeed);
}

