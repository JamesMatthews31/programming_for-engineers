#include <stdio.h>
int main(void){
    // numIn is a two digit number such that its form is digit1digit2. swappedNum is hence digit2digit1.
    int digit1 = 0;
    int digit2 = 0;
    int numIn = 0;
    int swappedNum = 0;
    printf("Please enter number: ");
    scanf("%d", &numIn);
    digit1 = numIn / 10;
    digit2 = numIn % 10;
    swappedNum = (digit2*10) + digit1;
    printf("The swapped number is: %d\n", swappedNum);
}