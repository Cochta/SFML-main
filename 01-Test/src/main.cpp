

#include <iostream>

#include "SFML/Main.hpp"
#include "SFML/Graphics.hpp"

#include "MyClass.h"
#include <random>   

int getRandomInt(int min, int max) {
	std::random_device os_seed;
	uint_least32_t seed = os_seed();

	std::mt19937 generator(seed);
	std::uniform_int_distribution<uint_least32_t> distribute(min, max);

	return distribute(generator);
}

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "The Game");
	// Basic Setup of the window
	// Vertical sync, framerate
	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(30);

	std::vector<sf::RectangleShape> rectangles;
	sf::Mouse mouse;
	sf::Vector2i pos;
	sf::RectangleShape rectangle(sf::Vector2f(40, 20));
	rectangle.setOrigin(20, 10);
	rectangle.setFillColor(sf::Color(0, 0, 0, 0));
	rectangle.setOutlineThickness(4);
	rectangle.setOutlineColor(sf::Color(255, 255, 255));
	while (window.isOpen())
	{

		// on inspecte tous les évènements de la fenêtre qui ont été émis depuis la précédente itération
		sf::Event event;

		while (window.pollEvent(event))
		{
			switch (event.type)
			{

				// évènement "fermeture demandée" : on ferme la fenêtre
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::MouseButtonPressed:
				//int width = getRandomInt(1, 2);
				pos = sf::Mouse::getPosition(window);
				rectangle.setPosition(pos.x, pos.y);
				rectangles.emplace_back(rectangle);
				break;
			default:
				break;
			}

		}

		// Graphical Region
		window.clear(sf::Color::Black);

		for (auto r : rectangles)
		{
			window.draw(r);
		}
		//window.draw(something to draw);

		// Window Display
		window.display();

	}



}
