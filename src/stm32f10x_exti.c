#include "stm32f10x.h"
#include "stm32f10x_exti.h"

void extiBeginPA0()
{
    EXTI->FTSR      |=  EXTI_FTSR_TR0;
    EXTI->RTSR      &=~ EXTI_RTSR_TR0;
    AFIO->EXTICR[0] |=  AFIO_EXTICR1_EXTI0_PA;

    EXTI->PR        |=  EXTI_PR_PR0;						
    EXTI->IMR       |=  EXTI_IMR_MR0;							
    EXTI->EMR       |=  EXTI_EMR_MR0;

    NVIC_EnableIRQ(EXTI0_IRQn);
}

void EXTI0_IRQHandler(void) 
{  
    EXTI->PR   |= EXTI_PR_PR0;
	  GPIOC->ODR ^= 0x0100;
	  
}

void extiBeginPA1()
{
    EXTI->FTSR      |=  EXTI_FTSR_TR1;
    EXTI->RTSR      &=~ EXTI_RTSR_TR1;
    AFIO->EXTICR[0] |=  AFIO_EXTICR1_EXTI1_PA;

    EXTI->PR        |=  EXTI_PR_PR1;						
    EXTI->IMR       |=  EXTI_IMR_MR1;							
    EXTI->EMR       |=  EXTI_EMR_MR1;

    NVIC_EnableIRQ(EXTI1_IRQn);
}

void EXTI1_IRQHandler(void) 
{  
    EXTI->PR   |= EXTI_PR_PR1;
	  GPIOC->ODR ^= 0x0100;
	  
}

void extiBeginPA2()
{

    EXTI->FTSR      |=  EXTI_FTSR_TR2;
    EXTI->RTSR      &=~ EXTI_RTSR_TR2;
    AFIO->EXTICR[0] |=  AFIO_EXTICR1_EXTI2_PA;

    EXTI->PR        |=  EXTI_PR_PR2;						
    EXTI->IMR       |=  EXTI_IMR_MR2;							
    EXTI->EMR       |=  EXTI_EMR_MR2;

    NVIC_EnableIRQ(EXTI2_IRQn);
}

void EXTI2_IRQHandler(void) 
{  
    EXTI->PR   |= EXTI_PR_PR2;
	  GPIOC->ODR ^= 0x0100;
	  
}

void extiBeginPA3()
{

    EXTI->FTSR      |=  EXTI_FTSR_TR3;
    EXTI->RTSR      &=~ EXTI_RTSR_TR3;
    AFIO->EXTICR[0] |=  AFIO_EXTICR1_EXTI3_PA;

    EXTI->PR        |=  EXTI_PR_PR3;						
    EXTI->IMR       |=  EXTI_IMR_MR3;							
    EXTI->EMR       |=  EXTI_EMR_MR3;

    NVIC_EnableIRQ(EXTI3_IRQn);
}

void EXTI3_IRQHandler(void) 
{  
    EXTI->PR   |= EXTI_PR_PR3;
	  GPIOC->ODR ^= 0x0100;
	  
}

void extiBeginPA4()
{

    EXTI->FTSR      |=  EXTI_FTSR_TR4;
    EXTI->RTSR      &=~ EXTI_RTSR_TR4;
    AFIO->EXTICR[1] |=  AFIO_EXTICR2_EXTI4_PA;

    EXTI->PR        |=  EXTI_PR_PR4;						
    EXTI->IMR       |=  EXTI_IMR_MR4;							
    EXTI->EMR       |=  EXTI_EMR_MR4;

    NVIC_EnableIRQ(EXTI4_IRQn);
}

void EXTI4_IRQHandler(void) 
{  
    EXTI->PR   |= EXTI_PR_PR4;
	  GPIOC->ODR ^= 0x0100;
	  
}

void extiBeginPA5()
{

    EXTI->FTSR      |=  EXTI_FTSR_TR5;
    EXTI->RTSR      &=~ EXTI_RTSR_TR5;
    AFIO->EXTICR[1] |=  AFIO_EXTICR2_EXTI5_PA;

    EXTI->PR        |=  EXTI_PR_PR5;						
    EXTI->IMR       |=  EXTI_IMR_MR5;							
    EXTI->EMR       |=  EXTI_EMR_MR5;

    NVIC_EnableIRQ(EXTI9_5_IRQn);
}

void EXTI9_5_IRQHandler(void) 
{  
	  if(EXTI->PR & EXTI_PR_PR5)
		{
		    EXTI->PR   |= EXTI_PR_PR5;
		    GPIOC->ODR  = GPIO_ODR_ODR8;
		}
    if(EXTI->PR & EXTI_PR_PR6)
    {    
		    EXTI->PR   |= EXTI_PR_PR6;
		    GPIOC->ODR  = GPIO_ODR_ODR9;
    }
		if(EXTI->PR & EXTI_PR_PR7)
    {    
		    EXTI->PR   |= EXTI_PR_PR7;
		    GPIOC->ODR  = (GPIO_ODR_ODR8 | GPIO_ODR_ODR9);	
	  }
}

void extiBeginPA6()
{

    EXTI->FTSR      |=  EXTI_FTSR_TR6;
    EXTI->RTSR      &=~ EXTI_RTSR_TR6;
    AFIO->EXTICR[1] |=  AFIO_EXTICR2_EXTI6_PA;

    EXTI->PR        |=  EXTI_PR_PR6;						
    EXTI->IMR       |=  EXTI_IMR_MR6;							
    EXTI->EMR       |=  EXTI_EMR_MR6;

    NVIC_EnableIRQ(EXTI9_5_IRQn);
}


void extiBeginPA7()
{

    EXTI->FTSR      |=  EXTI_FTSR_TR7;
    EXTI->RTSR      &=~ EXTI_RTSR_TR7;
    AFIO->EXTICR[1] |=  AFIO_EXTICR2_EXTI7_PA;

    EXTI->PR        |=  EXTI_PR_PR7;						
    EXTI->IMR       |=  EXTI_IMR_MR7;							
    EXTI->EMR       |=  EXTI_EMR_MR7;

    NVIC_EnableIRQ(EXTI9_5_IRQn);
}



void extiBeginPA8()
{

    EXTI->FTSR      |=  EXTI_FTSR_TR8;
    EXTI->RTSR      &=~ EXTI_RTSR_TR8;
    AFIO->EXTICR[2] |=  AFIO_EXTICR3_EXTI8_PA;

    EXTI->PR        |=  EXTI_PR_PR8;						
    EXTI->IMR       |=  EXTI_IMR_MR8;							
    EXTI->EMR       |=  EXTI_EMR_MR8;

    NVIC_EnableIRQ(EXTI9_5_IRQn);
}



void extiBeginPA9()
{

    EXTI->FTSR      |=  EXTI_FTSR_TR9;
    EXTI->RTSR      &=~ EXTI_RTSR_TR9;
    AFIO->EXTICR[2] |=  AFIO_EXTICR3_EXTI9_PA;

    EXTI->PR        |=  EXTI_PR_PR9;						
    EXTI->IMR       |=  EXTI_IMR_MR9;							
    EXTI->EMR       |=  EXTI_EMR_MR9;

    NVIC_EnableIRQ(EXTI9_5_IRQn);
}



void extiBeginPA10()
{

    EXTI->FTSR      |=  EXTI_FTSR_TR10;
    EXTI->RTSR      &=~ EXTI_RTSR_TR10;
    AFIO->EXTICR[2] |=  AFIO_EXTICR3_EXTI10_PA;

    EXTI->PR        |=  EXTI_PR_PR10;						
    EXTI->IMR       |=  EXTI_IMR_MR10;							
    EXTI->EMR       |=  EXTI_EMR_MR10;

    NVIC_EnableIRQ(EXTI15_10_IRQn);
}

void EXTI15_10_IRQHandler(void) 
{  
    EXTI->PR   |= EXTI_PR_PR10;
	  GPIOC->ODR ^= 0x0100;
	  
}

void extiBeginPA11()
{

    EXTI->FTSR      |=  EXTI_FTSR_TR11;
    EXTI->RTSR      &=~ EXTI_RTSR_TR11;
    AFIO->EXTICR[2] |=  AFIO_EXTICR3_EXTI11_PA;

    EXTI->PR        |=  EXTI_PR_PR11;						
    EXTI->IMR       |=  EXTI_IMR_MR11;							
    EXTI->EMR       |=  EXTI_EMR_MR11;

    NVIC_EnableIRQ(EXTI15_10_IRQn);
}



void extiBeginPA12()
{

    EXTI->FTSR      |=  EXTI_FTSR_TR12;
    EXTI->RTSR      &=~ EXTI_RTSR_TR12;
    AFIO->EXTICR[3] |=  AFIO_EXTICR4_EXTI12_PA;

    EXTI->PR        |=  EXTI_PR_PR12;						
    EXTI->IMR       |=  EXTI_IMR_MR12;							
    EXTI->EMR       |=  EXTI_EMR_MR12;

    NVIC_EnableIRQ(EXTI15_10_IRQn);
}



void extiBeginPA13()
{

    EXTI->FTSR      |=  EXTI_FTSR_TR13;
    EXTI->RTSR      &=~ EXTI_RTSR_TR13;
    AFIO->EXTICR[3] |=  AFIO_EXTICR4_EXTI13_PA;

    EXTI->PR        |=  EXTI_PR_PR13;						
    EXTI->IMR       |=  EXTI_IMR_MR13;							
    EXTI->EMR       |=  EXTI_EMR_MR13;

    NVIC_EnableIRQ(EXTI15_10_IRQn);
}



void extiBeginPA14()
{

    EXTI->FTSR      |=  EXTI_FTSR_TR14;
    EXTI->RTSR      &=~ EXTI_RTSR_TR14;
    AFIO->EXTICR[3] |=  AFIO_EXTICR4_EXTI14_PA;

    EXTI->PR        |=  EXTI_PR_PR14;						
    EXTI->IMR       |=  EXTI_IMR_MR14;							
    EXTI->EMR       |=  EXTI_EMR_MR14;

    NVIC_EnableIRQ(EXTI15_10_IRQn);
}



void extiBeginPA15()
{

    EXTI->FTSR      |=  EXTI_FTSR_TR15;
    EXTI->RTSR      &=~ EXTI_RTSR_TR15;
    AFIO->EXTICR[3] |=  AFIO_EXTICR4_EXTI15_PA;

    EXTI->PR        |=  EXTI_PR_PR15;						
    EXTI->IMR       |=  EXTI_IMR_MR15;							
    EXTI->EMR       |=  EXTI_EMR_MR15;

    NVIC_EnableIRQ(EXTI15_10_IRQn);
}




volatile GPIO_TypeDef * gpioa;
volatile GPIO_TypeDef * gpiob;
volatile GPIO_TypeDef * gpioc;
volatile RCC_TypeDef * rcc;
volatile EXTI_TypeDef * exti;
void debug()
{
	gpioa = GPIOA;
	gpiob = GPIOB;
	gpioc = GPIOC;
	rcc   = RCC;
	exti  = EXTI;
}



int main()
{ 
	  debug();
	
	
	  RCC->APB2ENR    |=  RCC_APB2ENR_AFIOEN;
	  RCC->APB2ENR    |=  RCC_APB2ENR_IOPAEN;
	  
    RCC->APB2ENR    |=  RCC_APB2ENR_IOPCEN;					
	  GPIOC -> CRH = 0x22;
	  
	  extiBeginPA0();
	  extiBeginPA1();
	  extiBeginPA2();
	  extiBeginPA3();
	  extiBeginPA4();
	  extiBeginPA5();
	  extiBeginPA6();
	  extiBeginPA7();
	  extiBeginPA8();
	  extiBeginPA9();
	  extiBeginPA10();
	  extiBeginPA11();
	  extiBeginPA12();
	  extiBeginPA13();
	  extiBeginPA14();
	  extiBeginPA15();
	
    
		
		while(1)
		{
		    
		}
}