#include "WsAutoNearRightKick1.h"


WsAutoNearRightKick1::WsAutoNearRightKick1()
{
}

WsAutoNearRightKick1::~WsAutoNearRightKick1()
{
}

void WsAutoNearRightKick1::initParams(void)
{
    WsAutoNStepBase::WsAutoNStepCmdT drive1;
    WsAutoNStepBase::WsAutoNStepCmdT kick1;
    WsAutoNStepBase::WsAutoNStepCmdT drive2;
    WsAutoNStepBase::WsAutoNStepCmdT drive3;

    WsAutoNStepBase::initParams();

    a_expectedNumKicks = 1;

    // Attributes for drive1
    drive1.driveType = AUTO_DRIVE_UNTIL_PRESS;
    drive1.crabEnable = true;
    drive1.crabAngle = 0;
    drive1.driveVector.a_speed = .3;
    drive1.driveVector.a_direction = 0;
    drive1.driveTimeout = 1.2;
    drive1.driveEncoderLoc = WsDriveBase::ENC_LOC_R;
    drive1.driveEncoderDist = 0;
    drive1.accumState = WsAccumulator::ACCUM_IN;
    drive1.kickerCmd = AUTO_KICKER_CMD_NONE;
    drive1.kickerRange = WsKickerRange::KICKER_RANGE_NEAR;
    drive1.kickerLoft = WsKickerLoft::KICKER_LOFT_LOW;

    // Attributes for kick1
    kick1.driveType = AUTO_DRIVE_TIME;
    kick1.crabEnable = true;
    kick1.crabAngle = 0;
    kick1.driveVector.a_speed = 0;
    kick1.driveVector.a_direction = 0;
    kick1.driveTimeout = 1;
    kick1.driveEncoderLoc = WsDriveBase::ENC_LOC_L;
    kick1.driveEncoderDist = 0;
    kick1.accumState = WsAccumulator::ACCUM_OFF;
    kick1.kickerCmd = AUTO_KICKER_CMD_BABY_KICK_LOW;
    kick1.kickerRange = WsKickerRange::KICKER_RANGE_NEAR;
    kick1.kickerLoft = WsKickerLoft::KICKER_LOFT_LOW;

    // Attributes for drive2
    drive2.driveType = AUTO_DRIVE_ENCODER;
    drive2.crabEnable = true;
    drive2.crabAngle = 90;
    drive2.driveVector.a_speed = .7;
    drive2.driveVector.a_direction = 0;
    drive2.driveTimeout = 1.5;
    drive2.driveEncoderLoc = WsDriveBase::ENC_LOC_R;
    drive2.driveEncoderDist = 100;
    drive2.accumState = WsAccumulator::ACCUM_OFF;
    drive2.kickerCmd = AUTO_KICKER_CMD_NONE;
    drive2.kickerRange = WsKickerRange::KICKER_RANGE_NEAR;
    drive2.kickerLoft = WsKickerLoft::KICKER_LOFT_LOW;

    // Attributes for drive3
    drive3.driveType = AUTO_DRIVE_ENCODER;
    drive3.crabEnable = true;
    drive3.crabAngle = 90;
    drive3.driveVector.a_speed = 1;
    drive3.driveVector.a_direction = 90;
    drive3.driveTimeout = 10;
    drive3.driveEncoderLoc = WsDriveBase::ENC_LOC_R;
    drive3.driveEncoderDist = 900;
    drive3.accumState = WsAccumulator::ACCUM_OFF;
    drive3.kickerCmd = AUTO_KICKER_CMD_NONE;
    drive3.kickerRange = WsKickerRange::KICKER_RANGE_NEAR;
    drive3.kickerLoft = WsKickerLoft::KICKER_LOFT_LOW;
    // Add the steps to the program...order matters

    addStep(drive1);
    addStep(kick1);
    addStep(drive2);
    //addStep(drive3);
}
