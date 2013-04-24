#include "WsDashboard.h"
#include "WPILib.h"
#include "Timer.h"
#include "DriverStation.h"
#include "WsDriveVector.h"

WsDashboard* WsDashboard::ap_instance = NULL;

WsDashboard::WsDashboard(DriverStation* p_ds)
{
    int i;

#if USE_DATA_TIMER
    dataTimer = new Timer();
    dataTimer->Start();
#endif

#if USE_VISION_TIMER
    visionTimer = new Timer();
    visionTimer->Start();
#endif

    ap_ds = p_ds;
    for(i = 0; i < MAX_NUM_DATA_IDX; i++)
    {
        a_data[i] = NULL;
    }

    a_data[IDX_IN_DRIVE_X] = new DashboardDataFloat();
    a_data[IDX_IN_DRIVE_Y] = new DashboardDataFloat();
    a_data[IDX_IN_DRIVE_RADIUS] = new DashboardDataFloat();
    a_data[IDX_IN_DRIVE_ANGLE] = new DashboardDataFloat();
    a_data[IDX_IN_DRIVE_TURBO] = new DashboardDataBool();
    a_data[IDX_IN_DRIVE_BUTTON_2] = new DashboardDataBool();
    a_data[IDX_IN_DRIVE_BUTTON_3] = new DashboardDataBool();
    a_data[IDX_IN_DRIVE_BUTTON_4] = new DashboardDataBool();

    a_data[IDX_IN_CRAB_X] = new DashboardDataFloat();
    a_data[IDX_IN_CRAB_Y] = new DashboardDataFloat();
    a_data[IDX_IN_CRAB_RADIUS] = new DashboardDataFloat();
    a_data[IDX_IN_CRAB_ANGLE] = new DashboardDataFloat();
    a_data[IDX_IN_CRAB_DISABLE] = new DashboardDataBool();
    a_data[IDX_IN_CRAB_MANUAL] = new DashboardDataBool();
    a_data[IDX_IN_ENCODER1_VALUE] = new DashboardDataINT32();
    a_data[IDX_IN_ENCODER1_DIST] = new DashboardDataFloat();
    a_data[IDX_IN_ENCODER1_RATE] = new DashboardDataFloat();
    a_data[IDX_IN_ENCODER2_VALUE] = new DashboardDataINT32();
    a_data[IDX_IN_ENCODER2_DIST] = new DashboardDataFloat();
    a_data[IDX_IN_ENCODER2_RATE] = new DashboardDataFloat();

    a_data[IDX_CRAB_CURRENT_POT] = new DashboardDataUINT32();
    a_data[IDX_CRAB_PID_TARGET] = new DashboardDataUINT32();
    a_data[IDX_CRAB_PID_P] = new DashboardDataFloat();
    a_data[IDX_CRAB_PID_I] = new DashboardDataFloat();
    a_data[IDX_CRAB_PID_D] = new DashboardDataFloat();
    a_data[IDX_CRAB_PID_EPS] = new DashboardDataFloat();
    a_data[IDX_CRAB_CALIB_LEFT] = new DashboardDataUINT32();
    a_data[IDX_CRAB_CALIB_MID] = new DashboardDataUINT32();
    a_data[IDX_CRAB_CALIB_RIGHT] = new DashboardDataUINT32();

    a_data[IDX_OUT_DRIVE_FL] = new DashboardDataFloat();
    a_data[IDX_OUT_DRIVE_FR] = new DashboardDataFloat();
    a_data[IDX_OUT_DRIVE_BL] = new DashboardDataFloat();
    a_data[IDX_OUT_DRIVE_BR] = new DashboardDataFloat();
    a_data[IDX_OUT_CRAB_L] = new DashboardDataFloat();
    a_data[IDX_OUT_CRAB_R] = new DashboardDataFloat();


    a_data[IDX_APPENDAGE_IN_ACCUM_IN] = new DashboardDataBool();
    a_data[IDX_APPENDAGE_IN_ACCUM_OUT] = new DashboardDataBool();
    a_data[IDX_APPENDAGE_IN_ACCUM_BAR_UP] = new DashboardDataBool();
    a_data[IDX_APPENDAGE_IN_RANGE_NEAR] = new DashboardDataBool();
    a_data[IDX_APPENDAGE_IN_RANGE_FAR] = new DashboardDataBool();
    a_data[IDX_APPENDAGE_IN_PREPARE_KICKER] = new DashboardDataBool();
    a_data[IDX_APPENDAGE_IN_KICK_LOW] = new DashboardDataBool();
    a_data[IDX_APPENDAGE_IN_KICK_HIGH] = new DashboardDataBool();
    a_data[IDX_APPENDAGE_IN_KICK_BABY] = new DashboardDataBool();
    a_data[IDX_APPENDAGE_IN_STOW] = new DashboardDataBool();
    a_data[IDX_APPENDAGE_IN_KICKER_CMD] = new DashboardDataUINT32();
    a_data[IDX_APPENDAGE_IN_BALL_POSSESSED] = new DashboardDataBool();

    a_data[IDX_APPENDAGE_OUT_KICKER_ENABLE] = new DashboardDataBool();
    a_data[IDX_APPENDAGE_OUT_RANGE] = new DashboardDataBool();
    a_data[IDX_APPENDAGE_OUT_LOFT] = new DashboardDataBool();
    a_data[IDX_APPENDAGE_OUT_TENSIONER] = new DashboardDataBool();
    a_data[IDX_APPENDAGE_OUT_LATCH] = new DashboardDataBool();
    a_data[IDX_APPENDAGE_OUT_ACCUM] = new DashboardDataUINT32();
    a_data[IDX_APPENDAGE_OUT_KICKER_STATE] = new DashboardDataUINT32();
    a_data[IDX_APPENDAGE_OUT_BAR_STATE] = new DashboardDataBool();

    a_data[IDX_VISION_DATA] = new DashboardDataVision();

    a_data[IDX_GENERAL_TEST_INT] = new DashboardDataUINT32();
    a_data[IDX_GENERAL_TEST_FLOAT] = new DashboardDataFloat();
    a_data[IDX_GENERAL_TEST_BOOL] = new DashboardDataBool();
    a_data[IDX_GENERAL_ANALOG_PRESSURE] = new DashboardDataFloat();
    a_data[IDX_GENERAL_SW_DISABLE] = new DashboardDataBool();

    a_data[IDX_AUTO_PROG_NUM] = new DashboardDataUINT32();
    a_data[IDX_AUTO_START_LOC] = new DashboardDataUINT32();
    a_data[IDX_AUTO_START_DELAY] = new DashboardDataFloat();
    a_data[IDX_AUTO_LOCK] = new DashboardDataBool();

    a_data[IDX_CRAB_TUNING_ENABLED] = new DashboardDataBool();
    a_data[IDX_CRAB_TUNING_TESTING] = new DashboardDataBool();
    a_data[IDX_CRAB_TUNING_P] = new DashboardDataFloat();
    a_data[IDX_CRAB_TUNING_I] = new DashboardDataFloat();
    a_data[IDX_CRAB_TUNING_D] = new DashboardDataFloat();
    a_data[IDX_CRAB_TUNING_EPS] = new DashboardDataFloat();
    a_data[IDX_CRAB_TUNING_INCR_SMALL] = new DashboardDataFloat();
    a_data[IDX_CRAB_TUNING_INCR_LARGE] = new DashboardDataFloat();
    a_data[IDX_CRAB_TUNING_STEP_SIZE] = new DashboardDataFloat();
    a_data[IDX_CRAB_TUNING_SET_POINT] = new DashboardDataUINT32();
    a_data[IDX_CRAB_TUNING_CURRENT_VALUE] = new DashboardDataUINT32();
    a_data[IDX_CRAB_TUNING_OUTPUT] = new DashboardDataFloat();
    a_data[IDX_CRAB_TUNING_CURRENT_PARAM] = new DashboardDataUINT32();

    /*
    for(i = 0; i < MAX_NUM_DATA_IDX; i++)
    {
        if(a_data[i] != NULL)
        {
            a_data[i]->reset();
        }
    }
    */
}

WsDashboard::~WsDashboard()
{
    int i;
    for(i = 0; i < MAX_NUM_DATA_IDX; i++)
    {
        if(a_data[i] != NULL)
        {
            delete a_data[i];
            a_data[i] = NULL;
        }
    }

    if(ap_instance != NULL)
    {
        delete ap_instance;
    }

    ap_instance = NULL;

#if USE_DATA_TIMER
    dataTimer->Stop();
    delete dataTimer;
#endif

#if USE_VISION_TIMER
    visionTimer->Stop();
    delete visionTimer;
#endif
}

WsDashboard* WsDashboard::getInstance()
{
   return ap_instance;
}

WsDashboard* WsDashboard::getInstance(DriverStation* p_ds)
{
    if(ap_instance == NULL)
    {
        ap_instance = new WsDashboard(p_ds);
    }
    return ap_instance;
}

void WsDashboard::setValue(DashboardIndexT index, bool value)
{
    a_data[index]->set(value);
}

void WsDashboard::setValue(DashboardIndexT index, UINT32 value)
{
    a_data[index]->set(value);
}

void WsDashboard::setValue(DashboardIndexT index, INT32 value)
{
    a_data[index]->set(value);
}

void WsDashboard::setValue(DashboardIndexT index, float value)
{
    a_data[index]->set(value);
}

void WsDashboard::setValue(DashboardIndexT index, std::vector<WsVisionTarget>& value)
{
    a_data[index]->set(value);
}

void WsDashboard::getValue(DashboardIndexT index, bool* value)
{
    a_data[index]->get(value);
}

void WsDashboard::getValue(DashboardIndexT index, UINT32* value)
{
    a_data[index]->get(value);
}

void WsDashboard::getValue(DashboardIndexT index, INT32* value)
{
    a_data[index]->get(value);
}

void WsDashboard::getValue(DashboardIndexT index, float* value)
{
    a_data[index]->get(value);
}

void WsDashboard::getValue(DashboardIndexT index, std::vector<WsVisionTarget>& value)
{
    a_data[index]->get(value);
}


void WsDashboard::resetValues()
{
    int i;
    for(i = 0; i < MAX_NUM_DATA_IDX; i++)
    {
        a_data[i]->reset();
    }
}

void WsDashboard::update()
{
    updateDataSections();
    //updateVisionSection();
}


void WsDashboard::updateDataSections(void)
{
#if USE_DATA_TIMER
    if (dataTimer->Get() < 0.1)
    {
        return;
    }
    dataTimer->Reset();
#endif

    Dashboard &dataDashboardPacker = ap_ds->GetLowPriorityDashboardPacker();

    // ORDER MATTERS!!!
    packDriveSection(dataDashboardPacker);
    packCrabSection(dataDashboardPacker);
    packOutputSection(dataDashboardPacker);
    packAppendageInputSection(dataDashboardPacker);
    packAppendageOutputSection(dataDashboardPacker);
    packGeneralSection(dataDashboardPacker);
    packPidTuningSection(dataDashboardPacker);
    packAutoSection(dataDashboardPacker);

    // Flush the data to the driver station
    dataDashboardPacker.Finalize();
}

void WsDashboard::updateVisionSection(void)
{
#if USE_VISION_TIMER
    if (visionTimer->Get() < 0.03)
    {
        return;
    }
    visionTimer->Reset();
#endif

    Dashboard &visionDashboardPacker = ap_ds->GetHighPriorityDashboardPacker();
    packVisionSection(visionDashboardPacker);

    // Flush the data to the driver station
    visionDashboardPacker.Finalize();
}

void WsDashboard::packGeneralSection(Dashboard& dashboard)
{
    int i;
    dashboard.AddCluster();
    for(i = SECTION_GENERAL_START; i <= SECTION_GENERAL_END; i++)
    {
        packData(dashboard, i);
    }
    dashboard.FinalizeCluster();
}

void WsDashboard::packDriveSection(Dashboard& dashboard)
{
    int i;
    dashboard.AddCluster();
    for(i = SECTION_DRIVE_START; i <= SECTION_DRIVE_END; i++)
    {
        packData(dashboard, i);
    }
    dashboard.FinalizeCluster();
}

void WsDashboard::packCrabSection(Dashboard& dashboard)
{
    int i;
    dashboard.AddCluster();
    for(i = SECTION_CRAB_START; i <= SECTION_CRAB_END; i++)
    {
        packData(dashboard, i);
    }
    dashboard.FinalizeCluster();
}

void WsDashboard::packOutputSection(Dashboard& dashboard)
{
    int i;
    dashboard.AddCluster();
    for(i = SECTION_OUTPUT_START; i <= SECTION_OUTPUT_END; i++)
    {
        packData(dashboard, i);
    }
    dashboard.FinalizeCluster();
}

void WsDashboard::packAppendageInputSection(Dashboard& dashboard)
{
    int i;
    dashboard.AddCluster();
    for(i = SECTION_APPENDAGE_INPUT_START; i <= SECTION_APPENDAGE_INPUT_END; i++)
    {
        packData(dashboard, i);
    }
    dashboard.FinalizeCluster();
}

void WsDashboard::packAppendageOutputSection(Dashboard& dashboard)
{
    int i;
    dashboard.AddCluster();
    for(i = SECTION_APPENDAGE_OUTPUT_START; i <= SECTION_APPENDAGE_OUTPUT_END; i++)
    {
        packData(dashboard, i);
    }
    dashboard.FinalizeCluster();
}

void WsDashboard::packPidTuningSection(Dashboard& dashboard)
{
    int i;
    dashboard.AddCluster();
    for(i = SECTION_PID_TUNING_START; i <= SECTION_PID_TUNING_END; i++)
    {
        packData(dashboard, i);
    }
    dashboard.FinalizeCluster();
}

void WsDashboard::packAutoSection(Dashboard& dashboard)
{
    int i;
    dashboard.AddCluster();
    for(i = SECTION_AUTONOMOUS_START; i <= SECTION_AUTONOMOUS_END; i++)
    {
        packData(dashboard, i);
    }
    dashboard.FinalizeCluster();
}

void WsDashboard::packVisionSection(Dashboard& dashboard)
{
    unsigned int i;
    static UINT32 count  = 0;

    std::vector<WsVisionTarget> targets;

    // If we had more than one piece of vision data we would need to loop, but since we only have
    // one, we'll hard code the index
    getValue(IDX_VISION_DATA, targets);

    dashboard.AddCluster(); // target Info (2 elements)
    {
        dashboard.AddArray(); // targets
        {
            for (i = 0; i < targets.size(); i++)
            {
                WsVisionTarget target = targets.at(i);
                dashboard.AddCluster(); // targets
                {
                    dashboard.AddDouble(target.a_score); // target score
                    dashboard.AddCluster(); // Circle Description (5 elements)
                    {
                        dashboard.AddCluster(); // Position (2 elements)
                        {
                            dashboard.AddFloat((float) (target.a_xPos / target.a_xMax)); // X
                            dashboard.AddFloat((float) target.a_yPos); // Y
                        }
                        dashboard.FinalizeCluster();

                        dashboard.AddDouble(target.a_rotation); // Angle
                        dashboard.AddDouble(target.a_majorRadius); // Major Radius
                        dashboard.AddDouble(target.a_minorRadius); // Minor Radius
                        dashboard.AddDouble(target.a_rawScore); // Raw score
                    }
                    dashboard.FinalizeCluster(); // Position
                }
                dashboard.FinalizeCluster(); // targets
            }
        }
        dashboard.FinalizeArray();
        dashboard.AddU32( count++);
    }
    dashboard.FinalizeCluster(); // target Info
}

void WsDashboard::packData(Dashboard& dashboard, const int& index)
{
    bool valueBool;
    UINT32 valueUINT32;
    INT32 valueINT32;
    float valueFloat;

    switch(a_data[index]->a_dataType)
    {
        case DATA_TYPE_BOOL:
            a_data[index]->get(&valueBool);
            dashboard.AddBoolean(valueBool);
            break;
        case DATA_TYPE_UINT32:
            a_data[index]->get(&valueUINT32);
            dashboard.AddU32(valueUINT32);
            break;
        case DATA_TYPE_INT32:
            a_data[index]->get(&valueINT32);
            dashboard.AddI32(valueINT32);
            break;
        case DATA_TYPE_FLOAT:
            a_data[index]->get(&valueFloat);
            dashboard.AddFloat(valueFloat);
            break;
        default:
            break;
    }
}
