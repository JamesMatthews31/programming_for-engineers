#include <stdio.h>

int isEven(int number);


void main(){
    // Ask user to enter input then check if even
    int num;
    printf("Enter an integer: ");
    scanf("%d", &num);
    switch (isEven(num)){
        case 0:
            printf("%d is odd.\n", num);
            break;
        case 1:
            printf("%d is even.\n", num);
            break;
        case 2:
            printf("The number is zero.\n");
            break;
    }
}

int isEven(int a){
    // Returns value 0-2 based on even, odd or zero
    if (a == 0){
        return 2;
    }
    if (a % 2 == 0){
        return 1;
    }
    else {
        return 0;
    }
}