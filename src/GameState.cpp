#include"pch.h"
#include "GameState.h"

GameState::GameState(sf::RenderWindow* window, std::stack<State*>* states, std::map<std::string, int>* supported_keys)
	:State(window, states,supported_keys), pauseMenu(*window,this->pixelFont)
{
	this->initKeyBinds(supported_keys);
	this->timerMax = 1000.f;
	this->timer = this->timerMax;
	this->player = new Player(150.f);
	this->pause = false;
}
void GameState::initKeyBinds(std::map<std::string, int>* supported_keys)
{
	std::ifstream keys_file("config/gamestate_keys.ini");
	std::string key = "";
	std::string key_digit = "";

	while (keys_file >> key >> key_digit)
	{
		this->keybinds[key] = supported_keys->at(key_digit);
	}
	keys_file.close();
}

GameState::~GameState()
{
	delete this->player;
}

void GameState::endState(std::stack<State*>* states)
{
	if (this->timer >= this->timerMax)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("CLOSE"))))
		{
			if (!this->pause)
			{
				this->pause = true;
			}
			else
			{
				this->pause = false;
			}
			this->timer = 0.f;
		}
	}
	++this->timer;
}

void GameState::updatePlayerInput(const float& dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_LEFT"))))
	{
		this->player->playerMovement("Left", -1.f, 0.f, dt);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_RIGHT"))))
	{
		this->player->playerMovement("Right", 1.f, 0.f, dt);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_UP"))))
	{
		this->player->playerMovement("Up", 0.f, -1.f, dt);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_DOWN"))))
	{
		this->player->playerMovement("Down", 0.f, 1.f, dt);
	}
	
}

void GameState::update(const float& dt)
{
	this->endState(this->states);
	if (!this->pause) // Unpaused update
	{
		this->updatePlayerInput(dt);
		this->player->update();
	}
	else
	{
		this->pauseMenu.update(this->getMousePos(),this->states);
	}
}

void GameState::render(sf::RenderWindow* window)
{
	if (this->pause)
	{
		this->pauseMenu.render(window);
	}
		this->player->render(window);
		
}
