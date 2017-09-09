#include "project.h"



int main()
{
		Gpio_setup();
	
		//insert function that blinks red light specified number of times as if it were booting the system up

			while(GPIOPinRead(GPIO_PORTF_BASE, GPIO_PIN_0)!=0x00)  // waits for the user to press start
			{
				//if (GPIOPinRead(GPIO_PORTF_BASE, GPIO_PIN_0)!=0x00)
					//{
						GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3,GPIO_PIN_3); // gives user the green light start touching stuff
					//}
			}
		GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3,0); // cuts off green light
		GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2,GPIO_PIN_2);  // blue light indicates user has begun touching stuff and process is under way
		
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

