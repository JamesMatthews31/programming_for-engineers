/*
Filename: waveform.c
Description: Header file source code for all calculation functions
Author: James Matthews
Date: 15/05/2026
Version: 0.1.0
Log:
- Version 0.0.1: First stage that implementation seems to be complete, any testing yet to be done.
- Verions 0.1.0: First set of code that will allow the main.c to run the whole way through. Results still innacurate.
*/


#include "waveform.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>

// Function to allocate memory to the heap

float storageSetup(double **RMSValues, float **P2PValues, float **DCOffsetValues, int **clippingCounts){

    // Allocates memory to the heap for storage arrays

    *RMSValues = malloc(3 * sizeof(double));
    *P2PValues = malloc(3 * sizeof(float));
    *DCOffsetValues = malloc(3 * sizeof(float));
    *clippingCounts = malloc(3 * sizeof(int));

    for (int i = 0; i < 3; i++){

        // Set DCOffset values to 0, as += is used to assign directly as opposed to = which would lead to innacurate results with heap garbage values

        (*DCOffsetValues)[i] = 0;

    }

    for (int i = 0; i < 3; i++){

        // Set DCOffset values to 0, as += is used to assign directly as opposed to = which would lead to innacurate results with heap garbage values

        (*clippingCounts)[i] = 0;

    }

    return 0;

}

// Function to calculate the RMS of each phase

float computeRMS(waveform *waveformLog, double *RMSValues, int sampleCount){

    //Inintialise temp variables

    double phaseARMS = 0, phaseBRMS = 0, phaseCRMS = 0;

    //Initialise pointer that will go through the array.

    waveform *readingPointer = waveformLog;

    for (int i = 0; i < sampleCount; i++){

        // Adds the square of the current phase voltage to each counter until the timesamp starts returning a negative value and hence is out of range
       
        phaseARMS += readingPointer->phaseAVoltage * readingPointer->phaseAVoltage;
        phaseBRMS += readingPointer->phaseBVoltage * readingPointer->phaseBVoltage;
        phaseCRMS += readingPointer->phaseCVoltage * readingPointer->phaseCVoltage;

        // Increments the reading pointer and sample count each time

        readingPointer++;
    }

    // Writes output values to RMSValues

    RMSValues[0] = sqrt(phaseARMS / sampleCount);
    RMSValues[1] = sqrt(phaseBRMS / sampleCount);
    RMSValues[2] = sqrt(phaseCRMS / sampleCount);

    return 0;
}

// Function to compute the P2P values of each phase

float computeP2P(waveform *waveformLog, float *P2PValues, double *RMSValues,int sampleCount){

    // Takes the RMS output of the previous subroutine and multiplies it by 2 sqrt 2 to give peak to peak amplitude

    P2PValues[0] = 2 * sqrt(2) * RMSValues[0];
    P2PValues[1] = 2 * sqrt(2) * RMSValues[1];
    P2PValues[2] = 2 * sqrt(2) * RMSValues[2];

    return 0;

}

// Function to compute the DC Offset of each phase

float computeDCOffset(waveform *waveformLog, float *DCOffsetValues, int sampleCount){

    //Initialise pointer that will go through the array.
    waveform *readingPointer = waveformLog;

    for (int i = 0; i < sampleCount; i++){

        // Adds all values of voltage for each phase to calculate mean value

        DCOffsetValues[0] += readingPointer->phaseAVoltage;
        DCOffsetValues[1] += readingPointer->phaseBVoltage;
        DCOffsetValues[2] += readingPointer->phaseCVoltage;

        // Increments the reading pointer and sample count each time

        readingPointer++;

    }

    for (int i = 0; i < 3; i++){

        // Divide values by 1000 for final output

        DCOffsetValues[i] /= sampleCount;

    }

    return 0;

}

// Function to detect any clipping values

float detectClipping(waveform *waveformLog, int sampleCount, int *clippingCounts){

    // Initialise temp variables

    double phaseAVoltage, phaseBVoltage, phaseCVoltage = 0;

    // Initialise pointer that will go through the array

    waveform *readingPointer = waveformLog;

    for (int i = 0; i < sampleCount; i++){

            // Loop through all samples, taking absolute voltage values and comparing them to the clipping limit, and adding to the appropriate counter if it is greater than or equal to it

            phaseAVoltage = fabs(readingPointer->phaseAVoltage);
            phaseBVoltage = fabs(readingPointer->phaseBVoltage);
            phaseCVoltage = fabs(readingPointer->phaseCVoltage);

            if (phaseAVoltage >= 324.9){

                clippingCounts[0]++;

            }

            if (phaseBVoltage >= 324.9){

                clippingCounts[1]++;

            }

            if (phaseCVoltage >= 324.9){

                clippingCounts[2]++; 

            }

            readingPointer++;

        }

    return 0;



}

// Function using all previous functions at once. This is to make main.c cleaner.

float calcAll(waveform *waveformLog, double *RMSValues, float *P2PValues, float *DCOffsetValues, int *clippingCounts, int sampleCount){

    computeRMS(waveformLog, RMSValues, sampleCount);
    computeP2P(waveformLog, P2PValues, RMSValues, sampleCount);
    computeDCOffset(waveformLog, DCOffsetValues, sampleCount);
    detectClipping(waveformLog, sampleCount, clippingCounts);

    printf("Storage set up");

    return 0;

}