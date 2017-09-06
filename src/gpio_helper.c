#include "gpio_helper.h"

	//This function sets up GPIO pins
	void Gpio_setup()
	{
			SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);  // Enables the use of PORTF
			SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);  // Enables the use of PORTA
			SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);  // Enables the use of PORTD
		
			GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3); // Defines the RGB Leds as outputs
			GPIOPinTypeGPIOInput (GPIO_PORTF_BASE, GPIO_PIN_0|GPIO_PIN_4);  // Defines the two on board switches as inputs
			GPIOPinTypeGPIOInput (GPIO_PORTD_BASE, GPIO_PIN_6|GPIO_PIN_7);  // Adds port d to be used for the two MOM switches
		
			// The code below unlocks the buttons and sets the drive strength, this was taken from a TIVA example file
			HWREG(GPIO_PORTF_BASE + GPIO_O_LOCK) = GPIO_LOCK_KEY;
			HWREG(GPIO_PORTF_BASE + GPIO_O_CR)  = 0x01;
			HWREG(GPIO_PORTF_BASE + GPIO_O_LOCK) = 0;
			GPIODirModeSet(GPIO_PORTF_BASE, GPIO_PIN_4|GPIO_PIN_0, GPIO_DIR_MODE_IN);
			GPIOPadConfigSet(GPIO_PORTF_BASE,GPIO_PIN_4|GPIO_PIN_0,GPIO_STRENGTH_2MA,GPIO_PIN_TYPE_STD_WPU);
		
			GPIOPadConfigSet(GPIO_PORTD_BASE,GPIO_PIN_6|GPIO_PIN_7,GPIO_STRENGTH_2MA,GPIO_PIN_TYPE_STD_WPU); // This enables the pull up resistors on pin 6 and 7 
			GPIODirModeSet(GPIO_PORTD_BASE, GPIO_PIN_6|GPIO_PIN_7, GPIO_DIR_MODE_IN);												 // of portD and prevents needing to power and add 
																																																		   // resistors to the external mom switches.
	

	} 

	//This function retrieves the GPIO data
	void process_GPIO();
	{
		//code here.
	} 

	//This function prints the GPIO_DATA  
	//in a human readable format to the terminal
	void print_GPIO_data();
	{
		//Uart must be initialized first.
		//code here.
	} 