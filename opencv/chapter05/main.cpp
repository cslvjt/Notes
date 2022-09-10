#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
    string img_path="/mnt/t/github/Notes/opencv/resources/cards.jpg";
    Mat img=imread(img_path);
    Mat imgGray,imgBlur,imgCanny,imgDia,imgErode;
    if(img.empty()){
        cout<<"load failue\n";
        return 0;
    }
    float w=250,h=350;

    Mat matrix,imgWrap;

    Point2f src[4]={{529,142},{771,190},{405,395},{674,457}};
    Point2f dst[4]={{0.0f,0.0f},{w,0.0f},{0.0f,h},{w,h}};

    matrix=getPerspectiveTransform(src,dst);
    warpPerspective(img,imgWrap,matrix,Point(w,h));

    imwrite("imgWrap.png",imgWrap);
    return 0;
}