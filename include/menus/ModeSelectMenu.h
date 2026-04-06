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
    std::unique_ptr<Menu> updateMenu(InputManager &inputManager, bool& userWantsExit) override;
    void drawMenu(sf::RenderWindow& window) override;
    MenuType getMenuType() override;
private:
};

#endif //JUEGOPEGARSE2D_MODESELECTMENU_H