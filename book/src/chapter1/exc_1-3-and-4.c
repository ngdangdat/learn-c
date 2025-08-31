#include <stdio.h>

float ctof(float c);
float ftoc(float f);

int main() {
    printf("Fahrenheit\tCelsius\n");
    for (float f = 1.0; f <= 300.0; f += 20) {
        float c = ftoc(f);
        printf("%.f\t%.f\n", f, c);
    }
    printf("==========\n");
    printf("Celsius\tFahrenheit\n");
    for (float c = 1.0; c <= 300.0; c += 20) {
        float f = ctof(c);
        printf("%.f\t%.f\n", c, f);
    }
    return 0;
}


float ctof(float c) {
    return (9 / 5) * c + 32;
}


float ftoc(float f) {
    return (5.0 / 9.0) * (f - 32.0);
}
