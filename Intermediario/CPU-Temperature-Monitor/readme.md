# 🖥️ ⚙️ Indicador de Temperatura da CPU com LED  

Este projeto demonstra como ler a temperatura da CPU no host e controlar um LED no STM32 utilizando **USB CDC**.  

## 📌 Funcionamento  
- A **aplicação host (C++)** lê em tempo real a temperatura da CPU.  
- O valor é enviado para o STM32 via **USB CDC**.  
- O firmware do STM32 processa o valor e altera o LED conforme a faixa de temperatura:  
  - 🟢 **Verde**: temperatura < 42 °C  
  - 🟡 **Amarelo**: temperatura ≤ 44 °C  
  - 🔴 **Vermelho**: temperatura > 44 °C
  - Obs: Foi utilizado `yes > /dev/null` para forçar a CPU a aquecer e alterar a temperatura.


## 📂 Estrutura do Projeto  
- **host_app/** → Código em C++ que roda no host, lê a temperatura da CPU (/sys/class/thermal/thermal_zone0/temp) e envia via USB.  
- **stm32_firmware/** → Firmware do STM32 que recebe o valor e controla o LED.  

## 🎥 Preview  
Vídeo de demonstração:  

https://github.com/user-attachments/assets/ecd736a8-443e-4a4d-8bbe-a01c9093c709

