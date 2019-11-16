#include "stm32f10x_gpio.h"  

void gpio::pinMode()
{
	if (GPIOx == GPIOA)
		RCC -> APB2ENR |= RCC_APB2ENR_IOPAEN;
	if (GPIOx == GPIOB)
		RCC -> APB2ENR |= RCC_APB2ENR_IOPBEN;
	if (GPIOx == GPIOC)
		RCC -> APB2ENR |= RCC_APB2ENR_IOPCEN;
	if (number <= 7)
	{
		GPIOx -> CRL &=~ ((GPIO_CRL_MODE0 << 4*number )| (GPIO_CRL_CNF0 << 4*number));
		GPIOx -> CRL |= GPIO_CRL_MODE0_1 << 4*number;
	}
	else
	{
		GPIOx -> CRH &=~ ((GPIO_CRH_MODE8 << 4 *(number % 8) )| (GPIO_CRH_CNF8 << 4 * (number % 8)));
		GPIOx -> CRH |= GPIO_CRH_MODE8_1 << 4 * (number % 8);
	}
}

void gpio::digitalWrite(bool pin)
{
	if(pin)
		GPIOx -> BSRR = GPIO_BSRR_BS0 << number;
	else
		GPIOx -> BSRR = GPIO_BSRR_BR0 << number;
}

bool gpio::digitalRead(uint16_t pin)
{
	 return ((GPIOx -> IDR) & (0x1 << pin));
}





