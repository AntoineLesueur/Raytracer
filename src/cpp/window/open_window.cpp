#include "video/video.h"

static bool update_video(sf::Clock &clock, sf::Sprite &img, VideoManager &video)
{
    if (clock.getElapsedTime().asSeconds() >= 1.f / 30.f) {
        if (video.Update(img) != SUCCESS)
            return false;
        clock.restart();
    }
    return true;
}

static void open_window(sf::RenderWindow &window)
{
    /*sf::Sprite img;
    std::string filename = "";
    VideoManager video(filename);
    if (video.Load() != SUCCESS)
        return;
    */
    sf::Event event;
    sf::Clock clock;
    
    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.display();
    }
}

std::uint8_t create_window(void)
{
    sf::VideoMode mode = {1920, 1080, 32};
    sf::RenderWindow window(mode, "Raytracer");
    
    window.setFramerateLimit(60);
    open_window(window);
    return SUCCESS;
}
