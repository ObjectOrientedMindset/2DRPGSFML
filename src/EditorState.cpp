#include "pch.h"
#include "EditorState.h"


EditorState::EditorState(sf::RenderWindow* window, std::stack<State*>* states, std::map<std::string, int>* supported_keys)
	:State(window, states, supported_keys), pmenu(*window, this->pixelFont)
{
	this->initKeyBinds(supported_keys);
	this->initEditMap();
	this->pause = false;
	this->timerMax = 1000.f;
	this->timer = this->timerMax;
	this->mouseCoordinatesText_x.setFont(this->pixelFont);
	this->mouseCoordinatesText_x.setCharacterSize(20);
	this->mouseCoordinatesText_y.setFont(this->pixelFont);
	this->mouseCoordinatesText_y.setCharacterSize(20);
	this->tileCollision.setPosition(this->getMousePos().x - 50.f, this->getMousePos().y - 50.f);
	this->tileCollision.setFillColor(sf::Color(0, 255, 0, 75));
	this->tileCollision.setSize(sf::Vector2f(this->tilemap.maxSize));
}


void EditorState::initKeyBinds(std::map<std::string, int>* supported_keys)
{
	std::ifstream keys_file("config/gamestate_keys.ini");
	std::string key = "";
	std::string key_digit = "";

	while (keys_file >> key >> key_digit)
	{
		this->keybinds[key] = supported_keys->at(key_digit);
	}
}
void EditorState::initEditMap()
{   //Invisible map for editing the real tilemap
	for (int x = 0; x < this->window->getSize().x / 100; x++)
	{
		this->editmap.push_back(std::vector<sf::RectangleShape>());
		for (int y = 0; y < this->window->getSize().y / 100; y++)
		{
			this->editmap[x].push_back(sf::RectangleShape(sf::Vector2f(this->tilemap.maxSize)));
			this->editmap[x][y].setPosition(x * 100, y * 100);
		}
	}
}
void EditorState::addTile(const sf::Vector2f& tile)
{
	this->tilemap.update(tile);
}
bool EditorState::tileCollisionCheck()
{
	for (auto& t : this->tilemap.tile)
	{
		if (this->tileCollision.getGlobalBounds().intersects(t->getTilePosition()))
		{   
			return true;
		}
	}

	return false;
}
const sf::Vector2f& EditorState::getEditMapCollisionCheck()
{ // checking which one of the invisible tiles and return its floatrect
	for (int x = 0; x < this->window->getSize().x / 100; x++)
	{
		for (int y = 0; y < this->window->getSize().y / 100; y++)
		{
			if (this->editmap[x][y].getGlobalBounds().contains(this->getMousePos()))
			{
				return this->editmap[x][y].getPosition();
			}
		}
	}

	return sf::Vector2f(0, 0);
}
void EditorState::updateMouseCoordinates()
{
	this->mouseCoordinatesText_x.setPosition(this->getMousePos().x + 10.f, this->getMousePos().y - 20.f);
	this->mouseCoordinatesText_x.setString(std::to_string((int)(this->getMousePos().x)));
	this->mouseCoordinatesText_y.setPosition(this->getMousePos().x + 40.f, this->getMousePos().y - 20.f);
	this->mouseCoordinatesText_y.setString(std::to_string((int)(this->getMousePos().y)));
}

EditorState::~EditorState()
{
}

void EditorState::endState(std::stack<State*>* states)
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
}

void EditorState::update(const float& dt)
{
	this->endState(this->states);
	if (!this->pause) // Unpaused update
	{   // update coordinates and titleCollision
		this->updateMouseCoordinates();
		this->tileCollision.setPosition(this->getMousePos().x - 50.f, this->getMousePos().y - 50.f);
		// check for mouse click and tile collision addtile
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if (this->timer >= this->timerMax)
			{
				if (!this->tileCollisionCheck())
				{
					this->addTile(this->getEditMapCollisionCheck());
					this->timer = 0.f;
				}
			}
		}
	}
	else
	{
		this->pmenu.update(this->getMousePos(), this->states);
	}
	++this->timer;
}

void EditorState::render(sf::RenderWindow* window)
{
	if (this->pause)
	{
		this->pmenu.render(window);
	}
	else 
	{
	this->tilemap.render(window);
	window->draw(this->tileCollision);
	window->draw(this->mouseCoordinatesText_x);
	window->draw(this->mouseCoordinatesText_y);
	}
}
