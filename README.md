# ESP32 Robotic Control Interface

Interface web para monitoramento e controle em tempo real de sistemas de automação industrial utilizando microcontrolador ESP32.

---

## Visão geral

Este projeto integra computação embarcada e desenvolvimento web para controle de uma célula robótica de transporte de peças. A solução permite acionar atuadores e monitorar sensores industriais via rede local, utilizando uma interface web leve e responsiva.

---

## Principais competências demonstradas

* Programação embarcada com ESP32 (C/C++)
* Desenvolvimento de servidores HTTP embarcados
* Integração hardware-software
* Comunicação via JSON
* Controle de I/O digital (entradas e saídas)
* Implementação de lógica de automação industrial
* Manipulação de temporização não bloqueante (`millis`)
* Desenvolvimento de interface web embarcada
* Debugging de hardware e conectividade

---

## Tecnologias

### Camada embarcada

* ESP32
* C/C++
* Servidor HTTP embarcado

### Camada web

* JavaScript
* HTML
* CSS

---

## Arquitetura

O sistema é dividido em duas camadas principais:

* **Firmware (ESP32)**: responsável pelo controle de entradas/saídas e execução da lógica de automação
* **Interface Web**: responsável pela interação com o usuário e consumo de endpoints JSON

O ESP32 atua como Access Point e servidor HTTP, eliminando dependência de infraestrutura externa.

---

## Funcionalidades

* Controle manual de atuadores (motores, válvulas, vácuo)
* Execução de ciclo automático de operação
* Monitoramento em tempo real de sensores
* Exibição de estados via interface web
* Registro de tempo de ciclo

---

## Desafios técnicos

* Estabilização da conexão Wi-Fi do ESP32
* Diagnóstico e correção de falhas físicas no hardware
* Implementação de lógica sequencial sem bloqueio do sistema
* Garantia de resposta em tempo real durante operação contínua

---

## Objetivo do projeto

Demonstrar capacidade de integração entre software e hardware, desenvolvimento de sistemas embarcados e construção de interfaces para controle de processos industriais em tempo real.

---

## Autor

William Furquim
