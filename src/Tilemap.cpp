#include "pch.h"
#include "Tilemap.h"

void Tilemap::initTilemap()
{
	std::ifstream file_tilemap("config/tilemap.ini");
	file_tilemap.open("config/tilemap.ini");
	file_tilemap >> maxSize.x >> maxSize.y;
	file_tilemap.close();
}

Tilemap::Tilemap()
{
	this->maxSize.x = 100;
	this->maxSize.y = 100;
}

Tilemap::~Tilemap()
{
	unsigned int iterator = 0;
	while (!this->tile.empty())
	{
		delete this->tile.at(iterator);
		this->tile.pop_back();
		--iterator;
	}
	++iterator;
}


void Tilemap::update(const sf::Vector2f& tile_position)
{   //Create new tile
	this->tile.push_back(new Tile(tile_position.x, tile_position.y, (sf::Vector2f)(this->maxSize)));
}

void Tilemap::render(sf::RenderTarget* window)
{
	for (auto& t : this->tile)
	{
		t->render(window);
	}
}
