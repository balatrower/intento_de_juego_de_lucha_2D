//
// Created by p0wer on 24/05/2026.
//

#ifndef JUEGOPEGARSE2D_AUDIOMANAGER_H
#define JUEGOPEGARSE2D_AUDIOMANAGER_H
#include "SFML/Audio/Music.hpp"
#include "core/GameState.h"

class AudioManager {
public:
    AudioManager();
    void playBackgroundMusic(GameState& currentState);
    void setMusicVolume(float newVolume);
    float getMusicVolume();
    void setSFXVolume(float newVolume);
    float getSFXVolume();
private:
    sf::Music m_backgroundMusic;
    float m_musicVolume = 50.f;
    float m_sfxVolume = 100.f;
};

#endif //JUEGOPEGARSE2D_AUDIOMANAGER_H