#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include "sysctl.h"
#include "gpio.h"
#include "hw_memmap.h"
#include "hw_types.h"
#include "hw_gpio.h"

void Gpio_setup (void) ; 
void process_GPIO( void );
void print_GPIO_DATA( void );