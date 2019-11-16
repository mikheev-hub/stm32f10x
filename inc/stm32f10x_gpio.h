#include "stm32f10x.h"

class gpio
{
public:
		uint8_t number;
		GPIO_TypeDef * GPIOx;
		gpio(GPIO_TypeDef * GPIOx, uint8_t number)
		{
			 this->number = number;
			 this->GPIOx = GPIOx;
		}
		void pinMode();
		void digitalWrite(bool pin);
		bool digitalRead(uint16_t pin);
};

