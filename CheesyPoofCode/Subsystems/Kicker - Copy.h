#ifndef _KICKER_H
#define _KICKER_H

#include "WPILib.h"

#define ROLLER_SPEED_DEFAULT_VAL	1.0
#define KICKER_PULLING_MOTOR_VAL	.5

/// This class contains the functionality of RAWC's 2010 Kicker
class Kicker
{
public:
	// FSM States
	enum KickerStates{
		STATE_KICKER_IDLE = 0,
		STATE_KICKER_PULLING,
		STATE_KICKER_LOCKED,
		STATE_KICKER_KICKING,
		STATE_KICKER_MOVING_DOWN,
		STATE_KICKER_STARTUP,
		STATE_KICKER_REZERO
		// May need to add kStateLatching for when lock is engaging
	};
	
	//Dont change these. It will break stuff.
	enum KickerDistances{
		KICKER_DISTANCE_NONE = 0,
		KICKER_DISTANCE_DEFAULT = 1,
		KICKER_DISTANCE_NEAR = 2,
		KICKER_DISTANCE_MIDDLE = 3,
		KICKER_DISTANCE_FAR = 4
	};

private:
	SpeedController * motor;
	SpeedController * roller;
	Solenoid * solenoid;
	AnalogChannel * sensor;
	Encoder * kickerSensor;
	Encoder * rollerSensor;
	
	// Map kicker distances to encoder ticks
	int GetEncoderPosition(KickerDistances distance);
	
	bool wantToKick;
	int count;
	int oldPosition;
	bool kickerReady;
	bool rollerOn;
	
	KickerStates cur_state;	 // FSM index
	KickerStates next_state;  // FSM Pusher
	KickerDistances distance, wantedDistance; //Distance index
	
public:
	Kicker(int winchMotorIn, int  solenoidIn, int rollerMotorIn, 
			int kickerEncoderAChannel, int kickerEncoderBChannel,
			int rollerEncoderAChannel, int rollerEncoderBChannel);
	
	~Kicker();
	void Handle(); // prod the FSM
	void SetDistance(KickerDistances dist);
	void Kick();  // make it kick on commands
	void Idle(); // set FSM to idle. This should let you kick, but will do nothing after
	void Run();  // set FSM back to run. This should also happen when you hit a distance button
	void SetRoller(bool isRollerOn);
	KickerDistances GetLockStatus();
	bool GetBallLock();
};

#endif
