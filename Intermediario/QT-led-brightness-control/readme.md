## 🖥️ ⚙️ Led Brightness control #

### Este projeto demonstra o controle de luminosidade de um LED utilizando Qt no host e STM32 (USB CDC + PWM)

##  📌 Funcionamento: 
#### - O usuário seleciona a porcentagem de luminosidade no Display Qt
#### - O valor é transmitido para o stm32 por meio do USB CDC e armazenado em um buffer circular
#### - É realizada a leitura do buffer circular alterando a luminosidade do Led conforme o valor

## Esse projeto contém dois arquivos principais:
### 📂 QT_Gui -> Interface gráfica utilizando Qt para o usuário selecionar a luminosidade
### 📂 stm32_firmware -> firmware do stm32 que recebe o valor via USB e altera a luminosidade do Led via PWM 



## PREVIEW 

https://github.com/user-attachments/assets/1d7dea52-13a9-46e4-92c5-3cbc9c05750b

