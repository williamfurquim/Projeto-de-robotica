Interface gráfica para controle e monitoramento em tempo real de sensores e atuadores robóticos utilizando ESP32 com comunicação via Wi-Fi. O sistema integra firmware embarcado em C++ com uma aplicação web desenvolvida em HTML, CSS e JavaScript, permitindo operação remota, execução de processos automáticos e acompanhamento de métricas.

👉 VISÃO GERAL
O ESP32 opera em modo Access Point, hospedando um servidor HTTP na porta 80. Através de qualquer navegador conectado à rede criada pelo dispositivo, é possível:
- Controlar manualmente 8 saídas digitais (atuadores) 
- Executar um processo automático sequencial
- Monitorar 8 entradas digitais (sensores) em tempo real
- Visualizar histórico de execução e tempo de ciclo
- O sistema abstrai a complexidade do firmware embarcado por meio de uma interface web responsiva e intuitiva.


👉 ARQUITETURA DO SISTEMA
⏺️ CAMADA EMBARCADA (C++ / ESP32)
- Servidor HTTP com WiFiServer
- Controle de 8 saídas digitais
- Leitura de 8 entradas digitais
- Execução de sequência automatizada com temporização controlada
- edição de tempo de ciclo do processo
- Registro de histórico com timestamp relativo
- Endpoint JSON para monitoramento em tempo real

⏺️ CAMADA WEB (HTML + CSS + JavaScript)
- Interface responsiva hospedada no próprio ESP32
- Atualização dinâmica de status via endpoint /status
- Botões de controle manual ON/OFF
- Página dedicada ao processo automático
- Página de histórico de execução


👉 FUNCIONALIDADES PRINCIPAIS
⏺️ CONTROLE MANUAL
Permite acionamento individual de cada saída digital através de rotas HTTP específicas, mantendo sincronização de estado entre firmware e interface.

⏺️ PROCESSO AUTOMÁTICO
Execução sequencial de etapas industriais simuladas:
- Acionamento de magazine 
- Avanço e recuo
- Ativação de vácuo
- Manipulação e liberação de peça
- O sistema mede o tempo total do ciclo e registra o resultado para análise posterior.

⏺️ MONITORAMENTO EM TEMPO REAL
Endpoint /status retorna JSON com o estado atual dos sensores, permitindo leitura dinâmica via JavaScript.

⏺️ HISTÓRICO DE PROCESSOS
Armazena número do ciclo executado, tempo total e horário relativo desde a inicialização do sistema.


👉 CONCEITOS TÉCNICOS APLICADOS
- Sistemas embarcados com ESP32
- Comunicação Wi-Fi em modo Access Point
- Implementação de servidor HTTP embarcado
- Manipulação de requisições GET
- Serialização de dados em JSON
- Controle de GPIO (entradas e saídas digitais)
- Temporização e medição de tempo com millis()
- Integração firmware + interface web
- Organização modular de páginas HTML via arquivos externos
