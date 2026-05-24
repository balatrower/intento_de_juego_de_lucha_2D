//
// Created by p0wer on 06/04/2026.
//

#include <memory>
#include "menus/ModeSelectMenu.h"

#include "menus/MainMenu.h"
#include "SFML/Graphics/Text.hpp"
#include "SFML/Graphics/Sprite.hpp"


ModeSelectMenu::ModeSelectMenu() {
    ModeSelectMenu::loadFont();
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
                        //std::unique_ptr<Menu> newMenu = std::make_unique<SideSelectionMenu>();
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

void ModeSelectMenu::drawBackground(sf::RenderWindow &window) {
    sf::Texture menuBackground = sf::Texture("assets/bgModeSelectionMenu.png");
    menuBackground.setSmooth(true); // no sawtooth basically

    sf::Sprite sprMenuBackground = sf::Sprite(menuBackground);
    sprMenuBackground.setScale({(float) window.getSize().x / menuBackground.getSize().x, (float) window.getSize().y / menuBackground.getSize().y});
    // set scale of background sprite to the entire screen size

    window.draw(sprMenuBackground);
}

void ModeSelectMenu::drawOptions(sf::RenderWindow &window) {
    sf::Text text(m_font);
    text.setCharacterSize(24);

    float screenCenterX = (float) window.getSize().x / 2.f; //get center X
    float screenCenterY = (float) window.getSize().y / 2.f; // get center Y

    int totalOptions = (int)ModeSelectMenuOptions::Count;
    float menuOptionOffset = 100.f;

    // position of the first option so the whole block/list of options is centered
    float initialPosY = screenCenterY - ((totalOptions - 1) * menuOptionOffset) / 2.f;

    for (int i = 0; i < totalOptions; i++) {
        text.setString(menuOptionToString((ModeSelectMenuOptions) i));

        sf::FloatRect textBoxSize = text.getLocalBounds();
        text.setOrigin({textBoxSize.position.x + textBoxSize.size.x / 2.f, textBoxSize.position.y + textBoxSize.size.y / 2.f});
        // above calculation is to set the origin of the text element in the exact middle of the word so it is centered
        //textBox or FloatRect class is a 2d rectangle align in the axis, what dat mean is like a box arround the element, hit has a position on the screen and a size
        // position is the x and y pos of the upper left corner and size its just the width and height of the rectangle

        text.setPosition({screenCenterX, initialPosY + (i * menuOptionOffset)});

        if ((int)m_currentOption == i) {
            text.setFillColor(sf::Color::Yellow);
        } else {
            text.setFillColor(sf::Color::White);
        }

        window.draw(text);
    }
}

void ModeSelectMenu::drawMenu(sf::RenderWindow& window) {
    drawBackground(window);
    drawOptions(window);
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