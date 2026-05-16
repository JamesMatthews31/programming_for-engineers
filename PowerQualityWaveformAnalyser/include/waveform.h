/*
Filename: waveform.h
Description: Header file for waveform and waveform calculation functions
Author: James Matthews
Date: 15/05/2026
Version: 0.1
Log:
- Version 0.1: All known structs and function prototypes implemented with header guard
*/

// Start of header guard
#ifndef WAVEFORM_H
#define WAVEFORM_H

// Waveform structure definition

typedef struct{
    float timestamp;
    double phaseAVoltage;
    double phaseBVoltage;
    double phaseCVoltage;
    double lineCurrent;
    double frequency;
    double powerFactor;
    double thdPercent;
} waveform;

// Function prototypes for waveform calculations

// Sets up the arrays that all calculation values are stored in

float storageSetup(void);

// Calculates the RMS value of each phase of voltages. Uses double as input and output as the values are used for P2P

float computeRMS(waveform *waveformLog, double *RMSValues, int sampleCount); 

// Calculates the P2P voltage for each phase using 2 sqrt 2

float computeP2P(waveform *waveformLog, float *P2PValues, float *RMSValues,int sampleCount); 

// Computes the DC offset by adding up all values and dividing my the number of samples

float computeDCOffset(waveform *waveformLog, float *DCOffsetValues, int sampleCount); 

// Detect all values outside of the clipping range

float detectClipping(waveform *waveformLog, int sampleCount, int *clippingCounts); 

#endif
// End of header guard