#include "pch.h"
#include "Tile.h"

void Tile::initTexture()
{
	
	if (!this->tile[0].loadFromFile("Images/Grass.png"))
	{
		std::cout << "ERROR:IMAGES/GRASS FILE LOAD NOT SUCCESFULL" << std::endl;
	}
	if (!this->tile[1].loadFromFile("Images/GrassFlower.png")) 
	{
		std::cout << "ERROR:IMAGES/GRASSFLOWER FILE LOAD NOT SUCCESFULL" << std::endl;
	}
	if (!this->tile[2].loadFromFile("Images/StoneGround.png"))
	{
		std::cout << "ERROR:IMAGES/STONEGROUND FILE LOAD NOT SUCCESFULL" << std::endl;
	}
	if(!this->tile[3].loadFromFile("Images/Tree.png"))
	{
		std::cout << "ERROR:IMAGES/TREE FILE LOAD NOT SUCCESFULL" << std::endl;
	}
}

Tile::Tile(const float& posX, const float& posY, const sf::Vector2f& size, const int& tile)
{
	this->initTexture();
	this->tileCode = tile;
	this->sprite.setTexture(this->tile[tile]);
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
