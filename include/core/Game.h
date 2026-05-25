//
// Created by power on 13/03/2026.
//

#ifndef JUEGOPEGARSE2D_GAME_H
#define JUEGOPEGARSE2D_GAME_H

#include <SFML/Graphics.hpp>
#include "core/GameState.h"
#include "Menus/Menu.h"

class Game {
public:

    void Run();
    void setGameState(const GameState& gameState);
    void changeMenu(std::unique_ptr<Menu> newMenu);
    void updateMatch(float dt);
private:
    sf::RenderWindow m_window;
    GameState m_gameState = GameState::InMenu;
    std::unique_ptr<Menu> m_currentMenu; // ptr to the menu so i dont need to worry about memory management cos it erases it when not in use.
};

#endif //JUEGOPEGARSE2D_GAME_H