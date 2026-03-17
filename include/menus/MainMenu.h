//
// Created by power on 16/03/2026.
//

#ifndef JUEGOPEGARSE2D_MAINMENU_H
#define JUEGOPEGARSE2D_MAINMENU_H

class MainMenu {
public:
    MainMenu();
    std::vector<std::string> getOptions();
    void setOptions(std::vector<std::string> options);
    void addOption(std::string);
private:
    std::vector<std::string> options;
};

#endif //JUEGOPEGARSE2D_MAINMENU_H