#include "Game.h"

#include <iostream>

Game::Game()
{

}

void Game::Init()
{
	window.create(sf::VideoMode(800, 800), "Arkanoid", sf::Style::Close);
	window.setPosition(sf::Vector2i(500, 0));
	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(144);
	fillBricks();

	_font.loadFromFile("data/font/arial_narrow_7.ttf");
	_sb1.loadFromFile("data/soundEffects/Tic.wav");
	_windowCollision.setBuffer(_sb1);
	_sb2.loadFromFile("data/soundEffects/Flop.wav");
	_outOfBounds.setBuffer(_sb2);
	_sb3.loadFromFile("data/soundEffects/Boom.wav");
	_break.setBuffer(_sb3);
}

void Game::Play()
{

	sf::Event event;

	sf::Clock clock;
	sf::Time totalElapsed;
	while (window.isOpen())
	{
		// on inspecte tous les évènements de la fenêtre qui ont été émis depuis la précédente itération


		while (window.pollEvent(event))
		{
			checkEvent(event);
		}
		if (IsStarted)
		{
			update(clock, totalElapsed);
		}

		display();
	}
}

void Game::checkEvent(sf::Event& event)
{
	if (event.type == sf::Event::Closed)
	{
		window.close();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !_ball.Grounded)
	{
		_player.SetDirection(sf::Vector2f(-1, 0));
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && !_ball.Grounded)
	{
		_player.SetDirection(sf::Vector2f(1, 0));
	}
	else
	{
		_player.SetDirection(sf::Vector2f(0, 0));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		if (IsStarted)
			_player.Launch(_ball);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
	{
		if (!IsStarted)
			IsStarted = true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && !IsStarted)
	{
		exit(0);
	}
}

void Game::update(sf::Clock& clock, sf::Time& totalElapsed)
{
	sf::Time elapsed = clock.restart();
	totalElapsed = totalElapsed + elapsed;

	_ball.Move(elapsed.asSeconds());
	if (_player.GetLeft() >= 0 && _player.GetRight() <= 800) //player movement
	{
		_player.Move(elapsed.asSeconds());
	}
	else if (_player.GetLeft() <= 0)
	{
		_player.SetLeft();

	}
	else if (_player.GetRight() >= 800)
	{
		_player.SetRight();
	}
	if (_ball.GetWest().x <= 0 && _ball.LastTouched != -2) //ball movement
	{

		_ball.LastTouched = -2;
		_ball.Bounce(Direction::Left);
		_windowCollision.play();
	}
	if (_ball.GetEast().x >= window.getSize().x && _ball.LastTouched != -3)
	{

		_ball.LastTouched = -3;
		_ball.Bounce(Direction::Right);
		_windowCollision.play();
	}
	if (_ball.GetNorth().y <= 0 && _ball.LastTouched != -4)
	{
		_ball.LastTouched = -4;
		_ball.Bounce(Direction::Up);
		_windowCollision.play();
	}
	if (_ball.GetSouth().y >= window.getSize().y)
	{
		_ball.LastTouched = -5;
		//_ball.Bounce(Direction::Up);
		//_windowCollision.play();

		_outOfBounds.play();
		Ball ball;
		_ball = ball;
		_player.SetDefaultPosition();
		_player.SetDirection(sf::Vector2f(0, 0));
		_player.HP -= 1;
	}
	if (_player.HP <= 0)
	{
		_bricks.clear();
		_player.HP = 3;
		IsStarted = false;
		fillBricks();
	}
	if (IsStarted && _ball.Grounded)
		window.setTitle("Lives: " + std::to_string(_player.HP) + " Press Space to Launch the ball !");
	else if (IsStarted)
		window.setTitle("Lives: " + std::to_string(_player.HP));
	else
		window.setTitle("Arkanoid");

	if (_player.IsColliding(_ball) && _ball.LastTouched != -1)
	{
		_ball.LastTouched = -1;
	}

	for (auto& brick : _bricks)
	{
		if (_ball.IsColliding(brick.GetGlobalBounds()) && _ball.LastTouched != brick.Id)
		{
			_ball.LastTouched = brick.Id;
			_break.play();
			brick.Break();
		}
	}
	_bricks.erase(std::remove_if(_bricks.begin(), _bricks.end(), [](const Brick& brick)
		{
			return brick.IsBroken;
		}
	), _bricks.end());
	if (_bricks.empty())
	{
		IsStarted = false;
	}

}

void Game::display()
{
	window.clear(sf::Color::Black);
	//window.draw(something to draw);
	if (IsStarted)
	{
		window.draw(_player);
		window.draw(_ball);
		for (auto brick : _bricks)
		{
			window.draw(brick);
		}
	}
	else
	{
		sf::Text text;
		text.setFont(_font);
		text.setString("Press Enter to start a new game ! \nPress Esc to quit !");
		text.setOrigin(text.getGlobalBounds().width / 2, text.getGlobalBounds().height / 2);
		text.setPosition(window.getSize().x / 2, window.getSize().y / 2);
		window.draw(text);
	}

	// Window Display
	window.display();
}

void Game::fillBricks()
{
	int brickId = 0;
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			_bricks.emplace_back(Brick(sf::Vector2f((160 * i), 50 * j), brickId));
			brickId++;
		}
	}
}