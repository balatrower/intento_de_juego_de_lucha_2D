//
// Created by p0wer on 15/03/2026.
//

#ifndef JUEGOPEGARSE2D_INPUTMANAGER_H
#define JUEGOPEGARSE2D_INPUTMANAGER_H
#include <list>
#include <optional>
#include <queue>
#include <unordered_map>
#include <vector>

#include "SFML/Window/Event.hpp"
#include "SFML/Window/Keyboard.hpp"

enum class MenuAction {
    Up,
    Down,
    Left,
    Right,
    Enter,
    Escape
};

class InputManager {
public:
    InputManager();
    void processEvent(std::optional<sf::Event> event);
    bool isMenuActionQueueEmpty();
    MenuAction extractFirstElementOfMenuQueue();
private:
    std::unordered_map<sf::Keyboard::Scancode, MenuAction> m_keyboardMap; // same as a hashmap but c++
    std::unordered_map<unsigned int, MenuAction> m_gamepadMap; // gamepad in sfml uses unsigned ints as buttons
    std::queue<MenuAction> m_menuActionQueue; // queue to not skip actions if 2 or more valid keys are pressed, queue used cos of FIFO and saved inputs
    void mapKeyToAction();
    void mapButtonToAction();
    void inicializateActionMaps();
};

#endif //JUEGOPEGARSE2D_INPUTMANAGER_H