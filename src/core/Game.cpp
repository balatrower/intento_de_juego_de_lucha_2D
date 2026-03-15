//
// Created by power on 13/03/2026.
//

#include "core/Game.h"
#include "entities/Player.h"
#include "SFML/System/Clock.hpp"

#include "SFML/Graphics/RenderWindow.hpp"

void Game::Run() {
    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "Ventana de juego", sf::Style::None, sf::State::Fullscreen);

    sf::Clock clock; // to measure delta time

    window.setFramerateLimit(60); // limit fps


    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
            window.close();
        }



        window.clear(sf::Color::White);

        float floorWidth = window.getSize().x;
        float floorHeight = 50.0f;

        sf::RectangleShape floor({floorWidth, floorHeight});
        floor.setFillColor(sf::Color::Green);
        floor.setPosition({0.0f, window.getSize().y - floorHeight});

        window.draw(floor);

        Player player1 = Player({250, 250}, sf::RectangleShape({50, 30}));

        window.display();
    }
}
