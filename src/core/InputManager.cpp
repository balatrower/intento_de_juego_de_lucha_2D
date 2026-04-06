//
// Created by p0wer on 15/03/2026.
//

#include "core/InputManager.h"
#include <optional>
#include "SFML/Window/Keyboard.hpp"
#include "SFML/Window/Event.hpp"

InputManager::InputManager() {
    inicializateActionMaps();
}

bool InputManager::isMenuActionQueueEmpty() {
    if (m_menuActionQueue.empty()) {
        return true;
    }
    return false;
}

void InputManager::inicializateActionMaps() {
    m_keyboardMap[sf::Keyboard::Scancode::W] = MenuAction::Up;
    m_keyboardMap[sf::Keyboard::Scancode::Up] = MenuAction::Up;

    m_keyboardMap[sf::Keyboard::Scancode::A] = MenuAction::Left;
    m_keyboardMap[sf::Keyboard::Scancode::Left] = MenuAction::Left;

    m_keyboardMap[sf::Keyboard::Scancode::D] = MenuAction::Right;
    m_keyboardMap[sf::Keyboard::Scancode::Right] = MenuAction::Right;

    m_keyboardMap[sf::Keyboard::Scancode::S] = MenuAction::Down;
    m_keyboardMap[sf::Keyboard::Scancode::Down] = MenuAction::Down;

    m_keyboardMap[sf::Keyboard::Scancode::Enter] = MenuAction::Enter;
    m_keyboardMap[sf::Keyboard::Scancode::Escape] = MenuAction::Escape;
}

void InputManager::processEvent(std::optional<sf::Event> event) {
    // getIf returns a ptr, if the event is not of this type then it returns nullptr, that's why the const auto* cos it validates the type and asigns it at the same time.
    if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) { // auto just asigns it the type of the getIf.
        if (m_keyboardMap.contains(keyPressed->scancode)) { // scancode is a member of keyPressed, this member has the data for the key being pressed.
            MenuAction action = m_keyboardMap.at(keyPressed->scancode);
            m_menuActionQueue.push(action);
        }
    }
}

MenuAction InputManager::extractFirstElementOfMenuQueue() {
    MenuAction currentAction = m_menuActionQueue.front();
    m_menuActionQueue.pop();
    return currentAction;
}


