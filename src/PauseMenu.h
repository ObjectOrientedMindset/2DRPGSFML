#pragma once
#include"Button.h"
#include"State.h"
#include"Player.h"
class PauseMenu
{
private:
	//Variables
	sf::RectangleShape background;
	sf::Text text;
	std::vector<Button*> button;

public:
	PauseMenu(sf::RenderWindow& window, sf::Font& font);
	~PauseMenu();

	//Functions
	void update(const sf::Vector2f mousePos, std::stack<State*>* states);
	void render(sf::RenderWindow* window);
};

