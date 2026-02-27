#include <stdio.h>

float power(float base, unsigned int exponent);

int main(){
    float base;
    unsigned int exponent;
    printf("Enter the base for the calculation: ");
    scanf("%f", &base);
    printf("Enter the exponent for the calculation: ");
    scanf("%u", &exponent);
    printf("The calculation gives: %f\n", power(base, exponent));
    return 0;
}

float power(float base, unsigned int exponent){
    float output = 1;
    for (int i = 0; i < exponent; i++){
        output *= base;
    }
    return output;
}