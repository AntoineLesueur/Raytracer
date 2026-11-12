#include "video/video.h"
#include <iostream>
#include <opencv2/opencv.hpp>

VideoManager::VideoManager(std::string filename)
{
    this->filename = filename;
    this->is_playing = false;
}

std::uint8_t VideoManager::Load(std::string filename)
{
    return SUCCESS;
}

std::uint8_t VideoManager::Play()
{
    this->is_playing = true;
    return SUCCESS;
}

std::uint8_t VideoManager::Pause()
{
    this->is_playing = false;
    return SUCCESS;
}

std::uint8_t VideoManager::Stop()
{
    this->is_playing = false;
    return SUCCESS;
}

std::uint8_t VideoManager::Draw(sf::RenderWindow &window)
{
    return SUCCESS;
}