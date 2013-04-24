//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Wildstang 2009
//  @ File Name : WsDriveBaseTank.h
//  @ Date : 1/14/2009
//  @ Author : 
//
//


#if !defined(_WSDRIVEBASETANK_H)
#define _WSDRIVEBASETANK_H

#include <stdio.h>
#include "WsDriveBase.h"

class WsDriveVector;
class WsDashboard;

class WsDriveBaseTank : public WsDriveBase
{
public:
    WsDriveBaseTank(WsSc* p_lf, WsSc* p_lb,
                    WsSc* p_rf, WsSc* p_rb);
    WsDriveBaseTank(WsSc* p_l, WsSc* p_r);
    virtual ~WsDriveBaseTank();
    virtual void setVector(WsDriveVector* p_vector);
    virtual void calcTankOutput(WsDriveVector* p_vector, float* p_lSpeed,
                                float* p_rSpeed);
    virtual void setTankOutput(float lfSpeed, float lbSpeed,
                               float rfSpeed, float rbSpeed);
protected:
    WsDashboard* ap_dashboard;
};

#endif  //_WSDRIVEBASETANK_H