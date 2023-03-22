// Description----------------------------------------------------------------|
/*Practical 5 - KGPSAK001
 *
 */
// DEFINES AND INCLUDES-------------------------------------------------------|

#define STM32F051												   //COMPULSORY
#include "stm32f0xx.h"											   //COMPULSORY
#include "lcd_stm32f0.h"
#include <string.h>
#include <stdio.h>

// GLOBAL VARIABLES ----------------------------------------------------------|



// FUNCTION DECLARATIONS -----------------------------------------------------|

void main(void);                                                   //COMPULSORY
void display_on_LCD(uint8_t num);
void display_on_LEDs(uint8_t num);
void init_LEDSs(void);
void init_external_interrupts(void);


// MAIN FUNCTION -------------------------------------------------------------|

void main(void)
{
	//init_LEDs();
	//init_switches();
	init_LCD();


	while(1)
	{

	}
}
// OTHER FUNCTIONS -----------------------------------------------------------|

void display_on_LCD(uint8_t num)

{
	char lcd_output[30];
		sprintf(lcd_output, "%d", num);
		lcd_command(CLEAR);
		lcd_putstring(lcd_output);
}
