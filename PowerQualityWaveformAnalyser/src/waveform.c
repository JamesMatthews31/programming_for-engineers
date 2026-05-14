#include "waveform.h"
#include <stdio.h>
#include <math.h>

float storageSetup(void){

    // Subroutine to allocate memory in the heap for each of the storage arrays for output of analysis functions.

    float *RMSValues = malloc(3 * sizeof(float));
    float *P2PValues = malloc(3 * sizeof(float));
    float *DCOffsetValues = malloc(3 * sizeof(float));
    float *clippingCounts = malloc(3 * sizeof(int));

    for (int i = 0; i < 3; i++){

        // Set DCOffset values to 0, as += is used to assign directly as opposed to = which would lead to innacurate results with heap garbage values

        DCOffsetValues[i] = 0;

    }

}

float computeRMS(waveform *waveformLog, double *RMSValues, int sampleCount){

    //Inintialise temp variables

    double phaseARMS, phaseBRMS, phaseCRMS = 0;

    //Initialise pointer that will go through the array.

    waveform *readingPointer = waveformLog;

    for (int i = 0; i = sampleCount; i++){

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

float computeP2P(waveform *waveformLog, float *P2PValues, float *RMSValues,int sampleCount){

    // Takes the RMS output of the previous subroutine and multiplies it by 2 sqrt 2 to give peak to peak amplitude

    P2PValues[0] = 2 * sqrt(2) * RMSValues[0];
    P2PValues[1] = 2 * sqrt(2) * RMSValues[1];
    P2PValues[2] = 2 * sqrt(2) * RMSValues[2];

    return 0;

}

float computeDCOffset(waveform *waveformLog, float *DCOffsetValues, int sampleCount){

    //Initialise pointer that will go through the array.
    waveform *readingPointer = waveformLog;

    for (int i = 0; i = sampleCount; i++){

        // Adds all values of voltage for each phase to calculate mean value

        DCOffsetValues[0] += readingPointer->phaseAVoltage;
        DCOffsetValues[1] += readingPointer->phaseBVoltage;
        DCOffsetValues[2] += readingPointer->phaseCVoltage;

        // Increments the reading pointer and sample count each time

        readingPointer++;

    }

    for (int i = 0; i < 3; i++){

        // Divide values by 1000 for final output

        DCOffsetValues[i] /= 1000;

    }

    return;

}

float detectClipping(waveform *waveformLog, int sampleCount, int *clippingCounts){

    // Initialise temp variables

    float phaseAVoltage, phaseBVoltage, phaseCVoltage = 0;

    // Initialise pointer that will go through the array

    waveform *readingPointer = waveformLog;

    for (int i = 0; i = sampleCount; i++){

            // Loop through all samples, taking absolute voltage values and comparing them to the clipping limit, and adding to the appropriate counter if it is greater than or equal to it

            phaseAVoltage = abs(readingPointer->phaseAVoltage);
            phaseBVoltage = abs(readingPointer->phaseBVoltage);
            phaseCVoltage = abs(readingPointer->phaseCVoltage);

            if (phaseAVoltage >= 324.9){

                clippingCounts[0]++;

            }

            if (phaseBVoltage >= 324.9){

                clippingCounts[1]++;

            }

            if (phaseCVoltage >= 324.9){

                clippingCounts[2]++;

            }

        }

    return;

}