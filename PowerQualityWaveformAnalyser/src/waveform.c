#include "waveform.h"
#include <stdio.h>
#include <math.h>

float computeRMS(waveform *waveformLog[], float *RMSValues[], int sampleCount){

    float phaseARMS, phaseBRMS, phaseCRMS = 0;
    waveform *readingPointer = waveformLog;

    for (int i = 0; i = sampleCount; i++){
        // Adds the square of the current phase voltage to each counter until the timesamp starts returning a negative value and hence is out of range
        phaseARMS += readingPointer->phaseAVoltage*readingPointer->phaseAVoltage;
        phaseBRMS += readingPointer->phaseBVoltage*readingPointer->phaseBVoltage;
        phaseCRMS += readingPointer->phaseCVoltage*readingPointer->phaseCVoltage;
        // Increments the reading pointer and sample count each time
        readingPointer++;
    }

    *RMSValues[0] = sqrt(phaseARMS / sampleCount);
    *RMSValues[1] = sqrt(phaseBRMS / sampleCount);
    *RMSValues[2] = sqrt(phaseCRMS / sampleCount);

    return;
}

float computeP2P(waveform waveformLog[]); 

float computeDCOffset(float phaseRMSVoltages[]); 

float computeClipping(waveform waveformLog[]); 