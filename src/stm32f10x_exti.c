#include "stm32f10x.h"
#include "stm32f10x_exti.h"

void extiBebin()
{
    RCC->APB2ENR    |=  RCC_APB2ENR_AFIOEN;
    RCC->APB2ENR    |=  RCC_APB2ENR_IOPAEN;
	  
	  EXTI->FTSR      |= EXTI_FTSR_TR0;
  	EXTI->RTSR      &=~  EXTI_RTSR_TR0;
	  AFIO->EXTICR[0] |=  AFIO_EXTICR1_EXTI0_PA;
	
	  EXTI->PR        |= EXTI_PR_PR0;						
	  EXTI->IMR       |= EXTI_IMR_MR0;							
	  EXTI->EMR       |= EXTI_EMR_MR0;
	
	  NVIC_EnableIRQ(EXTI0_IRQn);
}

void EXTI0_IRQHandler(void) 
{  
    EXTI->PR |= (1<<0);
	  GPIOC->ODR ^= 0x0100;
	  
}

int main()
{ 
	  RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;					
	  GPIOC -> CRH = 0x22;
	  extiBebin();
    while(1)
		{
		    
		}
}