#include "window/window.h"
#include "video/video.h"
#include <opencv2/opencv.hpp>

cv::Mat open_img(const std::string &filename)
{
    cv::Mat img;
    try {
        img = cv::imread(filename, cv::IMREAD_UNCHANGED);
        if (img.empty()) {
            std::cout << "open_img : Failed to load image" << std::endl;
            return img;
        }
        std::cout << "open_img: Success to load image" << std::endl;
    }
    catch (const cv::Exception &ex){
        return img;
    }
    return img;
}