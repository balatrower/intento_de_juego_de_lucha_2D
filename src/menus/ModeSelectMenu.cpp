//
// Created by p0wer on 06/04/2026.
//

#include <memory>
#include "menus/ModeSelectMenu.h"


ModeSelectMenu::ModeSelectMenu() {

}

std::unique_ptr<Menu> ModeSelectMenu::updateMenu(InputManager &inputManager, bool& userWantsExit) {
    return nullptr; // placeholder for submenu, will prob crash if triggered
}

void ModeSelectMenu::drawMenu(sf::RenderWindow& window) {
}

MenuType ModeSelectMenu::getMenuType() {
    return MenuType::ModeSelectMenu;
}

