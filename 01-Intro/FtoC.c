#include <stdio.h>

int main(){
    int iCelsius, iFahrenheit = 99;
    iCelsius = (iFahrenheit - 32) / 9 * 5;
    printf("%dF is %dC\n", iFahrenheit, iCelsius);

    float fCelsius, fFahrenheit = 99.0;
    fCelsius = (fFahrenheit - 32) / 9 * 5;
    printf("%5.2fF is %5.2fC\n", fFahrenheit, fCelsius);
    return 0;
}