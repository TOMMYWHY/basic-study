#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;
int main() {
    Mat src = imread("./images/limes.tif",0);
    imshow("src", src);

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
