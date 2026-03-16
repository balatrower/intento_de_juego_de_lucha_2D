//
// Created by power on 16/03/2026.
//

#ifndef JUEGOPEGARSE2D_MAINMENU_H
#define JUEGOPEGARSE2D_MAINMENU_H
#include <string>

class MainMenu {
public:
    MainMenu();
    std::vector<sf::String> getOptions();
    void setOptions(std::vector<std::string> options);
    void addOption(std::string);
private:
    std::vector<sf::String> options;
};

#endif //JUEGOPEGARSE2D_MAINMENU_H