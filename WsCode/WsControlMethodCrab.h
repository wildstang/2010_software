//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Wildstang 2010
//  @ File Name : WsControlMethodCrab.h
//  @ Date : 1/14/2009
//  @ Author : 
//
//


#if !defined(_WSCONTROLMETHODCRAB_H)
#define _WSCONTROLMETHODCRAB_H

#include <stdio.h>
#include <math.h>
#include "WsControlMethodArcade.h"
#include "WsDriveVector.h"
#include "WsControllerPolarStick.h"

class WsDashboard;

/**
* This control method implements crab input processing.
* A WsControllerPolarStick is used to calculate the crab angle.
* The WsControlMethodArcade base class handles the generation of the drive vector
*/
class WsControlMethodCrab : public WsControlMethodArcade
{
public:
    WsControlMethodCrab();
    virtual ~WsControlMethodCrab();
    void assignCrabStick(WsControllerPolarStick* p_stick);
    void assignCrabDisableButton(WsControllerButton* p_disable);
    void assignCrabManualButton(WsControllerButton* p_manual);
    void assignCrabManualSlowButton(WsControllerButton* p_manualSlow);
    void assignCrabReorientButton(WsControllerButton* p_reorient);
    virtual WsDriveVector getDriveVector(void );
    bool getCrabEnableState(void );
    float getCrabWheelAngle(void );
    float getCrabManualSpeed(void );

protected:
    typedef enum {
        CRAB_SIDE_NONE,  /*!< The last crab location was in the middle */
        CRAB_SIDE_LEFT,  /*!< The last crab location was to the left of center */
        CRAB_SIDE_RIGHT, /*!< The last crab location was to the right of center */
    } CrabSideT;

    WsControllerPolarStick *ap_crabStick;      /*!< The polar stick that will be used to calculate crab angle */
    WsControllerButton* ap_crabDisableButton;  /*!< The button that will enable/disable crab feedback*/
    WsControllerButton* ap_crabManualButton;   /*!< The button that will enable/disable manual crab movement*/
    WsControllerButton* ap_crabManualSlowButton;   /*!< The button that will enable/disable manual crab movement*/
    WsControllerButton* ap_crabReorientButton; /*!< The button that will change the virtual front of the robot*/
    float a_crab_stick_radius_thresh;          /*!< The stick radius at which crab is considered active */
    float a_crab_manu_scale;                   /*!< The scale factor to use for manual crab control */
    float a_crab_manu_slow_scale;                   /*!< The scale factor to use for manual crab control */
    CrabSideT a_crabSide;                      /*!< The side of middle that the crab angle was last iteration */
};

#endif  //_WSCONTROLMETHODCRAB_H
