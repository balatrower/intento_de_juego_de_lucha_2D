//
// Created by power on 24/03/2026.
//

#include "core/InputManager.h"
#include "menus/MainMenu.h"
#include <iostream>
#include <memory>
#include "SFML/Graphics/Font.hpp"
#include "SFML/Graphics/Text.hpp"
#include "menus/ModeSelectMenu.h"
#include "menus/SettingsMenu.h"
#include "SFML/Graphics/Sprite.hpp"

MainMenu::MainMenu() {
    loadFont();
}

std::unique_ptr<Menu> MainMenu::updateMenu(InputManager& inputManager, bool& userWantsExit) {
    while (!inputManager.isMenuActionQueueEmpty()) {
        MenuAction currentAction = inputManager.extractFirstElementOfMenuQueue();

        switch (currentAction) {
            case MenuAction::Up: {
                int newOptionInt = static_cast<int>(m_currentOption) - 1;
                if (isNewOptionOutOfBounds(newOptionInt)) {
                    m_currentOption = MainMenuOptions::Exit;
                } else {
                    m_currentOption = (MainMenuOptions)newOptionInt;
                }
                break;
            }

            case MenuAction::Down: {
                int newOptionInt = static_cast<int>(m_currentOption) + 1;
                if (isNewOptionOutOfBounds(newOptionInt)) {
                    m_currentOption = MainMenuOptions::Play;
                } else {
                    m_currentOption = (MainMenuOptions)newOptionInt;
                }
                break;
            }

            case MenuAction::Escape: {
                userWantsExit = true;
                break;
            }

            case MenuAction::Enter: {
                switch (m_currentOption) {
                    case MainMenuOptions::Play: {
                        std::unique_ptr<Menu> newMenu = std::make_unique<ModeSelectMenu>();
                        return std::move(newMenu);
                    }

                    case MainMenuOptions::Settings: {
                        std::unique_ptr<Menu> newMenu = std::make_unique<SettingsMenu>();
                        return std::move(newMenu);
                    }

                    case MainMenuOptions::Exit: {
                        userWantsExit = true;
                        break;
                    }
                }
            }
        }
    }

    return nullptr; 
}

MenuType MainMenu::getMenuType() {
    return MenuType::MainMenu;
}

void MainMenu::drawMenu(sf::RenderWindow& window) {
    sf::Texture menuBackground = sf::Texture("assets/bgMainMenu.jpg");
    menuBackground.setSmooth(true);
    sf::Sprite sprMenuBackground = sf::Sprite(menuBackground);
    sprMenuBackground.setScale({(float) window.getSize().x / menuBackground.getSize().x, (float) window.getSize().y / menuBackground.getSize().y});
    window.draw(sprMenuBackground);

    sf::Text text(m_font);
    text.setPosition({((float) window.getSize().x / 2), ((float) window.getSize().y / 2) - 100});
    sf::Vector2f menuOptionOffset = {0.0, 100.0};
    for (int i = 0; i < (int)MainMenuOptions::Count; i++) {
        text.setString(menuOptionToString((MainMenuOptions)i));
        text.setCharacterSize(24);
        if ((int)m_currentOption == i) {
            text.setFillColor(sf::Color::Yellow);
        } else {
            text.setFillColor(sf::Color::White);
        }
        text.move(menuOptionOffset);
        window.draw(text);
    }
}

std::string MainMenu::menuOptionToString(MainMenuOptions menuOption) {
    switch (menuOption) {
        case MainMenuOptions::Play: return "Play";
        case MainMenuOptions::Settings: return "Settings";
        case MainMenuOptions::Exit: return "Exit";
        default: return "";
    }
}

void MainMenu::loadFont() {
    if (!m_font.openFromFile("fonts/Freedom.ttf")) {
        std::cout << "FONT COULD NOT BE LOADED, REDIRECT THIS CONSOLE ERROR TO A LOG YOU LAZY IDIOT" << "\n";
    }
}

bool MainMenu::isNewOptionOutOfBounds(int newOptionInt) {
    if (newOptionInt < 0) {
        return true;
    }

    if (newOptionInt == static_cast<int>(MainMenuOptions::Count)) {
        return true;
    }

    return false;
}
