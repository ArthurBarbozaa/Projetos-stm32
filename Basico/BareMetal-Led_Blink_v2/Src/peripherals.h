#ifndef PERIPHERALS_H_
#define PERIPHERALS_H_

//struct clock
typedef struct{
	volatile uint32_t CR;
	volatile uint32_t CFGR;
	volatile uint32_t CIR;
	volatile uint32_t APB2RSTR;
	volatile uint32_t APB1RSTR;
	volatile uint32_t AHBENR;
	volatile uint32_t APB2ENR;
	volatile uint32_t APB1ENR;
	volatile uint32_t BCDR;
	volatile uint32_t CSR;
}RCC_T;

//struct GPIO
typedef struct{
	volatile uint32_t CRL;
	volatile uint32_t CRH;
	volatile uint32_t IDH;
	volatile uint32_t ODR;
	volatile uint32_t BSRR;
	volatile uint32_t BRR;
	volatile uint32_t LCKR;

}GPIO_T;

#define RCC   ((RCC_T  *)0x40021000)
#define GPIOA ((GPIO_T *)0x40010800)
#define GPIOB ((GPIO_T *)0x40010C00)

//funcao para delay
void delay(uint32_t delay)
{
	for(uint32_t i = 0; i < delay; i++){
		for(uint32_t j = 0; j < delay; j++){}
	}
}

#endif /* PERIPHERALS_H_ */
