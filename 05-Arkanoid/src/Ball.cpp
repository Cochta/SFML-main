#include "Ball.h"

#include <iostream>

Ball::Ball()
{
	_shape.setRadius(10);
	_shape.setFillColor(sf::Color::Green);
	setPosition(400, 769);
	_shape.setOrigin(_shape.getRadius() / 2, _shape.getRadius() / 2);
	setOrigin(_shape.getRadius() / 2, _shape.getRadius() / 2);

	_direction = sf::Vector2f(0, 0);
	LastTouched = -5;
}

void Ball::Move(float time)
{
	setPosition(getPosition() + (_direction * 600.0f) * time);
}

void Ball::Bounce(Direction d)
{
	if (d == Direction::Right || d == Direction::Left) // left
	{
		_direction.x *= -1;
	}
	else if (d == Direction::Up || d == Direction::Down) // up
	{
		_direction.y *= -1;
	}
}

void Ball::PlaySound()
{
	
}

bool Ball::IsColliding(sf::FloatRect rect)
{
	if (rect.contains(GetNorth()) || rect.contains(GetSouth()))
	{
		Bounce(Direction::Up);
		return true;
	}
	else if (rect.contains(GetEast()) || rect.contains(GetWest()))
	{
		Bounce(Direction::Right);
		return true;
	}
	return false;
}

void Ball::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	target.draw(_shape, states);
}
