//
// Created by power on 24/03/2026.
//

#ifndef JUEGOPEGARSE2D_MAINMENU_H
#define JUEGOPEGARSE2D_MAINMENU_H

class MainMenu {
    enum class MenuOptions {
        Play,
        Settings,
        Exit
    };

public:

private:
    MenuOptions m_currentOption = MenuOptions::Play;
};

#endif //JUEGOPEGARSE2D_MAINMENU_H