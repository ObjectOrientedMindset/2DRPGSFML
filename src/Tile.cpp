#include "pch.h"
#include "Tile.h"

void Tile::initTexture()
{
	
	if (!this->tile[0].loadFromFile("Images/Tilemap/Grass.png"))
	{
		std::cout << "ERROR:IMAGES/GRASS FILE LOAD NOT SUCCESFULL" << std::endl;
	}
	if (!this->tile[1].loadFromFile("Images/Tilemap/GrassFlower.png")) 
	{
		std::cout << "ERROR:IMAGES/GRASSFLOWER FILE LOAD NOT SUCCESFULL" << std::endl;
	}
	if (!this->tile[2].loadFromFile("Images/Tilemap/StoneGround.png"))
	{
		std::cout << "ERROR:IMAGES/STONEGROUND FILE LOAD NOT SUCCESFULL" << std::endl;
	}
	if(!this->tile[3].loadFromFile("Images/Tilemap/Tree.png"))
	{
		std::cout << "ERROR:IMAGES/TREE FILE LOAD NOT SUCCESFULL" << std::endl;
	}
}

Tile::Tile(const float& posX, const float& posY, const sf::Vector2f& size, const int& tile_code, const int& tile_layer)
{
	this->initTexture();
	this->tileCode = tile_code;
	this->tileLayer = tile_layer;
	this->sprite.setTexture(this->tile[tile_code]);
	this->sprite.setPosition(posX, posY);
}

Tile::~Tile()
{
}

const sf::Vector2f& Tile::getTilePosition()
{
	return this->sprite.getPosition();
}

void Tile::update()
{

}

void Tile::render(sf::RenderTarget* window)
{
	window->draw(this->sprite);
}
