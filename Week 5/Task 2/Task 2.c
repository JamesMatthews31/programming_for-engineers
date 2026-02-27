#include <stdio.h>

int addNumbers(int a, int b);

int main(){
    int num1, num2;
    printf("Enter the first number to be added: ");
    scanf("%d", &num1);
    printf("Enter the second number to be added: ");
    scanf("%d", &num2);
    printf("Sum of 2 numbers: %d\n", addNumbers(num1, num2));
    return 0;
}

int addNumbers(int a, int b){
    return a + b;
}