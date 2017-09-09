#include "project.h"

void loading() // This function cuts the red led on and off, totally unneccessary 
{
int i;
i = 10; 
	
	for(i=0;i<10;i++)
		{
			SysCtlDelay(1000000);  // Random delay I chose
			GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1,GPIO_PIN_1); //Red Light On
			SysCtlDelay(1000000);  // Random delay I chose
			GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1,0); //Red Light Off

		}
	
}

void LED_Display()
{
			while(GPIOPinRead(GPIO_PORTF_BASE, GPIO_PIN_0)!=0x00)  // waits for the user to press start
					{
								
						SysCtlDelay(1000000);  // Random delay I chose
						SysCtlDelay(1000000);  // Random delay I chose
		
					
						GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3,GPIO_PIN_3); // gives user the green light start touching stuff
					
					}
		
		SysCtlDelay(1000000);  // Random delay I chose
		
		GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3,0); // cuts off green light
		
		SysCtlDelay(1000000);  // Random delay I chose
		
		GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2,GPIO_PIN_2);  // blue light indicates user has begun touching stuff and process is under way
			
}	
int main()
{
		Gpio_setup();
	
		loading(); //function that blinks red light specified number of times as if it were booting the system up
		
		LED_Display();
				
}


//void read_from_terminal()
//{
//		switch()
//		{
//			case a:
//			//input whatever the case and then end line
//			break;
//			case b:
//			//input whatever the case and then end line
//			break;
//		
//		}

//	
//}	

