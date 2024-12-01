#include <iostream>
#include <SFML/Graphics.hpp>
#include "sine_wave.h"

int main()
{
    auto window = sf::RenderWindow({1920u, 1080u}, "CMake SFML Project");
    window.setFramerateLimit(144);

    float startx = 0.0f;
    float starty = 500.0f;

    int numSamples = 1920;
    float amplitude = 200.0f;
    float frequency = 5.0f; // One full cycle per numSamples
    float amplitude2 = 200.0f;
    float frequency2 = 10.0f; // One full cycle per numSamples
    float phase = 0.0f;

    // for (int i = 0; i < numSamples; ++i) {
    //     std::cout << "Sample " << i << ": " << sineWave[i] << std::endl;
    // }

    while (window.isOpen())
    {
        for (auto event = sf::Event(); window.pollEvent(event);)
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

        }

        window.clear(sf::Color::Black);

        std::vector<float> sineWave = generateSineWave(numSamples, amplitude, frequency, phase+= 0.01f);
        std::vector<float> sineWave2 = generateSineWave(numSamples, amplitude2, frequency2, phase+= 0.01f);
        std::vector<float> sum(numSamples);
        for (int i = 0; i < numSamples; ++i) {
            sum[i] = sineWave[i] + sineWave2[i];
        }

        sf::VertexArray wave(sf::LineStrip, numSamples);
        sf::VertexArray wave2(sf::LineStrip, numSamples);
        sf::VertexArray wave3(sf::LineStrip, numSamples);
        for (int i = 0; i < numSamples; ++i) {
            wave[i].color = sf::Color::Green;
            wave2[i].color = sf::Color::Red;
            wave3[i].color = sf::Color::Blue;

            wave[i].position = sf::Vector2f(startx + i, starty + sineWave[i]);
            wave2[i].position = sf::Vector2f(startx + i, starty + sineWave2[i]);
            wave3[i].position = sf::Vector2f(startx + i, starty + sum[i]);
        }

        window.draw(wave);
        window.draw(wave2);
        window.draw(wave3);

        window.display();
    }
}
