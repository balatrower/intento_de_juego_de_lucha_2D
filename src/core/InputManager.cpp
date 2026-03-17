//
// Created by p0wer on 15/03/2026.
//

#include "core/InputManager.h"

InputManager::InputManager() {
}

void InputManager::checkForInputs() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) addKey(sf::Keyboard::Key::W);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) addKey(sf::Keyboard::Key::A);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) addKey(sf::Keyboard::Key::S);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) addKey(sf::Keyboard::Key::D);
}
