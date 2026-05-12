/*
Filename: Task 2.c
Description: To understand how memory for local variables is managed on the stack
Author: James Matthews
Date: 03/03/2026
Version: 1.1
Log:
Version 1.0: foo3() not yet implemented, adrresses of x and y printed
*/

#include <stdio.h>
#include <stdlib.h>
void foo1(int xval){
 int x;
 x = xval;
 printf("The address of x is %p\n", &x);
}
void foo2(int yval){
 int y;
 y = yval;
 printf("The address of y is %p\n", &y);
}

void foo3(void){
 int z;
 foo1(z);
 printf("The address of z is %p\n", &z);
}

int main(void){
 foo1(7);
 foo2(11);
 foo3();
 system("PAUSE");
 return 0;
}

// Note that the addresses of x and y are the same in the first 2 outputs as they are local so the same memory address can be reused.
// However as x and z are used at the same time in foo3() they have different addresses.