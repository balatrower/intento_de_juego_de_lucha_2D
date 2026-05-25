//
// Created by power on 24/03/2026.
//

#ifndef JUEGOPEGARSE2D_MAINMENU_H
#define JUEGOPEGARSE2D_MAINMENU_H
#include <memory>
#include "Menu.h"
#include "SFML/Graphics/Font.hpp"
#include "SFML/Graphics/RenderWindow.hpp"

class MainMenu : public Menu {

public:
    MainMenu();
    std::unique_ptr<Menu> updateMenu(InputManager& inputManager, AudioManager& audioManager, bool& userWantsExit, bool& isFullscreen) override;
    void drawMenu(sf::RenderWindow& window) override;
    MenuType getMenuType() override;

private:
    enum class MainMenuOptions {
        Play,
        Settings,
        Exit,
        Count // just to know the size of the enum
    };
    MainMenuOptions m_currentOption = MainMenuOptions::Play;
    std::string menuOptionToString(MainMenuOptions menuOption);
    bool isNewOptionOutOfBounds(int newOptionInt);

    void loadFont() override;
    void loadLogo();
    void drawLogo(sf::RenderWindow &window);

    sf::Texture m_logoTexture;
    sf::Sprite m_logoSprite;

    void drawBackground(sf::RenderWindow &window) override;
    void drawOptions(sf::RenderWindow &window) override;
};

#endif //JUEGOPEGARSE2D_MAINMENU_H