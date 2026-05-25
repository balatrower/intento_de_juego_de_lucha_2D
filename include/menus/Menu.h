//
// Created by p0wer on 06/04/2026.
//

#ifndef JUEGOPEGARSE2D_MENU_H
#define JUEGOPEGARSE2D_MENU_H

#include "SFML/Graphics/Font.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "core/AudioManager.h"
#include "core/InputManager.h"

enum class MenuType {
    MainMenu,
    ModeSelectMenu,
    CharacterSelectMenu,
    StageSelectMenu,
    SettingsMenu,
    ExitGame,
    PauseMenu,
    Count
};

class Menu {
public:
    // sf::Sprite in SFML 3.X.X needs a texture asociated with it on creation, if not it will be deleted implicitly
    // : just means before executing the code inside this -> { } do this : -> m_bgSprite(m_bgTexture)
    Menu() :  m_bgSprite(m_bgTexture) {}
    virtual ~Menu() = default;
    virtual std::unique_ptr<Menu> updateMenu(InputManager& inputManager, AudioManager& audioManager, bool& userWantsExit, bool& isFullscreen) = 0; // = 0 means every child MUST implement this function
    virtual void drawMenu(sf::RenderWindow& window) = 0;
    virtual MenuType getMenuType() = 0;
protected:
    virtual bool isNewOptionOutOfBounds(int newOptionInt) = 0;
    virtual void drawBackground(sf::RenderWindow &window) = 0;
    virtual void drawOptions(sf::RenderWindow &window) = 0;
    virtual void loadFont() = 0;
    sf::Font m_font;
    sf::Texture m_bgTexture;
    sf::Sprite m_bgSprite;
};

#endif //JUEGOPEGARSE2D_MENU_H