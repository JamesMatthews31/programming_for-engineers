/*
Filename: Task 1.c
Description: 

Create a structure to hold the values of a complex number.
Then manipulate the variables as descibed:

(a) Declare structure variables c1, c2 and c3, each having members real and imaginary
of type double.
(b) Modify the declaration in part (a) so that c1’s members initially have the values 0.0 and 1.0,
while c2’s members are 1.0 and 0.0 initially (c3 is not initialised).
(c) Write statements that copy the members of c2 into c1. Can this be done in one
statement or does it require two?
(d) Write statements that add the corresponding members of c1 and c2 storing the result in
c3.

Author: James Matthews
Date: 10/03/2026
Version: 1.0
Log:
*/

#include <stdio.h>

typedef struct{
    double real;
    double imaginary;
} complexNumber;

int main(){
    // Define structure with a typename to improve readability
    // Initialise c1 and c2, create c3
    complexNumber c1 = {0.0, 1.0};
    complexNumber c2 = {1.0, 0.0};
    complexNumber c3;
    // Copy c2 into c1
    c1 = c2;
    // Add c1 and c2 into c3
    c3.real = c1.real + c2.real;
    c3.imaginary = c1.imaginary + c2.imaginary;
    // Print results
    printf("c1 = %.4lf + %.4lf i\n", c1.real, c1.imaginary);
    printf("c2 = %.4lf + %.4lf i\n", c2.real, c2.imaginary);
    printf("c3 = %.4lf + %.4lf i\n", c3.real, c3.imaginary);
    return 0;

}
