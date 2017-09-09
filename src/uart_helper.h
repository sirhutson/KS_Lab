#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include "sysctl.h"
#include "gpio.h"
#include "hw_memmap.h"
#include "hw_types.h"
#include "hw_gpio.h"
#include "uart.h"
#include "pin_map.h"

void Uart_setup(void);
void process_Uart(void);
void print_start_msg(void);