#pragma once

#include <random>

namespace UtilityFontion
{
	inline int getRandomInt(int min, int max) {
		std::random_device os_seed;
		uint_least32_t seed = os_seed();

		std::mt19937 generator(seed);
		std::uniform_int_distribution<uint_least32_t> distribute(min, max);

		return distribute(generator);
	}

	inline sf::Color HSVtoRGB(float H, float S, float V) {
		float s = S / 100;
		float v = V / 100;
		float C = s * v;
		float X = C * (1 - abs(fmod(H / 60.0, 2) - 1));
		float m = v - C;
		float r, g, b;
		if (H >= 0 && H < 60) {
			r = C, g = X, b = 0;
		}
		else if (H >= 60 && H < 120) {
			r = X, g = C, b = 0;
		}
		else if (H >= 120 && H < 180) {
			r = 0, g = C, b = X;
		}
		else if (H >= 180 && H < 240) {
			r = 0, g = X, b = C;
		}
		else if (H >= 240 && H < 300) {
			r = X, g = 0, b = C;
		}
		else {
			r = C, g = 0, b = X;
		}
		int R = (r + m) * 255;
		int G = (g + m) * 255;
		int B = (b + m) * 255;
		return sf::Color(R, G, B);
	}
}
