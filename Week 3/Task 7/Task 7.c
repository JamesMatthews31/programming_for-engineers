#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    int num1;
    printf("Enter a 3 digit number:");
    scanf("%d",&num1);
    int digit1 = num1 / 100;
    int digit2 = (num1 / 10) % 10;
    int digit3 = num1 % 10;
    int sumNum = pow(digit1,3) + pow(digit2,3) + pow(digit3,3); 
    if (sumNum == num1){
        printf("It is an Armstrong number");
    }
    else{
        printf("It is not an Armstrong number");
    }
    return 0;
}