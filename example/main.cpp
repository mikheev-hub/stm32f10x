#include "stm32f10x_gpio.h"

bool high = true;
bool low = false;

gpio pa1(GPIOA,1);
gpio pc8(GPIOC,8);
gpio pc9(GPIOC,9);


bool digitalRead(uint16_t pin)
{
	 return ((GPIOA -> IDR) & (0x00000001 << pin));
}


int main()
{

    pinMode(pc9,output);
    pinMode(pc9,output,10);
    pinMode(pc8,input);
    
    digitalWrite(pc8,low);  // return void
    digitalWrite(pc8,high); // return void
    
    digitalRead(pa0);       // return  bool and uint8_t
    
    while(1)
    {
        digitalWrite(pa0 << i, low);
        delay(uint32_t time);
        digitalWrite(pa0 << i, high);
        delay(uint32_t time);
    }
    
	pc9.pinMode();
	pa9.pinMode();
	pa8.pinMode();

	
	RCC -> APB2ENR |= RCC_APB2ENR_IOPAEN;
	GPIOA -> CRL &=~ ((GPIO_CRL_MODE0 )| (GPIO_CRL_CNF0));
	GPIOA -> CRL |= GPIO_CRL_CNF0_1;

	pa1.pinMode();
	pc8.pinMode();
  pc9.pinMode();
	
	pa1.digitalWrite(low);
	pc8.digitalWrite(low);
	pc9.digitalWrite(low);

	volatile bool check; 
	while(1)
	{

		pc9.digitalWrite(high);
		pa9.digitalWrite(false);
		for(uint32_t i = 0; i < 2400000;i++);
		pc9.digitalWrite(low);
		pa9.digitalWrite(true);
		for(uint32_t i = 0; i < 2400000;i++);
	}
	

		check = digitalRead(0);
		if(check == true)
		{
				pc8.digitalWrite(higt);
			  pc9.digitalWrite(low);
		}
		else 
		{
				pc8.digitalWrite(low);
			  pc9.digitalWrite(higt);
		}
			
	}


}
