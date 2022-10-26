#include "Player.h"

Player::Player() {
	bar.setPosition(sf::Vector2f(0,80));
	bar.setSize(sf::Vector2f(100,20));
	bar.setFillColor(sf::Color::Green);
}

void Player::Move(sf::Vector2f direction)
{
	
	bar.setPosition(bar.getPosition() * direction * 10);
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(bar);
}
