#include <stdio.h>

int main(){
    float fCelsius, fFahrenheit;

    printf("Please enter the tempreature in Fahrenheit: ");
    scanf("%f", &fFahrenheit);
    fCelsius = (fFahrenheit - 32) / 9 * 5;
    printf("%5.2fF is %5.2fC\n", fFahrenheit, fCelsius);
    return 0;
}