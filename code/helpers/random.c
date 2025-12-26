#include <avr/io.h>

int get_random(int a, int b){
    int numberDiff = b - a + 1;
    return (TCNT1 % numberDiff) + a; //Usamos el timer1 para obtener un valor y hacemos los calculos para que esté en el rango que se ha indicado
}