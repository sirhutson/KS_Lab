#include "SysTick_helper.h"

//Use the Systick and the NVIC to create code in Systick_helper.c and Systick_helper.h that meet the following requirements
//The software must have a global struct that contains a microseconds and milliseconds counter.
//The milliseconds counter must be 64 bit.
//The microseconds counter must be 32 bit.
//The counter must be extremely accurate.
//You must demonstrate the accuracy of the counter.
//Create a function that accepts 2 pointers to a timer struct and measures the time between difference between the events.
//Creata a function that accepts 2 pointers to a timer struct and returns a 1 or 0 depending on a certain amount of time has elapsed.
//Need a Global Struct- Lab requirements

//Taken from peripheral driver library
void SysTick_Setup()
{
	SysTickPeriodSet(1000); //Set the period to 1000 ticks
	SysTickEnable();
}

//Enable NVIC for something? 
void InterruptEnable()
{
	//write some code to setup an interrupt for SysTick Timer
	//where to put this code? 
	IntEnable(INT_GPIOF_TM4C123); //enables interrupt for PORTF
	
}

//Time delay using busy wait.
// The delay parameter is in units of the 80 MHz core clock. (12.5 ns)
void SysTickWait(unsigned long delay)
{
	HWREG(NVIC_ST_RELOAD) = delay - 1; // number of counts to wait
	HWREG(NVIC_ST_CURRENT) = 0; // any value written to CURRENT clears
	while ((HWREG(NVIC_ST_CTRL) &= 0x00010000) == 0)
	{
		// wait for count flag
	}
}
