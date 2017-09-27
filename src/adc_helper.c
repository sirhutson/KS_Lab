#include "adc_helper.h"

void ADC_setup()
{
	// Initialize PLL in order to use ADC, this is equivalent to using SysCtlClockSet()
	// function from the library...Trash way to do it lol
	
	SYSCTL_RCC_R |= (1 << 11); //sets the bypass bit
	SYSCTL_RCC_R &= ~(1 << 22); //clears usesys bit
	SYSCTL_RCC_R |= (0x15<<6); //select 16mhz as xtal value
	SYSCTL_RCC_R &= ~(1<<4); //select osc source as main
	SYSCTL_RCC_R &= ~(1<<13); //clear the pwrdn bits
	SYSCTL_RCC_R |= (0xB<<23); // sets the sysdiv for 16.change mhz
	SYSCTL_RCC_R |= (1 << 22);//now we set the usesys bit
	while(SYSCTL_RIS_PLLLRIS==0) //waits until the pll has locked
	{
	}
	SYSCTL_RCC_R &= ~(1<<11); //clears bypass bit to use pll
	
	// Enable ADC clock
	
	SYSCTL_RCGCADC_R |= SYSCTL_RCGCADC_R0; // enables clock gating for ADC0
	
	// Enable clock to correct port
	
	SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R3; //turns on portD clock gating
	
	//Configure proper pins
	
  GPIO_PORTD_AFSEL_R |= 0x03; //enable alt function on pins 0 and 1
	GPIO_PORTD_PCTL_R |= GPIO_PCTL_PD0_AIN7; //PIN 0 is now analog in 
	GPIO_PORTD_PCTL_R |= GPIO_PCTL_PD1_AIN6; //PIN 1 is now analog in 
	GPIO_PORTD_DEN_R &= ~0x03; //Clear bits so that it will function as analog
	GPIO_PORTD_AMSEL_R |= 0x03; //Analog function enabled and isolation turned off
	
	ADCSequenceDisable(ADC0_BASE, 0);
	
	ADCSequenceConfigure(ADC0_BASE, 0, ADC_TRIGGER_PROCESSOR, 0);
	
	ADCSequenceStepConfigure(ADC0_BASE, 0, 0,ADC_CTL_CH0);
	ADCSequenceStepConfigure(ADC0_BASE, 0, 1,ADC_CTL_CH1| ADC_CTL_END);
	
	ADCSequenceEnable(ADC0_BASE, 0);
	
}
    


void process_ADC()
{
	uint32_t * adcstuff;   // variable that will store adc information
	adcstuff = (uint32_t *) &ADCinfo; 

	
	ADCProcessorTrigger(ADC0_BASE, 0);  // Trigger the sample sequence.

	while(!ADCIntStatus(ADC0_BASE, 0, false))  // Wait until the sample sequence has completed.
	{
	}

	ADCSequenceDataGet(ADC0_BASE, 0, adcstuff);  // Read the value from the ADC.

	
}


void print_ADC_DATA(struct ADC_DATA * ADCinfo)
{
	printf("The information gathered from the analog to digital converter is %02x\n\r", ADCinfo->POT1);
	printf("The information gathered from the analog to digital converter is %02x\n\r", ADCinfo->POT2);
	
}







