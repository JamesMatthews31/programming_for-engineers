/*
Filename: Task 6.c
Description: Write a program that takes two numbers and one of the following operators: +, -,
*, /, %, ^. It should then perform the requested operation. Use switch to handle the different
operators. The ^ operator can be implemented with the pow() function from <math.h>.
Author: James Matthews
Date: 10/02/2026
Version: 1.0
Log:
*/

#include <stdio.h>
#include <math.h>

int main(){
    // Collects inputs
    printf("Enter a number:");
    float num1;
    scanf("%f",&num1);
    printf("Enter another number:");
    float num2;
    scanf("%f",&num2);
    printf("Enter an operator:");
    char operator;
    scanf(" %c",&operator);
    switch(operator){
        // Switch to carry out appropriate operation. Also includes division by zero error handling.
        case '+':
            printf("%f",num1 + num2);
            break;
        case '-':
            printf("%f",num1 - num2);
            break;
        case '*':
            printf("%f",num1 * num2);
            break;
        case '/':
            if (num2 == 0){
                printf("Exit code 1: Division by zero error");
                return 1;
            }
            else{
                printf("%f",num1 / num2);
                break;
            }
        case '%':
            if ((int)num2 == 0){
                printf("Exit code 1: Division by zero error");
                return 1;
            }
            else{
                printf("%d",(int)num1 % (int)num2);
                break;
            }
        case '^':
            printf("%f",pow(num1,num2));
            break;
        default:
            printf("Exit code 1: Operator not recognised");
            return 1;
    }
}