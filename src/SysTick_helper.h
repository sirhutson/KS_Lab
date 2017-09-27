#include <stdlib.h>
#include <stdint.h>
#include "../driverlib/systick.h"
#include "../driverlib/interrupt.h"
#include "../inc/hw_ints.h"
#include "../inc/hw_nvic.h"
#include "../inc/hw_types.h"



//Variables
int Tdiff;

void SysTick_Setup(void);
void InterruptEnable(void);
void SysTickWait(unsigned long delay);
uint64_t SysTickDifference(uint32_t uSTimer, uint64_t mSTimer);


