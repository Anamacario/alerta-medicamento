# 📌 Projeto: Lembrete de Medicamentos com LED, Buzzer e Display SSD1306

## 📌 Descrição

Este projeto implementa um sistema de alerta para lembrar a administração de medicamentos. O sistema ativa um **LED**, um **buzzer** e exibe uma mensagem no **display OLED SSD1306** quando chega o horário predefinido. O alarme permanece ativo até que o botão seja pressionado para confirmar a ingestão do medicamento. O projeto foi desenvolvido utilizando a **placa BitDogLab**.

## 🎯 Funcionalidades

- Ativa um **LED piscante** e um **buzzer** para alertar sobre o horário do medicamento.
- Exibe a mensagem **"Tome o remédio!"** no **display SSD1306** via comunicação **I2C**.
- Mantém o LED aceso e o buzzer ativado até que o usuário pressione o botão.
- Após a confirmação, exibe a mensagem **"Ingestão confirmada!"**, desliga o LED e o buzzer.
- Utiliza **GPIOs da BitDogLab** para controle do LED, buzzer e botão.

## 🛠 Requisitos

- **Placa**: BitDogLab
- **Componentes**:
  - **LED** para sinalização visual
  - **Buzzer** para alerta sonoro (usando **PWM**)
  - **Botão** para confirmação do usuário
  - **Display OLED SSD1306** para exibição de mensagens (via **I2C**)
  
- **Ferramentas:**
  - SDK da BitDogLab
  - Editor de código **VS Code**
  - CMake e Ninja para compilação

## 📌 Configuração dos Pinos

| Componente            | GPIO                          |
| --------------------- | ----------------------------- |
| LED de Alerta         | GPIO 13                       |
| Buzzer               | GPIO 21                       |
| Botão de Confirmação  | GPIO 5                        |
| Display SSD1306 (I2C) | GPIO 14 (SDA) / GPIO 15 (SCL) |

## 🚀 Como Executar

1. **Clonar o repositório**
   ```bash
   git clone https://github.com/Anamacario/alerta-medicamento.git
   cd alerta-medicamento
## 🚀 Como Executar

1. **Compilar e carregar na BitDogLab**
   - Conectar a placa ao computador
   - Compilar o código e copiar o arquivo `.uf2` para a bitdoglab

## 🔍 Testes Realizados

✅ LED piscando no início do alarme  
✅ Buzzer ativado com PWM durante o alerta  
✅ Mensagens exibidas corretamente no **display SSD1306**  
✅ Botão desativando corretamente o alarme e alterando a mensagem  

## 🎥 Entrega e Demonstração

1. **Código-fonte**: Disponível no repositório GitHub com documentação e organização.
2. **Vídeo Demonstrativo**:
   - Demonstração do funcionamento na **BitDogLab**.
   - Click [AQUI](https://drive.google.com/file/d/1l4K9c3dRssVQxDFc_9uf26-d4GLHesQN/view?usp=sharing) para acessar o vídeo de apresentação.

---

Projeto desenvolvido como parte da **Residência em Sistemas Embarcados**, demonstrando manipulação de **GPIOs, PWM e comunicação I2C** na BitDogLab.