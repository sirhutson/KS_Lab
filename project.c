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
