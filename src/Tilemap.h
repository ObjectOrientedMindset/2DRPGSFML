#pragma once
#include"Tile.h"
class Tilemap
{
private:
	void initTilemap();
public:
	std::vector<int> tileColor;
	std::vector<sf::Vector2f> tilePosition;
	std::vector<Tile*> tile;
	sf::Vector2u maxSize;

	Tilemap();
	virtual ~Tilemap();

	void saveTileMap();
	void update(const sf::Vector2f& tile_position, const int& tileColor);
	void render(sf::RenderTarget* window);
};

