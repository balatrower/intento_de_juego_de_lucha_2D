//
// Created by p0wer on 15/03/2026.
//

#ifndef JUEGOPEGARSE2D_INPUTMANAGER_H
#define JUEGOPEGARSE2D_INPUTMANAGER_H
#include "entities/Player.h"
#include "SFML/Window/Keyboard.hpp"

class InputManager {
public:
    InputManager();
    void checkForInputs();
    void executeInputs();
private:
    std::vector<sf::Keyboard::Key> m_inputKeyList;
    void addKey(sf::Keyboard::Key);
};

#endif //JUEGOPEGARSE2D_INPUTMANAGER_H