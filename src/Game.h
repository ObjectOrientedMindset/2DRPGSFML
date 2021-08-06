#pragma once
#include"State.h"
#include"GameState.h"
#include"MainMenu.h"
class Game
{
private:
	//Delta time
	sf::Clock dtClock;
	float dt;

	//Variables
	sf::RenderWindow* window;
	sf::Event e;

	//States
	std::stack<State*> state;
	std::map<std::string, int> supportedKeys;

	void initWindow();
	void initSupportedKeys();
public:
	Game();
	virtual ~Game();

	//Functions
	void initStates();
	void updateDt();
	void pollEvents();
	void update();
	void render();
	void run();

};

