#include "uart_helper.h"

//Redirect printf from Chase
void UART_OutChar(char data);
int fputc(int ch, FILE *f);

//This function sets up your Uart hardware
void Uart_setup()
{
	SysCtlPeripheralEnable(SYSCTL_PERIPH_UART0); //Turns on the UART port
	
	GPIOPinTypeUART(GPIO_PORTA_BASE, GPIO_PIN_0 | GPIO_PIN_1); //Names these pins as being the UART pins
	
	GPIOPinConfigure(GPIO_PA0_U0RX); //Pin 0 is configured as receive
	
	GPIOPinConfigure(GPIO_PA1_U0TX); //Pin 1 is configured as transmit

	SysCtlClockSet(SYSCTL_SYSDIV_1 | SYSCTL_USE_OSC | SYSCTL_OSC_MAIN |
                       SYSCTL_XTAL_16MHZ);   //This will be moved to a different module
	
	UARTConfigSetExpClk(UART0_BASE, SysCtlClockGet(), 38400,
                            (UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE |
                             UART_CONFIG_PAR_NONE));  // This was put in the UG as necessary not sure how the parameters affect the system
	
} 

void UART_OutChar(char data){
  while((UART0_FR_R&UART_FR_TXFF) != 0);
  UART0_DR_R = data;
}

// Print a character to UART.
int fputc(int ch, FILE *f){
  if((ch == 10) || (ch == 13) || (ch == 27)){
    UART_OutChar(13);
    UART_OutChar(10);
    return 1;
  }
  UART_OutChar(ch);
  return 1;
}

//This function retrieves UART data
void process_Uart(uint32_t base) // Processes data for any uart port but base must be entered as UARTx_BASE
{
		while(!UARTCharsAvail(base))  // This function waits until there is data to get
		{
			printf("NO DATA TO READ\n\r");
		}
		
		while(UARTCharGetNonBlocking(base)) // This gets the information from the port
		{
			printf("READING DATA IN\n\r");
			
		}
} 

//This function prints a menu in human readable format
void print_menu()
{
	int i;
	//char select[6];   // character array with the name select
	char select[] = {'A','B','C','D','E','F'};
	
	for(i=0;i<6;i++)
	{
		printf(" Please select letter to execute that function [%c]\n\r",select[i]);
	}
	
	
	// maybe create an array and have the value printed/sent to the uart port?
	//Uart must be initialized first.
	//code here.
}