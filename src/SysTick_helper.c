#include "SysTick_helper.h"

//Use the Systick and the NVIC to create code in Systick_helper.c and Systick_helper.h that meet the following requirements
//The software must have a global struct that contains a microseconds and milliseconds counter.
//The milliseconds counter must be 64 bit.
//The microseconds counter must be 32 bit.
//The counter must be extremely accurate.
//You must demonstrate the accuracy of the counter.
//Create a function that accepts 2 pointers to a timer struct and measures the time difference between the events.
//Creata a function that accepts 2 pointers to a timer struct and returns a 1 or 0 depending on a certain amount of time has elapsed.
//Need a Global Struct- Lab requirements

int periodSet = 0x0000000F;
int TimeDiff;
int Count = 0;

void SysTick_Setup()
{
	SysTickPeriodSet(periodSet); //Set the period to ?? ticks
	SysTickIntEnable(); //enable NVIC
	SysTickEnable();		//enable Systick (starts counting)

}

//Create a function that accepts 2 pointers to a timer struct and measures the time difference between the events.
int SysTickDifference(struct SysTickTimers * myTimer)
{
	int CounterVal = SysTickValueGet();
	TimeDiff = (periodSet-CounterVal)*(12.5);
	Mytimer.uSTimer = TimeDiff/(10^3);	//not sure this is right
	Mytimer.mSTimer = TimeDiff/(10^6);
	
	return Mytimer.uSTimer;
}


