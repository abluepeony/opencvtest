#include </usr/include/opencv4/opencv2/opencv.hpp>
#include </usr/include/opencv4/opencv2/cudaimgproc.hpp>
#include </usr/include/opencv4/opencv2/cudaarithm.hpp>

int main() {
    // Load two images
    cv::Mat background = cv::imread("background.jpg");
    cv::Mat overlay = cv::imread("overlay.png", cv::IMREAD_UNCHANGED);

    if (background.empty() || overlay.empty()) {
        std::cerr << "Error: Unable to load one or both images." << std::endl;
        return 1;
    }

    // Transfer images to GPU memory
    cv::cuda::GpuMat gpuBackground(background);
    cv::cuda::GpuMat gpuOverlay(overlay);

    // Create a GPU Mat for the output image
    cv::cuda::GpuMat gpuResult;

    // Define the position to overlay the image (x, y coordinates)
    int posX = 100;
    int posY = 50;

    // Perform GPU-based image overlay
    cv::cuda::GpuMat roi(gpuResult, cv::Rect(posX, posY, overlay.cols, overlay.rows));
    gpuOverlay.copyTo(roi, gpuOverlay);

    // Transfer the result back to CPU memory
    cv::Mat result;
    gpuResult.download(result);

    // Display the combined image
    cv::imshow("Overlay Image", result);
    cv::waitKey(0);

    return 0;
}
