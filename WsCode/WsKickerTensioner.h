//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Wildstang
//  @ File Name : WsKickerTensioner.h
//  @ Date : 1/27/2010
//  @ Author : 
//
//


#if !defined(_WSKICKERTENSIONER_H)
#define _WSKICKERTENSIONER_H

class WsSolenoid;

class WsKickerTensioner {
public:
    typedef enum {
        KICKER_TENSION_NONE = 0,
        KICKER_TENSION_UP,
        KICKER_TENSION_DOWN,
    } WsKickerTensionT;

    WsKickerTensioner(WsSolenoid* p_solenoid);
    ~WsKickerTensioner();
    void setTension(WsKickerTensionT tension);
    WsKickerTensionT getTension(void );
    void resetState(void );
protected:
    WsSolenoid* ap_solenoid;
    WsKickerTensionT a_state;
    WsKickerTensionT a_defaultState;
};

#endif  //_WSKICKERTENSIONER_H
