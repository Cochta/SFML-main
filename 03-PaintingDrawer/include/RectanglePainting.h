#pragma once
#include <utility>
#include <SFML/Graphics.hpp>

class RectanglePainting : public sf::Drawable
{
public:
	std::vector<std::pair<sf::RectangleShape, sf::RectangleShape>> rectangles;
	RectanglePainting();
	~RectanglePainting();

	void CreateRectanglePainting(int nbRectangle, int windowPosX, int windowPosY);

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
private:
	std::pair<sf::RectangleShape, sf::RectangleShape> CreateRectangleAndShadow(int _width, int _height, int _x, int _y);
};
