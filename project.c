#include "project.h"
//*******************************************************************
// The focus of our project file is to demonstrate the functions of some
// of the peripherals available on the tiva board. In the main function
// all the peripherals are initialized and setup. Afterward the user is
// allowed to make a selection of what they would like demonstrated. It is
// setup in a one and done manner. Once a function is selected it is usually 
// set to stay in a loop. So it is neccesarry to reset the board to select another
// function.
//********************************************************************
struct ADC_DATA ADCinfo;
struct ADC_DATACONVERTED ADCconvertedinfo;
struct SysTickTimers Mytimer;

void SysTick_Handler()
{
	
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
			GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_7,GPIO_PIN_7); // Writes a 1 to pin 7
			GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1,GPIO_PIN_1); //Red Light On
			SysCtlDelay(1000000);  // Random delay I chose
			GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1,0); //Red Light Off
			GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_7,0); // Turns pin 7 off
		}
	
}

void LED_Display () // Function that allows user to change LED color based on pressing different buttons
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

void read_from_terminal() // Grabs user selection from UART Port to execute desired function
{
	char f;
	while(!UARTCharsAvail(UART0_BASE)) //waits until info is put on the UART PORT
{
	loading(); //blinks led while waiting
}

	process_UART(UART0_BASE); // function defined in uart_helper file

	
	switch(f) //checks what character user inputted
	{
		case 'a':
		case 'A':
			printf("Executing function A which is NVIC/SYSTick for whatever reason");
			break;
		
		case 'b':
		case 'B':
			printf("Executing function B which is a loading 'screen' ");
			loading();
			break;
		
		case 'c':
		case 'C':
			printf("Executing function C which is get ADC data");
			process_ADC(&ADCinfo);
			print_ADC_DATA(&ADCinfo);
			break;
		
		case 'd':
		case 'D':
			printf("Executing function D which is LED display");
			LED_Display();
			break;
		
		case 'e':
		case 'E':
			printf("Executing function E which is turn motor left"); // no motor exists led will just pwm 
			PWM_example();
			break;
		
		case 'f':
		case 'F':
			printf("Executing function F which is turn motor right"); // no motor exists led will just pwm 
			PWM_example();
			break;
		
		default:
			printf("%c is not an option\n\r",f);
	}
		
}
int main()
{

		ADC_setup(); // goes first because it has the clock settings 
		Gpio_setup(); 
	
		UART_setup();

		  
	  PWM_setup();

		print_menu();
		read_from_terminal();

}