#include "video/video.h"
#include <iostream>
#include <opencv2/opencv.hpp>

VideoManager::VideoManager() : 
    is_playing(false),
    filename(""),
    pos_x_start(0),
    pos_x_end(0),
    pos_y_start(0),
    pos_y_end(0),
    size_x(100),
    size_y(100),
    clock(),
    texture(),
    img(),
    video()
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

std::uint8_t VideoManager::Update()
{
    if (true != is_playing) {
        return SUCCESS;
    }
    if (clock.getElapsedTime().asSeconds() < 1.f / 30.f) {
        return SUCCESS;
    }
    clock.restart();
    cv::Mat frame;

    if (!video.read(frame) || frame.empty()) {
        return FAILURE;
    }

    texture = convert_mat2texture(frame);
    img.setTexture(texture, true);
    return SUCCESS;
}

std::uint8_t VideoManager::Play()
{
    if (true != video.isOpened()) {
        return FAILURE;
    }

    this->is_playing = true;
    clock.restart();
    return SUCCESS;
}

std::uint8_t VideoManager::Draw(sf::RenderWindow &window)
{
    window.draw(img);
    return SUCCESS;
}


void VideoManager::Resize()
{

}

void VideoManager::Move()
{
    
}