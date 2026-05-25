//
// Created by power on 13/03/2026.
//

#include "core/Game.h"
#include "core/AudioManager.h"
#include "core/InputManager.h"
#include "menus/MainMenu.h"
#include "SFML/System/Clock.hpp"
#include "SFML/Graphics/RenderWindow.hpp"

void Game::Run() {
    m_window.create(sf::VideoMode::getDesktopMode(), "StickFighters", sf::Style::None, sf::State::Fullscreen);

    // frametime stuff
    sf::Clock clock; // to measure delta time
    m_window.setFramerateLimit(60); // limit fps

    // input manager
    InputManager inputManager = InputManager();

    // asign main menu object to currentMenu and wrap it in a unique pointer for easier memory management
    m_currentMenu = std::make_unique<MainMenu>();

    // audio manager
    AudioManager audioManager = AudioManager();
    audioManager.playBackgroundMusic(m_gameState);

    bool isFullscreen = true;
    bool userWantsExit = false;
    while (m_window.isOpen()) {
        //cheeking if the state of fullscreen has changed at the start of the frame


        // 0. get delta time as sf::Time, convert it and restart the clock for next frame
        sf::Time dt = clock.restart();
        float deltaTime = dt.asSeconds();

        // 0.5 handle events, window close and inputs. While loop empties the queue of events to check for input and window closure
        while (const std::optional event = m_window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                m_window.close();
            }

            // 1. Check for input only in menus where we want the input and don't care about a buffer
            if (m_gameState == GameState::InMenu)
            inputManager.processEvent(*event); // * used to dereference the std::optional and only get the event data
        }

        // 1.5. check for inputs/inputStream for when ingame
        if (m_gameState == GameState::InMatch) {
            // here make the ingame input process function
        }

        // 2. update physics, logic and menus
        // here will be the switch with the updater for each game state
        switch (m_gameState) {
            case GameState::InMenu: {
                //before posible changes in the update menu
                bool previusStateOfFullscreen = isFullscreen;

                std::unique_ptr<Menu> newMenu = m_currentMenu->updateMenu(inputManager, audioManager, userWantsExit, isFullscreen);

                if (newMenu != nullptr) {
                    changeMenu(std::move(newMenu));
                }

                if (isFullscreen != previusStateOfFullscreen) {
                    if (isFullscreen) {
                        m_window.create(sf::VideoMode::getDesktopMode(), "StickFighters", sf::Style::None, sf::State::Fullscreen);
                    } else {
                        m_window.create(sf::VideoMode({800, 600}), "StickFighters", sf::Style::Default);
                    }

                    m_window.setFramerateLimit(60); // limiting the framerate again just in case, seen it spike to 400fps in debugging while this wasnt present
                }
                break;
            }

            case GameState::InMatch:
                updateMatch(deltaTime);
                break;
        }

        if (userWantsExit) {
            m_window.close();
            continue;
        }

        // 3. render the updated info on the screen
        m_window.clear(sf::Color::Black);

        m_currentMenu->drawMenu(m_window);

        m_window.display();
    }
}

void Game::updateMatch(float dt) {
    // logic for match update goes here
    // todo: probably make it a class later on idkkkk
}

void Game::changeMenu(std::unique_ptr<Menu> newMenu) {
    m_currentMenu = std::move(newMenu);

}

void Game::setGameState(const GameState& gameState) {
    m_gameState = gameState;
}
