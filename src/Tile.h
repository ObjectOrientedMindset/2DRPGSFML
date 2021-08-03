#pragma once
class Tile
{
private:
	//array accessor
	int tileCode;
	sf::RectangleShape tile[4];
	enum tileColor
	{
		GREEN = 0, BLUE, GREY, YELLOW
	};
public:
	Tile(const float& posX, const float& posY,const sf::Vector2f& size, const int& tile);
	virtual ~Tile();

	const sf::Vector2f& getTilePosition();
	void update();
	void render(sf::RenderTarget* window);
};

