#include "pch.h"
#include "Tile.h"

Tile::Tile(const float& posX, const float& posY, const sf::Vector2f& size)
{
	this->tile.setSize(size);
	this->tile.setPosition(posX, posY);
	this->tile.setFillColor(sf::Color::Green);
}

Tile::~Tile()
{
}

const sf::FloatRect& Tile::getTilePosition()
{
	return this->tile.getGlobalBounds();
}

void Tile::update()
{
	
}

void Tile::render(sf::RenderTarget* window)
{
	window->draw(this->tile);
}
