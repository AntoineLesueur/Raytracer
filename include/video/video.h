/*
Creation de la class pour afficher une video dans la fenetre SFML
*/

#ifndef VIDEO_H_
    #define VIDEO_H_

    #include "macro.h"
    
    #include <string>
    #include <cstdint>

    #include <SFML/Graphics.hpp>

    #include <opencv2/opencv.hpp>

class VideoManager {
    public:
        VideoManager();
        VideoManager(std::string &filename);
        ~VideoManager();
        std::uint8_t Load();
        std::uint8_t Play();
        std::uint8_t Draw(sf::RenderWindow &window);
        std::uint8_t Update();
        void Move();
        void Resize();
        void Set_size();
        void ManageMouse(sf::RenderWindow &window);
        void Set_pos();

        sf::Vector2f Get_pos();
        sf::Vector2f Get_size();


    private:
        bool is_playing;
    
        std::string filename;
    
        cv::VideoCapture video;
    
        sf::Texture texture;
        sf::Sprite img;
        sf::Clock clock;
        sf::FloatRect bounds;
        sf::Vector2f size;
        sf::Vector2f size_bef;
        sf::Vector2f size_aft;
        sf::Vector2f pos;

        sf::FloatRect dim;

        float pos_x_start;
        float pos_y_start;
        float pos_x_end;
        float pos_y_end;
    
    protected:
        void Up_top();
        void Up_left();
        void Up_right();
        void Up_bottom();

        void Down_top();
        void Down_left();
        void Down_right();
        void Down_bottom();

        bool Detect_right(sf::Vector2i &mouse_pos);
        bool Detect_top(sf::Vector2i &mouse_pos);
        bool Detect_left(sf::Vector2i &mouse_pos);
        bool Detect_bott(sf::Vector2i &mouse_pos);

        sf::FloatRect Get_dim();
        void Set_dim();
};

sf::Texture convert_mat2texture(cv::Mat &mat);
cv::Mat open_img(const std::string &filename);

#endif