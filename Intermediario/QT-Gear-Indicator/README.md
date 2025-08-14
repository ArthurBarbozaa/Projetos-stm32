## 🖥️ ⚙️ QT GEAR INDICATOR #

### Este projeto simula a leitura de marcha selecionada e exibe no display usando Qt.

## Funcionamento: 
#### - **Botão UP/DOWN** simula aumentar/reduzir a marcha (R, N, 1, 2, 3, 4, 5)
#### - STM32 envia os dados pelo USB CDC (porta `/dev/ttyACM0` no Linux)
#### - Qt realiza a leitura da porta serial e atualiza a interface gráfica


## PREVIEW 


https://github.com/user-attachments/assets/f64487c1-0968-4162-b80b-6db080cbf004


## Fluxo de Comunicação
1. **Botão no STM32** → Interrupção GPIO
2. **Atualiza marcha** no array `gear[]`
3. **Envia string** para USB CDC (`CDC_Transmit_FS`)
4. **Qt lê porta** e atualiza UI em tempo real

