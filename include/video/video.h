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
        VideoManager(std::string filename);
        ~VideoManager();
        std::uint8_t Load(std::string filename);
        std::uint8_t Play();
        std::uint8_t Pause();
        std::uint8_t Stop();
        std::uint8_t Draw(sf::RenderWindow &window);

    private:
        bool is_playing;
        std::string filename;
};

sf::Texture convert_mat2texture(cv::Mat &mat);
cv::Mat open_img(const std::string &filename);

#endif