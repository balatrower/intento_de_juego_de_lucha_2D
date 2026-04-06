//
// Created by p0wer on 06/04/2026.
//


#include "menus/SettingsMenu.h"

SettingsMenu::SettingsMenu() {

}

std::unique_ptr<Menu> SettingsMenu::updateMenu(InputManager &inputManager, bool& userWantsExit) {
    return nullptr; // placeholder for submenu, will prob crash if triggered
}

void SettingsMenu::drawMenu(sf::RenderWindow& window) {
}

MenuType SettingsMenu::getMenuType() {
    return MenuType::ModeSelectMenu;
}