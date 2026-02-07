#include <stdio.h>

int main(void){
    int numA = 0;
    int numB = 0;
    int tempNum = 0;
    printf("Enter the first number: ");
    scanf("%d", &numA);
    printf("Enter the second number: ");
    scanf("%d", &numB);
    tempNum = numA;
    numA = numB;
    numB = tempNum;
    printf("Initial values: a=%d; b=%d\n", numB, numA);
    printf("Swapped values: a=%d; b=%d\n", numA, numB);
}