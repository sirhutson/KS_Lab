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
	uint8_t POT1;
	uint8_t POT2;
	uint8_t POT3;
	uint8_t POT4;
	uint8_t GYRO;
	uint8_t sensor2;
	
};


void ADC_setup(void); 
void process_ADC( struct ADC_DATA * data_ptr );
void print_ADC_DATA( struct ADC_DATA * );



extern struct ADC_DATA ADCinfo;