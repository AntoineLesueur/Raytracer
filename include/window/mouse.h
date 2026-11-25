#ifndef MOUSE_H_
    #define MOUSE_H_

    #include <SFML/Graphics.hpp>

enum class CursorType {
    Basic,
    Vertical,
    Horizontal
};

class MouseManager {
    public:
        MouseManager();
        ~MouseManager();

        void Set_cursor(CursorType type);
        void Update_pos();
        void Draw(sf::RenderWindow &window);
        sf::Vector2i Get_pos();

    private:
        sf::Texture vertical_Texture;
        sf::Texture horizontal_Texture;
        sf::Sprite sprite;
        sf::Vector2i pos;
};

#endif