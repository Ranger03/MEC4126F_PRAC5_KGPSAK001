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
void init_LEDs(void)
{
	RCC->AHBENR |= RCC_AHBENR_GPIOBEN;
	GPIOB->MODER |= GPIO_MODER_MODER0_0;
	GPIOB->MODER |= GPIO_MODER_MODER1_0;
	GPIOB->MODER |= GPIO_MODER_MODER2_0;
	GPIOB->MODER |= GPIO_MODER_MODER3_0;
	GPIOB->MODER |= GPIO_MODER_MODER4_0;
	GPIOB->MODER |= GPIO_MODER_MODER5_0;
	GPIOB->MODER |= GPIO_MODER_MODER6_0;
	GPIOB->MODER |= GPIO_MODER_MODER7_0;
}
void display_on_LEDs(uint8_t num)
{
	GPIOB->ODR = num;
}

void init_switches(void)
{
	GPIOA->MODER &= ~GPIO_MODER_MODER1;
	GPIOA->MODER &= ~GPIO_MODER_MODER2;
	GPIOA->MODER &= ~GPIO_MODER_MODER3;

	GPIOA->PUPDR |=GPIO_PUPDR_PUPDR1_0;
	GPIOA->PUPDR |=GPIO_PUPDR_PUPDR2_0;
	GPIOA->PUPDR |=GPIO_PUPDR_PUPDR3_0;
}

void init_external_interrupts(void)
{
	RCC->APB2ENR |= RCC_APB2ENR_SYSCFGCOMPEN;
	SYSCFG->EXTICR[0] |= SYSCFG_EXTIRC1_EXTI3_PA;
	EXTI->IMR |= EXTI_IMR_MR3;
	EXTI->FTSR |= EXTI_FTSR-TR3;
	NVIC_EnableIRQ(EXTI2_3_IRQn);
}
