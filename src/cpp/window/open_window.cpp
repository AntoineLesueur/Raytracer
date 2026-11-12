#include "video/video.h"

static void open_window(sf::RenderWindow &window)
{
    sf::Event event;

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
