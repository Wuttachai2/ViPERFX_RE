//
// Created by mart on 7/31/21.
//

#pragma once


#include "IIR_NOrder_BW_LH.h"
#include "WaveBuffer_I32.h"
#include "IIR_NOrder_BW_BP.h"

class HiFi {
public:
    HiFi();
    ~HiFi();

    void Process(float* samples, uint32_t size);
    void Reset();

    void SetClarity(float value);
    void SetSamplingRate(uint32_t samplerate);

    WaveBuffer_I32* buffers[2];
    struct {
        IIR_NOrder_BW_LH* lowpass;
        IIR_NOrder_BW_LH* highpass;
        IIR_NOrder_BW_BP* bandpass;
    } filters[2];
    float gain;
    uint32_t samplerate;
};

