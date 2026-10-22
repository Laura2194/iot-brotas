# Relatório técnico — Brotas Alerta

**Curso:** Técnico em Desenvolvimento de Sistemas  
**Unidade Curricular:** Desenvolvimento de Sistemas / IoT  
**Integrante:** Laura Salviatti
**Professor:** Robson Lourenço e Renan Café  
**Data:** 22/10/2026

## 1. Introdução

O projeto Brotas Alerta apresenta uma proposta educativa de Internet das Coisas (IoT) voltada à demonstração do monitoramento simulado do nível da água. A solução utiliza um ESP32, um sensor ultrassônico e um painel web para representar como informações coletadas por dispositivos eletrônicos podem ser transmitidas e visualizadas em tempo real.

A escolha do tema está relacionada à importância do acompanhamento das condições ambientais e dos possíveis impactos das chuvas em municípios como Brotas, no interior do estado de São Paulo. Uma reportagem publicada pela VEJA São Paulo em 10 de março de 2024, por exemplo, registrou consequências de fortes chuvas no município, incluindo danos em pontes e uma ocorrência envolvendo um veículo arrastado pela enxurrada.

Diante desse contexto, o objetivo do projeto é desenvolver um protótipo que demonstre a integração entre sensores, comunicação MQTT, consulta a dados meteorológicos e visualização de informações em uma interface digital.

É importante destacar que o Brotas Alerta possui finalidade exclusivamente acadêmica. O sistema simula o monitoramento e não substitui equipamentos profissionais, sistemas oficiais de defesa civil ou mecanismos reais de prevenção de desastres.

## 2. Problema investigado e evidências

2.1. Área e local estudado

A pesquisa documental foi direcionada ao município de Brotas, localizado no estado de São Paulo. A área específica para uma possível instalação do sistema ainda não foi definida, pois essa escolha exigiria uma investigação local mais detalhada, com identificação dos pontos relevantes e consulta aos órgãos responsáveis.

2.2. Fatos documentados

A pesquisa encontrou informações que ajudam a contextualizar a proposta:

Ocorrências relacionadas às chuvas: uma reportagem da VEJA São Paulo, publicada em 10 de março de 2024, relatou consequências de fortes chuvas em Brotas. Segundo a matéria, um veículo foi arrastado pela enxurrada na Estrada do Gouvêa e duas pontes tiveram suas estruturas danificadas, sendo interditadas preventivamente. Esse registro demonstra que eventos de chuva intensa podem provocar impactos na mobilidade e na infraestrutura local.

Informações sobre saneamento e drenagem: a plataforma Infosanbas apresenta indicadores municipais relacionados ao saneamento básico, à drenagem urbana e à gestão de riscos. Parte dos dados apresentados tem como referência informações declaradas ao Sistema Nacional de Informações sobre Saneamento (SNIS), especialmente do ano de 2020. Por isso, esses indicadores devem ser interpretados considerando seu período de referência, e não como uma descrição completa da situação atual.

As fontes consultadas contextualizam a importância do tema, mas não são suficientes, por si só, para determinar qual local de Brotas deveria receber um sensor ou comprovar a necessidade de instalação de um sistema específico.

2.3. Observações do grupo

Até o momento, não foram registradas observações presenciais próprias em um ponto específico da cidade. A etapa prática do projeto está concentrada na simulação computacional do sistema.

Caso sejam realizadas visitas de campo, deverão ser anotados o local, a data, as condições observadas e a autorização necessária. Não devem ser realizadas aproximações perigosas de rios, pontes, áreas alagadas ou outros locais de risco.

2.4. Hipótese de trabalho

A hipótese do projeto é que um sistema demonstrativo capaz de combinar leituras simuladas do nível da água com informações meteorológicas pode facilitar a visualização de dados ambientais e contribuir para o estudo de soluções tecnológicas de acompanhamento preventivo.

Essa hipótese será avaliada por meio dos testes do protótipo. Ela não comprova que determinado ponto de Brotas precise receber uma instalação real.

2.5. Pessoas potencialmente afetadas

Dependendo do local estudado, eventos relacionados a chuvas intensas e alagamentos podem afetar moradores, visitantes, motoristas, comerciantes e equipes responsáveis pela manutenção urbana e pelo atendimento de emergências.

2.6. Possíveis causas e consequências

Entre os fatores que podem contribuir para alagamentos e enxurradas estão a intensidade da precipitação, as características do relevo, as condições dos sistemas de drenagem e o comportamento dos cursos d’água. A participação de cada fator depende das condições específicas do local e precisa ser confirmada por fontes técnicas ou estudos apropriados.

Entre as possíveis consequências estão dificuldades de circulação, danos à infraestrutura e riscos à segurança das pessoas. A reportagem consultada documenta consequências de uma ocorrência em Brotas em março de 2024, mas não permite atribuir todos esses impactos a uma única causa.

## 3. Solução proposta e desenvolvida

O Brotas Alerta foi planejado como um protótipo de IoT que integra sensores simulados, comunicação entre dispositivos e uma interface web.

O ESP32, executado no simulador Wokwi, utiliza um sensor ultrassônico HC-SR04 para medir uma distância simulada. A partir dessa leitura, o programa calcula um percentual didático de nível da água. Em seguida, as informações são enviadas por meio do protocolo MQTT para um broker, permitindo que o painel web receba e apresente os valores.

O painel também consulta a API Open-Meteo para obter informações meteorológicas de Brotas, como temperatura, umidade relativa do ar e precipitação, conforme as variáveis configuradas no código.

A proposta permite estudar a comunicação entre hardware simulado, serviços externos e aplicações web, além de demonstrar como dados de diferentes fontes podem ser reunidos em uma interface.

3.1. Componentes e tecnologias

ESP32: microcontrolador responsável pela leitura do sensor e pelo envio das informações.

HC-SR04: sensor ultrassônico utilizado para medir a distância até uma superfície.

Wokwi: ambiente de simulação do circuito eletrônico.

HTML: estrutura da página web.

CSS: aparência visual e organização do painel.

JavaScript: processamento dos dados e atualização das informações na interface.

MQTT: protocolo de comunicação utilizado para transmitir as leituras.

Broker MQTT: serviço intermediário responsável por receber e distribuir as mensagens.

Open-Meteo: API utilizada para consultar dados meteorológicos.

GitHub: plataforma para armazenar os arquivos e acompanhar as alterações do projeto.

3.2. Regra de negócio

Para facilitar a demonstração, foram definidos três níveis de classificação para o percentual simulado da água:

Normal: percentual inferior a 70%.

Atenção: percentual igual ou superior a 70% e inferior a 90%.

Alerta crítico: percentual igual ou superior a 90%.

Esses limites são parâmetros didáticos definidos para o protótipo. Eles não foram validados por estudos técnicos e não devem ser utilizados para orientar decisões reais de segurança, evacuação ou prevenção de enchentes.

3.3. Testes e resultados

Os testes a seguir deverão ser executados e registrados antes da entrega final. Como a compilação apresentou um erro relacionado à biblioteca PubSubClient.h, ainda não é possível afirmar que a integração completa esteja funcionando.

Teste 1 — Sensor simulado em diferentes distâncias

Procedimento: alterar a distância simulada no sensor ultrassônico e verificar se o ESP32 recebe leituras diferentes e calcula o percentual correspondente.

Resultado observado: pendente de execução e registro.

Teste 2 — Recepção das mensagens MQTT

Procedimento: verificar se o ESP32 consegue publicar as leituras no broker MQTT e se o painel web recebe e apresenta os valores.

Resultado observado: pendente de execução e registro.

Teste 3 — Consulta à API meteorológica

Procedimento: abrir o painel web e verificar se a aplicação consegue consultar a API Open-Meteo e apresentar os dados meteorológicos disponíveis.

Resultado observado: pendente de execução e registro.

Teste 4 — Verificação dos três níveis de alerta

Procedimento: testar valores abaixo de 70%, valores entre 70% e menos de 90% e valores iguais ou superiores a 90%, verificando se cada faixa recebe a classificação correta.

Resultado observado: pendente de execução e registro.

Após a execução dos testes, deverão ser inseridas capturas de tela que comprovem os resultados, incluindo a simulação no Wokwi, o painel web e as mensagens ou classificações observadas.

3.4. Limitações do projeto

O protótipo possui limitações importantes. O sensor, o ambiente e os níveis de alerta são simulados, portanto não representam medições reais de um rio ou de outro corpo d’água.

A comunicação utiliza um broker MQTT público, que não oferece as mesmas garantias de controle e segurança de uma infraestrutura privada devidamente configurada. A consulta meteorológica depende de conexão com a internet e da disponibilidade da API.

Além disso, os dados meteorológicos regionais não substituem medições locais de chuva ou de nível da água. Uma aplicação real exigiria equipamentos adequados, instalação segura, calibração, validação dos limites, avaliação técnica do local e participação dos órgãos responsáveis.

Por essas razões, o Brotas Alerta não deve ser considerado um sistema oficial de monitoramento ou emissão de alertas de emergência.

3.5. Melhorias futuras

Como possibilidades de evolução, propõem-se:

Armazenamento de dados: implementar um banco de dados para registrar as leituras e permitir a análise de tendências ao longo do tempo.

Validação técnica: avaliar sensores, limites de alerta e possíveis locais de instalação com profissionais especializados e órgãos responsáveis antes de qualquer aplicação real.

Segurança da comunicação: substituir o broker público por uma infraestrutura privada, com autenticação e configurações de segurança apropriadas.

Ampliação do painel: incluir filtros por período, histórico de medições e gráficos para facilitar a interpretação dos dados.

Tratamento de falhas: implementar mensagens para situações de desconexão, ausência de leituras ou indisponibilidade da API.

## 4. Conclusão

O projeto Brotas Alerta foi planejado para demonstrar como a Internet das Coisas pode integrar sensores, comunicação MQTT, dados meteorológicos e interfaces web em uma solução tecnológica voltada ao estudo do monitoramento ambiental.

A pesquisa documental identificou registros de impactos relacionados às chuvas em Brotas, reforçando a relevância de estudar tecnologias que auxiliem na visualização de informações ambientais. Entretanto, a definição de um local específico para instalação real dependeria de uma investigação técnica complementar.

Até o momento, a integração completa do protótipo ainda precisa ser confirmada por meio de testes, pois foi identificado um erro de compilação relacionado à biblioteca MQTT. Dessa forma, não é possível afirmar que todos os objetivos práticos foram atingidos.

Após corrigir o erro, executar os testes e registrar as evidências, será possível avaliar o funcionamento do sensor simulado, a comunicação MQTT, a consulta meteorológica e a classificação dos níveis de alerta.

A principal contribuição acadêmica do projeto está no aprendizado da integração entre hardware simulado, programação web, comunicação de dados e serviços externos. Para transformar essa demonstração em uma solução real, seriam necessárias validação técnica, testes em condições controladas, medidas de segurança e colaboração com os órgãos competentes.

## 5. Referências

VEJA SÃO PAULO. Chuva causa alagamentos e deixa uma pessoa desaparecida em São Paulo. Agência Brasil, 10 mar. 2024. Disponível em: https://vejasp.abril.com.br/cidades/chuva-causa-alagamentos-e-deixa-uma-pessoa-desaparecida-em-sao-paulo/. Acesso em: 22 out. 2026.

INFOSANBAS. Brotas – SP. Informações municipais sobre saneamento básico, drenagem urbana e gestão de riscos. Disponível em: https://infosanbas.org.br/municipio/brotas-sp/. Acesso em: 22 out. 2026.

OPEN-METEO. Weather Forecast API Documentation. Documentação oficial da API meteorológica. Disponível em: https://open-meteo.com/en/docs. Acesso em: 22 out. 2026.

OPEN-METEO. Open-Meteo Weather API. Repositório oficial do projeto e informações sobre o serviço. Disponível em: https://github.com/open-meteo/open-meteo. Acesso em: 22 out. 2026.

WOKWI. ESP32 Simulation and Documentation. Ambiente de simulação de circuitos eletrônicos. Disponível em: https://wokwi.com/. Acesso em: 22 out. 2026.

As referências acima devem ser complementadas por outras fontes que forem efetivamente consultadas durante o desenvolvimento do projeto.

## Anexo — Evidências do projeto

Figura 1 — Simulação do circuito no Wokwi
Inserir uma captura de tela mostrando o ESP32, o sensor ultrassônico e as conexões. Informar a data da captura e descrever o que ela demonstra.

Figura 2 — Painel web do Brotas Alerta
Inserir uma captura de tela da interface, mostrando os dados meteorológicos e os campos de monitoramento disponíveis. Informar a data da captura.

Figura 3 — Comunicação MQTT
Inserir uma captura de tela que comprove o recebimento das mensagens MQTT pelo painel ou por uma ferramenta de monitoramento.

Figura 4 — Testes dos níveis de alerta
Inserir capturas de tela demonstrando os valores testados e as classificações normal, atenção e alerta crítico.

Observação: as imagens devem ser obtidas durante a execução real do projeto. Não utilizar imagens ilustrativas como se fossem resultados de testes realizados.em-sao-paulo/
- Infosanbas, informações sobre Brotas/SP: https://infosanbas.org.br/municipio/brotas-sp/
- Incluir outras fontes efetivamente consultadas pelo grupo.


