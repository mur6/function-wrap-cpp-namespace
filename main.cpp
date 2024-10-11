#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <filesystem>
#include <iostream>

int main() {
    std::cout << "Hello, OpenCV!" << std::endl;
    std::string img_path = "./images/IMG_3753.jpeg";
    std::cout << "img_path: " << img_path << std::endl;

    // check img_path exists, by using std::filesystem
    if (!std::filesystem::exists(img_path)) {
        std::cout << "file not found: " << img_path << std::endl;
        return -1;
    } else {
        std::cout << "file found: " << img_path << std::endl;
    }
    std::string current_path = std::filesystem::current_path();
    std::cout << "current path: " << current_path << std::endl;

    cv::Mat img = cv::imread(img_path);

    // 画像が正しく読み込まれたかを確認する
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
