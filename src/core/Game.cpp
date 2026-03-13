//
// Created by power on 13/03/2026.
//

#include "core/Game.h"

#include "SFML/Graphics/RenderWindow.hpp"

void Game::Run() {
    sf::Window window(sf::VideoMode({800, 600}), "Ventana de juego");

    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
            window.close();
        }
    }
}
