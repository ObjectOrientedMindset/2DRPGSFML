#pragma once
#include"Tile.h"
class Tilemap
{
private:
	void initTilemap(const std::string& filePathway);
public:
	std::vector<int> tileColor;
	std::vector<sf::Vector2f> tilePosition;
	std::vector<Tile*> tile;
	sf::Vector2u maxSize;

	Tilemap(const std::string& filePathway);
	virtual ~Tilemap();

	void saveTileMap(const std::string& filePathway);
	void update(const sf::Vector2f& tile_position, const int& tileColor);
	void render(sf::RenderTarget* window);
};

