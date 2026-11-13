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

    private:
        bool is_playing;
        std::string filename;
        sf::Texture texture;
        sf::Sprite img;
        cv::VideoCapture video;
        sf::Clock clock;
        float pos_x_start;
        float pos_y_start;
        float pos_x_end;
        float pos_y_end;
        float size_x;
        float size_y;
    
    protected:
        void Set_size();
        void Set_pos();
};

sf::Texture convert_mat2texture(cv::Mat &mat);
cv::Mat open_img(const std::string &filename);

#endif