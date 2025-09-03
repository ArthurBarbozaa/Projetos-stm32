# 🖥️⚙️ Qt Data Display with CAN & STM32  

## 📖 Descrição  
Este projeto integra **Linux, Qt e STM32** para exibir informações do sistema em tempo real através de **SocketCAN** e **USB CDC**.  
O host lê dados como temperatura da CPU e status da bateria, envia via **CAN (vcan0)**, o **Display Qt** mostra essas informações, e o **STM32** aciona LEDs conforme os limites definidos.  

##

## 📌 Funcionamento:
#### - O host lê informações como: temperatura da CPU, porcentagem e status da bateria do sistema  
#### - Os dados são enviados no formato de mensagens CAN para o SocketCAN (`vcan0`)  
#### - O Display Qt lê as mensagens CAN e atualiza a interface em tempo real  
#### - IDs CAN utilizados:  
- **0x100** → Bateria (nível e status)  
- **0x200** → Temperatura da CPU  
#### - A interface Qt exibe:  
- Data e hora  
- Status e porcentagem da bateria (com barra de progresso colorida)  
- Temperatura da CPU (fica vermelha ao passar limite)  
- Ícones da bateria e termômetro (cinza → vermelho no alerta)  
- Botões para alternar entre tema Claro 🌞 e Escuro 🌙  
#### - O STM32 recebe os dados via **USB CDC**, armazena em buffer circular, e aciona LEDs:  
-  LED VERDE aceso se a bateria < 75%  
-  LED VERMELHO aceso se a temperatura passar de 56º
- Obs: STM32 recebe apenas o sinal de ligar/desligar os LED, a verificação do valor ocorre no Qt
---

## 📂 Estrutura do Projeto
#### 📂 **host_side/** → Código em C que coleta dados do sistema e envia como mensagens CAN (`vcan0`)  
#### 📂 **stm32_firmware/** → Firmware STM32 (HAL + USB CDC + buffer circular) que aciona LEDs  
#### 📂 **QT-DataDisplay/** → Aplicativo Qt que lê do SocketCAN e exibe os dados no display  

---

##  Preview
# Qt
<img width="715" height="700" alt="qtm2" src="https://github.com/user-attachments/assets/ef8f06c4-d49e-4dea-ba11-2d35493ee293" />

# Demo
https://github.com/user-attachments/assets/7f4bcf81-6218-4856-8f32-1367ff8603b8



