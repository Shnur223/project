#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <stdio.h>

using namespace std;
using namespace cv;

float w = 250;
float h = 350;
Mat matrix, imgWarp, sum_rgb;
int main() {

    string path = "C:/library/Project4/cards.jpg";//указать путь на изображение
    Mat img = imread(path);

    Point2f scr[4] = { {686,700},{1028,1000},{105,1000},{432,1345} };
    Point2f dst[4] = { {0.0f,0.0f},{w,0.0f},{0.0f,h},{w,h} };

    matrix = getPerspectiveTransform(scr, dst);
    warpPerspective(img, imgWarp, matrix, Point(w, h));
    imshow("Image", img);
    imshow("Image Warp", imgWarp);

    Mat rgbchannel[3];

    split(imgWarp, rgbchannel);

    namedWindow("Blue", 500);
    imshow("Red", rgbchannel[0]);

    namedWindow("Green", 500);
    imshow("Green", rgbchannel[1]);

    namedWindow("Red", 500);
    imshow("Blue", rgbchannel[2]);

    merge(rgbchannel, 3, sum_rgb);
    imshow("Merged", sum_rgb);

    Mat thresh_img;
    threshold(imgWarp, thresh_img, 100, 255, THRESH_BINARY);
    imshow("Threshold Binary", thresh_img);

    threshold(imgWarp, thresh_img, 100, 255, THRESH_BINARY_INV);
    imshow("Threshold Binary Inverse", thresh_img);

    waitKey(0);
}