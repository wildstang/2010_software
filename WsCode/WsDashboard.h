#if !defined(_WSDASHBOARD_H)
#define _WSDASHBOARD_H

#include <stdio.h>
#include <vector>
#include "WsDriveVector.h"
#include "WsVisionTarget.h"

class Dashboard;
class Timer;


#define USE_VISION_TIMER 0
#define USE_DATA_TIMER 0


typedef enum
{
    ////////////////////////////////////
    SECTION_DRIVE_START,
    IDX_IN_DRIVE_X = SECTION_DRIVE_START,
    IDX_IN_DRIVE_Y,
    IDX_IN_DRIVE_RADIUS,
    IDX_IN_DRIVE_ANGLE,
    IDX_IN_DRIVE_TURBO,
    IDX_IN_DRIVE_BUTTON_2,
    IDX_IN_DRIVE_BUTTON_3,
    IDX_IN_DRIVE_BUTTON_4,
    IDX_IN_CRAB_X,
    IDX_IN_CRAB_Y,
    IDX_IN_CRAB_RADIUS,
    IDX_IN_CRAB_ANGLE,
    IDX_IN_CRAB_DISABLE,
    IDX_IN_CRAB_MANUAL,
    IDX_IN_ENCODER1_VALUE,
    IDX_IN_ENCODER1_DIST,
    IDX_IN_ENCODER1_RATE,
    IDX_IN_ENCODER2_VALUE,
    IDX_IN_ENCODER2_DIST,
    IDX_IN_ENCODER2_RATE,
    SECTION_DRIVE_END = IDX_IN_ENCODER2_RATE,
    ////////////////////////////////////

    ////////////////////////////////////
    SECTION_CRAB_START,
    IDX_CRAB_CURRENT_POT = SECTION_CRAB_START,
    IDX_CRAB_PID_TARGET,
    IDX_CRAB_PID_P,
    IDX_CRAB_PID_I,
    IDX_CRAB_PID_D,
    IDX_CRAB_PID_EPS,
    IDX_CRAB_CALIB_LEFT,
    IDX_CRAB_CALIB_MID,
    IDX_CRAB_CALIB_RIGHT,
    SECTION_CRAB_END = IDX_CRAB_CALIB_RIGHT,
    ////////////////////////////////////

    ////////////////////////////////////
    SECTION_OUTPUT_START,
    IDX_OUT_DRIVE_FL = SECTION_OUTPUT_START,
    IDX_OUT_DRIVE_FR,
    IDX_OUT_DRIVE_BL,
    IDX_OUT_DRIVE_BR,
    IDX_OUT_CRAB_L,
    IDX_OUT_CRAB_R,
    SECTION_OUTPUT_END = IDX_OUT_CRAB_R,
    ////////////////////////////////////

    ////////////////////////////////////
    SECTION_APPENDAGE_INPUT_START,
    IDX_APPENDAGE_IN_ACCUM_IN = SECTION_APPENDAGE_INPUT_START,
    IDX_APPENDAGE_IN_ACCUM_OUT,
    IDX_APPENDAGE_IN_ACCUM_BAR_UP,
    IDX_APPENDAGE_IN_RANGE_NEAR,
    IDX_APPENDAGE_IN_RANGE_FAR,
    IDX_APPENDAGE_IN_PREPARE_KICKER,
    IDX_APPENDAGE_IN_KICK_LOW,
    IDX_APPENDAGE_IN_KICK_HIGH,
    IDX_APPENDAGE_IN_KICK_BABY,
    IDX_APPENDAGE_IN_STOW,
    IDX_APPENDAGE_IN_KICKER_CMD,
    IDX_APPENDAGE_IN_BALL_POSSESSED,
    SECTION_APPENDAGE_INPUT_END = IDX_APPENDAGE_IN_BALL_POSSESSED,
    ////////////////////////////////////

    ////////////////////////////////////
    SECTION_APPENDAGE_OUTPUT_START,
    IDX_APPENDAGE_OUT_KICKER_ENABLE = SECTION_APPENDAGE_OUTPUT_START,
    IDX_APPENDAGE_OUT_RANGE,
    IDX_APPENDAGE_OUT_LOFT,
    IDX_APPENDAGE_OUT_TENSIONER,
    IDX_APPENDAGE_OUT_LATCH,
    IDX_APPENDAGE_OUT_ACCUM,
    IDX_APPENDAGE_OUT_KICKER_STATE,
    IDX_APPENDAGE_OUT_BAR_STATE,
    SECTION_APPENDAGE_OUTPUT_END = IDX_APPENDAGE_OUT_BAR_STATE,
    ////////////////////////////////////

    ////////////////////////////////////
    SECTION_PID_TUNING_START,
    IDX_CRAB_TUNING_ENABLED = SECTION_PID_TUNING_START,
    IDX_CRAB_TUNING_TESTING,
    IDX_CRAB_TUNING_P,
    IDX_CRAB_TUNING_I,
    IDX_CRAB_TUNING_D,
    IDX_CRAB_TUNING_EPS,
    IDX_CRAB_TUNING_INCR_SMALL,
    IDX_CRAB_TUNING_INCR_LARGE,
    IDX_CRAB_TUNING_STEP_SIZE,
    IDX_CRAB_TUNING_SET_POINT,
    IDX_CRAB_TUNING_CURRENT_VALUE,
    IDX_CRAB_TUNING_OUTPUT,
    IDX_CRAB_TUNING_CURRENT_PARAM,
    SECTION_PID_TUNING_END = IDX_CRAB_TUNING_CURRENT_PARAM,
    ////////////////////////////////////

    ////////////////////////////////////
    SECTION_GENERAL_START,
    IDX_GENERAL_TEST_INT = SECTION_GENERAL_START,
    IDX_GENERAL_TEST_FLOAT,
    IDX_GENERAL_TEST_BOOL,
    IDX_GENERAL_ANALOG_PRESSURE,
    IDX_GENERAL_SW_DISABLE,
    SECTION_GENERAL_END = IDX_GENERAL_SW_DISABLE,
    ////////////////////////////////////

    ////////////////////////////////////
    SECTION_AUTONOMOUS_START,
    IDX_AUTO_PROG_NUM = SECTION_AUTONOMOUS_START,
    IDX_AUTO_START_LOC,
    IDX_AUTO_START_DELAY,
    IDX_AUTO_LOCK,
    SECTION_AUTONOMOUS_END = IDX_AUTO_LOCK,
    ////////////////////////////////////

    ////////////////////////////////////
    SECTION_VISION_START,
    IDX_VISION_DATA = SECTION_VISION_START,
    SECTION_VISION_END = IDX_VISION_DATA,
    ////////////////////////////////////



    // All indicies go above here
    MAX_NUM_DATA_IDX
} DashboardIndexT;

typedef enum
{
    DATA_TYPE_BOOL,
    DATA_TYPE_UINT32,
    DATA_TYPE_INT32,
    DATA_TYPE_FLOAT,
    DATA_TYPE_VISION,
} DashboardDataTypeT;

class DriverStation;

class DashboardDataBase
{
    public:
        virtual void reset(void) = 0;
        virtual void get(bool* value)
        {
            *value = false;
        }
        virtual void get(UINT32* value)
        {
            *value = 0;
        }
        virtual void get(INT32* value)
        {
            *value = 0;
        }
        virtual void get(float* value)
        {
            *value = 0;
        }
        virtual void get(std::vector<WsVisionTarget>& targets)
        {
            std::vector<WsVisionTarget> temp;
            targets = temp;
        }
        virtual void set(bool value)
        {
        }
        virtual void set(UINT32 value)
        {
        }
        virtual void set(INT32 value)
        {
        }
        virtual void set(float value)
        {
        }
        virtual void set(const std::vector<WsVisionTarget>& targets)
        {
        }

        DashboardDataTypeT a_dataType;

};
class DashboardDataBool : public DashboardDataBase
{
    public:
        DashboardDataBool()
        {
            a_dataType = DATA_TYPE_BOOL;
            reset();
        }
        virtual void reset(void)
        {
            a_value = false;
        }
        virtual void set(bool value)
        {
            a_value = value;
        }
        virtual void get(bool* value)
        {
            *value = a_value;
        }
    protected:
        bool a_value;

};
class DashboardDataUINT32 : public DashboardDataBase
{
    public:
        DashboardDataUINT32()
        {
            a_dataType = DATA_TYPE_UINT32;
            reset();
        }
        virtual void reset(void)
        {
            a_value = 0;
        }
        virtual void set(UINT32 value)
        {
            a_value = value;
        }
        virtual void get(UINT32* value)
        {
            *value = a_value;
        }
    protected:
        UINT32 a_value;
};
class DashboardDataINT32 : public DashboardDataBase
{
    public:
        DashboardDataINT32()
        {
            a_dataType = DATA_TYPE_INT32;
            reset();
        }
        virtual void reset(void)
        {
            a_value = 0;
        }
        virtual void set(INT32 value)
        {
            a_value = value;
        }
        virtual void get(INT32* value)
        {
            *value = a_value;
        }
    protected:
        INT32 a_value;
};
class DashboardDataFloat : public DashboardDataBase
{
    public:
        DashboardDataFloat()
        {
            a_dataType = DATA_TYPE_FLOAT;
            reset();
        }
        virtual void reset(void)
        {
            a_value = 0;
        }
        virtual void set(float value)
        {
            a_value = value;
        }
        virtual void get(float *value)
        {
            *value = a_value;
        }
    protected:
        float a_value;
};

class DashboardDataVision : public DashboardDataBase
{
    public:
        DashboardDataVision()
        {
            a_dataType = DATA_TYPE_VISION;
            reset();
        }

        virtual ~DashboardDataVision()
        {
        }

        virtual void reset(void)
        {
            a_targets.clear();
        }

        virtual void set(const std::vector<WsVisionTarget>& targets)
        {
            a_targets = targets;
        }

        virtual void get(std::vector<WsVisionTarget>& targets)
        {
            targets = a_targets;
        }

    protected:
        std::vector<WsVisionTarget> a_targets;
};


class WsDashboard
{
public:
    virtual ~WsDashboard();
    // This should be called by the robot to assign the DS
    static WsDashboard* getInstance(DriverStation* p_ds);
    // This should be called by classes that will update data
    static WsDashboard* getInstance();
    void resetValues(void);
    void update(void);

    void setValue(DashboardIndexT index, bool value);
    void setValue(DashboardIndexT index, UINT32 value);
    void setValue(DashboardIndexT index, INT32 value);
    void setValue(DashboardIndexT index, float value);
    void setValue(DashboardIndexT index, std::vector<WsVisionTarget>& value);

    void getValue(DashboardIndexT index, bool* value);
    void getValue(DashboardIndexT index, UINT32* value);
    void getValue(DashboardIndexT index, INT32* value);
    void getValue(DashboardIndexT index, float* value);
    void getValue(DashboardIndexT index, std::vector<WsVisionTarget>& value);

protected:
    WsDashboard(DriverStation* p_ds);
    static WsDashboard* ap_instance;

    // There are two top level data streams: data and vision
    void updateDataSections(void);
    void updateVisionSection(void);

    // Each subsection has its own pack method
    void packDriveSection(Dashboard& dashboard);
    void packCrabSection(Dashboard& dashboard);
    void packOutputSection(Dashboard& dashboard);
    void packAppendageInputSection(Dashboard& dashboard);
    void packAppendageOutputSection(Dashboard& dashboard);
    void packGeneralSection(Dashboard& dashboard);
    void packAutoSection(Dashboard& dashboard);
    void packPidTuningSection(Dashboard& dashboard);

    void packVisionSection(Dashboard& dashboard);

    // This is a generic function that knows how to pack
    // all data types.  It will determine the type based on index
    void packData(Dashboard& dashboard, const int& index);

    DriverStation* ap_ds;
    DashboardDataBase* a_data[MAX_NUM_DATA_IDX];

#if USE_DATA_TIMER
    Timer *dataTimer;
#endif
#if USE_VISION_TIMER
    Timer *visionTimer;
#endif
};

#endif  //_WSDASHBOARD_H

