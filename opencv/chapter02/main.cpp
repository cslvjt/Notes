#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
    string img_path="/mnt/t/github/Notes/opencv/resources/test.png";
    Mat img=imread(img_path);
    Mat imgGray,imgBlur,imgCanny,imgDia,imgErode;
    if(img.empty()){
        cout<<"load failue\n";
        return 0;
    }

    /*cvtColor(img,imgGray,COLOR_BGR2GRAY); //图像转为灰度图像
    imwrite("result.png",imgGray);*/
    
    GaussianBlur(img,imgBlur,Size(3,3),3,0); //高斯模糊
    
    Canny(imgBlur,imgCanny,25,75); //Canny边缘检测器
    
    Mat kernel=getStructuringElement(MORPH_RECT,Size(5,5));
    dilate(imgCanny,imgDia,kernel);

    erode(imgDia,imgErode,kernel);
    imwrite("imgErode.png",imgErode);
   // waitKey(0);
    return 0;
}