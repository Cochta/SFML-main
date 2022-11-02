#pragma once

#include "Ball.h"
#include "Brick.h"
#include "Player.h"
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
class Game
{
public:
	Game();

	sf::RenderWindow window;

	void Init();
	void Play();

private:
	bool IsStarted = false;

	void checkEvent(sf::Event& event);
	void update(sf::Clock& clock, sf::Time& totalElapsed);
	void display();

	void fillBricks();

	sf::Font _font;
	Player _player;
	Ball _ball;
	std::vector<Brick> _bricks;
	sf::SoundBuffer _sb1;
	sf::SoundBuffer _sb2;
	sf::SoundBuffer _sb3;
	sf::Sound _windowCollision;
	sf::Sound _outOfBounds;
	sf::Sound _break;
};