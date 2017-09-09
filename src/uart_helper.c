#include "uart_helper.h"


//This function sets up your Uart hardware
void Uart_setup()
{
	SysCtlPeripheralEnable(SYSCTL_PERIPH_UART0); //Turns on the UART port
	
	GPIOPinTypeUART(GPIO_PORTA_BASE, GPIO_PIN_0 | GPIO_PIN_1); //Names these pins as being the UART pins
	
	GPIOPinConfigure(GPIO_PA0_U0RX); //Pin 0 is configured as receive
	
	GPIOPinConfigure(GPIO_PA1_U0TX); //Pin 1 is configured as transmit

	SysCtlClockSet(SYSCTL_SYSDIV_1 | SYSCTL_USE_OSC | SYSCTL_OSC_MAIN |
                       SYSCTL_XTAL_4MHZ);   //This will be moved to a different module
	
	UARTConfigSetExpClk(UART0_BASE, SysCtlClockGet(), 115200,
                            (UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE |
                             UART_CONFIG_PAR_NONE));  // This was put in the UG as necessary not sure how the parameters affect the system
	
} 

//This function retrieves UART data
void process_Uart()
{
		while(UARTCharGet(UART0_BASE))  // This function waits until a character is put in the receive FIFO and then returns it
		{
		}
} 

//This function prints a menu in human readable format
void print_menu()
{
	// maybe create an array and have the value printed/sent to the uart port?
	//Uart must be initialized first.
	//code here.
}