//
// Created by power on 13/03/2026.
//

#include "core/Game.h"
#include "core/InputManager.h"
#include "SFML/System/Clock.hpp"
#include "SFML/Graphics/RenderWindow.hpp"

void Game::Run() {
    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "Ventana de juego", sf::Style::None, sf::State::Fullscreen);

    // frametime stuff
    sf::Clock clock; // to measure delta time
    window.setFramerateLimit(60); // limit fps

    // input manager
    InputManager inputManger = InputManager();

    while (window.isOpen()) {
        // 0. get delta time as sf::Time, convert it and restart the clock for next frame
        sf::Time dt = clock.restart();
        float deltaTime = dt.asMilliseconds();

        // 0.5 handle window close event if game is windowed
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
            window.close();
        }


        // 1. Check for input
        switch (m_gameState) {
            case GameState::MainMenu:
                inputManger.checkForMenuInput();
                break;

            case GameState::InGame:
                inputManger.checkForInGameInput();
                break;

            case GameState::Paused:
                inputManger.checkForMenuInput();
                break;
        }


        // 2. update physics, logic and menus
            // here will be the switch with the updater for each game state

        // 3. render the updated info on the screen
        window.clear();
        // here will be the switch with the renderer for each game state
        window.display();
    }
}

void Game::setGameState(const GameState& gameState) {
    m_gameState = gameState;
}
