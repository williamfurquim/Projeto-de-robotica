# 🤖 ESP32 Robotic Control Interface

> Interface Web para monitoramento e controle em tempo real de uma célula robótica de transporte de peças industriais.

⚠️ **NOTA DE CONECTIVIDADE:** Esta aplicação roda de forma 100% embarcada no microcontrolador ESP32 atuando como *Access Point*. Não há link web público! A interface é acessada localmente ao conectar-se à rede Wi-Fi emitida pelo próprio chip.

[![C++](https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)](https://isocpp.org/)
[![ESP32](https://img.shields.io/badge/ESP32-E7352C?style=for-the-badge&logo=espressif&logoColor=white)](https://www.espressif.com/)
[![JavaScript](https://img.shields.io/badge/JavaScript-F7DF1E?style=for-the-badge&logo=javascript&logoColor=black)](https://developer.mozilla.org/)

O projeto integra computação embarcada e desenvolvimento web para acionamento de atuadores e leitura de sensores industriais via rede local, utilizando uma interface leve, responsiva e de baixa latência.

---

## 📸 Demonstração do Painel de Controle

<img width="900" height="1600" alt="WhatsApp Image 2026-05-24 at 21 01 33" src="https://github.com/user-attachments/assets/ac0f28bb-3a1f-49ae-a79a-8634c653a8c7" />


---

## 🏗️ Arquitetura do Sistema

O sistema adota uma arquitetura descentralizada de duas camadas, eliminando qualquer dependência de internet externa (Edge Computing local):

*   **Camada de Interface**: Construída com HTML5, CSS3 e Vanilla JavaScript. Ela roda diretamente no navegador do usuário e realiza requisições HTTP assíncronas consumindo endpoints JSON expostos pelo microcontrolador.

*   **Camada de Firmware**: Roda diretamente no ESP32, que atua simultaneamente como Access Point (provendo a rede Wi-Fi) e como Servidor HTTP Embarcado. Esta camada processa as requisições web, executa a lógica sequencial de automação e controla diretamente as portas de I/O Digital (entradas e saídas) conectadas aos sensores industriais, motores e válvulas do hardware.

---

## ⚡ Engenharia e Soluções para os Desafios Técnicos

Desenvolver para hardware escasso em recursos (memória e processamento) exige decisões de software diferentes do desenvolvimento web tradicional:

### Programação Assíncrona e Não-Bloqueante (`millis`)
Em automação industrial, congelar o processamento pode causar acidentes ou perda de leitura de sensores. Substituímos completamente o uso de funções bloqueantes como `delay()` pela checagem de tempo baseada na função `millis()`. Isso garante que o loop principal do ESP32 continue rodando e respondendo às requisições web enquanto monitora o tempo de ciclo dos motores em background.

---

## 🚀 Funcionalidades Implementadas

*   **Controle Manual Baseado em Eventos:** Acionamento individual de motores, válvulas e sistemas de vácuo diretamente pela tela.
*   **Ciclo Automático de Operação:** Rotina sequencial automatizada para transporte contínuo de peças.
*   **Telemetria Real-time:** Monitoramento visual do estado de sensores industriais e registro preciso do tempo de ciclo da máquina.

---

## 🛠️ Hardware & Tecnologias Utilizadas

*   **Camada Embarcada:** Microcontrolador ESP32, Linguagem C/C++ (Framework Arduino), Servidor HTTP Nativo.
*   **Camada Web:** HTML5, CSS3, Vanilla JavaScript.

---

## 👥 Desenvolvedores

*   [William Furquim](https://github.com/williamfurquim)
*   [Amanda Jaguella](https://github.com/AmandaJaguella)
*   [Emilly Nascimento](#)
