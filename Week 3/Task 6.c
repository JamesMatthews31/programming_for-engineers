#include <stdio.h>
#include <math.h>

int main(){
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