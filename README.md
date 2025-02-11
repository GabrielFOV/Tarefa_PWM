# Tarefa_PWM
tarefa da unidade 4 - trabalhando com PWM para controle de servo motor

Gabriel França Oliveira Viana
TIC370100619

Para a realização da tarefa é empregado um sistema com um servo motor controlado por um modulo raspberry pico w.
Ao iniciar a simulação o flange do motor se encontra na posição 180°, com duty cycle de 2400 microssegundos, após 5 segundos a posição do flange é alterada para 90°, no duty cycle de 1470 microssegundos, passados mais 5 segundos o flange muda para a posição 0°, á um duty cycle de 500 microssegundos.
Completado o ciclo inicial o motor começa a ocilar sua posição entre 0° e 180° através da alteração do duty cycle a uma taxa de 5 microssegundos.  
Sempre que o flange passa pelas posições 0°, 90° e 180° é impressa uma mensagem referente a posição.

Figura 1
![image](https://github.com/user-attachments/assets/fb994ed4-979b-43c2-8d21-79d7a11e2edf)
Fonte: autor.
Na figura 1, consta o método usado para encontrar um divisor inteiro aproximado. 

Figura 2
![image](https://github.com/user-attachments/assets/587233f4-7000-4fc2-95a2-ba52f482a701)
fonte: embarcatech, 2024.
Na figura 2 consta o metodo no qual o calculo foi baseado.
