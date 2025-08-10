# Controle de LED utilizando um menu via USB

### Esse projeto realiza a leitura das opções por meio de um menu no host (Linux) e envia o comando via usb para o stm32,que executa a respectiva ação

## Preview
https://github.com/user-attachments/assets/b035367a-b818-4a13-a239-17dd7049d383

## Menu
<img width="271" height="129" alt="image" src="https://github.com/user-attachments/assets/f8f27137-0ff6-48f5-88fe-b2692bb74c4e" />
<img width="294" height="105" alt="image" src="https://github.com/user-attachments/assets/7ff93902-eb54-4445-979f-ae4af3284dda" />


## Esse projeto contém dois arquivos principais:
### 📂 host_app -> Contendo o programa em C que oferece o menu com opções ao usuário 
### 📂 stm32_firmware -> feito a inicialização dos LEDs, sendo responsável por ler o comando enviado pelo Host e executar a ação


#


### Host code
<img width="616" height="743" alt="image" src="https://github.com/user-attachments/assets/7d39a43a-e6a0-40fa-9e3b-171e6ab20a4d" />
<img width="584" height="338" alt="image" src="https://github.com/user-attachments/assets/a705f4ce-b4ab-4b9b-8b2c-502281ef8ded" />

