# Projetos STM32

Este repositório contém projetos desenvolvidos com a placa STM32F103C8T6 (Blue Pill), focados em aplicações práticas de sistemas embarcados. Os projetos são realizados de três principais maneiras:
- Bare Metal -> feito com acesso direto a registradores e memórias, sem bibliotecas ou camada de abstração, oferecendo controle total do hardware.
- HAL (Hardware Abstraction Layer) -> para projetos focados em prototipagem rápida e redução no tempo de desenvolvimento.
- FreeRTOS -> para projetos baseado em sistemas operacionais em tempo real, onde  multitarefas e escalonamento são necessários.
desde o controle básico de LEDs até a implementação de um sistema operacional em tempo real (RTOS).

## 📂 Projetos

- 🔧 [BareMetal-Led_Blink](https://github.com/ArthurBarbozaa/Projetos-stm32/tree/master/BareMetal-Led_Blink): Alterna o funcionamento de dois LEDs, bare metal
- 🔧 [BareMetal-Led_Blink_v2](https://github.com/ArthurBarbozaa/Projetos-stm32/tree/master/BareMetal-Led_Blink_v2) Versão aprimorada do Led_Blink,com structs e código modular
- 🛠️ [HAL-Button_IRQ_Debounce](https://github.com/ArthurBarbozaa/Projetos-stm32/tree/master/HAL-Button_IRQ_Debounce): Aciona um LED com EXTI e possui tratamento de debounce no botão.
- 🔄 [RTOS - Troca de Tarefas](https://github.com/ArthurBarbozaa/Projetos-STM32/tree/master/RTOS-TASK-SWITCH): Implementação de troca de tarefas utilizando um RTOS.

## 🛠️ IDE Utilizadas

- **STM32CubeIDE**: 
- **STM32CubeMX**: 

## ⚙️ Ferramentas

- **Placa STM32F103C8T6 (Blue Pill)**
- **ST-LINK V2** 
- **IDE STM32CubeIDE** 
- **Componentes eletrônicos como: led, botões e resistores** 

