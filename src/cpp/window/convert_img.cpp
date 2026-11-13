#include "window/window.h"
#include "video/video.h"
#include <opencv2/opencv.hpp>

sf::Texture convert_mat2texture(cv::Mat &mat)
{
    sf::Texture texture;

    if (mat.empty()) {
        std::cout << "convert_mat2texure : Empty mat" << std::endl;
        return texture;
    }
    
    uchar *data = new uchar[mat.total() * 4];
    cv::Mat mat_rgba(mat.size(), CV_8UC4, data);
    cv::cvtColor(mat, mat_rgba, cv::COLOR_BGR2RGBA, 4);

    sf::Image img;
    img.create(mat.cols, mat.rows, data);
    texture.loadFromImage(img);
    return texture;
}