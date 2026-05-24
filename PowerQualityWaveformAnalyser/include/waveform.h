/*
Filename: waveform.h
Description: Header file for waveform and waveform calculation functions
Author: James Matthews
Date: 15/05/2026
Version: 0.1
Log:
- Version 0.1: All known structs and function prototypes implemented with header guard.
- Version 0.2: Implemented the sort funcitions and updated all parameters to be accurate.
*/

// Start of header guard.
#ifndef WAVEFORM_H
#define WAVEFORM_H

// Waveform structure definition.

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

// Function prototypes for waveform calculations.

// Sets up the arrays that all calculation values are stored in.

float storageSetup(double **RMSValues, float **P2PValues, float **DCOffsetValues, int **clippingCounts);

// Calculates the RMS value of each phase of voltages. Uses double as input and output as the values are used for P2P.

float computeRMS(waveform *waveformLog, double *RMSValues, int sampleCount); 

// Calculates the P2P voltage for each phase using 2 sqrt 2.

float computeP2P(waveform *waveformLog, float *P2PValues, double *RMSValues,int sampleCount); 

// Computes the DC offset by adding up all values and dividing my the number of samples.

float computeDCOffset(waveform *waveformLog, float *DCOffsetValues, int sampleCount); 

// Detect all values outside of the clipping range.

float detectClipping(waveform *waveformLog, int sampleCount, int *clippingCounts); 

// Function to do all of the above functions at once.

float calcAll(waveform *waveformLog, double *RMSValues, float *P2PValues, float *DCOffsetValues, int *clippingCounts, int sampleCount);

// Function to swap two items.

int swap(waveform *a, waveform *b);

// Function to sort an array of values using the quick sort method.

int quickSort(waveform **waveformLog, int idxLow, int idxHigh);

// Function to actually do the swapping for the quick sort block.

int qSSwaps(waveform **waveformLog, int idxLow, int idxHigh);


#endif
// End of header guard