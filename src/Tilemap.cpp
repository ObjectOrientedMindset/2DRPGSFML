#include "pch.h"
#include "Tilemap.h"

void Tilemap::initTilemap()
{ //Load Tilemap from file
	this->maxSize.x = 100;
	this->maxSize.y = 100;
	sf::Vector2f tilePosition;
	int color = 0;
	std::fstream file_tilemap;
	file_tilemap.open("config/tilemap.ini", std::ios::in);
	if (!file_tilemap.is_open()) { std::cout << "ERROR:CANNOT OPEN TILEMAP.INI" << std::endl; }
	while (file_tilemap >> tilePosition.x >> tilePosition.y >> color)
	{
			this->update(tilePosition, color);
	}

	file_tilemap.close();
}

Tilemap::Tilemap()
{
	this->initTilemap();
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


void Tilemap::saveTileMap()
{ //Save Tilemap from file
	std::fstream file_tilemap;
	file_tilemap.open("config/tilemap.ini", std::ios::out);
	if (!file_tilemap.is_open()) { std::cout << "ERROR:CANNOT OPEN TILEMAP.INI" << std::endl; }
	for (unsigned int i = 0; i < this->tileColor.size(); i++)
	{
		file_tilemap << (int)(this->tilePosition[i].x) << std::endl << (int)(this->tilePosition[i].y) << std::endl << tileColor[i] << std::endl;
	}
	file_tilemap.close();
}

void Tilemap::update(const sf::Vector2f& tile_position, const int& tileColor)
{   //Create new tile
	if (tileColor != 4)
	{
		this->tile.push_back(new Tile(tile_position.x, tile_position.y, (sf::Vector2f)(this->maxSize), tileColor));
		this->tileColor.push_back(tileColor);
		this->tilePosition.push_back(tile_position);
	}
	//Delete a tile
	else
	{
		unsigned int iterationCounter = 0;
		for (auto& t : this->tile)
		{
			if (t->getTilePosition() == tile_position)
			{
			 	delete this->tile.at(iterationCounter);
				this->tile.erase(this->tile.begin() + iterationCounter);
				this->tilePosition.erase(this->tilePosition.begin() + iterationCounter);
				this->tileColor.erase(this->tileColor.begin() + iterationCounter);
				--iterationCounter;
			}
			++iterationCounter;
		}
	}
}

void Tilemap::render(sf::RenderTarget* window)
{
	for (auto& t : this->tile)
	{
		t->render(window);
	}
}
