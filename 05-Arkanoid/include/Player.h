#pragma once

#include "Ball.h"
#include "SFML/Graphics.hpp"
#include <SFML/Audio.hpp>
class Player : public sf::Drawable
{
public:
	Player();

	int HP;

	void Move(float time);
	void Launch(Ball& ball);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	void SetDirection(sf::Vector2f direction) { _direction = direction; }

	bool IsColliding(Ball& ball);
	void SetDefaultPosition();
	void SetLeft() { _bar.setPosition(1 + _bar.getSize().x / 2, _bar.getPosition().y); }
	void SetRight() { _bar.setPosition(800 - _bar.getSize().x / 2, _bar.getPosition().y); }
	sf::FloatRect GetGlobalBounds() { return _bar.getGlobalBounds(); }
	float GetLeft() { return _bar.getPosition().x - _bar.getSize().x / 2; }
	float GetRight() { return _bar.getPosition().x + _bar.getSize().x / 2; }
private:
	sf::RectangleShape _bar;
	sf::Vector2f _direction;
	sf::SoundBuffer _sb;
	sf::Sound _sound;
};