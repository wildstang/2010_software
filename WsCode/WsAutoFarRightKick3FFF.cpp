#include "WsAutoFarRightKick3FFF.h"


WsAutoFarRightKick3FFN::WsAutoFarRightKick3FFN()
{
}

WsAutoFarRightKick3FFN::~WsAutoFarRightKick3FFN()
{
}

void WsAutoFarRightKick3FFN::initParams(void)
{
    WsAutoNStepBase::WsAutoNStepCmdT setRangeFar;
    WsAutoNStepBase::WsAutoNStepCmdT setRangeNear;
    WsAutoNStepBase::WsAutoNStepCmdT loadKicker1;

    WsAutoNStepBase::WsAutoNStepCmdT drive1;
    WsAutoNStepBase::WsAutoNStepCmdT rev1;
    WsAutoNStepBase::WsAutoNStepCmdT kick1;
    WsAutoNStepBase::WsAutoNStepCmdT reload1;

    WsAutoNStepBase::WsAutoNStepCmdT drive2;
    WsAutoNStepBase::WsAutoNStepCmdT rev2;
    WsAutoNStepBase::WsAutoNStepCmdT kick2;
    WsAutoNStepBase::WsAutoNStepCmdT reload2;

    WsAutoNStepBase::WsAutoNStepCmdT drive3;
    WsAutoNStepBase::WsAutoNStepCmdT rev3;
    WsAutoNStepBase::WsAutoNStepCmdT kick3;
    WsAutoNStepBase::WsAutoNStepCmdT stow;

    WsAutoNStepBase::initParams();

    a_expectedNumKicks = 3;

    // Set the overall encoder timeout for the program
    a_overallEncTimeout = 770;
    //a_overallEncTimeout = 1150;
    a_overallEncLoc = WsDriveBase::ENC_LOC_R;

    a_encoderToRevCmd.driveType = AUTO_DRIVE_ENCODER;
    a_encoderToRevCmd.crabEnable = false;
    a_encoderToRevCmd.crabAngle = 0;
    a_encoderToRevCmd.driveVector.a_direction = 0;
    a_encoderToRevCmd.driveVector.a_speed = -.5;
    a_encoderToRevCmd.driveTimeout = 2;
    a_encoderToRevCmd.driveEncoderDist = -200;
    a_encoderToRevCmd.driveEncoderLoc = WsDriveBase::ENC_LOC_R;
    a_encoderToRevCmd.accumState = WsAccumulator::ACCUM_IN;
    a_encoderToRevCmd.kickerCmd = AUTO_KICKER_CMD_KICK;
    a_encoderToRevCmd.kickerRange = WsKickerRange::KICKER_RANGE_FAR;
    a_encoderToRevCmd.kickerLoft = WsKickerLoft::KICKER_LOFT_HIGH;


    // Attributes for setRangeFar
    setRangeFar.driveType = AUTO_DRIVE_TIME;
    //setRangeFar.crabAngle = 2;
    setRangeFar.crabEnable = false;
    setRangeFar.crabAngle = 0;
    setRangeFar.driveVector.a_speed = 0;
    setRangeFar.driveVector.a_direction = 0;
    setRangeFar.driveTimeout = 0;
    setRangeFar.driveEncoderLoc = WsDriveBase::ENC_LOC_R;
    setRangeFar.driveEncoderDist = 0;
    setRangeFar.accumState = WsAccumulator::ACCUM_IN;
    setRangeFar.kickerCmd = AUTO_KICKER_CMD_SET_RANGE;
    setRangeFar.kickerRange = WsKickerRange::KICKER_RANGE_FAR;
    setRangeFar.kickerLoft = WsKickerLoft::KICKER_LOFT_HIGH;

    // Attributes for setRangeNear
    setRangeNear.driveType = AUTO_DRIVE_TIME;
    //setRangeNear.crabAngle = 2;
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
    setRangeNear.kickerLoft = WsKickerLoft::KICKER_LOFT_HIGH;

    // Attributes for setRangeFar
    loadKicker1.driveType = AUTO_DRIVE_TIME;
    //loadKicker1.crabAngle = 2;
    loadKicker1.crabEnable = false;
    loadKicker1.crabAngle = 0;
    loadKicker1.driveVector.a_speed = 0;
    loadKicker1.driveVector.a_direction = 0;
    loadKicker1.driveTimeout = 1.75;
    loadKicker1.driveEncoderLoc = WsDriveBase::ENC_LOC_R;
    loadKicker1.driveEncoderDist = 0;
    loadKicker1.accumState = WsAccumulator::ACCUM_IN;
    loadKicker1.kickerCmd = AUTO_KICKER_CMD_LOAD;
    loadKicker1.kickerRange = WsKickerRange::KICKER_RANGE_FAR;
    loadKicker1.kickerLoft = WsKickerLoft::KICKER_LOFT_HIGH;

    // Attributes for drive1
    drive1.driveType = AUTO_DRIVE_UNTIL_PRESS;
    //drive1.crabAngle = 2;
    drive1.crabEnable = false;
    drive1.crabAngle = 0;
    drive1.driveVector.a_speed = .3;
    drive1.driveVector.a_direction = 0;
    drive1.driveTimeout = 16;
    drive1.driveEncoderLoc = WsDriveBase::ENC_LOC_R;
    drive1.driveEncoderDist = 0;
    drive1.accumState = WsAccumulator::ACCUM_IN;
    drive1.kickerCmd = AUTO_KICKER_CMD_LOAD;
    drive1.kickerRange = WsKickerRange::KICKER_RANGE_FAR;
    drive1.kickerLoft = WsKickerLoft::KICKER_LOFT_HIGH;

    // Attributes for rev1
    rev1.driveType = AUTO_DRIVE_ENCODER;
    //rev1.crabAngle = 2;
    rev1.crabEnable = false;
    rev1.crabAngle = 0;
    rev1.driveVector.a_speed = -.2;
    rev1.driveVector.a_direction = 0;
    rev1.driveTimeout = 1.5;
    rev1.driveEncoderLoc = WsDriveBase::ENC_LOC_R;
    rev1.driveEncoderDist = -20;
    rev1.accumState = WsAccumulator::ACCUM_IN;
    rev1.kickerCmd = AUTO_KICKER_CMD_LOAD;
    rev1.kickerRange = WsKickerRange::KICKER_RANGE_FAR;
    rev1.kickerLoft = WsKickerLoft::KICKER_LOFT_HIGH;


    // Attributes for kick1
    kick1.driveType = AUTO_DRIVE_TIME;
    //kick1.crabAngle = 2;
    kick1.crabEnable = false;
    kick1.crabAngle = 0;
    kick1.driveVector.a_speed = .1;
    kick1.driveTimeout = .1;

    kick1.driveVector.a_direction = 0;
    kick1.driveEncoderLoc = WsDriveBase::ENC_LOC_R;
    kick1.driveEncoderDist = 0;
    kick1.accumState = WsAccumulator::ACCUM_IN;
    kick1.kickerCmd = AUTO_KICKER_CMD_KICK;
    kick1.kickerRange = WsKickerRange::KICKER_RANGE_FAR;
    kick1.kickerLoft = WsKickerLoft::KICKER_LOFT_HIGH;

    // Attributes for reload1
    reload1.driveType = AUTO_DRIVE_TIME;
    //reload1.crabAngle = 2;
    reload1.crabEnable = false;
    reload1.crabAngle = 0;
    reload1.driveVector.a_speed = 0;
    reload1.driveVector.a_direction = 0;
    reload1.driveTimeout = .5;
    reload1.driveEncoderLoc = WsDriveBase::ENC_LOC_R;
    reload1.driveEncoderDist = 0;
    reload1.accumState = WsAccumulator::ACCUM_IN;
    reload1.kickerCmd = AUTO_KICKER_CMD_LOAD;
    reload1.kickerRange = WsKickerRange::KICKER_RANGE_FAR;
    reload1.kickerLoft = WsKickerLoft::KICKER_LOFT_HIGH;

    // Attributes for drive2
    drive2.driveType = AUTO_DRIVE_UNTIL_PRESS;
    //drive2.crabAngle = 2;
    drive2.crabEnable = false;
    drive2.crabAngle = 0;
    drive2.driveVector.a_speed = .2;
    drive2.driveVector.a_direction = 0;
    drive2.driveTimeout = 16;
    drive2.driveEncoderLoc = WsDriveBase::ENC_LOC_R;
    drive2.driveEncoderDist = 0;
    drive2.accumState = WsAccumulator::ACCUM_IN;
    drive2.kickerCmd = AUTO_KICKER_CMD_LOAD;
    drive2.kickerRange = WsKickerRange::KICKER_RANGE_FAR;
    drive2.kickerLoft = WsKickerLoft::KICKER_LOFT_HIGH;

    // Attributes for rev2
    rev2.driveType = AUTO_DRIVE_ENCODER;
    //rev2.crabAngle = 2;
    rev2.crabEnable = false;
    rev2.crabAngle = 0;
    rev2.driveVector.a_speed = -.3;
    rev2.driveVector.a_direction = 0;
    rev2.driveTimeout = 1.5;
    rev2.driveEncoderLoc = WsDriveBase::ENC_LOC_R;
    rev2.driveEncoderDist = -10;
    rev2.accumState = WsAccumulator::ACCUM_IN;
    rev2.kickerCmd = AUTO_KICKER_CMD_NONE;
    rev2.kickerRange = WsKickerRange::KICKER_RANGE_FAR;
    rev2.kickerLoft = WsKickerLoft::KICKER_LOFT_HIGH;

    // Attributes for kick2
    kick2.driveType = AUTO_DRIVE_TIME;
    //kick2.crabAngle = 2;
    kick2.crabEnable = false;
    kick2.crabAngle = 0;
    kick2.driveVector.a_speed = .1;
    kick2.driveVector.a_direction = 0;
    kick2.driveTimeout = .1;
    kick2.driveEncoderLoc = WsDriveBase::ENC_LOC_R;
    kick2.driveEncoderDist = 0;
    kick2.accumState = WsAccumulator::ACCUM_IN;
    kick2.kickerCmd = AUTO_KICKER_CMD_KICK;
    kick2.kickerRange = WsKickerRange::KICKER_RANGE_FAR;
    kick2.kickerLoft = WsKickerLoft::KICKER_LOFT_HIGH;

    // Attributes for reload2
    reload2.driveType = AUTO_DRIVE_TIME;
    //reload2.crabAngle = 2;
    reload2.crabEnable = false;
    reload2.crabAngle = 0;
    reload2.driveVector.a_speed = 0;
    reload2.driveVector.a_direction = 0;
    reload2.driveTimeout = .5;
    reload2.driveEncoderLoc = WsDriveBase::ENC_LOC_R;
    reload2.driveEncoderDist = 0;
    reload2.accumState = WsAccumulator::ACCUM_IN;
    reload2.kickerCmd = AUTO_KICKER_CMD_LOAD;
    reload2.kickerRange = WsKickerRange::KICKER_RANGE_NEAR;
    reload2.kickerLoft = WsKickerLoft::KICKER_LOFT_HIGH;

    // Attributes for drive3
    drive3.driveType = AUTO_DRIVE_UNTIL_PRESS;
    //drive3.crabAngle = 2;
    drive3.crabEnable = false;
    drive3.crabAngle = 0;
    drive3.driveVector.a_speed = .3;
    drive3.driveVector.a_direction = 0;
    drive3.driveTimeout = 16;
    drive3.driveEncoderLoc = WsDriveBase::ENC_LOC_R;
    drive3.driveEncoderDist = 0;
    drive3.accumState = WsAccumulator::ACCUM_IN;
    drive3.kickerCmd = AUTO_KICKER_CMD_LOAD;
    drive3.kickerRange = WsKickerRange::KICKER_RANGE_NEAR;
    drive3.kickerLoft = WsKickerLoft::KICKER_LOFT_HIGH;

    // Attributes for rev3
    rev3.driveType = AUTO_DRIVE_ENCODER;
    //rev3.crabAngle = 2;
    rev3.crabEnable = false;
    rev3.crabAngle = 0;
    rev3.driveVector.a_speed = -.5;
    rev3.driveVector.a_direction = 0;
    rev3.driveTimeout = 1;
    rev3.driveEncoderLoc = WsDriveBase::ENC_LOC_R;
    rev3.driveEncoderDist = -30;
    rev3.accumState = WsAccumulator::ACCUM_IN;
    rev3.kickerCmd = AUTO_KICKER_CMD_LOAD;
    rev3.kickerRange = WsKickerRange::KICKER_RANGE_NEAR;
    rev3.kickerLoft = WsKickerLoft::KICKER_LOFT_HIGH;

    // Attributes for kick3
    kick3.driveType = AUTO_DRIVE_TIME;
    //kick3.crabAngle = 2;
    kick3.crabEnable = false;
    kick3.crabAngle = 0;
    kick3.driveVector.a_speed = 0;
    kick3.driveVector.a_direction = 0;
    kick3.driveTimeout = .3;
    kick3.driveEncoderLoc = WsDriveBase::ENC_LOC_R;
    kick3.driveEncoderDist = 0;
    kick3.accumState = WsAccumulator::ACCUM_IN;
    kick3.kickerCmd = AUTO_KICKER_CMD_KICK;
    kick3.kickerRange = WsKickerRange::KICKER_RANGE_NEAR;
    //kick3.kickerLoft = WsKickerLoft::KICKER_LOFT_HIGH;
    kick3.kickerLoft = WsKickerLoft::KICKER_LOFT_HIGH;

    addStep(loadKicker1);
    addStep(setRangeFar);

    addStep(drive1);
    //addStep(rev1);
    addStep(kick1);
    addStep(reload1);

    addStep(drive2);
    //addStep(rev2);
    addStep(kick2);
    addStep(reload2);

    addStep(drive3);
    addStep(rev3);
    addStep(kick3);

    addStep(setRangeNear);


}
