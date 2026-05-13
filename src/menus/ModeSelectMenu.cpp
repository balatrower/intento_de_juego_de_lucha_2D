//
// Created by p0wer on 06/04/2026.
//

#include <memory>
#include "menus/ModeSelectMenu.h"

#include "menus/MainMenu.h"
#include "SFML/Graphics/Text.hpp"
#include "SFML/Graphics/Sprite.hpp"


ModeSelectMenu::ModeSelectMenu() {
    loadFont();
}

std::unique_ptr<Menu> ModeSelectMenu::updateMenu(InputManager &inputManager, bool& userWantsExit) {
    while (!inputManager.isMenuActionQueueEmpty()) {
        MenuAction currentAction = inputManager.extractFirstElementOfMenuQueue();

        switch (currentAction) {
            case MenuAction::Up: {
                int newOptionInt = static_cast<int>(m_currentOption) - 1;
                if (isNewOptionOutOfBounds(newOptionInt)) {
                    m_currentOption = ModeSelectMenuOptions::Back;
                } else {
                    m_currentOption = (ModeSelectMenuOptions)newOptionInt;
                }
                break;
            }

            case MenuAction::Down: {
                int newOptionInt = static_cast<int>(m_currentOption) + 1;
                if (isNewOptionOutOfBounds(newOptionInt)) {
                    m_currentOption = ModeSelectMenuOptions::Versus2P;
                } else {
                    m_currentOption = (ModeSelectMenuOptions)newOptionInt;
                }
                break;
            }

            case MenuAction::Escape: {
                userWantsExit = true;
                break;
            }

            case MenuAction::Enter: {
                switch (m_currentOption) {
                    case ModeSelectMenuOptions::Versus2P: {
                        //std::unique_ptr<Menu> newMenu = std::make_unique<>();
                        //return std::move(newMenu);
                        return nullptr;
                    }

                    case ModeSelectMenuOptions::Back: {
                        std::unique_ptr<Menu> newMenu = std::make_unique<MainMenu>();
                        return std::move(newMenu);
                    }
                }
            }
        }
    }

    return nullptr;
}

void ModeSelectMenu::drawMenu(sf::RenderWindow& window) {
    sf::Texture menuBackground = sf::Texture("assets/bgModeSelectionMenu.png");
    menuBackground.setSmooth(true);
    sf::Sprite sprMenuBackground = sf::Sprite(menuBackground);
    sprMenuBackground.setScale({(float) window.getSize().x / menuBackground.getSize().x, (float) window.getSize().y / menuBackground.getSize().y});
    window.draw(sprMenuBackground);

    sf::Text text(m_font);
    text.setPosition({((float) window.getSize().x / 2), ((float) window.getSize().y / 2) - 100});
    sf::Vector2f menuOptionOffset = {0.0, 100.0};
    for (int i = 0; i < (int)ModeSelectMenuOptions::Count; i++) {
        text.setString(menuOptionToString((ModeSelectMenuOptions) i));
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

MenuType ModeSelectMenu::getMenuType() {
    return MenuType::ModeSelectMenu;
}

bool ModeSelectMenu::isNewOptionOutOfBounds(int newOptionInt) {
    if (newOptionInt < 0) {
        return true;
    }

    if (newOptionInt == static_cast<int>(ModeSelectMenuOptions::Count)) {
        return true;
    }

    return false;
}

void ModeSelectMenu::loadFont() {
    if (!m_font.openFromFile("fonts/Pixellettersfull-BnJ5.ttf")) {
        std::cout << "FONT COULD NOT BE LOADED, REDIRECT THIS CONSOLE ERROR TO A LOG YOU LAZY IDIOT" << "\n";
    }
}

std::string ModeSelectMenu::menuOptionToString(ModeSelectMenuOptions menuOption) {
    switch (menuOption) {
        case ModeSelectMenuOptions::Versus2P: return "Versus 2P";
        case ModeSelectMenuOptions::Back: return "Back";
        default: return "";
    }
}

