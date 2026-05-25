//
// Created by p0wer on 06/04/2026.
//

#ifndef JUEGOPEGARSE2D_SETTINGSMENU_H
#define JUEGOPEGARSE2D_SETTINGSMENU_H

#include <memory>
#include "Menu.h"
#include "SFML/Graphics/RenderWindow.hpp"

class SettingsMenu : public Menu {
public:
    SettingsMenu();
    std::unique_ptr<Menu> updateMenu(InputManager& inputManager,AudioManager& audioManager, bool& userWantsExit, bool& isFullscreen) override;
    void drawMenu(sf::RenderWindow& window) override;
    MenuType getMenuType() override;

private:
    enum class SettingsMenuOptions {
        Fullscreen,
        VolumeSFX,
        VolumeMusic,
        Back,
        Count
    };

    SettingsMenuOptions m_currentOption = SettingsMenuOptions::Fullscreen;
    std::string menuOptionToString(SettingsMenuOptions menuOption);
    bool isNewOptionOutOfBounds(int newOptionInt) override;

    void loadFont() override;
    void drawBackground(sf::RenderWindow &window) override;
    void drawOptions(sf::RenderWindow &window) override;

    float m_currentSFXVolume = 100.f;
    float m_currentMusicVolume = 100.f;

    bool m_currentlyFullscreen;

    void loadLogo();
    void drawLogo(sf::RenderWindow &window);

    sf::Texture m_logoTexture;
    sf::Sprite m_logoSprite;
};

#endif //JUEGOPEGARSE2D_SETTINGSMENU_H