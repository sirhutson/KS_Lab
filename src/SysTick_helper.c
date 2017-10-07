#include "SysTick_helper.h"
#include <inttypes.h>

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
void SysTickDifference(struct SysTickTimers * myTimer)
{
	int CounterVal = SysTickValueGet();
	TimeDiff = (periodSet-CounterVal)*(12.5);
	Mytimer.uSTimer = TimeDiff/(10^3);	//microsecond timer value
	Mytimer.mSTimer = TimeDiff/(10^6);	//millisecond timer value 
	printf("%" PRId64 "\n", Mytimer.uSTimer);
	printf("%" PRId32 "\n", Mytimer.mSTimer);
	
}


