//
// Created by p0wer on 13/03/2026.
//

#ifndef JUEGOPEGARSE2D_PLAYER_H
#define JUEGOPEGARSE2D_PLAYER_H
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/System/Vector2.hpp"

class Player {
public:
    Player(sf::Vector2<int> position, sf::RectangleShape hitbox);

    Player(sf::Vector2<int> position);

    void move(sf::Vector2<int>);
    sf::Vector2<int> getPosition();
    void setPosition(sf::Vector2<int>);
private:
    sf::RectangleShape m_hitbox; // make later a hitbox class, and hurtbox class
    sf::Vector2<int> m_position;
};


#endif //JUEGOPEGARSE2D_PLAYER_H