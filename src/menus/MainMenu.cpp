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

MainMenu::MainMenu() {
    loadFont();
}

std::unique_ptr<Menu> MainMenu::updateMenu(InputManager& inputManager, bool& userWantsExit) {
    while (inputManager.isMenuActionQueueEmpty()) {
        MenuAction currentAction = inputManager.extractFirstElementOfMenuQueue();

        switch (currentAction) {
            case MenuAction::Up: {
                int newOptionInt = static_cast<int>(m_currentOption) - 1;
                if (isNewOptionIsOutOfBounds(newOptionInt)) {
                    m_currentOption = MainMenuOptions::Exit;
                }
                break;
            }

            case MenuAction::Down: {
                int newOptionInt = static_cast<int>(m_currentOption) + 1;
                if (isNewOptionIsOutOfBounds(newOptionInt)) {
                    m_currentOption = MainMenuOptions::Play;
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
                        break;
                    }

                    case MainMenuOptions::Settings: {
                        std::unique_ptr<Menu> newMenu = std::make_unique<SettingsMenu>();
                        return std::move(newMenu);
                        break;
                    }

                    case MainMenuOptions::Exit: {
                        userWantsExit = true;
                        break;
                    }
                }
            }
        }
    }

    return std::make_unique<MainMenu>(); // needed cos it needs the same type of menu for it to not change, if i used a nullptr or smth it will try to load a null menu
}

MenuType MainMenu::getMenuType() {
    return MenuType::MainMenu;
}

void MainMenu::drawMenu(sf::RenderWindow& window) {
    sf::Text text(m_font);

    text.setString(menuOptionToString(m_currentOption));

    text.setCharacterSize(24);

    text.setFillColor(sf::Color::White);

    window.draw(text);
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
    if (m_font.openFromFile("fonts/Freedom.ttf")) {
        std::cout << "FONT COULD NOT BE LOADED, REDIRECT THIS CONSOLE ERROR TO A LOG YOU LAZY IDIOT";
    }
}

bool MainMenu::isNewOptionIsOutOfBounds(int newOptionInt) {
    if (newOptionInt < 0) {
        return true;
    }

    if (newOptionInt == static_cast<int>(MainMenuOptions::Count)) {
        return true;
    }

    return false;
}
