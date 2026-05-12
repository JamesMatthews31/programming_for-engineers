#include "waveform.h"
#include <stdio.h>


float computeRMS(waveform *waveformLog[]){
    float phaseARMS, phaseBRMS, phaseCRMS = 0;
    int samples = 0;
    waveform *readingPointer = waveformLog;

    while(readingPointer->timestamp >= 0){
        // Adds the square of the current phase voltage to each counter until the timesamp starts returning a negative value and hence is out of range
        phaseARMS += readingPointer->phaseAVoltage*readingPointer->phaseAVoltage;
        phaseBRMS += readingPointer->phaseBVoltage*readingPointer->phaseBVoltage;
        phaseCRMS += readingPointer->phaseCVoltage*readingPointer->phaseCVoltage;
        // Increments the reading pointer and sample count each time
        readingPointer++;
        samples++;
    }


    
}

float computeP2P(waveform waveformLog[]); 

float computeDCOffset(float phaseRMSVoltages[]); 

float computeClipping(waveform waveformLog[]); 