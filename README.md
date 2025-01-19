# tarefa_teclado
Repositório criado a fim de desenvolver o projeto de controle de GPIO's por meio de teclado matricial.

Este código, tem a finalidade de controler três LED's (vermelho, azul e verde) e um buzzer utilizando um teclado matricial 4x4,
tudo isso por meio da placa Raspberry Pi Pico W.
As linhas do teclado devem ser conectadas às GPIO's 8, 7, 6, 5, enquanto que as colunas devem ser conectadas às GPIO's 4, 3, 2, 1.
Os LED's já vem imbutidos na placa BitDogLab, assim como o buzzer. Após carregar o código, o sistema imprime as instruções no console serial.
Conecte o Pico ao computador e use um terminal serial configurado para 115200 baud. Na interação com o teclado matricial, o LED vermelho irá
acender quando a tecla 'C' for apertada, o LED verde, quando a tecla 'A' for apertada, e o LED azul, quando a tecla 'B' for pressionada.
O buzzer, por sua vez, toca quando a tecla '#' é pressionada.
