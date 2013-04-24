#include "WsAutoMidRightKick2.h"

#define ALLOW_KICK 1

WsAutoMidRightKick2::WsAutoMidRightKick2()
{
}

WsAutoMidRightKick2::~WsAutoMidRightKick2()
{
}

void WsAutoMidRightKick2::initParams(void)
{
    WsAutoNStepBase::WsAutoNStepCmdT setRangeNear;
    WsAutoNStepBase::WsAutoNStepCmdT loadKicker1;

    WsAutoNStepBase::WsAutoNStepCmdT drive1;
    WsAutoNStepBase::WsAutoNStepCmdT rev1;
    WsAutoNStepBase::WsAutoNStepCmdT kick1;
    WsAutoNStepBase::WsAutoNStepCmdT reload1;

    WsAutoNStepBase::WsAutoNStepCmdT drive2;
    WsAutoNStepBase::WsAutoNStepCmdT drive2a;
    WsAutoNStepBase::WsAutoNStepCmdT kick2;

    WsAutoNStepBase::WsAutoNStepCmdT pointWheels3;
    WsAutoNStepBase::WsAutoNStepCmdT drive3;
    WsAutoNStepBase::initParams();

    a_expectedNumKicks = 2;

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
    drive1.driveTimeout = 2;
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

    // Attributes for reload1
    reload1.driveType = AUTO_DRIVE_TIME;
    reload1.crabEnable = false;
    reload1.crabAngle = 0;
    reload1.driveVector.a_speed = 0;
    reload1.driveVector.a_direction = 0;
    reload1.driveTimeout = .5;
    reload1.driveEncoderLoc = WsDriveBase::ENC_LOC_R;
    reload1.driveEncoderDist = 0;
    reload1.accumState = WsAccumulator::ACCUM_IN;
    reload1.kickerCmd = AUTO_KICKER_CMD_LOAD;
    reload1.kickerRange = WsKickerRange::KICKER_RANGE_NEAR;
    reload1.kickerLoft = WsKickerLoft::KICKER_LOFT_LOW;

    // Attributes for drive2
    drive2.driveType = AUTO_DRIVE_UNTIL_PRESS;
    drive2.crabEnable = false;
    drive2.crabAngle = 0;
    drive2.driveVector.a_speed = .3;
    drive2.driveVector.a_direction = 0;
    drive2.driveTimeout = 2.5;
    drive2.driveEncoderLoc = WsDriveBase::ENC_LOC_R;
    drive2.driveEncoderDist = 0;
    drive2.accumState = WsAccumulator::ACCUM_IN;
    drive2.kickerCmd = AUTO_KICKER_CMD_LOAD;
    drive2.kickerRange = WsKickerRange::KICKER_RANGE_NEAR;
    drive2.kickerLoft = WsKickerLoft::KICKER_LOFT_LOW;

    // Attributes for drive2
    drive2a.driveType = AUTO_DRIVE_TIME;
    drive2a.crabEnable = false;
    drive2a.crabAngle = 0;
    drive2a.driveVector.a_speed = -.5;
    drive2a.driveVector.a_direction = 0;
    drive2a.driveTimeout = .4;
    drive2a.driveEncoderLoc = WsDriveBase::ENC_LOC_R;
    drive2a.driveEncoderDist = 0;
    drive2a.accumState = WsAccumulator::ACCUM_IN;
    drive2a.kickerCmd = AUTO_KICKER_CMD_LOAD;
    drive2a.kickerRange = WsKickerRange::KICKER_RANGE_NEAR;
    drive2a.kickerLoft = WsKickerLoft::KICKER_LOFT_LOW;


    // Attributes for kick2
    kick2.driveType = AUTO_DRIVE_TIME;
    kick2.crabEnable = false;
    kick2.crabAngle = 0;
    kick2.driveVector.a_speed = .3;
    kick2.driveVector.a_direction = 0;
    kick2.driveTimeout = .2;
    kick2.driveEncoderLoc = WsDriveBase::ENC_LOC_R;
    kick2.driveEncoderDist = 0;
    kick2.accumState = WsAccumulator::ACCUM_IN;
    kick2.kickerCmd = AUTO_KICKER_CMD_KICK;
    kick2.kickerRange = WsKickerRange::KICKER_RANGE_NEAR;
    kick2.kickerLoft = WsKickerLoft::KICKER_LOFT_LOW;

    // Attributes for drive3
    pointWheels3.driveType = AUTO_DRIVE_TIME;
    pointWheels3.crabEnable = true;
    pointWheels3.crabAngle = 90;
    pointWheels3.driveVector.a_speed = .2;
    pointWheels3.driveVector.a_direction = 0;
    pointWheels3.driveTimeout = 1;
    pointWheels3.driveEncoderLoc = WsDriveBase::ENC_LOC_R;
    pointWheels3.driveEncoderDist = 150;
    pointWheels3.accumState = WsAccumulator::ACCUM_IN;
    pointWheels3.kickerCmd = AUTO_KICKER_CMD_NONE;
    pointWheels3.kickerRange = WsKickerRange::KICKER_RANGE_NEAR;
    pointWheels3.kickerLoft = WsKickerLoft::KICKER_LOFT_LOW;

    // Attributes for drive3
    drive3.driveType = AUTO_DRIVE_ENCODER;
    drive3.crabEnable = true;
    drive3.crabAngle = 90;
    drive3.driveVector.a_speed = .5;
    drive3.driveVector.a_direction = 0;
    drive3.driveTimeout = 2;
    drive3.driveEncoderLoc = WsDriveBase::ENC_LOC_R;
    drive3.driveEncoderDist = 180;
    drive3.accumState = WsAccumulator::ACCUM_IN;
    drive3.kickerCmd = AUTO_KICKER_CMD_NONE;
    drive3.kickerRange = WsKickerRange::KICKER_RANGE_NEAR;
    drive3.kickerLoft = WsKickerLoft::KICKER_LOFT_LOW;


    addStep(loadKicker1);

    addStep(drive1);
    //addStep(rev1);
    addStep(kick1);
    addStep(reload1);

    addStep(drive2);
    //addStep(drive2a);
    addStep(kick2);

    addStep(pointWheels3);
    addStep(drive3);
}
