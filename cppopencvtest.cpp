#include <opencv2/opencv.hpp>

int main() {
    // Create a window
    cv::namedWindow("OpenCV Test", cv::WINDOW_NORMAL);

    // Create an image to display the "Hi" message
    cv::Mat image = cv::Mat::zeros(100, 300, CV_8UC3); // 100x300 pixel black image

    // Display the "Hi" message on the image
    cv::putText(image, "Hi", cv::Point(50, 50), cv::FONT_HERSHEY_SIMPLEX, 1.0, cv::Scalar(255, 255, 255), 2);

    // Display the image in the window
    cv::imshow("OpenCV Test", image);

    // Wait for a key press and then close the window
    cv::waitKey(0);
    cv::destroyAllWindows();

    return 0;
}
