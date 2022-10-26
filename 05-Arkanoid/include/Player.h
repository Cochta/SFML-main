#pragma once

#include "SFML/Graphics.hpp"
class Player : public sf::Drawable, public sf::Transformable
{
public:
	Player();

	sf::RectangleShape bar;

	void Move(sf::Vector2f direction);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
private:

};