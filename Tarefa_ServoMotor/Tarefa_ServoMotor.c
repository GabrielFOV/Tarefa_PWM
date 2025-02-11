#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"

#define servo_pin 22   // GPIO 22 conectado ao servo.
#define WRAP 20000 // Para 50Hz (20ms) frequência PWM.
#define angulo_0   500   // 0° - Duty cycle de 500 microssegundos.
#define angulo_90  1470  // 90° - Duty cycle de 1475 microssegundos.
#define angulo_180 2400  // 180° - Duty cycle de 2400 microssegundos.
#define Divisor  125  // Divisor de clock ajustado para servo.

void pwm_setup()//Função de inicialização para o PWM. 
{
    gpio_set_function(servo_pin, GPIO_FUNC_PWM); // Configura GPIO 22 como PWM.
    uint slice = pwm_gpio_to_slice_num(servo_pin); // Obtém o slice do PWM.
    pwm_set_clkdiv(slice, Divisor); // Define divisor de clock.
    pwm_set_wrap(slice, WRAP);   // Define período do PWM (50Hz).
    pwm_set_enabled(slice, true);       // Habilita o PWM.
}

// Função para definir o ângulo do servo (0° a 180°).
void Controle_Angulo(uint16_t angulo) 
{
    pwm_set_gpio_level(servo_pin, angulo);
}

int main() 
{
    uint16_t angulo = angulo_0;// Inicializa o parametro de comparação.
    stdio_init_all();//Inicializa as funcionalidades de entrada e saída padrão.
    pwm_setup();//Inicializa o PWM.

    Controle_Angulo(angulo_180);//Ajusta o flange para 180°. 
    printf("Posição: 180°\n");
    sleep_ms(5000);

    Controle_Angulo(angulo_90);//Ajusta o flange para 90°. 
    printf("Posição: 90°\n");
    sleep_ms(5000);

    Controle_Angulo(angulo_0);//Ajusta o flange para 0°. 
    printf("Posição: 0°\n");
    sleep_ms(5000);

    while (true)//Loop principal. 
    {
        for (uint16_t angulo = angulo_0; angulo <= angulo_180; angulo += 5)//Enquanto o angulo é menor que 180°, há incremento. 
        {
            Controle_Angulo(angulo);//Ajusta o angulo.
            sleep_ms(10);//Aguarda 10 microssegundos para a próxima mudança de angulo. 
            if(angulo==angulo_180)//quando atinge 180° imprime mensagem.
            {
                printf("Posição: 180°\n");
            }
            if(angulo==angulo_90)//quando atinge 90° imprime mensagem.
            {
                printf("Posição: 90°\n");
            }
            if(angulo==angulo_0)//quando atinge 0° imprime mensagem.
            {
                printf("Posição: 0°\n");
            }
        }
        for (uint16_t angulo = angulo_180; angulo >= angulo_0; angulo -= 5)//quando atindge 180°, há decremento. 
        {
            Controle_Angulo(angulo);//Ajusta o angulo.
            sleep_ms(10);//Aguarda 10 microssegundos para a próxima mudança de angulo. 
            if(angulo==angulo_90)//quando atinge 90° imprime mensagem.
            {
                printf("Posição: 90°\n");
            }
           
        }
    }
}
