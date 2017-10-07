
## Names 
Kristina Torres, Shemar Hutson, & Nicholas Hunt
   
## Design Overview
This project shows the use of the Analog to Digital Convertor (ADC), General Purpose Input/Outputs (GPIOs), Pulse Width Modulation (PWM), System Timer (SysTick), and Universal Asynchronous Receivers/Transmitters (UART). The two functions in the adc_helper.c file sets up the ADC, reads values from the ADC_Data struct, and then prints the data. The gpio_helper.c file contains the function Gpio_setup() which allows for the multiple uses of its ports throughout the rest of the project (LEDs, switches etc). The functions in SysTick_helper.c use the system timer to measure the time between two events happening. In PWM.c two functions are used to setup the timers in PWM mode while configuring them with their corresponding LEDs. The LEDs are then faded on and off one by one. Lastly, the uart_helper.c files has functions that sets up the UART, receives a character from UART and then prints a character to it. 
    
## Hardware List

1. TM4C123GH6PM

   -Port F RGB LEDs (PF1, PF2, PF3)
   
   -Port F user switches (SW1 & SW2)

## Hardware Description
The hardware that we used was all on the TM4C123GH6PM board already. The LEDs are configured with timers in PWM mode to fade them on and off. The switches are used to determine whether a task is completed depending on whether it is pressed or not.


## Software Description
The file structure for this projects is as follows:

        ├── .gitignore                (list of files to ignore in Repo)
        ├── README.md                 (a README file in markup language)
        ├── project.uvprojx           (the keil project file)
        ├── project.c                 (main c file)
        ├── project.h                 (main header)
        ├── project.sct               (scatter file)
        ├── startup_rvmdk.S           (startup file in asm)
        ├── src                       (Directory for your .c and .h )
            ├── PWM.c 
            ├── PWM.h
            ├── SysTick_helper.c 
            ├── Systick_helper.h
            ├── adc_helper.c
            ├── adc_helper.h
            ├── gpio_helper.c
            ├── gpio_helper.h
            ├── uart_helper.c
            └── uart_helper.h
        ├── inc                       (Directory for precompiled libraries and headers)
            ├── <stdlib.h>
            ├── <stdint.h>
            ├── <stdbool.h>
            ├── <stdio.h>
            ├── hw_ints.h
            ├── hw_memmap.h
            ├── hw_timer.h
            ├── hw_gpio.h
            ├── hw_nvic.h
            ├── hw_types.h
            └── tm4c123gh6pm.h
            
        ├── driverlib                (Directory for driver libraries source)
            ├── systick.h             
            ├── interrupt.h
            ├── adc.h
            ├── pinmap.h
            ├── gpio.h
            ├── timer.h
            ├── pin_map.h
            ├── sysctl.h
            └── uart.h
           
  

## Summary and Conclusions
Overall this project served as a good learning experience and C refresher. Each member was able to learn from writing their own code as well as reviewing the code that other members wrote.
