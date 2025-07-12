#include <stdint.h>

#define RCC_BASE (0x40021000) //endereco base RCC

#define RCC_APB2ENR *((volatile uint32_t *)(RCC_BASE + 0x18)) //RCC responsavel pelos GPIOS

#define GPIOA_BASE (0x40010800) //endereco base GPIOA
#define GPIOA_CRH *((volatile uint32_t *) (GPIOA_BASE + 0x04))
#define GPIOA_BSRR *((volatile uint32_t *) (GPIOA_BASE + 0x10))

#define GPIOB_BASE (0x40010C00)//endereco base GPIOB
#define GPIOB_CRH *((volatile uint32_t * ) (GPIOB_BASE + 0x04))
#define GPIOB_BSRR *((volatile uint32_t *) (GPIOB_BASE + 0x10))

//set 1 no bit 2 (GPIOA)
#define APB2ENR_IOPAEN (1 << 2)
//set 1 no bit 3 (GPIOB)
#define APB2ENR_IOPBEN (1 << 3)

void delay(uint32_t delay)
{
	for(int i = 0; i < delay; i++)
		for(int j = 0; j < delay; j++);
}

int main(void)
{
	//Habilita clock para GPIOA e GPIOB
    RCC_APB2ENR |= APB2ENR_IOPAEN;
    RCC_APB2ENR |= APB2ENR_IOPBEN;

    //PA8 -> bits 3,2,1,0
    GPIOA_CRH &= ~(0xF << 0);//limpa os bits
    GPIOA_CRH |= (0x1 << 0); //set 1 no bit 1 MODE(10 MHz), CNF 00 (output pp)

    //PB12 -> bits 19,18,17,16
    GPIOB_CRH &= ~(0xF << 16); //limpa os bits
    GPIOB_CRH |= (0x1 << 16); ////set 1 no bit 16 MODE(10 MHz), CNF 00 (output pp)


	for(;;){
		GPIOA_BSRR = (1 << 8); //set 1 bit 8 -> liga o led PA8
		delay(1000);
		GPIOA_BSRR = (1 << (8 + 16)); //set 1 bit 24 -> desliga o led PA8
		GPIOB_BSRR = (1 << 12); //set 1 bit 12 -> liga o led PB12
		delay(1000);
		GPIOB_BSRR = (1 << (12 + 16)); //set 1 bit 28 -> desliga o led PB12

	}
}
