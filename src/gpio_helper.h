#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>
#include "../driverlib/sysctl.h"
#include "../driverlib/gpio.h"
#include "../inc/hw_memmap.h"
#include "../inc/hw_types.h"
#include "../inc/hw_gpio.h"
#include "../inc/hw_nvic.h"
#include "../inc/hw_types.h"

void Gpio_setup (void) ; 
void process_GPIO( void );
void print_GPIO_DATA( void );
