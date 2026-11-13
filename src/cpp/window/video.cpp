#include "video/video.h"
#include <iostream>
#include <opencv2/opencv.hpp>

VideoManager::VideoManager() : is_playing(false), filename("")
{
}

VideoManager::VideoManager(std::string &filename)
{
    this->filename = filename;
    this->is_playing = false;
}

VideoManager::~VideoManager()
{
    
}

std::uint8_t VideoManager::Load()
{
    video.open(filename);
    std::cout << filename << std::endl;
    if (!video.isOpened()) {
        std::cout << "VideoManage::Load : Can't read video" << std::endl;
        return FAILURE;   
    }

    return SUCCESS;
}

std::uint8_t VideoManager::Update(sf::Sprite &img)
{
    cv::Mat frame;

    if (!video.read(frame) || frame.empty())
        return FAILURE;

    texture = convert_mat2texture(frame);
    img.setTexture(texture, true);
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