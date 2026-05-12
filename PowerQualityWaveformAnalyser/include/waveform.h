// Header file for waveform data structure and calculation functions

// Start of header guard
#ifndef WAVEFORM_H
#define WAVEFORM_H

// Waveform structure definition

typedef struct{
    float timestamp;
    float phaseAVoltage;
    float phaseBVoltage;
    float phaseCVoltage;
    float lineCurrent;
    float frequency;
    float powerFactor;
    float thdPercent;
} waveform;

// Function prototypes for waveform calculations

float computeRMS(waveform waveformLog[]); 

float computeP2P(waveform waveformLog[]); 

float computeDCOffset(float phaseRMSVoltages[]); 

float computeClipping(waveform waveformLog[]); 


#endif
// End of header guard