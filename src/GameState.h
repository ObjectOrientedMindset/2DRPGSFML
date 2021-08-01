#pragma once
#include "State.h"
#include"Player.h"
#include"Tilemap.h"
#include"PauseMenu.h"
class GameState :
    public State
{
private:
    //Variables
    Player* player;
    Tilemap tilemap;
    PauseMenu pauseMenu;
    bool pause;
    float timer;
    float timerMax;
    //Keybind
    std::map<std::string, int> keybinds;

    void initKeyBinds(std::map<std::string, int>* supported_keys);

public:
    GameState(sf::RenderWindow* window, std::stack<State*>* states, std::map<std::string, int>* supported_keys);
    virtual ~GameState();



    //Functions
    void endState(std::stack<State*>* states);
    void updatePlayerInput(const float& dt);
    void update(const float& dt);
    void render(sf::RenderWindow* window);
};

