//
// Created by power on 13/03/2026.
//

#include "core/Game.h"
#include "entities/Player.h"
#include "SFML/System/Clock.hpp"
#include "menus/MainMenu.h"
#include "SFML/Graphics/RenderWindow.hpp"

void Game::Run() {
    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "Ventana de juego", sf::Style::None, sf::State::Fullscreen);

    // frametime stuff
    sf::Clock clock; // to measure delta time
    window.setFramerateLimit(60); // limit fps

    // main menu
    MainMenu menu = MainMenu();


    while (window.isOpen()) {
        // 0. get delta time as sf::Time, convert it and restart the clock for next frame
        sf::Time dt = clock.restart();
        float deltaTime = dt.asMilliseconds();

        // 0.5 handle window events (close and stuff)
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
            window.close();
        }

        // 1. Check for input
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {

        }

        // 2. update physics and logic


        // 3. update the screen


    }
}
