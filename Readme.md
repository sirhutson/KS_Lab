
## Names 
Kristina Torres, Shemar Hutson, & Nicholas Hunt
   
## Design Overview
This should be a general description.  It should make sense to your grandma / or a high school student.  It should explain what the project is, what it does, and how to set it up. Example:
<em> This device is a tool used in the machining industry to control rotational speed of the shaft of a lathe.  The device consists of a motor to rotate the lathe, a dial to control the speed manual, an input port to control the speed via a computer terminal, a screen to display the rotational speed, an encoder to measure the rotation, and two emergency stop switches for safety. 
    
## Hardware List

1. TM4C123GH6PM
   -Port F RGB LEDs (PF1, PF2, PF3)
   -Port F user switches (SW1 & SW2)

## Hardware Description
The Motor is connected to the encoder via JPF-23 cable, 3 wire, doubled shield.  The Encoder has a 13 bit resolution which allows the micrprocessor to control the motor to within N rpms, etc etc.  The schematic is show below.

![schematic](https://github.com/drnobodyphd/LAB_SETUP/blob/master/images/schem.jpg)    


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
Put something here that shows you learned something and / or you understand what you are talking about.  
