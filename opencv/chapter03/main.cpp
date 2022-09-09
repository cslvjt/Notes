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
    if(img.empty()){
        cout<<"load failue\n";
        return 0;
    }
    Mat imgResize,imgCrop;

    //cout<<img.size()<<endl;

    //resize
    //resize(img,imgResize,Size(640,480));//具体尺寸
    resize(img,imgResize,Size(),0.5,0.5); //按比例

    Rect roi(100,100,300,250); //指定裁剪区域
    imgCrop=img(roi);//图像裁剪
    imwrite("imgCrop.png",imgCrop);
   
    return 0;
}