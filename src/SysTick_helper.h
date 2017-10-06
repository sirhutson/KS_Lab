#include <stdlib.h>
#include <stdint.h>
#include "../driverlib/systick.h"
#include "../driverlib/interrupt.h"

#include "../inc/hw_nvic.h"
#include "../inc/hw_types.h"

struct SysTickTimers
{
	uint32_t mSTimer;
	uint64_t uSTimer;
};

void SysTick_Setup(void);
void InterruptEnable(void);
int SysTickDifference(struct SysTickTimers * myTimer);

extern struct SysTickTimers Mytimer;
