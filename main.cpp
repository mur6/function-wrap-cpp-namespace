#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <filesystem>
#include <iostream>

#include <opencv2/opencv.hpp>


extern "C" cv::Mat __wrap_cv_imread(const std::string& filename, int flags) {
    return cv::Mat::zeros(100, 100, CV_8UC3);
}

extern "C" cv::Mat __real_cv_imread(const std::string& filename, int flags);


int main() {
    std::cout << "Hello, OpenCV!" << std::endl;
    std::string img_path = "./images/IMG_3753.jpeg";
    std::cout << "img_path: " << img_path << std::endl;

    if (!std::filesystem::exists(img_path)) {
        std::cout << "file not found: " << img_path << std::endl;
        return -1;
    } else {
        std::cout << "file found: " << img_path << std::endl;
    }

    cv::Mat img = cv::imread(img_path);
    // cv::Mat img = cv::Mat::zeros(100, 100, CV_8UC3);

    if(img.empty()) {
        std::cout << "画像を読み込めませんでした。" << std::endl;
        return -1;
    }

    // 画像を表示する
    cv::namedWindow("Image", cv::WINDOW_AUTOSIZE);
    cv::imshow("Image", img);

    // キー入力を待つ
    cv::waitKey(0);

    return 0;
}
