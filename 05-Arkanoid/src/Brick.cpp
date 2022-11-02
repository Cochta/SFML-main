#include "Brick.h"

Brick::Brick(sf::Vector2f pos, int id)
{
	_shape.setPosition(pos);
	_shape.setSize(sf::Vector2f(160, 50));
	_shape.setFillColor(sf::Color::Blue);
	_shape.setOutlineColor(sf::Color::Green);
	_shape.setOutlineThickness(1.0f);
	_shape.setOrigin(0,0);
	Id = id;
}

void Brick::Break()
{
	IsBroken = true;
}

void Brick::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(_shape);
}
