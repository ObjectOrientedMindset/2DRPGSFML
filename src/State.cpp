#include "pch.h"
#include "State.h"

State::State(sf::RenderWindow* window, std::stack<State*>* states, std::map<std::string, int>* supported_keys)
{
	//Init window
	this->window = window;
	this->states = states;
	this->supported_keys= supported_keys;
	this->pixelFont.loadFromFile("Fonts/PixellettersFull.ttf");
	this->mousePos = sf::Vector2f(sf::Mouse::getPosition(*this->window));
}

State::~State()
{
	delete this->states->top();
}

sf::Vector2f& State::getMousePos()
{
	this->mousePos = sf::Vector2f(sf::Mouse::getPosition(*this->window));
	return this->mousePos;
}
