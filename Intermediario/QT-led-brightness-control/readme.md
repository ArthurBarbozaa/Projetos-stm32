## 🖥️ ⚙️ Led Brightness control #

### Este projeto controla a luminosidade de um Led conforme alterado no display Qt

## Funcionamento: 
#### - O usuáro seleciona a % de luminosidade no Display
#### - É transmitido para o stm32 por meio do USB CDC e armazenado em um buffer circular
#### - É realizado a leitura do buffer circular alterando a luminosidade do Led conforme o valor


## PREVIEW 



https://github.com/user-attachments/assets/1d7dea52-13a9-46e4-92c5-3cbc9c05750b

## Esse projeto contém dois arquivos principais:
### 📂 QT_Gui -> Contendo o Display utilizando Qt para o usuário selecionar a temperatura
### 📂 stm32_firmware -> Onde é inicializado o LED e alterado a luminosidade (PWM) conforme o valor recebido

