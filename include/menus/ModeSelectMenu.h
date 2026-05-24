//
// Created by p0wer on 06/04/2026.
//

#ifndef JUEGOPEGARSE2D_MODESELECTMENU_H
#define JUEGOPEGARSE2D_MODESELECTMENU_H
#include "Menu.h"
#include "SFML/Graphics/RenderWindow.hpp"

class ModeSelectMenu : public Menu {

public:
    ModeSelectMenu();
    std::unique_ptr<Menu> updateMenu(InputManager& inputManager, bool& userWantsExit) override;
    void drawMenu(sf::RenderWindow& window) override;
    MenuType getMenuType() override;

private:
    enum class ModeSelectMenuOptions {
        Versus2P,
        Back,
        Count // just to know the size of the enum
    };
    ModeSelectMenuOptions m_currentOption = ModeSelectMenuOptions::Versus2P;

    std::string menuOptionToString(ModeSelectMenuOptions menuOption);
    bool isNewOptionOutOfBounds(int newOptionInt) override;
    void loadFont() override;
    void drawBackground(sf::RenderWindow &window) override;
    void drawOptions(sf::RenderWindow &window) override;
};

#endif //JUEGOPEGARSE2D_MODESELECTMENU_H