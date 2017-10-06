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
	SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R4; //turns on portE clock gating
	
	//Configure proper pins
	
  GPIO_PORTD_AFSEL_R |= 0x0F; //enable alt function on pins 0-3
	GPIO_PORTE_AFSEL_R |= 0x03; //enable alt function on pins 0 and 1 of E
	GPIO_PORTE_PCTL_R |= GPIO_PCTL_PE0_AIN3; //PIN 0 is now analog in 
	GPIO_PORTE_PCTL_R |= GPIO_PCTL_PE1_AIN2; //PIN 1 is now analog in
	GPIO_PORTD_PCTL_R |= GPIO_PCTL_PD0_AIN7; //PIN 0 is now analog in 
	GPIO_PORTD_PCTL_R |= GPIO_PCTL_PD1_AIN6; //PIN 1 is now analog in 
	GPIO_PORTD_PCTL_R |= GPIO_PCTL_PD2_AIN5; //PIN 2 is now analog in 
	GPIO_PORTD_PCTL_R |= GPIO_PCTL_PD3_AIN4; //PIN 3 is now analog in
	GPIO_PORTD_DEN_R &= ~0x0F; // Clear bits so that it will function as analog
	GPIO_PORTD_AMSEL_R |= 0x0F; // Analog function enabled and isolation turned off
	GPIO_PORTE_DEN_R &= ~0x03;  // Clear bits so that it will function as analog
	GPIO_PORTE_AMSEL_R |= 0x03; // Analog function enabled and isolation turned off
	
	
	ADCReferenceSet(ADC0_BASE, ADC_REF_EXT_3V); // sets adc reference to three volts so that the conversion is accurate
	
	ADCSequenceDisable(ADC0_BASE, 0);
	
	ADCSequenceConfigure(ADC0_BASE, 0, ADC_TRIGGER_PROCESSOR, 0);
	
	ADCSequenceStepConfigure(ADC0_BASE, 0, 0,ADC_CTL_CH0);
	ADCSequenceStepConfigure(ADC0_BASE, 0, 1,ADC_CTL_CH1);
	ADCSequenceStepConfigure(ADC0_BASE, 0, 2,ADC_CTL_CH2);
	ADCSequenceStepConfigure(ADC0_BASE, 0, 3,ADC_CTL_CH3);
	ADCSequenceStepConfigure(ADC0_BASE, 0, 4,ADC_CTL_CH4);
	ADCSequenceStepConfigure(ADC0_BASE, 0, 5,ADC_CTL_CH5| ADC_CTL_END);
	
	ADCSequenceEnable(ADC0_BASE, 0);
	
}
    


void process_ADC( struct ADC_DATA * data_ptr )
{
	uint32_t * adcstuff;   // variable that will store adc information
	adcstuff = (uint32_t *) &ADCinfo; 

	
	ADCProcessorTrigger(ADC0_BASE, 0);  // Trigger the sample sequence.

	while(!ADCIntStatus(ADC0_BASE, 0, false))  // Wait until the sample sequence has completed.
	{
	}

	ADCSequenceDataGet(ADC0_BASE, 0, adcstuff);  // Read the value from the ADC.

	
}


void print_ADC_DATA(struct ADC_DATA * INFO)
{
	ADCconvertedinfo.POT1 = (ADCinfo.POT1 * .00080556);  // .80556 is found from a reference voltage of 3.3/4096 the resolution. multiply this by the result for the correct value
	ADCconvertedinfo.POT2 = (ADCinfo.POT2 * .00080556); //  then divided by 1000 moves the decimal place over 3 places correctly
	ADCconvertedinfo.POT3 = (ADCinfo.POT3 * .00080556);
	ADCconvertedinfo.POT4 = (ADCinfo.POT4 * .00080556);

	
	
	//Above is a really sloppy way to convert the values from the adc before they are printed
	
	printf("The information gathered from pot 1 is %.2f\n\r", ADCconvertedinfo.POT1);
	printf("The information gathered from pot 2 is %.2f\n\r", ADCconvertedinfo.POT2);
	printf("The information gathered from pot 3 is %.2f\n\r", ADCconvertedinfo.POT3);
	printf("The information gathered from pot 4 is %.2f\n\r", ADCconvertedinfo.POT4);
	
}







