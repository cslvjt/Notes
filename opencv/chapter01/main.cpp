#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;
/*
load image
int main()
{
    string img_path="./Notes/opencv/resources/test.png";
    Mat img=imread(img_path);
    imshow("Image",img);
    waitKey(0);
    return 0;
}

// load video

void main()
{
    string path="./Notes/opencv/resources/test_video";
    VideoCapture cap(path);
    Mat img;
    while (true){
        cap.read(img);
        imshow("Image",img);
        waitKey(20);
    }
}
*/
//load webcam
void main()
{
    VideoCapture cap(1);//相机ID
    Mat img;
    while (true){
        cap.read(img);
        imshow("Image",img);
        waitKey(20);
    }
}