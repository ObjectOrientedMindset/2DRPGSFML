#pragma once
#include "State.h"
#include"PauseMenu.h"
#include"Tilemap.h"
class EditorState : 
	public State
{
private:
    //Variables
    PauseMenu pmenu;
    Tilemap* tilemap;
    bool pause;
    float timer;
    float timerMax;
    std::map<std::string, int> keybinds;
    sf::Text mouseCoordinatesText_x;
    sf::Text mouseCoordinatesText_y;
    sf::RectangleShape tileCollision;
    sf::RectangleShape editMapRectangle;
    std::vector<std::vector<sf::RectangleShape>> editmap;
    int tileColor;
    sf::Text text;

    //Functions
    void initKeyBinds(std::map<std::string, int>* supported_keys);
    void initEditMap();
    void addTile(const sf::Vector2f& tile);
    void deleteTile(const sf::Vector2f& tile);
    bool tileCollisionCheck();
    const sf::Vector2f& getEditMapCollisionCheck();
    void updateMouseCoordinates();
    void changeTileColor();
public:
    EditorState(sf::RenderWindow* window, std::stack<State*>* states, std::map<std::string, int>* supported_keys);
    virtual ~EditorState();

    //Functions
    void endState(std::stack<State*>* states);
    void update(const float& dt);
    void render(sf::RenderWindow* window);
};

