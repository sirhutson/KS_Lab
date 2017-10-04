#include "project.h"



struct ADC_DATA ADCinfo;
struct SysTickTimers Mytimer;

void SysTick_Handler()
{
	Count = Count++;
}


void loading() // This function cuts the red led on and off, totally unneccessary 
{
int i;

	//while(GPIOPinRead(GPIO_PORTF_BASE,GPIO_PIN_4)!=0x00) //waits until you press the left button 
	//{
	//}
	for(i=0;i<10;i++)
		{
			SysCtlDelay(1000000);  // Random delay I chose
			GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_7,GPIO_PIN_7);
			GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1,GPIO_PIN_1); //Red Light On
			SysCtlDelay(1000000);  // Random delay I chose
			GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1,0); //Red Light Off
			GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_7,0);
		}
	
}

void LED_Display()
{
			while(GPIOPinRead(GPIO_PORTD_BASE, GPIO_PIN_6)!=0x00)  // waits for the user to press start
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

void read_from_terminal()
{
	char f;
	while(!UARTCharsAvail(UART0_BASE)) //waits until info is put on the UART PORT
{
	loading(); //blinks led while waiting
}

	process_UART(UART0_BASE);

	
	switch(f) //checks what character user inputted
	{
		case 'a':
		case 'A':
			printf("Executing function A which is...");
			break;
		
		case 'b':
		case 'B':
			printf("Executing function A which is...");
			break;
		
		case 'c':
		case 'C':
			printf("Executing function A which is...");
			break;
		
		case 'd':
		case 'D':
			printf("Executing function A which is...");
			break;
		
		case 'e':
		case 'E':
			printf("Executing function A which is...");
			break;
		
		case 'f':
		case 'F':
			printf("Executing function A which is...");
			break;
		
		default:
			printf("%c is not an option\n\r",f);
	}
		
}



int main()
{

		IntEnable(15);
		SysTick_Setup();	//Setup Systick & begin timer
		Gpio_setup();
		int uSTime = SysTickDifference(&Mytimer);	//read timer after GPIO setup.  
	
		UART_setup();
	
		//LED_Display();
	  
	  PWM_setup();
		PWM_example();
	
		
	
		//print_menu();
	
		//read_from_terminal();
}



