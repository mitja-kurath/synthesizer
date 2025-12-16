#pragma once
#include <JuceHeader.h>

class Oscillator
{
public:
    void setSampleRate(double rate);
    void setFrequency(float freq);
    float process();

private:
    double sampleRate = 0.0;
    float frequency = 0.0f;
    float currentPhase = 0.0f;
    float phaseIncrement = 0.0f;

    void updatePhaseIncrement();
};