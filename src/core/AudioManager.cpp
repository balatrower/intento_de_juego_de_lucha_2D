//
// Created by p0wer on 24/05/2026.
//

#include "core/AudioManager.h"

#include "SFML/Audio/Music.hpp"
#include "core/Logger.h"
#include "core/Game.h"

AudioManager::AudioManager() {
}

void AudioManager::playBackgroundMusic(GameState &currentState) {
    if (currentState == GameState::InMenu) {
        if (!m_backgroundMusic.openFromFile("music/menuMusic.flac")) {
            Logger::error("Song could not be loaded");
        }
    } else {
        if (!m_backgroundMusic.openFromFile("music/inGameMusic.flac")) {
            Logger::error("Song could not be loaded");
        }
    }

    m_backgroundMusic.setLooping(true);
    m_backgroundMusic.play();
    m_backgroundMusic.setVolume(getMusicVolume());
}

void AudioManager::setSFXVolume(float newVolume) {
    m_sfxVolume = newVolume;
}

float AudioManager::getSFXVolume() {
    return m_sfxVolume;
}

void AudioManager::setMusicVolume(float newVolume) {
    m_musicVolume = newVolume;
    m_backgroundMusic.setVolume(m_musicVolume);
}

float AudioManager::getMusicVolume() {
    return m_musicVolume;
}
