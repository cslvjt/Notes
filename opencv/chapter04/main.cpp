#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
    Mat img(512,512,CV_8UC3,Scalar(255,255,255));

    circle(img,Point(256,256),155,Scalar(0,70,255),FILLED);//画一个圆
    rectangle(img,Point(130,220),Point(260,260),Scalar(255,255,255),3); //画一个矩形
    line(img,Point(130,300),Point(382,296),Scalar(255,255,255),2); //画一条线

    putText(img,"lvjt work",Point(137,262),FONT_HERSHEY_DUPLEX,2,Scalar(0,70,255));//显示文本
    imwrite("img.png",img); 
    return 0;
}