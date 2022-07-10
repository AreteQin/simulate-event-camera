#include <opencv2/opencv.hpp>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

int main() {
    cv::Mat color, grey_k, grey_last, event;
    cv::VideoCapture capture1(0); //Mind the number in(), make sure the point at the right port of cameras.
    if (!capture1.isOpened()) {
        std::cout << "Failed to open video device\n";
        return -1;
    }
    capture1 >> color;
    cv::cvtColor(color, grey_last, cv::COLOR_BGR2GRAY);
    sleep(0.1);
    while (true) {
        capture1 >> color;
        cv::cvtColor(color, grey_k, cv::COLOR_BGR2GRAY);
        event = (grey_last - grey_k) + 150;
//        for (int i = 0; i < event.rows * event.cols; i++) {
//            uint8_t *data = (uint8_t *) event.data;
//            std::cout << unsigned(data[i]) << ",";
//        }
        grey_last = grey_k.clone();
        imshow("rgb", color);
        imshow("event", event);
        cv::waitKey(1);
        sleep(0.1);
    }
    return 0;
}