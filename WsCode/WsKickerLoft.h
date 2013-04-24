//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Wildstang
//  @ File Name : WsKickerLoft.h
//  @ Date : 1/27/2010
//  @ Author : 
//
//


#if !defined(_WSKICKERLOFT_H)
#define _WSKICKERLOFT_H

class WsSolenoid;

class WsKickerLoft {
public:
    typedef enum {
        KICKER_LOFT_NONE = 0,
        KICKER_LOFT_HIGH,
        KICKER_LOFT_LOW,
    } WsKickerLoftT;

    WsKickerLoft(WsSolenoid* p_solenoid);
    ~WsKickerLoft();
    void setLoft(WsKickerLoftT state);
    WsKickerLoft::WsKickerLoftT getLoft(void );
    void resetState(void );
protected:
    WsSolenoid* ap_solenoid;
    WsKickerLoftT a_state;
    WsKickerLoftT a_defaultState;
};

#endif  //_WSKICKERLOFT_H