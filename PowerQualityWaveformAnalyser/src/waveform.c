/*
Filename: waveform.c
Description: Header file source code for all calculation functions
Author: James Matthews
Date: 15/05/2026
Version: 0.1.0
Log:
- Version 0.0.1: First stage that implementation seems to be complete, any testing yet to be done.
- Verions 0.1.0: First set of code that will allow the main.c to run the whole way through. Results still innacurate.
- Version 0.1.1: First attempted implementation of quick sort function
*/


#include "waveform.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>

// Function to allocate memory to the heap

float storageSetup(double **RMSValues, float **P2PValues, float **DCOffsetValues, int **clippingCounts){

    // Allocates memory to the heap for storage arrays, based on data size

    *RMSValues = malloc(3 * sizeof(double));
    *P2PValues = malloc(3 * sizeof(float));
    *DCOffsetValues = malloc(3 * sizeof(float));
    *clippingCounts = malloc(3 * sizeof(int));

    for (int i = 0; i < 3; i++){

        // Set DCOffset values to 0, as += is used to assign directly as opposed to = which would lead to innacurate results with heap garbage values

        (*DCOffsetValues)[i] = 0;

    }

    for (int i = 0; i < 3; i++){

        // Set clippingCount values to 0, as += is used to assign directly as opposed to = which would lead to innacurate results with heap garbage values

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

    // Initialise variables for max min and temp values of each phase

    double phaseATemp = 0;
    double phaseBTemp = 0;
    double phaseCTemp = 0;  
    double phaseAMax = 0;
    double phaseBMax = 0;
    double phaseCMax = 0;
    double phaseAMin = 0;
    double phaseBMin = 0;
    double phaseCMin =  0;

    // Initialise pointer for reading pointer
    
    waveform *readingPointer = waveformLog;


    for (int i = 0; i < sampleCount; i++){

        // Assign values to temporary variables for the appropriate phase
       
        phaseATemp = readingPointer->phaseAVoltage;
        phaseBTemp = readingPointer->phaseBVoltage;
        phaseCTemp = readingPointer->phaseCVoltage;

        // Compare phase A to phaseAMax, and if it is greater that or equal to it set as new value, then do the inverse for min if first condition isnt met

        if (phaseATemp >= phaseAMax){

            phaseAMax = phaseATemp;

        }

        else if(phaseATemp <= phaseAMin){
            
            phaseAMin = phaseATemp;

        }

        // Compare phase B to phaseBMax, and if it is greater that or equal to it set as new value, then do the inverse for min if first condition isnt met

        if (phaseBTemp >= phaseBMax){

            phaseBMax = phaseBTemp;

        }

        else if(phaseBTemp <= phaseBMin){
            
            phaseBMin = phaseBTemp;

        }

        // Compare phase C to phaseCMax, and if it is greater that or equal to it set as new value, then do the inverse for min if first condition isnt met

        if (phaseCTemp >= phaseCMax){

            phaseCMax = phaseCTemp;

        }

        else if(phaseCTemp <= phaseCMin){
            
            phaseCMin = phaseCTemp;

        }

        readingPointer++;
    }

    // Return outputs to pointers

    P2PValues[0] = (phaseAMax - phaseAMin);
    P2PValues[1] = (phaseBMax - phaseBMin);
    P2PValues[2] = (phaseCMax - phaseCMin);
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

// Function to swap items

int swap(waveform *a, waveform *b){

    // Assign the value at a to the temp variable, then put the value at b into a, then write temp into b

    waveform temp = *a;
    *a = *b;
    *b = temp;

    return 0;

}

// Function to sort an array of values using the quick sort method

int quickSort(waveform **waveformLog, int idxLow, int idxHigh){

    if (idxLow < idxHigh){

        // Carry out swapping routine for the sub list

        int boundary = qSSwaps(waveformLog, idxLow, idxHigh);

        // Then call the sort again for the further sub lists created while the low is still the low

        quickSort(waveformLog, boundary + 1, idxHigh);
        quickSort(waveformLog, idxLow, boundary -1);

    }    

    return 0;

}

// Function to actually do the swapping for the quick sort block

int qSSwaps(waveform **waveformLog, int idxLow, int idxHigh){

    // Create the pivot for the quick sort

    double pivot = (*waveformLog)[idxHigh].phaseAVoltage;

    // Set min of current elements to go from low to high

    int currentElements = idxLow - 1;

    // Iterate through elements

    for (int i = idxLow; i <= idxHigh; i++){

        // If current elements is larger than the pivot swap and increment the pivot element counter

        if((*waveformLog)[i].phaseAVoltage > pivot){

            currentElements++;
            swap(&(*waveformLog)[currentElements], &(*waveformLog)[i]);

        }

    }

    // Swap new pivot end and high end

    swap(&(*waveformLog)[currentElements + 1], &(*waveformLog)[idxHigh]);

    return currentElements + 1;

}