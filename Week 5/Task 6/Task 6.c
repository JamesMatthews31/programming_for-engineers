#include <stdio.h>

void swapVariables(int a, int b);

int main(){
    int num1, num2;
    printf("Enter the first number: ");
    scanf("%d", num1);
    printf("Enter the second number: ");
    scanf("%d", num2);
    printf("num1 = %d, num2 = %d\n", num1, num2);
    swapVariables(num1, num2);
    printf("num1 = %d, num2 = %d\n", num1, num2);
    return 0;
}

void swapVariables(int a, int b){
    int temp = a;
    a = b;
    b = temp;
}