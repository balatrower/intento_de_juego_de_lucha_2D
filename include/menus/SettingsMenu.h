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
    std::unique_ptr<Menu> updateMenu(InputManager& inputManager, bool& userWantsExit) override;
    void drawMenu(sf::RenderWindow& window) override;
    MenuType getMenuType() override;
private:
    enum class SettingsMenuOptions {
        Graphics,
        Sound,
        Back,
        Count
    };

    SettingsMenuOptions m_currentOption = SettingsMenuOptions::Graphics;
    bool isNewOptionOutOfBounds(int newOptionInt);
    void loadFont() override;
    std::string menuOptionToString(SettingsMenuOptions menuOption);
};

#endif //JUEGOPEGARSE2D_SETTINGSMENU_H