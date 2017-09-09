#include "project.h"



int main()
{
			Gpio_setup() ; 

			while(1){
				if (GPIOPinRead(GPIO_PORTF_BASE, GPIO_PIN_0)==0x00){
					
			GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3,GPIO_PIN_3);
			}
		}
		
}


void read_from_terminal()
{
		switch()
		{
			case a:
			//input whatever the case and then end line
			break;
			case b:
			//input whatever the case and then end line
			break;
		
		}

	
	
}
