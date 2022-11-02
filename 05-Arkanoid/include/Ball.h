#pragma once

#include "SFML/Graphics.hpp"

enum class Direction
{
	Up,
	Down,
	Left,
	Right
};
class Ball : public sf::Drawable, public sf::Transformable
{
public:
	Ball(); 
	void Move(float time);
	void Bounce(Direction d);
	void PlaySound();
	bool IsColliding(sf::FloatRect rect);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	bool Grounded = true;
	int LastTouched;

	float GetRadius() { return _shape.getRadius(); }
	void SetDirection(sf::Vector2f direction) { _direction = direction; }
	void SetX(float x) { _direction.x = x; }

	sf::Vector2f GetNorth() { return  sf::Vector2f(getPosition().x, getPosition().y - _shape.getRadius()); }
	sf::Vector2f GetSouth() { return  sf::Vector2f(getPosition().x, getPosition().y + _shape.getRadius()); }
	sf::Vector2f GetEast() { return sf::Vector2f(getPosition().x + _shape.getRadius(), getPosition().y); }
	sf::Vector2f GetWest() { return sf::Vector2f(getPosition().x - _shape.getRadius(), getPosition().y); }
private:
	sf::Vector2f _direction;
	sf::CircleShape _shape;
};
