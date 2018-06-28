#include<iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

int main()
{
//Reading the image
Mat image = imread("object.jpeg",1);
//to find the intensity of red colour
Mat OutputImage1;
inRange(image,Scalar(100,10,10),Scalar(255,100,100),OutputImage1);
//to find the intensity of blue colour
Mat OutputImage2;
inRange(image,Scalar(10,10,100),Scalar(100,100,255),OutputImage2);

int x1,x2;
x1=countNonZero(OutputImage1);
x2=countNonZero(OutputImage2);
//comparing red and blue
if (x1>x2)
{cout<<"Blue Object";}
else
{cout<<"Red Object";}

//displaying blue component in grey scale
namedWindow("output",CV_WINDOW_FREERATIO);
imshow("output",OutputImage1);
waitKey(0);
//displaying red component
namedWindow("output",CV_WINDOW_FREERATIO);
imshow("output",OutputImage2);
waitKey(0);

}
