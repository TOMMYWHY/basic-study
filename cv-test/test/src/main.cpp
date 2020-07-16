//
// Created by Tommy on 2020-03-07.
//
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;


#if 01
int main (int argc, char* argv[]){
//    if(argc!=2){ cout << "needs 1 argument, e.g. image.jpg" << endl ; exit (0) ;}
//    Mat img1 = imread(argv[1],1);
    Mat img1 = imread("./images/lena.jpg",1);
//    print(img1);
//    Mat img2;
//    flip(img1,img2,1);

    imshow("img1",img1);
//    imshow("img2",img2);
    waitKey(0);

    return 0;
}
#endif
