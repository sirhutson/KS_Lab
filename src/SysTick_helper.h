#include <stdlib.h>
#include <stdint.h>
#include "../driverlib/systick.h"
#include "../driverlib/interrupt.h"
#include "../inc/hw_ints.h"
#include "../inc/hw_nvic.h"
#include "../inc/hw_types.h"

//global struct 
struct SysTickTimer
{
	uint32_t uS_Timer;	//Need 32bit microsecond timer
	uint64_t mS_Timer;	//Need 64bit millisecond timer
};


void SysTick_Setup(void);
void InterruptEnable(void);
void SysTickWait(unsigned long delay);

