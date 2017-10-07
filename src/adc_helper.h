#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include "gpio.h"
#include "sysctl.h"
#include "hw_memmap.h"
#include "hw_types.h"
#include "hw_gpio.h"
#include "adc.h"
#include "../inc/tm4c123gh6pm.h"

//*************************************************************************
// This function the values attached to the ADC pins into human readable 
// format in the form of volts. 
//*************************************************************************

struct ADC_DATA // RAW data if it is ever needed
{
	uint32_t POT1;
	uint32_t POT2;
	uint32_t POT3;
	uint32_t POT4;

	
};

struct ADC_DATACONVERTED
{
	float POT1;
	float POT2;
	float POT3;
	float POT4;

	
};

void ADC_setup(void); 
void process_ADC(struct ADC_DATA * data_ptr);
void print_ADC_DATA( struct ADC_DATA * INFO);



extern struct ADC_DATA ADCinfo;
extern struct ADC_DATACONVERTED ADCconvertedinfo;

