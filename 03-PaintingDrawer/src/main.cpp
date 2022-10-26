

#include <iostream>

#include "SFML/Main.hpp"
#include "SFML/Graphics.hpp"

#include "RectanglePainting.h"
#include "SquarePainting.h"

int main()
{
	// Basic Setup of the window
	sf::RenderWindow window1(sf::VideoMode(800, 600), "Squares With Shadow");
	sf::RenderWindow window2(sf::VideoMode(480, 720), "Just Squares");
	window1.setPosition(sf::Vector2i(0, 0));
	window2.setPosition(sf::Vector2i(800, 0));
	// Vertical sync, framerate
	window1.setVerticalSyncEnabled(true);
	window1.setFramerateLimit(30);
	window2.setVerticalSyncEnabled(true);
	window2.setFramerateLimit(30);

	RectanglePainting rectanglePainting;
	SquarePainting squarePainting;

	while (window1.isOpen() || window2.isOpen())
	{

		// on inspecte tous les évènements de la fenêtre qui ont été émis depuis la précédente itération
		sf::Event event;

		while (window1.pollEvent(event))
		{
			switch (event.type)
			{
				// évènement "fermeture demandée" : on ferme la fenêtre
			case sf::Event::Closed:
				window1.close();
				break;
			case sf::Event::MouseButtonPressed:
				rectanglePainting.CreateRectanglePainting(15, window1.getSize().x, window1.getSize().y);
				break;
			default:
				break;
			}

		}
		while (window2.pollEvent(event))
		{
			switch (event.type)
			{
				// évènement "fermeture demandée" : on ferme la fenêtre
			case sf::Event::Closed:
				window2.close();
				break;
			case sf::Event::MouseButtonPressed:
				squarePainting.CreateSquarePainting(16, 24, window2.getSize().x / 16);
				break;
			default:
				break;
			}

		}

		// Graphical Region
		window1.clear(sf::Color(192, 192, 192));
		window2.clear(sf::Color(55, 55, 55));

		//window.draw(something to draw);
		window1.draw(rectanglePainting);
		window2.draw(squarePainting);

		// Window Display
		window1.display();
		window2.display();
	}
}
