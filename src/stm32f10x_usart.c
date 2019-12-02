#include "stm32f10x.h"
#include "stm32f10x_usart.h"
#include "string.h"
#include "stdio.h"


void delay (int pause)
{
    for(int i = 0; i < 24 * pause; i++);
}

void usartBegin(void)
{
    uint32_t baudrate = 9600;
	  uint32_t _BRR = ((SystemCoreClock +  baudrate / 2 ) / baudrate); // вычисляем скорость передачи данных USART
	  
	  RCC->APB2ENR |= (RCC_APB2ENR_USART1EN | RCC_APB2ENR_AFIOEN);
	  
	  RCC->APB2ENR |= RCC_APB2ENR_IOPAEN; 
		GPIOA->CRH &= ~(GPIO_CRH_MODE9 | GPIO_CRH_CNF9);
		GPIOA->CRH |= GPIO_CRH_CNF9_1;  /* PA9 TX*/
		GPIOA->CRH |= GPIO_CRH_MODE9_1;		
		
	  GPIOA->CRH &= ~(GPIO_CRH_MODE10 | GPIO_CRH_CNF10);
		GPIOA->CRH |= GPIO_CRH_CNF10_0; /* PA10 RX */
	
	  USART1->BRR = _BRR;
		USART1->CR2 = 0;
		USART1->CR1 = 0;
		USART1->CR1 |= USART_CR1_TE;
		USART1->CR1 |= USART_CR1_RE;
		USART1->CR1 |= USART_CR1_UE;
	  
	  USART1->CR1 |= USART_CR1_RXNEIE;
	
	  NVIC_EnableIRQ(USART1_IRQn);
	
}


void usartTransmission(char *str)
{
	uint16_t i = 0;
	
	for (i=0; i < strlen(str); i++)
	{	
		while(!(USART1->SR&USART_SR_TC)){};
	  USART1->DR = str[i];
	}
	
	while(!(USART1->SR&USART_SR_TC));
	USART1->DR = '\n';
	
}

void led(char *str)
{
    if(!strcmp(str, "ON_PC8"))
    {
		    GPIOC->BSRR = GPIO_BSRR_BS8;
			  usartTransmission("OK");
		}
		
		if(!strcmp(str, "OFF_PC8"))
    {
		    GPIOC->BSRR = GPIO_BSRR_BR8;
			  usartTransmission("OK");
		}
		
		if(!strcmp(str, "ON_PC9"))
    {
		    GPIOC->BSRR = GPIO_BSRR_BS9;
			  usartTransmission("OK");
		}
		
		if(!strcmp(str, "OFF_PC9"))
    {
		    GPIOC->BSRR = GPIO_BSRR_BR9;
			  usartTransmission("OK");
		}
		
}

char receiverBuffer[100];

void USART1_IRQHandler(void)
{
	char tmp;
	if ((USART1->SR & USART_SR_RXNE)!=0)	
	{
		tmp = USART1->DR;
		if (tmp == 0x0D)							
		{	
		   led(receiverBuffer);
			 memset(receiverBuffer, 0, 255);
			return;	
		}	
		receiverBuffer[strlen(receiverBuffer)] = tmp;
	} 	
}


int main()
{
    usartBegin();
	  RCC-> APB2ENR |= RCC_APB2ENR_IOPCEN;
	  GPIOC->CRH     = 0x33;

	  while(1)
		{

		}
}