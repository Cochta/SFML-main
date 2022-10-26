#include <SFML/Graphics.hpp>

class SquarePainting : public sf::Drawable
{
public:
	std::vector<sf::RectangleShape> squares;
	SquarePainting();
	~SquarePainting();
	void CreateSquarePainting(int row, int col, float width);

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
private:
	sf::RectangleShape CreateSquare(float width, sf::Color color, float x, float y);

};
