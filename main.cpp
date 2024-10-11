#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <filesystem>
#include <iostream>

int main() {
    // 画像を読み込む
    std::string img_path = "/Users/taichi.muraki/workspace/Python/mur6/2024/github/wasm-sdl-opencv-test/IMG_3753.jpeg";
    
    // check img_path exists, by using std::filesystem
    if (!std::filesystem::exists(img_path)) {
        std::cout << "file not found: " << img_path << std::endl;
        return -1;
    } else {
        std::cout << "file found: " << img_path << std::endl;
    }
    std::string current_path = std::filesystem::current_path();
    std::cout << "current path: " << current_path << std::endl;
    // // list files in current directory
    // for (const auto & entry : std::filesystem::directory_iterator(current_path)) {
    //     std::cout << entry.path() << std::endl;
    // }
    std::string img_path2 = "test.pbm";
    cv::Mat img = cv::imread(img_path2);
    if (std::filesystem::exists(img_path2)) {
        std::cout << "file found: " << img_path2 << std::endl;
    } else {
        std::cout << "file not found: " << img_path2 << std::endl;
    }
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

    // 画像を保存する
    // cv::imwrite("output.bmp", img);

    return 0;
}
