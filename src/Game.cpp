#include"pch.h"
#include "Game.h"


void Game::initWindow()
{
	//Initialize Game window
	this->window = new sf::RenderWindow(sf::VideoMode(1024,960), "SlavetoLegend", sf::Style::Close | sf::Style::Titlebar);
}

void Game::initSupportedKeys()
{
	std::ifstream keys_file("config/supported_keys.ini");
	std::string key = "";
	int key_digit = 0;

	while (keys_file >> key >> key_digit)
	{
		this->supportedKeys[key] = key_digit;
	}
	keys_file.close();
}

Game::Game()
{
	this->initWindow();
	this->initSupportedKeys();
	this->initStates();
}

Game::~Game()
{
	delete this->window;
}

void Game::initStates()
{
	this->state.push(new MainMenu(this->window, &this->state,&this->supportedKeys));
}


void Game::updateDt()
{
	//Updates the dt variable with the time it takes to update and render one frame

	this->dt = this->dtClock.restart().asSeconds();

}

void Game::pollEvents()
{
	while (this->window->pollEvent(this->e))
	{
		if (this->e.type == sf::Event::Closed)
			this->window->close();

	}
}

void Game::update()
{
	if (this->state.empty() == false)
	{
		this->state.top()->update(this->dt);
	}
	//Application end
	else
	{
		this->window->close();
	}

}

void Game::render()
{
	this->window->clear();

	if (this->state.empty() == false)
	{
		this->state.top()->render(this->window);
	}

	this->window->display();

}

void Game::run()
{
	while (this->window->isOpen())
	{
		this->updateDt();
		this->pollEvents();
		this->update();
		this->render();
	}
}
