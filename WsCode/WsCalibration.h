//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Wildstang 2009
//  @ File Name : WsCalibration.h
//  @ Date : 1/19/2009
//  @ Author : 
//
//


#if !defined(_WSCALIBRATION_H)
#define _WSCALIBRATION_H

#include <stdio.h>

#define CALIBRATION_FILENAME "/ws_calib"
#define PROTO_FILENAME "/ws_proto"
#define OLD_ROBOT_FILENAME "/ws_old"

/**
* This is a singleton that handles anything on the robot that requires calibration
*/
class WsCalibration
{
public:
    typedef enum
    {
      CRAB_MID = 0, /**< Index of the crab midpoint parameter */
      CRAB_LEFT,    /**< Index of the crab left extreme parameter */
      CRAB_RIGHT,   /**< Index of the crab right extreme parameter */
      ENCODER_FL,   /**< Index of the front left encoder parameter */
      ENCODER_FR,   /**< Index of the front right encoder parameter */
      ENCODER_BL,   /**< Index of the back left encoder parameter */
      ENCODER_BR,   /**< Index of the back right encoder parameter */

      /* do not change the line below */
      MAX_NUM_VALUES,
    } CalibrationIndexT;

    virtual ~WsCalibration();
    static WsCalibration* getInstance();
    void saveData();
    void readData();
    void printValues();
    bool isCompetitionRobot(void );
    bool isOldRobot(void );
    UINT32 getValue(CalibrationIndexT index);
    void setValue(CalibrationIndexT index, UINT32 value);

protected:
    WsCalibration();

    UINT32 a_data[MAX_NUM_VALUES]; /*!< An internal data array that holds the configuration values*/
    bool a_competitionRobot;       /*!< An internal flag that denotes whether the current robot is competition or proto*/
    bool a_oldRobot;               /*!< An internal flag that denotes whether the current robot is 2010 or 2009*/

private:
    static WsCalibration* ap_instance; /*!< The singleton instance */
};

#endif  //_WSCALIBRATION_H