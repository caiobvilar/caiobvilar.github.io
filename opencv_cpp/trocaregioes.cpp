#include <iostream>
#include <opencv2/opencv.hpp>
#include <highgui.h>
#include <vector>
#include <algorithm>

void negRegion(cv::Rect* rect, cv::Mat* img);
void promptUser(cv::Rect *inputRect); 

int main(int argc, char* argv[])
{
	cv::Mat image;
	Region R1;
	cv::Rect rect1;
	std::vector<cv::Mat> quadrants;

	promptUser(&rect1);

  image= cv::imread(argv[1],CV_LOAD_IMAGE_GRAYSCALE);

  if(!image.data)
	{
		std::cout << "[ERROR]: image " << argv[1] << "didn't load." << std::endl;
	}

	//negRegion(&rect1,&image);
	cvNamedWindow("Window",CV_WINDOW_AUTOSIZE);
	cv::imshow("Window", image);  
  cvWaitKey();

  return 0;
}

void promptUser(cv::Rect* inputRect)
{
	std::cout << "Define a region:" << "X1: ";
	std::cin >> rect1.x;
	std::cout << "Y1: ";
	std::cin >> rect1.y;
	std::cout << "X2: ";
	std::cin >> rect1.width;
	std::cout << "Y2: ";
	std::cin >> rect1.height;
}

void negRegion(cv::Rect* rect,cv::Mat *img)
{
  for(int i=rect->y;i<rect->height;i++)
	{
    for(int j=rect->x;j<rect->width;j++)
		{
      img->at<uchar>(i,j)= (-1)* img->at<uchar>(i,j);
    }
  }
}
