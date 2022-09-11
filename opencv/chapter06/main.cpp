#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
    string img_path="/mnt/t/github/Notes/opencv/resources/lambo.png";
    Mat img=imread(img_path);
    if(img.empty()){
        cout<<"load failue\n";
        return 0;
    }

    Mat imgHSV,mask;
    cvtColor(img,imgHSV,COLOR_BGR2HSV);
    int hmin=0，smin=110,vmin=152;
    int hmax=19,smax=240,vmax=255;


    nameWindow("Trackbars",(640,200));
    createTrackbar("Hue Min","Trackbars",&hmin,179);
    createTrackbar("Hue Max","Trackbars",&hmax,179);
    createTrackbar("Sat Min","Trackbars",&smim,255);
    createTrackbar("Sat Max","Trackbars",&smax,255);
    createTrackbar("Val Min","Trackbars",&vmin,255);
    createTrackbar("Val Max","Trackbars",&vmax,255);


    while(true){
        Scalar lower(hmin,smin,vmin);
        Scalar upper(hmax,smax,vmax);
        inRange(imgHSV,lower,upper,mask);
    }

    return 0;
}