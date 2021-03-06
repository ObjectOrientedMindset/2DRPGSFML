#include "pch.h"
#include "Tilemap.h"

void Tilemap::initTilemap(const std::string& filePathway)
{ //Load Tilemap from file
	this->maxSize.x = 100;
	this->maxSize.y = 100;
	sf::Vector2f tilePosition; tilePosition.x = 0; tilePosition.y = 0;
	int color = 0;
	int layer = 0;
	std::fstream file_tilemap;
	file_tilemap.open(filePathway, std::ios::in);
	if (!file_tilemap.is_open()) { std::cout << "ERROR:CANNOT OPEN TILEMAP.INI" << std::endl; }
	while (file_tilemap >> tilePosition.x >> tilePosition.y >> color >> layer)
	{
			this->update(tilePosition, color, layer);
	}

	file_tilemap.close();
}

Tilemap::Tilemap()
{
	this->initTilemap("Config/maps/map0.ini");
}

Tilemap::Tilemap(const std::string& filePathway)
{
	this->initTilemap(filePathway);
}

Tilemap::~Tilemap()
{
	unsigned int iterator = 0;
	while (!this->tile[0].empty())
	{
		delete this->tile[0].at(iterator);
		this->tile[0].pop_back();
		--iterator;
	}
	++iterator;
	iterator = 0;
	while (!this->tile[1].empty())
	{
		delete this->tile[1].at(iterator);
		this->tile[1].pop_back();
		--iterator;
	}
	++iterator;
}


void Tilemap::saveTileMap(const std::string& filePathway)
{ //Save Tilemap from file
	std::fstream file_tilemap;
	file_tilemap.open(filePathway, std::ios::out);
	if (!file_tilemap.is_open()) { std::cout << "ERROR:CANNOT OPEN TILEMAP.INI" << std::endl; }
	for (int i = 0; i < this->tile_code.size(); i++)
	{
		file_tilemap << (int)(this->tilePosition[i].x) << std::endl << (int)(this->tilePosition[i].y)
			<< std::endl << this->tile_code[i] << std::endl << this->tile_layer[i] << std::endl;
	}
	file_tilemap.close();
}

void Tilemap::update(const sf::Vector2f& tile_position, const int& tile_code, const int& tile_layer)
{   //Create new tile
	if (tile_code != 4)
	{
		this->tile[tile_layer].push_back(new Tile(tile_position.x, tile_position.y, (sf::Vector2f)(this->maxSize), tile_code, tile_layer));
		this->tile_code.push_back(tile_code);
		this->tilePosition.push_back(tile_position);
		this->tile_layer.push_back(tile_layer);
	}
	//Delete a tile
	else
	{
		bool erased = false;
		unsigned int iterationCounter = 0;
		for (auto& t : this->tile[0])
		{
			if (t->getTilePosition() == tile_position)
			{
			 	delete this->tile[0].at(iterationCounter);
				this->tile[0].erase(this->tile[0].begin() + iterationCounter);
				this->tilePosition.erase(this->tilePosition.begin() + iterationCounter);
				this->tile_code.erase(this->tile_code.begin() + iterationCounter);
				this->tile_layer.erase(this->tile_layer.begin() + iterationCounter);
				--iterationCounter;
				erased = true;
			}
			++iterationCounter;
		}
		iterationCounter = 0;
		for (auto& t : this->tile[1])
		{
			if (t->getTilePosition() == tile_position && erased == false)
			{
				delete this->tile[1].at(iterationCounter);
				this->tile[1].erase(this->tile[1].begin() + iterationCounter);
				this->tilePosition.erase(this->tilePosition.begin() + iterationCounter);
				this->tile_code.erase(this->tile_code.begin() + iterationCounter);
				this->tile_layer.erase(this->tile_layer.begin() + iterationCounter);
				--iterationCounter;
			}
			++iterationCounter;
		}
	}
}

void Tilemap::render(sf::RenderTarget* window)
{
	//Render for layer order
	for (auto& t : this->tile[1])
	{
		t->render(window);
	}
	for (auto& t : this->tile[0])
	{
		t->render(window);
	}
}
