#include "Kicker.h"
#include "../RAWCRobot.h"
#include "../RAWCConstants.h"
#include "WPILib.h"


/// Constructor. This will
Kicker::Kicker(int winchMotorIn, int  solenoidIn, int rollerMotorIn, 
		int kickerEncoderAChannel, int kickerEncoderBChannel,
		int rollerEncoderAChannel, int rollerEncoderBChannel)
{
	// motors and such
	motor = new Victor(winchMotorIn);
	solenoid = new Solenoid(solenoidIn);
	roller = new Victor(rollerMotorIn);
	
	kickerSensor = new Encoder(kickerEncoderAChannel, kickerEncoderBChannel, true);
	rollerSensor = new Encoder(rollerEncoderAChannel, rollerEncoderBChannel, true);
	
	kickerSensor->Start();
	rollerSensor->Start();
	
	//FSM init
	cur_state = STATE_KICKER_STARTUP;
	next_state = cur_state;
	
	// state vars
	wantToKick = false;
	distance = KICKER_DISTANCE_NONE;
	wantedDistance = KICKER_DISTANCE_NONE;
	
	count = 0;
	oldPosition = 0;
	kickerReady = false;
	rollerOn = false;
}

Kicker::~Kicker()
{
	delete motor;
	delete solenoid;
	delete roller;
	delete kickerSensor;
	delete rollerSensor;
}

void Kicker::SetDistance(KickerDistances dist)
{
	wantedDistance = dist;
}

// FSM handler
void Kicker::Handle()
{
	static bool isSettling = false;
	static int initCounts = 0;
	int position = kickerSensor->Get();
	float motorValue = 0.0;
	float rollerValue = 0.0;
	bool locked = true;
	
	// Handle the roller
	if(rollerOn)
		rollerValue = ROLLER_SPEED_DEFAULT_VAL;
	
	switch(cur_state){
	
	case STATE_KICKER_STARTUP:
		motorValue = 0;
		locked = true;
		if(wantToKick)
			next_state = STATE_KICKER_REZERO;
		break;
		
	case STATE_KICKER_REZERO:
		motorValue = 0;
		locked = false;
		if( position > (oldPosition -1) && position < (oldPosition+1)){
			isSettling = true;
			if(initCounts > 5){
				next_state = STATE_KICKER_IDLE;
				wantedDistance = KICKER_DISTANCE_DEFAULT;
				kickerSensor->Reset();
				position = kickerSensor->Get();
				initCounts = 0;
			}
			initCounts++;
		}
		else {
			isSettling = false;
			initCounts = 0;
		}
		break;
		
	case STATE_KICKER_IDLE:
		motorValue = 0;
		locked = false;
		kickerReady = true;
		initCounts++;
		if(wantToKick){// still holding button
			wantToKick = false;
			locked = false;
			break;
		}
		
		wantToKick = false;
		if (wantedDistance != KICKER_DISTANCE_NONE && initCounts > 10)
			next_state = STATE_KICKER_PULLING;
		
		break;
	
	case STATE_KICKER_PULLING:
		motorValue = KICKER_PULLING_MOTOR_VAL;
		distance = KICKER_DISTANCE_NONE;
		locked = true;
		//TODO: Replace this with a sensor reading
		if( position > GetEncoderPosition(wantedDistance))
		{
			next_state = STATE_KICKER_LOCKED;
			distance = wantedDistance;
		}

		break;
	
	case STATE_KICKER_LOCKED:
		if(wantedDistance != distance)
		{
			if(wantedDistance > distance)
				next_state = STATE_KICKER_PULLING;
			else
				next_state = cur_state;
				//next_state = STATE_KICKER_MOVING_DOWN;
		}
		locked = true;
		motorValue = 0;
		break;
	
	case STATE_KICKER_KICKING:
		rollerValue = 0;
		distance = KICKER_DISTANCE_NONE;
		wantedDistance = KICKER_DISTANCE_DEFAULT;
		locked = false;
		//Dont let it pull until it hits the end
		//TODO: Replace this with a sensor reading
		if(position  <= 0){
			wantToKick = false;
			next_state = STATE_KICKER_IDLE;
		}
		break;
	
	case STATE_KICKER_MOVING_DOWN:
		//TODO: Make this do the right thing
		next_state = STATE_KICKER_IDLE;
		break;
	default:
		break;
	}
		
	// Jump to a kick
	if(wantToKick && kickerReady)
		next_state = STATE_KICKER_KICKING;
	
	// Keep track of sensor
	oldPosition = position;
		
	// Set outputs
	locked = (locked) ? KICKER_LOCK_ENGAGED : KICKER_LOCK_OPEN;
	solenoid->Set(locked);
	
	
	// Clip the motor
	if(motorValue < 0)
	{
		motorValue = 0;
	}
	motor->Set(motorValue);
	
	roller->Set(rollerValue);
	
	// Poke state machine
	cur_state = next_state;
	
	count++;
	if(count % 20 == 0)  ;
		//printf("State: %d , Kicker Pos: %d - Wanted Dist: %d - Wanted Pos: %d\r\n", 
			//	cur_state, position , wantedDistance, (int) getEncoderPosition(wantedDistance));
		//printf("Kicker State: %d \tSensor: %d\tMotor: %f\tLock: %d\r\n", cur_state, position,motorValue,locked);
}

/// Transform the KickerDistances enum into real world pot/encoder values
int Kicker::GetEncoderPosition(KickerDistances distance)
{
	RAWCConstants * rc = RAWCConstants::GetInstance();
	int retValue;
	printf("-----------%d", distance);
	switch(distance)
	{
	case KICKER_DISTANCE_NONE:
		retValue = 0;
		break;
	case KICKER_DISTANCE_NEAR:
		retValue = (int) rc->GetValueForKey("KickerPosNear");
		break;
	case KICKER_DISTANCE_MIDDLE:
		retValue = (int) rc->GetValueForKey("KickerPosMiddle");
		break;
	case KICKER_DISTANCE_FAR:
		retValue =(int) rc->GetValueForKey("KickerPosFar");
		break;
	case KICKER_DISTANCE_DEFAULT:
		retValue = (int) rc->GetValueForKey("KickerPosShort");
		break;
	default:
		retValue = 0;
		break;
	}
	
	return retValue;
}

/// Tell kicker to kick
void Kicker::Kick()
{
	wantToKick = true;
}

/// Sets whether the roller is on or off
void Kicker::SetRoller(bool isRollerOn){
	rollerOn = isRollerOn;
}

/// Tell kicker to sit and wait
void Kicker::Idle()
{
	// set FSM to idle. This should let you kick, but will do nothing after
}

/// Tell kicker to start functioning as normal
void Kicker::Run()
{
	
}

/// Get whether the kicker is locked in
Kicker::KickerDistances Kicker::GetLockStatus()
{
	if(cur_state == STATE_KICKER_LOCKED)
		return distance;
	else return KICKER_DISTANCE_NONE;
}

bool Kicker::GetBallLock()
{
	if(rollerOn && (cur_state != STATE_KICKER_KICKING)){
		if( rollerSensor->GetRate() < 500)
			return true;
	}
	return false;
}
