//
// Created by p0wer on 15/03/2026.
//

#ifndef JUEGOPEGARSE2D_INPUTMANAGER_H
#define JUEGOPEGARSE2D_INPUTMANAGER_H
#include <list>
#include <vector>

#include "SFML/Window/Keyboard.hpp"

class InputManager {
public:
    InputManager();
    void checkForInGameInputs();
    void checkForMenuInputs();
    void executeInputs();
private:
    std::pmr::vector<sf::Keyboard::Key> m_inputKeyList;
    void addKey(sf::Keyboard::Key key);
};

#endif //JUEGOPEGARSE2D_INPUTMANAGER_H