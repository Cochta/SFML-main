

#include <iostream>

#include "SFML/Main.hpp"
#include "SFML/Graphics.hpp"

#include "MyClass.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "The Game");
	// Basic Setup of the window
	// Vertical sync, framerate
	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(30);
	sf::Texture up;
	sf::Texture down;
	sf::Texture right;
	sf::Texture left;
	up.loadFromFile("data/sprites/up.png");
	down.loadFromFile("data/sprites/down.png");
	left.loadFromFile("data/sprites/left.png");
	right.loadFromFile("data/sprites/right.png");
	sf::Sprite link;
	auto center = window.getSize();
	link.setPosition(center.x / 2, center.y / 2);
	link.setTexture(up);
	float speed = 10;
	while (window.isOpen())
	{

		// on inspecte tous les évènements de la fenêtre qui ont été émis depuis la précédente itération
		sf::Event event;

		while (window.pollEvent(event))
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			{
				link.setTexture(up);
				link.setPosition(link.getPosition().x, link.getPosition().y - speed);
			}
			switch (event.type)
			{
				// évènement "fermeture demandée" : on ferme la fenêtre
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::KeyPressed:
				switch (event.key.code)
				{
				case sf::Keyboard::Down:
				case sf::Keyboard::S:
					link.setTexture(down);
					link.setPosition(link.getPosition().x, link.getPosition().y + speed);
					break;
				case sf::Keyboard::Left:
				case sf::Keyboard::A:
					link.setTexture(left);
					link.setPosition(link.getPosition().x - speed, link.getPosition().y);
					break;
				case sf::Keyboard::Right:
				case sf::Keyboard::D:
					link.setTexture(right);
					link.setPosition(link.getPosition().x + speed, link.getPosition().y);
					break;
				default:
					break;
				}
				break;
			default:
				break;
			}

		}

		// Graphical Region
		window.clear(sf::Color::Black);

		window.draw(link);
		//window.draw(something to draw);

		// Window Display
		window.display();

	}



}
