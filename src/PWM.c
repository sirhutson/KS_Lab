#include "PWM.h"

int Period, dutyCycle;
int value;

 void PWM_setup(void)
 {

    //Set the clock
 // SysCtlClockSet(SYSCTL_SYSDIV_2_5|SYSCTL_USE_PLL|SYSCTL_OSC_MAIN|SYSCTL_XTAL_16MHZ);
	 //clock already set in adc_helper
	
//set GPIO to work with timer	1
  GPIOPinConfigure(GPIO_PF1_T0CCP1);  //configure pf1 with timer 0 b
	GPIOPinConfigure(GPIO_PF2_T1CCP0);  //configure pf2 with timer 1 a
 GPIOPinConfigure(GPIO_PF3_T1CCP1);   //configure pf3 with timer 1 b
 GPIOPinTypeTimer(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3);
	 
//define period and duty cycle
 //Period = SysCtlClockGet()/100000; //800Hz
  //dutyCycle = Period/2; //400Hz

//setup timer	0 (b) and timer 1 (a&b)
  SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER0); 
  SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER1);    
 // SysCtlDelay(3);
  TimerConfigure(TIMER0_BASE, TIMER_CFG_SPLIT_PAIR|TIMER_CFG_B_PWM);   
  TimerLoadSet(TIMER0_BASE, TIMER_B, Period -1);                     
  TimerMatchSet(TIMER0_BASE, TIMER_B, dutyCycle); 
  TimerConfigure(TIMER1_BASE, TIMER_CFG_SPLIT_PAIR|TIMER_CFG_A_PWM|TIMER_CFG_B_PWM);   
  TimerLoadSet(TIMER1_BASE, TIMER_A, Period -1);
  TimerLoadSet(TIMER1_BASE, TIMER_B, Period -1);  
  TimerMatchSet(TIMER1_BASE, TIMER_A, dutyCycle);  
  TimerMatchSet(TIMER1_BASE, TIMER_B, dutyCycle); 
	
	  //Turn on both timers
//TimerEnable(TIMER0_BASE, TIMER_B);
 // TimerEnable(TIMER1_BASE, TIMER_A|TIMER_B);
	return;

 }

 void PWM_example(){
	 
 value= GPIOPinRead(GPIO_PORTF_BASE, GPIO_PIN_0);
 if( (value & GPIO_PIN_0)==0){
	for (int x=0; x<=10; x++)
	 {
		for(int i=Period-2; i >  0;i--){            // Starts with Purple on
			TimerMatchSet(TIMER0_BASE, TIMER_B, i);   // Red on
			TimerMatchSet(TIMER1_BASE, TIMER_A, i);   // Blue on
			SysCtlDelay(time);
			}  
      
		   //Blue brightness goes down - PF2
    for(int i=1; i < Period-1; i++){          //blue brightness goes down and we are left with red
      TimerMatchSet(TIMER1_BASE, TIMER_A, i);  
      SysCtlDelay(time);
			}  

	    //Green brightness goes up - PF3         //green brightness goes up and mixes with red to make yellow?
    for(int i=Period-2; i >  0;i--){
      TimerMatchSet(TIMER1_BASE, TIMER_B, i);  
      SysCtlDelay(time);
			}  
 
			//Green and red brightness goes down - PF3 //both turn off               
    for(int i=1; i < Period-1; i++){
      TimerMatchSet(TIMER1_BASE, TIMER_B, i); 
      TimerMatchSet(TIMER0_BASE, TIMER_B, i);			
      SysCtlDelay(time);
			} 
			}
		}
	  return;

	}
