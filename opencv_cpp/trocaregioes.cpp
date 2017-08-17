#include <iostream>
#include <opencv2/opencv.hpp>
#include <highgui.h>

struct pos
{
	int x=0;
	int y=0;
};

struct Region
{
	pos p1;
	pos p2;
};

void negRegion(cv::Rect* rect, cv::Mat* img);

int main(int argc, char* argv[])
{
	cv::Mat image,result;
	cv::Vec3b val;
	Region R1;
	cv::Rect rect1;
  image= cv::imread(argv[1],CV_LOAD_IMAGE_GRAYSCALE);
  if(!image.data)
	{
		std::cout << "nao abriu " << argv[1] << std::endl;
	}

	std::cout << "Define a region:" << "X1: ";
	std::cin >> rect1.x;
	std::cout << "Y1: ";
	std::cin >> rect1.y;
	std::cout << "X2: ";
	std::cin >> rect1.width;
	std::cout << "Y2: ";
	std::cin >> rect1.height;
	negRegion(&rect1,&image);

	//cvNamedWindow("Window",CV_WINDOW_AUTOSIZE);

  
	cv::imshow("window", image);  
  cvWaitKey();

  return 0;
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
