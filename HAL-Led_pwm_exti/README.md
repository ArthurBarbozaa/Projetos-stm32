## 🛠️ CONTROLE LUMINOSIDADE DO LED UTILIZANDO PWM

### A luminosidade do led é alterada de duas formas:
#### 1 - Modo manual - ao pressionar o botão a intensidade do led é alterada seguindo o ciclo: 10 -> 50 -> 100 -> 255
#### 2 - Modo automático - após percorrer o ciclo, o sistema entra no modo automático, alterando a intensidade de 0 a 255 

demo
  
### 📌 Recursos utilizados
  - STM32F103C8T6 (Blue Pill)
  - PWM via TIM2
  - GPIO com interrupção externa (EXTI)
  - Debounce por software
  - STM32CubeIDE (HAL)

 ## Main function and External Interrupt function
<img width="604" height="532" alt="image" src="https://github.com/user-attachments/assets/a62e608a-18fb-4652-a1cf-7e90dbe4f230" />
<img width="604" height="209" alt="image" src="https://github.com/user-attachments/assets/21e78388-38ec-4a8f-a0d8-4f8be3e7a705" />

