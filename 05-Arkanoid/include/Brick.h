#pragma once

#include <SFML/Audio.hpp>
#include "SFML/Graphics.hpp"
class Brick : public sf::Drawable, public sf::Transformable
{
public:
	Brick(sf::Vector2f pos, int id);

	void Break();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	bool IsBroken = false;
	int Id;

	sf::FloatRect GetGlobalBounds() { return _shape.getGlobalBounds(); }
private:
	sf::RectangleShape _shape;
};
