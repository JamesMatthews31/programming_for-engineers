 /*
Filename: Task 4.c
Description: Write a function which takes as parameters the values of resistance, capacitance, inductance,
and angular frequency (ω and pointers to variables that will store the calculated impedance
and phase angle. Use the sqrt() and acos() functions from the <math.h> library.
Author: James Matthews
Date: 03/03/2026
Version: 1.0
Log:
*/

#include <stdio.h>
#include <math.h>

// Function prototype

void calcRLCProperties(double R, double L, double C, double omega, double *impedance, double *phaseAngle);



int main(){
    // Collects values to use for calculations
    double R, L, C, omega, impedance, phaseAngle;
    printf("Enter resistance: ");
    scanf("%lf", &R);
    printf("Enter inductance: ");
    scanf("%lf", &L);
    printf("Enter capacitance: ");
    scanf("%lf", &C);
    printf("Enter angular frequency: ");
    scanf("%lf", &omega);
    calcRLCProperties(R, L, C, omega, &impedance, &phaseAngle);
    printf("Z = %.4lf\n", impedance);
    printf("Phi = %.4lf\n", phaseAngle);
    return 0;
}

// Function body

void calcRLCProperties(double R, double L, double C, double omega, double *impedance, double *phaseAngle){
    double zCalc = sqrt(R*R + pow((omega*L - 1/(omega*C)), 2));
    double phiCalc = acos(R / zCalc);
    *impedance = zCalc;
    *phaseAngle = phiCalc;
}