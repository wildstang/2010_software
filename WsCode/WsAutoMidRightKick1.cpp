#include "WsAutoMidRightKick1.h"

#define ALLOW_KICK 1

WsAutoMidRightKick1::WsAutoMidRightKick1()
{
}

WsAutoMidRightKick1::~WsAutoMidRightKick1()
{
}

void WsAutoMidRightKick1::initParams(void)
{
    WsAutoNStepBase::WsAutoNStepCmdT setRangeNear;
    WsAutoNStepBase::WsAutoNStepCmdT loadKicker1;

    WsAutoNStepBase::WsAutoNStepCmdT drive1;
    WsAutoNStepBase::WsAutoNStepCmdT rev1;
    WsAutoNStepBase::WsAutoNStepCmdT kick1;
    WsAutoNStepBase::WsAutoNStepCmdT reload1;

    WsAutoNStepBase::initParams();

    a_expectedNumKicks = 1;

    // Attributes for setRangeNear
    setRangeNear.driveType = AUTO_DRIVE_TIME;
    setRangeNear.crabEnable = false;
    setRangeNear.crabAngle = 0;
    setRangeNear.driveVector.a_speed = 0;
    setRangeNear.driveVector.a_direction = 0;
    setRangeNear.driveTimeout = 0;
    setRangeNear.driveEncoderLoc = WsDriveBase::ENC_LOC_R;
    setRangeNear.driveEncoderDist = 0;
    setRangeNear.accumState = WsAccumulator::ACCUM_IN;
    setRangeNear.kickerCmd = AUTO_KICKER_CMD_SET_RANGE;
    setRangeNear.kickerRange = WsKickerRange::KICKER_RANGE_NEAR;
    setRangeNear.kickerLoft = WsKickerLoft::KICKER_LOFT_LOW;

    // Attributes for setRangeFar
    loadKicker1.driveType = AUTO_DRIVE_TIME;
    loadKicker1.crabEnable = false;
    loadKicker1.crabAngle = 0;
    loadKicker1.driveVector.a_speed = 0;
    loadKicker1.driveVector.a_direction = 0;
    loadKicker1.driveTimeout = 1.75;
    loadKicker1.driveEncoderLoc = WsDriveBase::ENC_LOC_R;
    loadKicker1.driveEncoderDist = 0;
    loadKicker1.accumState = WsAccumulator::ACCUM_IN;
    loadKicker1.kickerCmd = AUTO_KICKER_CMD_LOAD;
    loadKicker1.kickerRange = WsKickerRange::KICKER_RANGE_NEAR;
    loadKicker1.kickerLoft = WsKickerLoft::KICKER_LOFT_LOW;

    // Attributes for drive1
    drive1.driveType = AUTO_DRIVE_UNTIL_PRESS;
    drive1.crabEnable = false;
    drive1.crabAngle = 0;
    drive1.driveVector.a_speed = .2;
    drive1.driveVector.a_direction = 0;
    drive1.driveTimeout = 3;
    drive1.driveEncoderLoc = WsDriveBase::ENC_LOC_R;
    drive1.driveEncoderDist = 0;
    drive1.accumState = WsAccumulator::ACCUM_IN;
    drive1.kickerCmd = AUTO_KICKER_CMD_LOAD;
    drive1.kickerRange = WsKickerRange::KICKER_RANGE_NEAR;
    drive1.kickerLoft = WsKickerLoft::KICKER_LOFT_LOW;

    rev1.driveType = AUTO_DRIVE_ENCODER;
    rev1.crabEnable = false;
    rev1.crabAngle = 0;
    rev1.driveVector.a_speed = -.3;
    rev1.driveVector.a_direction = 0;
    rev1.driveTimeout = 1.5;
    rev1.driveEncoderLoc = WsDriveBase::ENC_LOC_R;
    rev1.driveEncoderDist = -30;
    rev1.accumState = WsAccumulator::ACCUM_IN;
    rev1.kickerCmd = AUTO_KICKER_CMD_LOAD;
    rev1.kickerRange = WsKickerRange::KICKER_RANGE_NEAR;
    rev1.kickerLoft = WsKickerLoft::KICKER_LOFT_LOW;

    // Attributes for kick1
    kick1.driveType = AUTO_DRIVE_TIME;
    kick1.crabEnable = false;
    kick1.crabAngle = 0;
    kick1.driveVector.a_speed = -.1;
    kick1.driveVector.a_direction = 0;
    kick1.driveTimeout = .2;
    kick1.driveEncoderLoc = WsDriveBase::ENC_LOC_R;
    kick1.driveEncoderDist = 0;
    kick1.accumState = WsAccumulator::ACCUM_IN;
    kick1.kickerCmd = AUTO_KICKER_CMD_KICK;
    kick1.kickerRange = WsKickerRange::KICKER_RANGE_NEAR;
    kick1.kickerLoft = WsKickerLoft::KICKER_LOFT_LOW;

    addStep(loadKicker1);

    addStep(drive1);
    //addStep(rev1);
    addStep(kick1);
}
