#include "SquarePainting.h"

#include "UtilityFunction.h"

SquarePainting::SquarePainting()
{
}

SquarePainting::~SquarePainting()
{
}

void SquarePainting::CreateSquarePainting(int row, int col, float width)
{
	sf::Color color;
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			int rnd = UtilityFontion::getRandomInt(1, 10);
			if (rnd == 1)
			{
				color = UtilityFontion::HSVtoRGB(
					UtilityFontion::getRandomInt(320, 358),
					UtilityFontion::getRandomInt(30, 70),
					UtilityFontion::getRandomInt(30, 50));
			}
			else
			{
				color = UtilityFontion::HSVtoRGB(
					UtilityFontion::getRandomInt(320, 358),
					UtilityFontion::getRandomInt(30, 70),
					UtilityFontion::getRandomInt(80, 90));
			}

			squares.emplace_back(CreateSquare(width, color, width * i, width * j));
		}
	}
}

void SquarePainting::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (auto square : squares)
	{
		target.draw(square);
	}
}

sf::RectangleShape SquarePainting::CreateSquare(float width, sf::Color color, float x, float y)
{
	sf::RectangleShape rectangle(sf::Vector2f(width, width));
	rectangle.setFillColor(color);
	rectangle.setOutlineThickness(1);
	rectangle.setOutlineColor(sf::Color::Black);
	rectangle.setPosition(x, y);
	return rectangle;
}
