#pragma once
class Tile
{
private:
	//array accessor
	int tileCode;
	sf::Texture tile[4];
	sf::Sprite sprite;
	void initTexture();
public:
	Tile(const float& posX, const float& posY,const sf::Vector2f& size, const int& tile);
	virtual ~Tile();

	const sf::Vector2f& getTilePosition();
	void update();
	void render(sf::RenderTarget* window);
};

