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
    pos{0, 0},
    size{1, 1},
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
    size = {1, 1};
    clock.restart();
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
    Set_dim();
    return SUCCESS;
}

sf::FloatRect VideoManager::Get_dim()
{
    return dim;
}

void VideoManager::Set_dim()
{
    dim = img.getGlobalBounds();
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

void VideoManager::ManageMouse(sf::RenderWindow &window)
{
    sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);

    Detect_right(mouse_pos);
    Detect_left(mouse_pos);
    Detect_bott(mouse_pos);
    Detect_top(mouse_pos);
}

sf::Vector2f VideoManager::Get_pos()
{
    return img.getPosition();
}

sf::Vector2f VideoManager::Get_size()
{
    sf::FloatRect b(img.getGlobalBounds());
    sf::Vector2f p(Get_pos());

    float size_vert = p.x; 
    return p;
}

void VideoManager::Resize()
{
    img.setScale(size);
}

void VideoManager::Set_size()
{
    sf::Vector2f p = img.getPosition();
    sf::FloatRect a = Get_dim();
    std::cout << a.left << " " << a.top << " " << a.height << " " << a.width << std::endl;
    std:: cout << p.x << " " << p.y << std::endl;
    size.x += 0.1;
    size.y = 1;
    Resize();
}

void VideoManager::Move()
{
    img.setPosition(pos);
}

void VideoManager::Set_pos()
{
    pos.x += 30;
    pos.y = 0;
    Move();
}

void VideoManager::Up_top()
{

}

void VideoManager::Up_left()
{

}

void VideoManager::Up_right()
{

}

void VideoManager::Up_bottom()
{

}

void VideoManager::Down_top()
{

}

void VideoManager::Down_left()
{

}

void VideoManager::Down_right()
{

}

void VideoManager::Down_bottom()
{

}

bool VideoManager::Detect_right(sf::Vector2i &mouse_pos)
{
    int x = mouse_pos.x;
    int y = mouse_pos.y;

    if (
        (x > dim.left + dim.width - 10) && 
        (x < dim.left + dim.width + 10) &&
        (y < dim.top + dim.height) &&
        (y > dim.top)
    ) {
        std::cout << "Zone droite" << std::endl;
        return true;
    }

    return false;
}

bool VideoManager::Detect_top(sf::Vector2i &mouse_pos)
{
    int x = mouse_pos.x;
    int y = mouse_pos.y;

    if (
        (x > dim.left) &&
        (x < dim.left + dim.width) &&
        (y < dim.top + 10) &&
        (y > dim.top - 10)
    ) {
        std::cout << "Zone haut" << std::endl;
        return true;
    }

    return false;
}

bool VideoManager::Detect_left(sf::Vector2i &mouse_pos)
{
    int x = mouse_pos.x;
    int y = mouse_pos.y;

    if (
        (x > dim.left - 10) &&
        (x < dim.left + 10) &&
        (y < dim.top + dim.height) &&
        (y > dim.top)
    ) {
        std::cout << "Zone gauche" << std::endl;
        return true;
    }

    return false;
}

bool VideoManager::Detect_bott(sf::Vector2i &mouse_pos)
{
    int x = mouse_pos.x;
    int y = mouse_pos.y;

    if (
        (x > dim.left) &&
        (x < dim.left + dim.width) &&
        (y < dim.top + dim.height + 10) &&
        (y > dim.top + dim.height - 10)
    ) {
        std::cout << "Zone bas" << std::endl;
        return true;
    }

    return false;
}
