#include "Player.h"

#include <iostream>

Player::Player() {
	SetDefaultPosition();
	_bar.setSize(sf::Vector2f(100, 20));
	_bar.setFillColor(sf::Color::Green);
	_bar.setOrigin(_bar.getSize().x * 0.5f, 0);
	HP = 3;
	_sb.loadFromFile("data/soundEffects/Clong.wav");
	_sound.setBuffer(_sb);
}

void Player::Move(float time)
{
	_bar.setPosition(_bar.getPosition() + (_direction * 450.0f) * time);
}

void Player::Launch(Ball& ball)
{
	if (ball.Grounded)
	{
		ball.Grounded = false;
		ball.SetDirection(sf::Vector2f(0, -1));
	}
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(_bar);
}

bool Player::IsColliding(Ball& ball)
{
	sf::FloatRect rect = GetGlobalBounds();
	float left = _bar.getPosition().x - _bar.getGlobalBounds().width / 2;
	float right = _bar.getPosition().x + _bar.getGlobalBounds().width / 2;
	float middle = _bar.getPosition().x;
	if (rect.contains(ball.GetSouth()) && ball.LastTouched != -1)
	{
		std::cout << middle << " " << ball.GetSouth().x << std::endl;
		ball.Bounce(Direction::Up);
		if (ball.GetSouth().x < middle - _bar.getGlobalBounds().width / 4)
			ball.SetX(-0.5f);
		else if (ball.GetSouth().x < middle)
			ball.SetX(-0.25f);
		else if (ball.GetSouth().x > middle + _bar.getGlobalBounds().width / 4)
			ball.SetX(+0.5f);
		else if (ball.GetSouth().x > middle)
			ball.SetX(+0.25f);
		//ball.SetX(); // doit retourner une valeur entre -1 et +1
		_sound.play();
		return true;
	}
}

void Player::SetDefaultPosition()
{
	_bar.setPosition(sf::Vector2f(400, 780));
}
