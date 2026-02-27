#include <stdio.h>
 int main(){
    float num1,num2,num3,num4 = 0;
    printf("Enter number 1:");
    scanf("%f",&num1);
    float min = num1;
    printf("Enter number 2:");
    scanf("%f",&num2);
    if(num2 < min){
        min = num2;
    }
    printf("Enter number 3:");
    scanf("%f",&num3);
    if(num3 < min){
        min = num3;
    }
    printf("Enter number 4:");
    scanf("%f",&num4);
    if(num4 < min){
        min = num4;
    }
    printf("The minimum value is: %.4f\n",min);
    return 0;
    // Works by checking each number against the current minimum value and updating the minimum value to the new number if it is smaller.
 }