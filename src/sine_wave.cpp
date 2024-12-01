//
// Created by losec on 01/12/2024.
//

#include "sine_wave.h"
#include <cmath>
#include <vector>

// Function to generate a sine wave
std::vector<float> generateSineWave(int numSamples, float amplitude, float frequency, float phase) {
    std::vector<float> wave(numSamples);
    for (int i = 0; i < numSamples; ++i) {
        // Calculate the angle for the current sample
        float angle = phase + (2 * M_PI * frequency * i / numSamples);
        // Compute the sine value and scale by amplitude
        wave[i] = amplitude * std::sin(angle);
    }
    return wave;
}