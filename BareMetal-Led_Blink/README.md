## 🔧 LED BLINK EM BARE METAL #

### Esse projeto altera o estado de dois LEDs PA8 e PB12 por meio do acesso direto aos registradores.
### - Não é utilizado CMSIS/HAL/RTOS
### -  Controle manual sobre configuração de pins e saídas.

## PREVIEW 

![ledblink1](https://github.com/user-attachments/assets/4c495e6e-59c7-42e2-9bcb-3c62e5ad23a2)

## Registradores Utilizados
- RCC_APB2ENR -> habilita clock para GPIOA e GPIOB
- GPIOA_CRH -> configura PA8
- GPIOB_CRH > configra PB12
- GPIOA_BSRR -> altera o estado do PA8
- GPIOB_BSRR -> altera o estado do PB12

## Main Code

<img width="550" height="410" alt="image" src="https://github.com/user-attachments/assets/4c1bd4f0-f52e-4336-960a-4043ad73bcb0" />
<img width="550" height="410" alt="image" src="https://github.com/user-attachments/assets/fc6f81e3-ce68-4a97-bdfe-9475145c1af3" />

