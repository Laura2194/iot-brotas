# Brotas Alerta — Monitoramento do Nível da Água

O Brotas Alerta é um projeto desenvolvido para a área de Internet das Coisas (IoT), com o objetivo de simular o monitoramento do nível da água em Brotas/SP. A proposta utiliza um ESP32 no Wokwi para simular as medições e enviar os dados por meio do protocolo MQTT. Essas informações são exibidas em um painel web, que também consulta dados meteorológicos da região.

## Tecnologias utilizadas

- HTML, CSS e JavaScript para desenvolver o painel web.
- ESP32 para simular o envio das informações.
- Sensor ultrassônico HC-SR04 para representar a medição do nível da água.
- MQTT para a comunicação entre o ESP32 e o painel.
- Wokwi para realizar a simulação do circuito.
- API Open-Meteo para consultar informações meteorológicas.

## Organização dos arquivos

- `src/frontend/index.html`: contém o código do painel web.
- `src/iot/sketch.ino`: contém a programação do ESP32.
- `src/iot/diagram.json`: armazena o diagrama do circuito utilizado no Wokwi.
- `relatorio/relatorio.md`: arquivo para registrar as informações e os resultados do projeto.
- `.env.example`: exemplo de configuração do projeto.
- `.gitignore`: define os arquivos que não devem ser enviados ao GitHub.

## Como executar o painel web

1. Abra o arquivo `src/frontend/index.html` no navegador. Outra opção é utilizar a extensão Live Server no Visual Studio Code.
2. Verifique se o computador está conectado à internet, pois o painel precisa carregar a biblioteca MQTT.js e consultar a API Open-Meteo.
3. Aguarde a tentativa de conexão com o broker público HiveMQ, utilizado para a comunicação MQTT.
4. Inicie a simulação do ESP32 no Wokwi para enviar os dados ao painel.
5. Confira se os tópicos MQTT utilizados no código do ESP32 são os mesmos configurados no painel.

Caso a conexão não funcione, verifique a internet, os tópicos configurados e o status do broker MQTT.

## Como configurar o ESP32 no Wokwi

1. Acesse o Wokwi e crie um projeto com ESP32.
2. Abra o arquivo `sketch.ino` e coloque o código disponível em `src/iot/sketch.ino`.
3. Adicione o sensor ultrassônico HC-SR04 ao circuito.
4. Faça as ligações conforme a programação:
   - TRIG: GPIO 5.
   - ECHO: GPIO 18.
   - VCC: 5V/VIN, conforme o componente e a configuração utilizada.
   - GND: GND.
5. Inicie a simulação e observe os valores apresentados no monitor serial.
6. Verifique se os dados estão sendo enviados corretamente pelos tópicos MQTT.

**Atenção:** se o circuito for montado com componentes físicos, o pino ECHO do HC-SR04 pode fornecer 5 V, enquanto o ESP32 utiliza sinais de 3,3 V. Nesse caso, utilize um divisor de tensão ou conversor de nível lógico adequado.

## Comunicação MQTT

O projeto utiliza os seguintes tópicos para enviar as informações do nível da água:

- `iot-brotas/agua/nivel_cm`: envia o nível da água em centímetros.
- `iot-brotas/agua/percentual`: envia o nível representado em porcentagem.

O painel utiliza esses dados para acompanhar as medições recebidas durante a simulação.

## Classificação do nível da água

Para demonstrar o funcionamento do sistema, foram definidos três níveis de classificação:

- **Normal:** abaixo de 70%.
- **Atenção:** de 70% até valores inferiores a 90%.
- **Alerta crítico:** 90% ou mais.

Esses valores foram definidos para a atividade e servem apenas para demonstrar como o sistema pode classificar diferentes situações. Eles não representam limites oficiais de segurança e não devem ser utilizados para orientar decisões em situações reais de enchentes.

## Testes e resultados

<img width="1901" height="912" alt="image" src="https://github.com/user-attachments/assets/c4b23ea6-9c02-4a85-bc87-1d12e330e6bc" />

## Considerações finais

O desenvolvimento do Brotas Alerta permite colocar em prática conhecimentos de programação web, comunicação MQTT e Internet das Coisas. Com a simulação, é possível entender como os dados de um sensor podem ser enviados e apresentados em uma página web.

Apesar de demonstrar esse funcionamento, o projeto ainda precisa de testes e validações para que sua proposta possa ser avaliada em condições reais. Ele foi desenvolvido com finalidade educacional e não substitui sistemas oficiais de monitoramento ou alerta.




