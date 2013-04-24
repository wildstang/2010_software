//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Wildstang
//  @ File Name : WsKicker.h
//  @ Date : 1/27/2010
//  @ Author : 
//
//

#if !defined(_WSKICKER_H)
#define _WSKICKER_H
#include "WsKickerRange.h"
#include "WsKickerLoft.h"
#include "WsKickerTensioner.h"
#include "WsKickerLatch.h"
#include "Timer.h"

// These pause times are in ms and are used
// in the kicker state machine to pause to
// allow pneumatics to move as necessary
#define KICKER_PAUSE_INIT             1.0
#define KICKER_PAUSE_STOW             1.0
//#define KICKER_PAUSE_LOAD_NEAR        1.3
//#define KICKER_PAUSE_LOAD_FAR         1.3
#define KICKER_PAUSE_LOAD_NEAR        1.0
#define KICKER_PAUSE_LOAD_FAR         1.0
#define KICKER_PAUSE_LOAD_FAR_QUICK   .1
#define KICKER_PAUSE_ADJUST_LOFT      0.02
#define KICKER_PAUSE_SHOOT_NEAR       0.2
#define KICKER_PAUSE_SHOOT_FAR        0.2
#define KICKER_PAUSE_PREP_TRIGGER     0.02
#define KICKER_PAUSE_SET_NEAR_KICKER  1
#define KICKER_PAUSE_BABY_KICK        .4

class WsKickerCommand;
class WsSolenoid;
class DigitalInput;


class WsKicker {
public:

    typedef enum
    {
        KICKER_STATE_UNINIT = 0,
        KICKER_STATE_INIT,
        KICKER_STATE_STOW,
        KICKER_STATE_SET_NEAR_KICK,
        KICKER_STATE_SET_FAR_KICK,
        KICKER_STATE_LOAD_KICKER_NEAR,
        KICKER_STATE_LOAD_KICKER_FAR,
        KICKER_STATE_ADJUST_LOFT,
        KICKER_STATE_SHOOT_NEAR,
        KICKER_STATE_SHOOT_FAR,
        KICKER_STATE_PREP_TRIGGER,
        KICKER_STATE_LATCH_KICKER,
        KICKER_STATE_BABY_KICK,
        KICKER_STATE_ADJUST_LOFT_BABY,
    } WsKickerStateT;

    typedef enum
    {
        KICKER_CMD_NONE = 0,
        KICKER_CMD_INIT,
        KICKER_CMD_SET_RANGE_NEAR,
        KICKER_CMD_SET_RANGE_FAR,
        KICKER_CMD_PREPARE_TO_KICK,
        KICKER_CMD_KICK_LOW,
        KICKER_CMD_KICK_HIGH,
        KICKER_CMD_KICK_BABY_LOW,
        KICKER_CMD_KICK_BABY_HIGH,
        KICKER_CMD_STOW,
    } WsKickerCommandT;

    WsKicker(WsSolenoid *p_range, WsSolenoid *p_loft, WsSolenoid *p_tension,
        WsSolenoid *p_latch);
    ~WsKicker();

    void assignKickerSensors(DigitalInput* p_ballPossessedLimit);

    void setCommand(WsKickerCommandT command);
    void enable(bool enabled);
    void resetState(void );
    WsKicker::WsKickerStateT getState(void );

    bool isBallPossessed(void);
    bool isKicking(void);
    bool isStowed(void);

    // Get functions used by the dashboard
    bool getEnabled(void);
    WsKickerRange::WsKickerRangeT getKickerRange(void);
    WsKickerLoft::WsKickerLoftT getKickerLoft(void);
    WsKickerTensioner::WsKickerTensionT getKickerTension(void);
    WsKickerLatch::WsKickerLatchStateT getKickerLatch(void);
    WsKicker::WsKickerStateT getKickerState(void);




protected:
    bool a_enabled;
    WsKickerRange* ap_kickerRange;
    WsKickerLoft* ap_kickerLoft;
    WsKickerTensioner* ap_kickerTensioner;
    WsKickerLatch* ap_kickerLatch;
    DigitalInput* ap_ballPossessedLimit;

    WsKickerStateT a_state;
    WsKickerStateT a_statePrev;
    WsKickerStateT a_desiredNextState;
    WsKickerCommandT a_commandPrev;

    Timer a_pauseTimer;
};

#endif  //_WSKICKER_H
