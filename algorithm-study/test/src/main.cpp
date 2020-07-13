/*
 *  Assignment 2:Colour 2D barcodes , 159.731, S1 2020
 *  Family Name: JIANG , Given Name: TAO , Student ID:20004769,
 *
 * */


#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>

#include<algorithm>
#include "decoding.h"
#include <math.h>

#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include <ImgModel.h>


using namespace std;
using namespace cv;
int main() {
    cout << "testing..!!!!"<<endl;
    Mat srcImage = imread("./images/abcde.jpg");
    if (!srcImage.data) {
        std::cout << "Image not loaded";
        return -1;
    }
    imshow("demo1", srcImage);
//    cout<< srcImage <<endl;
    waitKey(0);
    return 0;
}
