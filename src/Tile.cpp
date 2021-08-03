#include "pch.h"
#include "Tile.h"

Tile::Tile(const float& posX, const float& posY, const sf::Vector2f& size, const int& tile)
{
	this->tileCode = tile;
	this->tile[tile].setSize(size);
	this->tile[tile].setPosition(posX, posY);
	switch (tile)
	{
	case GREEN:
		this->tile[tile].setFillColor(sf::Color::Green);
		break;
	case BLUE:
		this->tile[tile].setFillColor(sf::Color::Blue);
		break;
	case GREY:
		this->tile[tile].setFillColor(sf::Color(128,128,128,255));
		break;
	case YELLOW:
		this->tile[tile].setFillColor(sf::Color::Yellow);
		break;
	}
}

Tile::~Tile()
{
}

const sf::Vector2f& Tile::getTilePosition()
{
	return this->tile[tileCode].getPosition();
}

void Tile::update()
{

}

void Tile::render(sf::RenderTarget* window)
{
	window->draw(this->tile[tileCode]);
}
