#pragma once
#include"Entities.h"
#include"AnimationComponent.h"

class Player 
	: public Entities
{
private:
	//Variables
	sf::Texture playerTexture;
	sf::Sprite playerSprite;
	float movementSpeed;
	float timer;
	float timerMax;
	float posX;
	float posY;
	AnimationComponent* playerAnimations;
	void initPlayerFromFile();

public:
	Player();
	virtual ~Player();

	void initTextures();
	void playerMovement(std::string direction,float dirX, float dirY,const float& dt);

	const sf::Vector2f& getPlayerPosition();
	void update();
	void render(sf::RenderTarget* target);
};
