#include "Oscillator.h"

void Oscillator::setSampleRate(double rate)
{
    sampleRate = rate;
    updatePhaseIncrement();
}

void Oscillator::setFrequency(float freq)
{
    frequency = freq;
    updatePhaseIncrement();
}

void Oscillator::updatePhaseIncrement()
{
    if (sampleRate > 0 && frequency > 0)
        phaseIncrement = frequency * juce::MathConstants<float>::twoPi / (float)sampleRate;
    else
        phaseIncrement = 0.0f;

    currentPhase = fmodf(currentPhase, juce::MathConstants<float>::twoPi);
}

float Oscillator::process()
{
    float sampleValue = std::sin (currentPhase);
    currentPhase += phaseIncrement;

    if (currentPhase >= juce::MathConstants<float>::twoPi)
        currentPhase -= juce::MathConstants<float>::twoPi;
    else if (currentPhase < 0.0f)
        currentPhase += juce::MathConstants<float>::twoPi;

    return sampleValue;
}