#include "PWM.h"

int Period, dutyCycle;
int value;

 void PWM_setup(void)
 {
	
//set GPIO to work with timer	1
  GPIOPinConfigure(GPIO_PF1_T0CCP1);  //configure pf1 with timer 0 b
	GPIOPinConfigure(GPIO_PF2_T1CCP0);  //configure pf2 with timer 1 a
 GPIOPinConfigure(GPIO_PF3_T1CCP1);   //configure pf3 with timer 1 b
  GPIOPinTypeTimer(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3);
	 
  //define period and duty cycle
  Period = SysCtlClockGet()/100000; //800Hz
  dutyCycle = Period/2; //400Hz

//setup timer	0 (b) and timer 1 (a&b)
  SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER0); 
  SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER1);    

  TimerConfigure(TIMER0_BASE, TIMER_CFG_SPLIT_PAIR|TIMER_CFG_B_PWM);   
  TimerLoadSet(TIMER0_BASE, TIMER_B, Period -1);                     
  TimerMatchSet(TIMER0_BASE, TIMER_B, dutyCycle); 
  TimerConfigure(TIMER1_BASE, TIMER_CFG_SPLIT_PAIR|TIMER_CFG_A_PWM|TIMER_CFG_B_PWM);   
  TimerLoadSet(TIMER1_BASE, TIMER_A, Period -1);
  TimerLoadSet(TIMER1_BASE, TIMER_B, Period -1);  
  TimerMatchSet(TIMER1_BASE, TIMER_A, dutyCycle);  
  TimerMatchSet(TIMER1_BASE, TIMER_B, dutyCycle); 
	
	  //Turn on both timers
  TimerEnable(TIMER0_BASE, TIMER_B);
  TimerEnable(TIMER1_BASE, TIMER_A|TIMER_B);

	return;

 }

 void PWM_example(){
	 
	for (int x=0; x<=10; x++)
	 {
		for(int i=Period-2; i >  0;i--){          
			TimerMatchSet(TIMER1_BASE, TIMER_A, i);   // Blue on

			SysCtlDelay(time);
			}  
      
		//Blue brightness goes down - PF2
    for(int i=1; i < Period-1; i++){          //blue brightness goes down 
      TimerMatchSet(TIMER1_BASE, TIMER_A, i);  
      SysCtlDelay(time);
			}  
		
			for(int i=Period-2; i >  0;i--){           
			TimerMatchSet(TIMER0_BASE, TIMER_B, i);   // Red on

			SysCtlDelay(time);
			}  
			
					// red brightness goes down              
    for(int i=1; i < Period-1; i++){
      TimerMatchSet(TIMER0_BASE, TIMER_B, i); 			
      SysCtlDelay(time);
			} 

	    //Green brightness goes up - PF3         //green brightness 
    for(int i=Period-2; i >  0;i--){
      TimerMatchSet(TIMER1_BASE, TIMER_B, i);  
      SysCtlDelay(time);
			}  
 
			//Green brightness goes down              
    for(int i=1; i < Period-1; i++){
      TimerMatchSet(TIMER1_BASE, TIMER_B, i); 			
      SysCtlDelay(time);
			}
		}		
		
	  return;

}
