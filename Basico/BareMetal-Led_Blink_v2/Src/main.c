#include <stdint.h>
#include "peripherals.h"

int main(void)
{
	RCC->APB2ENR |= (0x1 << 2); //habilita clock para GPIOA
	RCC->APB2ENR |= (0x1 << 3); //habilita clock para GPIOB

    //PA8 -> bits 3,2,1,0
    GPIOA->CRH &= ~(0xF << 0);
    GPIOA->CRH |= (0x1 << 0);

    //PB12 -> bits 19,18,17,16
    GPIOB->CRH &= ~(0xF << 16);
    GPIOB->CRH |= (0x1 << 16);

	for(;;){
		GPIOA->BSRR = (1 << 8); //set 1 bit 8 -> liga o led PA8
		GPIOB->BSRR = (1 << (12 + 16)); //set 1 bit 12 -> liga o led PB12
		delay(1000);
		GPIOB->BSRR = (1 << 12); //set 1 bit 12 -> liga o led PB12
		GPIOA->BSRR = (1 << (8 + 16)); //set 1 bit 24 -> desliga o led PA8
		delay(1000);

	}
}
