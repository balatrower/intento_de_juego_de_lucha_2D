//
// Created by p0wer on 15/03/2026.
//

#include "core/InputManager.h"

InputManager::InputManager() = default;

void InputManager::checkForInGameInputs() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) addKey(sf::Keyboard::Key::W);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) addKey(sf::Keyboard::Key::A);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) addKey(sf::Keyboard::Key::S);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) addKey(sf::Keyboard::Key::D);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter)) addKey(sf::Keyboard::Key::Enter);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) addKey(sf::Keyboard::Key::Space);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) addKey(sf::Keyboard::Key::Escape);
}

void InputManager::checkForMenuInputs() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) addKey(sf::Keyboard::Key::W);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) addKey(sf::Keyboard::Key::A);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) addKey(sf::Keyboard::Key::S);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) addKey(sf::Keyboard::Key::D);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter)) addKey(sf::Keyboard::Key::Enter);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) addKey(sf::Keyboard::Key::Space);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) addKey(sf::Keyboard::Key::Escape);
}

void InputManager::addKey(sf::Keyboard::Key key) {
}


