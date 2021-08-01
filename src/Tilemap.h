#pragma once
#include"Tile.h"
class Tilemap
{
private:
	void initTilemap();
public:
	std::vector<Tile*> tile;
	sf::Vector2u maxSize;
	Tilemap();
	virtual ~Tilemap();

	void update(const sf::Vector2f& tile_position);
	void render(sf::RenderTarget* window);
};

