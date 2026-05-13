//
// Created by p0wer on 06/04/2026.
//

#ifndef JUEGOPEGARSE2D_MENU_H
#define JUEGOPEGARSE2D_MENU_H
#include <iostream>

#include "core/InputManager.h"
#include "SFML/Graphics/Font.hpp"
#include "SFML/Graphics/RenderWindow.hpp"

enum class MenuType {
    MainMenu,
    ModeSelectMenu,
    CharacterSelectMenu,
    StageSelectMenu,
    SettingsMenu,
    GraphicsMenu,
    SoundMenu,
    ExitGame,
    PauseMenu,
    Count
};

class Menu {
public:
    virtual ~Menu() = default;
    virtual std::unique_ptr<Menu> updateMenu(InputManager& inputManager, bool& userWantsExit) = 0; // = 0 means every child MUST implement this function
    virtual void drawMenu(sf::RenderWindow& window) = 0; // define later when thinkin bout the render stuff
    virtual MenuType getMenuType() = 0;
protected:
    virtual void loadFont() = 0;
    sf::Font m_font;
};

#endif //JUEGOPEGARSE2D_MENU_H