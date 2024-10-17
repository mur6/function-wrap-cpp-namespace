#include <filesystem>
#include <iostream>

#include <opencv2/opencv.hpp>


// extern "C"
// {
//     cv::Mat cv::imread(const std::string& filename, int flags);
// }

// 新しい名前空間で元の関数を隠蔽
namespace cv {
    // オリジナルのimreadを異なる名前で保持
    inline Mat original_imread(const std::string& filename, int flags = IMREAD_COLOR) {
        return ::cv::imread(filename, flags);
    }

    // 新しいimread関数を定義（オリジナルを隠蔽）
    inline Mat imread(const std::string& filename, int flags) {
        std::cout << "Custom imread called: " << filename << std::endl;
        // 必要に応じてoriginal_imreadを呼び出すことも可能
        return ::cv::Mat::zeros(100, 100, CV_8UC3);
    }
}


int main() {
    std::cout << "Hello, OpenCV!" << std::endl;
    std::string img_path = "/tmp/sky.jpg";
    std::cout << "img_path: " << img_path << std::endl;

    cv::Mat img = cv::imread(img_path);

    if(img.empty()) {
        std::cout << "画像を読み込めませんでした。" << std::endl;
        return -1;
    } else {
        // show image info
        std::cout << "image size: " << img.size() << std::endl;
        std::cout << "image channels: " << img.channels() << std::endl;
    }

    return 0;
}
