#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include "sysctl.h"
#include "gpio.h"
#include "hw_memmap.h"
#include "hw_types.h"
#include "hw_gpio.h"
#include "adc.h"
#include "pin_map.h"
#include "../inc/tm4c123gh6pm.h"

struct ADC_DATA
{
	uint32_t POT1;
	uint32_t POT2;
	uint32_t POT3;
	uint32_t POT4;
	uint32_t GYRO;
	uint32_t PRESSURE;
	
};


void ADC_setup(void); 
void process_ADC();
void print_ADC_DATA( struct ADC_DATA * INFO);



extern struct ADC_DATA ADCinfo;