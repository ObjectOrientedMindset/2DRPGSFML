#pragma once
#include "State.h"
class SettingState :
    public State
{
private:
    std::vector<Button*> button;
    sf::Texture texture;
    sf::Sprite background;
public:
    SettingState(sf::RenderWindow* window, std::stack<State*>* states);
    virtual ~SettingState();


    void initBackground();
    void endState(std::stack<State*>* states);
    void update(const float& dt);
    void render(sf::RenderWindow* window);

};

