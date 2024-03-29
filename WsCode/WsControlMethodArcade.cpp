//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Wildstang 2010
//  @ File Name : WsControlMethodArcade.cpp
//  @ Date : 1/14/2009
//  @ Author : 
//
//


#include "WsControlMethodArcade.h"
#include "WsDriveVector.h"
#include "WsControllerAxis.h"
#include "WsControllerButton.h"
#include "WsDashboard.h"

/**
* Constructs a WsControlMethodArcade.  The drive stick and turbo button need to be assigned after construction.
*/
WsControlMethodArcade::WsControlMethodArcade()
{
    ap_driveStick = NULL;
    ap_turboButton = NULL;

    a_turboState = true;
    a_turboScaleFactor = 0.5;
}

/**
* Destructs a WsControlMethodArcade.
*/
WsControlMethodArcade::~WsControlMethodArcade()
{
}

/**
* Assigns the drive stick to the member variable
*/
void WsControlMethodArcade::assignDriveStick(WsControllerPolarStick* p_stick)
{
    ap_driveStick = p_stick;
}

/**
* Assigns the turbo button to the member variable
*/
void WsControlMethodArcade::assignTurboButton(WsControllerButton* p_turbo, TurboStyleT turboStyle)
{
    ap_turboButton = p_turbo;
    a_turboStyle = turboStyle;
}

/**
* Calculates the desired drive vector.
* The polar radius and angle map directly to the speed and direction of the vector.
* The turbo state is actually anti-turbo.  Turbo is on by default and turned off when the button is pressed.
* After the speed is calculated, it is scaled by the scale factor if turbo is off.
* @returns The desired drive vector
*/
WsDriveVector WsControlMethodArcade::getDriveVector(void )
{
    WsDriveVector v;
    float driveRadius = 0;
    float driveAngle = 0;

    if(ap_driveStick != NULL)
    {
        driveRadius = ap_driveStick->GetRadius();
        driveAngle = ap_driveStick->GetAngle();
    }


    if(ap_turboButton != NULL)
    {
        if(a_turboStyle == TURBO_STYLE_ANTI)
        {
            // Treat the turbo button as an anti-turbo
            // Turbo on when button not pressed
            // Turbo off when button pressed
            a_turboState = !ap_turboButton->getState();
        }
        else
        {
            a_turboState = ap_turboButton->getState();
        }
    }
    else
    {
        a_turboState = true;
    }

    if(a_turboState == false)
    {
        driveRadius *= a_turboScaleFactor;
    }

    v.a_speed = driveRadius;
    v.a_direction = driveAngle;
    v.a_x = ap_driveStick->GetX();
    v.a_y = ap_driveStick->GetY();

    return v;
}

/**
* An accessor function for the turbo state
* @returns The turbo state
*/
bool WsControlMethodArcade::getTurboState(void)
{
    return a_turboState;
}

/**
* Clears the turbo state
*/

void WsControlMethodArcade::clearTurboState(void)
{
    a_turboState = false;
}
