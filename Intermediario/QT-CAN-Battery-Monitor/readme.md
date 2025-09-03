## 🖥️ ⚙️ Battery Level CAN Monitor #

### Este projeto demonstra a leitura do nível de bateria no host, altera no Display Qt e envia uma mensagem no formato CAN para o STM32, que aciona o LEDs caso o nível da bateria for abaixo que 75%.

## 📌 Funcionamento:
#### - O host lê o nível de bateria do sistema (/sys/class/power_supply/BAT1/capacity)  
#### - O valor é enviado via USB CDC no formato de uma mensagem CAN para o STM32  
#### - O STM32 recebe a mensagem e armazena em um buffer circular 
#### - LED vermelho é acionados caso a porcentagem for menor que 75 
#### - STM32 envia apenas o valor que é exibido no Display Qt

## Esse projeto contém:
#### 📂 host-app -> Código em C que lê a bateria, envia a mensagem estilo CAN via USB CDC para o STM32
#### 📂 stm32_firmware -> Firmware que lê a mensagem, envia o valor para o host e aciona o LED vermelho 
#### 📂 QT-Gui -> faz a leitura de /dev/ttyACM0 (valor enviado pelo STM32) e altera no display

## PREVIEW


https://github.com/user-attachments/assets/a7f780bf-def9-478e-a194-7ad58a0cbe4f


