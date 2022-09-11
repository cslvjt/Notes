#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

void getContours(Mat imgDil,Mat img)
{

    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy;

    vector<vector<Point>> conPoly(contours.size());
    findContours(imgDil,contours,hierarchy,RETR_EXTERBAL,CHAIN_APPROX_SIMPLE);
    drawContours(img,contours,-1,Scalar(255,0,255),2);

    vector<Rect> boundRect(contours.size());

    for(int i=0;i<contours.size();i++){
        int area = contoursArea(contours[i]);
        cout<<area<<endl;

        //画出所有面积大于1000的图像
        string objectType;
        if(area>1000){
            float peri=arcLength(contours[i],true);
            approxPolyDP(contours[i],conPoly[i],0.02*peri,true);
            
            cout<<conPoly[i].size()<<endl;
            
            boundingRect[i]=boundingRect(conPoly[i]);

            int objCor=(int)conPoly[i].size();

            if (objCor==3){
                objectType="Tri";
            }
            if(objCor==4){
                float aspRatio=(float)boundRect[i].width/boundRect[i].height;
                if (aspRatio >0.95 && aspRatio<1.05){
                    objectType="Square";
                }
                objectType="Rect";
            }
            if(objCor>4){
                objectType="Circle";
            }

            drawContours(img,contours,i,Scalar(255,0,255),2);
            rectangle(img,boundingRect[i].tl(),boundingRect[i].br,boundingRect[i],Scalar(0,255,0),5);//使用矩形框
            putText(img,objectType,{boundRect[i].x,boundRect[i].y-5},FONT_HERSHEY_PLAIN,0.75,Scalar(0,70,255),1);
        }
    }
}

int main()
{
    string img_path="/mnt/t/github/Notes/opencv/resources/test.png";
    Mat img=imread(img_path);
    
    if(img.empty()){
        cout<<"load failue\n";
        return 0;
    }

    Mat imgGray,imgBlur,imgCanny,imgDil;
    cvtColor(img,imgGray,COLOR_BGR2GRAY); //图像转为灰度图像
    imwrite("result.png",imgGray);*/
    
    GaussianBlur(img,imgBlur,Size(3,3),3,0); //高斯模糊
    
    Canny(imgBlur,imgCanny,25,75); //Canny边缘检测器
    
    Mat kernel=getStructuringElement(MORPH_RECT,Size(5,5));
    dilate(imgCanny,imgDia,kernel);

    getContours(imgDil,img);
    return 0;
}