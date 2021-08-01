#pragma once
class Tile
{
private:
	sf::RectangleShape tile;
public:
	Tile(const float& posX, const float& posY,const sf::Vector2f& size);
	virtual ~Tile();

	const sf::FloatRect& getTilePosition();
	void update();
	void render(sf::RenderTarget* window);
};

