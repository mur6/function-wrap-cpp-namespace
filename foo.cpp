#include <iostream>
#include <opencv2/opencv.hpp>

#ifdef __cplusplus
extern "C"
{
#endif

// int foo()
// {
//     std::cout << "Func foo." << std::endl;
//     return 0;
// }

extern cv::Mat __real_cv_imread(const std::string& filename, int flags);

cv::Mat __wrap_cv_imread(const std::string& filename, int flags)
{
    std::cout << "Func start wrap foo." << std::endl;
    // __real_foo();
    std::cout << "Func wrapped." << std::endl;
    return cv::Mat::zeros(100, 100, CV_8UC3);
}

#ifdef __cplusplus
}
#endif
