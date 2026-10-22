# Relatório técnico — Brotas Alerta

**Curso:** Técnico em Desenvolvimento de Sistemas  
**Unidade Curricular:** Desenvolvimento de Sistemas / IoT  
**Integrantes:** preencher  
**Professor:** Robson Lourenço e Renan Café  
**Data:** preencher

## 1. Introdução
Este projeto apresenta o Brotas Alerta, um protótipo educativo de Internet das Coisas para demonstrar o monitoramento simulado do nível da água e sua visualização em um painel web. O tema foi escolhido por permitir estudar como sensores, comunicação MQTT e informações meteorológicas podem apoiar o acompanhamento preventivo de situações relacionadas à chuva em Brotas/SP.

O objetivo é construir e testar uma demonstração funcional, sem afirmar que ela substitui sistemas oficiais de monitoramento ou alerta.

## 2. Problema investigado e evidências
**Área/local estudado:** preencher após pesquisa.

**Fatos documentados:** registrar aqui apenas fatos que as fontes consultadas comprovem, com data, título e link.

**Observações do grupo:** descrever observações próprias, indicando quando e onde foram feitas e se havia autorização.

**Hipótese de trabalho:** um sistema demonstrativo que combine leituras de nível da água e dados meteorológicos pode ajudar a visualizar informações relevantes para acompanhamento preventivo. Essa hipótese não prova que um local específico precise de instalação.

**Quem poderia ser afetado:** moradores, visitantes, motoristas e equipes responsáveis pela manutenção urbana, dependendo do local estudado.

**Possíveis causas e consequências:** preencher com base nas fontes; não apresentar suposições como fatos.

## 3. Solução proposta e desenvolvida
O ESP32 simulado lê um sensor ultrassônico HC-SR04 e estima um percentual didático de nível de água. As leituras são publicadas em um broker MQTT. O painel web recebe os tópicos MQTT e consulta a API Open-Meteo para exibir temperatura, umidade relativa e precipitação.

### Componentes e tecnologias
- ESP32 e HC-SR04 no Wokwi.
- HTML, CSS e JavaScript.
- MQTT para transportar as leituras.
- Open-Meteo para dados meteorológicos.
- GitHub para controle de versão e entrega.

### Regra de negócio
No protótipo, abaixo de 70% é classificado como normal; entre 70% e menos de 90% como atenção; e 90% ou mais como alerta crítico. Os valores são didáticos e não foram validados para qualquer ponto real de Brotas.

### Testes e resultados
Preencher somente depois de executar os testes:
1. Sensor simulado em diferentes distâncias: resultado observado ______.
2. Recepção de mensagens MQTT no painel: resultado observado ______.
3. Consulta à API meteorológica: resultado observado ______.
4. Teste dos três níveis de alerta: resultado observado ______.
Anexar capturas de tela do Wokwi, do painel e dos testes.

### Limitações
O sensor, o ambiente e os limites são simulados; o broker é público; a API depende de internet; os dados meteorológicos são regionais e não substituem um pluviômetro local. O protótipo não é um sistema oficial de segurança.

### Melhorias futuras
1. Armazenar medições em banco de dados para observar tendências ao longo do tempo.
2. Validar sensores, limites e local de instalação com especialistas e órgãos responsáveis antes de qualquer aplicação real.
3. Como melhoria adicional, utilizar um broker MQTT privado e autenticação.

## 4. Conclusão
Completar depois dos testes: informar se o protótipo atingiu o objetivo acadêmico, quais dificuldades ocorreram, quais resultados foram observados e o que seria necessário para uma aplicação real.

## 5. Referências
- Open-Meteo, documentação oficial: https://open-meteo.com/en/docs
- Open-Meteo, informações sobre o serviço: https://github.com/open-meteo/open-meteo
- Notícia sobre impactos de chuvas em Brotas, publicada em 10/03/2024: https://vejasp.abril.com.br/cidades/chuva-causa-alagamentos-e-deixa-uma-pessoa-desaparecida-em-sao-paulo/
- Infosanbas, informações sobre Brotas/SP: https://infosanbas.org.br/municipio/brotas-sp/
- Incluir outras fontes efetivamente consultadas pelo grupo.

## Anexo — evidências
Inserir imagens com legenda, data e descrição do que cada imagem comprova.
