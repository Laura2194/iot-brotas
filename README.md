# Brotas Alerta — Monitoramento Inteligente do Nível da Água

Projeto educacional de IoT para demonstrar como um ESP32 simulado pode publicar medições de nível da água por MQTT, enquanto um painel web apresenta os dados e consulta condições meteorológicas da região de Brotas/SP.

## Importante
- Este é um protótipo acadêmico, não um sistema oficial de alerta ou segurança.
- O nível da água é simulado no Wokwi e os limites são regras didáticas, não limites técnicos validados para locais reais.
- Pesquise e cite fontes locais antes de afirmar que um ponto específico de Brotas apresenta risco recorrente.
- O MQTT usa um broker público de demonstração. Não envie dados pessoais ou informações sensíveis.
- A API Open-Meteo é usada sem chave para este exemplo de uso gratuito não comercial. Consulte os termos e a documentação oficial.

## Tecnologias
HTML, CSS, JavaScript, ESP32, sensor ultrassônico HC-SR04 simulado, MQTT, Wokwi e API Open-Meteo.

## Estrutura
- `src/frontend/index.html`: painel web.
- `src/iot/sketch.ino`: programa do ESP32.
- `src/iot/diagram.json`: diagrama inicial de ligação no Wokwi.
- `relatorio/relatorio.md`: modelo de relatório técnico para completar.
- `.env.example`: exemplo informativo de configuração (nenhuma chave é necessária neste projeto).
- `.gitignore`: arquivos que não devem ser publicados.

## Como executar o painel
1. Abra `src/frontend/index.html` no navegador. Se preferir, use a extensão Live Server no VS Code.
2. Permita acesso à internet para carregar MQTT.js e consultar a Open-Meteo.
3. O painel se conecta ao broker público HiveMQ via WebSocket.
4. Inicie o ESP32 no Wokwi para publicar os dados. Use o mesmo tópico configurado no firmware.
5. Se a conexão MQTT falhar, confira o status do broker e tente novamente mais tarde.

## Como executar o ESP32 no Wokwi
1. Crie um projeto ESP32 no Wokwi.
2. Copie o conteúdo de `src/iot/sketch.ino` para `sketch.ino`.
3. Adicione um sensor ultrassônico HC-SR04.
4. Ligue TRIG ao GPIO 5, ECHO ao GPIO 18, VCC ao 5V/VIN e GND ao GND.
5. Execute a simulação e acompanhe a saída serial.
6. Para hardware físico real, não conecte diretamente o ECHO de 5 V ao ESP32: use divisor de tensão ou conversor de nível lógico.

## Tópicos MQTT
- `iot-brotas/agua/nivel_cm`
- `iot-brotas/agua/percentual`

## Regra didática
- Menos de 70%: nível simulado normal.
- De 70% a menos de 90%: atenção.
- 90% ou mais: alerta crítico no protótipo.
Esses valores são apenas parâmetros demonstrativos e precisam ser validados antes de qualquer uso real.

## Testes
Registre capturas de tela e os resultados reais observados.
<img width="1901" height="912" alt="image" src="https://github.com/user-attachments/assets/c4b23ea6-9c02-4a85-bc87-1d12e330e6bc" />


