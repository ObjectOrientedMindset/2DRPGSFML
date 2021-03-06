#include "pch.h"
#include "Player.h"



Player::Player()
	:Entities()
{
	this->initTextures();
	this->timerMax = 500.f;
	this->timer = this->timerMax;
	this->initPlayerFromFile();
	this->playerSprite.setPosition(this->posX, this->posY);
	this->movementSpeed = 200.f;
	this->playerAnimations = new AnimationComponent(this->playerSprite);
	this->playerAnimations->addAnimation("Down", this->playerSprite, this->timer, 0, 0, 3, 0, 64, 60);
	this->playerAnimations->addAnimation("Left", this->playerSprite, this->timer, 4, 0, 7, 0, 64, 60);
	this->playerAnimations->addAnimation("Right", this->playerSprite, this->timer, 8, 0, 11, 0, 64, 60);
	this->playerAnimations->addAnimation("Up", this->playerSprite, this->timer, 12, 0, 15, 0, 64, 60);
}

void Player::initPlayerFromFile()
{
	std::fstream file;
	file.open("Config/player.ini", std::ios::in);
	if (!file.is_open()) { std::cout << "ERROR:CANNOT OPEN PLAYER.INI" << std::endl; }
	file >> this->posX >> this->posY;
	file.close();
}

Player::~Player()
{
	delete this->playerAnimations;
}
void Player::initTextures()
{
	if (!this->playerTexture.loadFromFile("Images/PLAYER_SHEET2.png"))
	{
		std::cout << "Images/Player pathway error" << "\n";
	}
		
	this->playerSprite.setTexture(this->playerTexture);
}

void Player::playerMovement(std::string direction,float dirX, float dirY, const float& dt)
{
	//Update player input
		this->playerSprite.move(dirX * dt * this->movementSpeed, dirY * dt * this->movementSpeed);
		if (this->timer >= this->timerMax) 
		{
			this->playerAnimations->playAnimation(direction, dt);
			this->timer = 0.f;
			this->playerSprite.setPosition(this->playerSprite.getPosition().x, this->playerSprite.getPosition().y);
		}
}

const sf::Vector2f& Player::getPlayerPosition()
{
	return this->playerSprite.getPosition();
}
void Player::setPlayerPosition(float x, float y)
{
	this->playerSprite.setPosition(x, y);
}
void Player::update()
{
	++this->timer;
}

void Player::render(sf::RenderTarget* target)
{
	target->draw(this->playerSprite);
}

