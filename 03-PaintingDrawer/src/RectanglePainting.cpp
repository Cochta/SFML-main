#include "RectanglePainting.h"

#include "UtilityFunction.h"

RectanglePainting::RectanglePainting()
{

}

RectanglePainting::~RectanglePainting()
{
}

std::pair<sf::RectangleShape, sf::RectangleShape> RectanglePainting::CreateRectangleAndShadow(int _width, int _height, int _x, int _y)
{
	sf::RectangleShape rectangle(sf::Vector2f(_width, _height));
	rectangle.setFillColor(sf::Color(0, 0, 0, 0));
	rectangle.setOutlineThickness(5);
	rectangle.setOutlineColor(sf::Color(0, 0, 0));
	rectangle.setPosition(_x, _y);

	sf::RectangleShape shadow = rectangle;
	shadow.setOutlineColor(sf::Color(100, 100, 100));
	shadow.setPosition(_x + 10, _y + 30);
	return std::pair(rectangle, shadow);
}

void RectanglePainting::CreateRectanglePainting(int nbRectangle, int windowPosX, int windowPosY)
{
	rectangles.clear();
	for (int i = 0; i < nbRectangle; ++i)
	{
		int width = UtilityFontion::getRandomInt(windowPosX / 40, windowPosY / 2);
		int height = width;
		int x = UtilityFontion::getRandomInt(windowPosX / 8, windowPosX - width - windowPosX / 8);
		int y = UtilityFontion::getRandomInt(windowPosY / 6, windowPosY - height - windowPosY / 6);
		rectangles.emplace_back(CreateRectangleAndShadow(width, height, x, y));
	}
}

void RectanglePainting::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (auto pair : rectangles)
	{
		target.draw(pair.second);
	}

	for (auto pair : rectangles)
	{
		target.draw(pair.first);
	}
}
