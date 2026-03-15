//
// Created by p0wer on 13/03/2026.
//

#include "entities/Player.h"

Player::Player(sf::Vector2<int> position, sf::RectangleShape hitbox) {
    m_position = position;
    m_hitbox = hitbox;
}

void Player::move(sf::Vector2<int> posDiffernce) {
    m_position -= posDiffernce;
}

sf::Vector2<int> Player::getPosition() {
    return m_position;
}


void Player::setPosition(sf::Vector2<int> newPos) {
    m_position = newPos;
}