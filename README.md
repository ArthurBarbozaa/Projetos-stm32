# 🚀 Projetos STM32

Este repositório contém projetos desenvolvidos com a placa **STM32F103C8T6 (Blue Pill)**, explorando diferentes abordagens de programação embarcada:  

- **Bare Metal** → acesso direto a registradores e memórias, sem bibliotecas ou camadas de abstração.  
- **HAL (Hardware Abstraction Layer)** → prototipagem rápida e redução do tempo de desenvolvimento.  
- **FreeRTOS** → multitarefa e escalonamento em sistemas de tempo real.  

---

## 📂 Projetos

### 📘 Básico
- 🔧 [BareMetal-Led_Blink](https://github.com/ArthurBarbozaa/Projetos-stm32/tree/master/BareMetal-Led_Blink) — Alterna o funcionamento de dois LEDs, bare metal.  
- 🔧 [BareMetal-Led_Blink_v2](https://github.com/ArthurBarbozaa/Projetos-stm32/tree/master/BareMetal-Led_Blink_v2) — Versão aprimorada do Led_Blink, com structs e código modular. 
- 🛠️ [HAL-Button_IRQ_Debounce](https://github.com/ArthurBarbozaa/Projetos-stm32/tree/master/Basico/HAL-Button_IRQ_Debounce) — Aciona LED com EXTI e tratamento de debounce. 
- 🛠️ [HAL-Led_pwm_exti](https://github.com/ArthurBarbozaa/Projetos-stm32/tree/master/Basico/HAL-Led_pwm_exti) — Controle de brilho de LED via botão (modo manual/automático).
- 🔄 [RTOS-BlinkSpeed_EXTI](https://github.com/ArthurBarbozaa/Projetos-stm32/tree/master/Basico/RTOS-BlinkSpeed_EXTI) — Ajuste da velocidade do LED via botão, com FreeRTOS.  
- 🔄 [RTOS-TrafficLight_Semaphores](https://github.com/ArthurBarbozaa/Projetos-stm32/tree/master/Basico/RTOS-TrafficLight_Semaphores) — Semáforo de trânsito com FreeRTOS e semáforos.

### ⚙️ Intermediário

- 🖥️ [CPU-Temperature-Monitor](https://github.com/ArthurBarbozaa/Projetos-stm32/tree/master/Intermediario/CPU-Temperature-Monitor) — Leitura de `/dev` e envio de alerta de temperatura ao STM32. 
- 🔌 [USB-Menu_led_control](https://github.com/ArthurBarbozaa/Projetos-stm32/tree/master/Intermediario/USB-Menu_led_control) — Menu via USB para controle de LEDs. 

### 🖥️ Interface Gráfica (Qt + STM32)

- ⚙️ [QT-Gear-Indicator](https://github.com/ArthurBarbozaa/Projetos-STM32/tree/master/Intermediario/QT-Gear-Indicator): Indicador de marcha simulando painel automotivo, integrado via Qt.
- ⚙️ [QT-Led-Brightness-Control](https://github.com/ArthurBarbozaa/Projetos-STM32/tree/master/Intermediario/QT-led-brightness-control): Controle da intensidade de LED pela interface gráfica.
- ⚙️ [QT-CAN-Battery-Monitor](https://github.com/ArthurBarbozaa/Projetos-stm32/tree/master/Intermediario/QT-CAN-Battery-Monitor): Monitor de nivel de bateria que simula o envio de uma mensagem CAN, altera o Display e aciona LED se a bateria for menor que 75%
---

## 🛠️ IDEs e Ferramentas

- **STM32CubeIDE**  
- **STM32CubeMX**  
- **ST-LINK V2**
- **Qt Creator**
- **Componentes eletrônicos (LEDs, botões, resistores, etc.)**  

---

📌 Este repositório é constantemente atualizado à medida que novos projetos são desenvolvidos.
