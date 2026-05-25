//
// Created by p0wer on 06/04/2026.
//


#include "menus/SettingsMenu.h"

#include "core/AudioManager.h"
#include "core/Logger.h"
#include "menus/MainMenu.h"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Text.hpp"

SettingsMenu::SettingsMenu() : m_logoSprite(m_logoTexture) {
    loadFont();
    loadLogo();

    if (m_bgTexture.loadFromFile("assets/bgSettingsMenu.png")) {
        m_bgTexture.setSmooth(true);

        m_bgSprite.setTexture(m_bgTexture, true);
    } else {
        Logger::error("Texture could not be loaded correctly");
    }
}

std::unique_ptr<Menu> SettingsMenu::updateMenu(InputManager& inputManager, AudioManager& audioManager, bool& userWantsExit, bool& isFullscreen) {
    while (!inputManager.isMenuActionQueueEmpty()) {
        MenuAction currentAction = inputManager.extractFirstElementOfMenuQueue();

        switch (currentAction) {
            case MenuAction::Up: {
                int newOptionInt = static_cast<int>(m_currentOption) - 1;
                if (isNewOptionOutOfBounds(newOptionInt)) {
                    m_currentOption = SettingsMenuOptions::Back;
                } else {
                    m_currentOption = (SettingsMenuOptions)newOptionInt;
                }
                break;
            }

            case MenuAction::Down: {
                int newOptionInt = static_cast<int>(m_currentOption) + 1;
                if (isNewOptionOutOfBounds(newOptionInt)) {
                    m_currentOption = SettingsMenuOptions::Fullscreen;
                } else {
                    m_currentOption = (SettingsMenuOptions)newOptionInt;
                }
                break;
            }

            case MenuAction::Left: {
                if (m_currentOption == SettingsMenuOptions::VolumeSFX) {
                    float currentVolume = audioManager.getSFXVolume();
                    currentVolume = currentVolume - 5;
                    if (currentVolume < 0.f) {
                        currentVolume = 0.f;
                    }
                    audioManager.setSFXVolume(currentVolume);
                } else if (m_currentOption == SettingsMenuOptions::VolumeMusic) {
                    float currentVolume = audioManager.getMusicVolume();
                    currentVolume = currentVolume - 5;
                    if (currentVolume < 0.f) {
                        currentVolume = 0.f;
                    }
                    audioManager.setMusicVolume(currentVolume);
                }
                break;
            }

            case MenuAction::Right: {
                if (m_currentOption == SettingsMenuOptions::VolumeSFX) {
                    float currentVolume = audioManager.getSFXVolume();
                    currentVolume = currentVolume + 5;
                    if (currentVolume > 100.f) {
                        currentVolume = 100.f;
                    }
                    audioManager.setSFXVolume(currentVolume);
                } else if (m_currentOption == SettingsMenuOptions::VolumeMusic) {
                    float currentVolume = audioManager.getMusicVolume();
                    currentVolume = currentVolume + 5;
                    if (currentVolume > 100.f) {
                        currentVolume = 100.f;
                    }
                    audioManager.setMusicVolume(currentVolume);
                }
                break;
            }

            case MenuAction::Escape: {
                userWantsExit = true;
                break;
            }

            case MenuAction::Enter: {
                switch (m_currentOption) {
                    case SettingsMenuOptions::Fullscreen: {
                        if (isFullscreen) {
                            isFullscreen = !isFullscreen;
                            m_currentlyFullscreen = isFullscreen;
                        } else {
                            isFullscreen = !isFullscreen;
                            m_currentlyFullscreen = isFullscreen;
                        }
                        break;
                    }


                    case SettingsMenuOptions::Back: {
                        std::unique_ptr<Menu> newMenu = std::make_unique<MainMenu>();
                        return std::move(newMenu);
                    }
                }
                break;
            }
        }
    }

    m_currentMusicVolume = audioManager.getMusicVolume();
    m_currentSFXVolume = audioManager.getSFXVolume();

    return nullptr;
}

void SettingsMenu::drawMenu(sf::RenderWindow& window) {
    drawBackground(window);
    drawLogo(window);
    drawOptions(window);
}

void SettingsMenu::drawBackground(sf::RenderWindow &window) {
    m_bgSprite.setScale({(float) window.getSize().x / m_bgTexture.getSize().x, (float) window.getSize().y / m_bgTexture.getSize().y});

    window.draw(m_bgSprite);
}

void SettingsMenu::drawOptions(sf::RenderWindow &window) {
    sf::Text text(m_font);
    text.setCharacterSize(32);

    float screenCenterX = (float) window.getSize().x / 2.f; //get center X
    float screenCenterY = (float) window.getSize().y / 2.f; // get center Y

    int totalOptions = (int)SettingsMenuOptions::Count;
    float menuOptionOffset = 100.f;

    // position of the first option so the whole block/list of options is centered
    float initialPosY = screenCenterY - ((totalOptions - 1) * menuOptionOffset) / 2.f;

    for (int i = 0; i < totalOptions; i++) {
        text.setString(menuOptionToString((SettingsMenuOptions) i));

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

MenuType SettingsMenu::getMenuType() {
    return MenuType::SettingsMenu;
}

bool SettingsMenu::isNewOptionOutOfBounds(int newOptionInt) {
    if (newOptionInt < 0) {
        return true;
    }

    if (newOptionInt == static_cast<int>(SettingsMenuOptions::Count)) {
        return true;
    }

    return false;
}

void SettingsMenu::loadFont() {
    if (!m_font.openFromFile("fonts/Pixellettersfull-BnJ5.ttf")) {
        Logger::error("Font could not be loaded");
    }
}

std::string SettingsMenu::menuOptionToString(SettingsMenuOptions menuOption) {
    switch (menuOption) {
        case SettingsMenuOptions::Fullscreen: return m_currentlyFullscreen ? "Fullscreen ON" : "Fullscreen OFF";
        case SettingsMenuOptions::VolumeSFX: {
            int sfxVolume = (int) m_currentSFXVolume;
            std::string stringVolumePercentageFormated = std::to_string(sfxVolume) + "%";
            return "<< Effects Volume " + stringVolumePercentageFormated + " >>";
        }
        case SettingsMenuOptions::VolumeMusic: {
            int musicVolume = (int) m_currentMusicVolume;
            std::string stringVolumePercentageFormated = std::to_string(musicVolume) + "%";
            return "<< Music Volume " + stringVolumePercentageFormated + " >>";
        }
        case SettingsMenuOptions::Back: return "Back";
        default: return "";
    }
}

void SettingsMenu::loadLogo() {
    if (!m_logoTexture.loadFromFile("assets/settingsLogo.png")) {
        Logger::error("Main menu logo could not be loaded");
    }

    m_logoSprite.setTexture(m_logoTexture, true);

    sf::FloatRect logoBox = m_logoSprite.getLocalBounds();
    m_logoSprite.setOrigin({logoBox.position.x + logoBox.size.x / 2.f, logoBox.position.y + logoBox.size.y / 2.f});
}

void SettingsMenu::drawLogo(sf::RenderWindow& window) {
    float screenCenterX = (float) window.getSize().x / 2.f;

    float logoPosY = (float) window.getSize().y * 0.25f;

    m_logoSprite.setPosition({screenCenterX, logoPosY});

    window.draw(m_logoSprite);
}