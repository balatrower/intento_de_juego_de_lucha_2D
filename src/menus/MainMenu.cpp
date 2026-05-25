//
// Created by power on 24/03/2026.
//

#include "core/InputManager.h"
#include "menus/MainMenu.h"
#include <iostream>
#include <memory>

#include "core/Logger.h"
#include "SFML/Graphics/Font.hpp"
#include "SFML/Graphics/Text.hpp"
#include "menus/ModeSelectMenu.h"
#include "menus/SettingsMenu.h"
#include "SFML/Graphics/Sprite.hpp"

MainMenu::MainMenu() : m_logoSprite(m_logoTexture) {
    loadFont();
    loadLogo();

    if (m_bgTexture.loadFromFile("assets/bgMainMenu.jpg")) {
        m_bgTexture.setSmooth(true);

        m_bgSprite.setTexture(m_bgTexture, true);
    } else {
        Logger::error("Texture could not be loaded correctly");
    }
}

std::unique_ptr<Menu> MainMenu::updateMenu(InputManager& inputManager, AudioManager& audioManager, bool& userWantsExit, bool& isFullscreen) {
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

void MainMenu::drawBackground(sf::RenderWindow &window) {
    m_bgSprite.setScale({(float) window.getSize().x / m_bgTexture.getSize().x, (float) window.getSize().y / m_bgTexture.getSize().y});

    window.draw(m_bgSprite);
}

void MainMenu::drawMenu(sf::RenderWindow& window) {
    drawBackground(window);
    drawLogo(window);
    drawOptions(window);
}

void MainMenu::drawOptions(sf::RenderWindow& window) {
    sf::Text text(m_font);
    text.setCharacterSize(32);

    float screenCenterX = (float) window.getSize().x / 2.f; //get center X
    float screenCenterY = (float) window.getSize().y / 2.f; // get center Y

    int totalOptions = (int)MainMenuOptions::Count;
    float menuOptionOffset = 100.f;

    // position of the first option so the whole block/list of options is centered
    float initialPosY = screenCenterY - ((totalOptions - 1) * menuOptionOffset) / 2.f;

    for (int i = 0; i < totalOptions; i++) {
        text.setString(menuOptionToString((MainMenuOptions) i));

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

std::string MainMenu::menuOptionToString(MainMenuOptions menuOption) {
    switch (menuOption) {
        case MainMenuOptions::Play: return "Play";
        case MainMenuOptions::Settings: return "Settings";
        case MainMenuOptions::Exit: return "Exit";
        default: return "";
    }
}

void MainMenu::loadFont() {
    if (!m_font.openFromFile("fonts/Pixellettersfull-BnJ5.ttf")) {
        Logger::error("Font could not be loaded");;
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

void MainMenu::loadLogo() {
    if (!m_logoTexture.loadFromFile("assets/mainMenuLogo.png")) {
        Logger::error("Main menu logo could not be loaded");
    }

    m_logoSprite.setTexture(m_logoTexture, true);

    sf::FloatRect logoBox = m_logoSprite.getLocalBounds();
    m_logoSprite.setOrigin({logoBox.position.x + logoBox.size.x / 2.f, logoBox.position.y + logoBox.size.y / 2.f});
}

void MainMenu::drawLogo(sf::RenderWindow& window) {
    float screenCenterX = (float) window.getSize().x / 2.f;

    float logoPosY = (float) window.getSize().y * 0.25f;

    m_logoSprite.setPosition({screenCenterX, logoPosY});

    window.draw(m_logoSprite);
}