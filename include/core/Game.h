//
// Created by power on 13/03/2026.
//

#ifndef JUEGOPEGARSE2D_GAME_H
#define JUEGOPEGARSE2D_GAME_H
#include <SFML/Graphics.hpp>

class Game {
    enum class GameState {
        MainMenu,
        InGame,
        Paused
    };

public:
    void Run();
    void setGameState(const GameState& gameState);
private:
    sf::RenderWindow m_window;
    GameState m_gameState = GameState::MainMenu;
};

#endif //JUEGOPEGARSE2D_GAME_H