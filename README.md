# 🌟 Controle de LEDs e Buzzer com Teclado Matricial 4x4 (Raspberry Pi Pico W) 🌟

Este projeto utiliza o **Raspberry Pi Pico W** para controlar três LEDs (vermelho, azul e verde) e um buzzer por meio de um teclado matricial 4x4. O código é carregado diretamente na placa e a interação é feita via terminal serial.

---

## 👨‍💻 Desenvolvedores

- **Felipe Chaves Lacerda**
- **Gabriel Finotti Barros**  
- **Mariana Farias da Silva**  
- **Pablo Vinicius Rodrigues Barboza**  
- **Pedro Henrique Carvalho Felix**  
- **Ramon Leite Petitinga**
- **Samuel Rodrigues**


---

## 🛠️ Funcionalidades

1. **Controle de LEDs** 💡:
   - O LED **Vermelho** acende quando a tecla `C` é pressionada.
   - O LED **Verde** acende quando a tecla `A` é pressionada.
   - O LED **Azul** acende quando a tecla `B` é pressionada.
   - Acende todos os LEDs com a tecla `D`.

2. **Controle do Buzzer** 🎵:
   - O **Buzzer** toca quando a tecla `#` é pressionada, emitindo um som a 3350 Hz por 500 ms.

3. **Teclado Matricial 4x4** 🔢:
   - O teclado está mapeado para 16 teclas, cada uma controlando LEDs ou o buzzer.

---

## 📋 Requisitos

```plaintext
🔧 Hardware:
- Raspberry Pi Pico W.
- Teclado Matricial 4x4 conectado aos pinos GPIO 1 a 8.
- LEDs integrados na placa BitDogLab (GPIO 11, 12 e 13).
- Buzzer integrado na placa BitDogLab (GPIO 21).
- Resistores adequados para proteger os LEDs.

💻 Software:
- SDK do Raspberry Pi Pico configurado.
- Compilador C compatível (como GCC).
- Ferramentas para upload do código para o Pico (como `picotool`).
```
---
## 🧩 Configuração do Hardware
```plaintext
1. Conecte o Teclado Matricial 4x4:
   - Linhas conectadas aos pinos GPIO 5, 6, 7 e 8.
   - Colunas conectadas aos pinos GPIO 1, 2, 3 e 4.

2. Conecte os LEDs:
   - LED Verde no GPIO 11 (integrado na placa).
   - LED Azul no GPIO 12 (integrado na placa).
   - LED Vermelho no GPIO 13 (integrado na placa).

3. Conecte o Buzzer ao GPIO 21 (integrado na placa).

4. Certifique-se de usar resistores de proteção adequados.
```
---
🚀 Compilação e Upload

```plaintext
1. Clone o repositório do código:
   git clone <URL_DO_REPOSITORIO>

2. Compile o programa usando CMake:
   mkdir build
   cd build
   cmake ..
   make

3. Envie o arquivo `.uf2` gerado para o Raspberry Pi Pico:
   - Mantenha o botão `BOOTSEL` pressionado enquanto conecta o Pico ao computador.
   - Copie o arquivo `.uf2` gerado para a unidade montada.
```
---
## 🎮 Comandos e Funções

| **Tecla** | **Função**                               | **Ação**                                |
|-----------|------------------------------------------|-----------------------------------------|
| `A`       | Acende o LED verde                       | 💡 Verde                               |
| `B`       | Acende o LED azul                        | 💡 Azul                                |
| `C`       | Acende o LED vermelho                    | 💡 Vermelho                            |
| `D`       | Acende todos os LEDs                    | 🌈 Luz branca                          |
| `#`       | Toca o buzzer      | 🎵 Toque do buzzer                     |
| `*`       | Apaga todos os LEDs                     | ❌ Desliga todos os LEDs               |


---
## 🎥 Demonstração

```plaintext
https://youtu.be/w7YDV_CNgn4
```
