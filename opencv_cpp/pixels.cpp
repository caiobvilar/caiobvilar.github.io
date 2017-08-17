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

void negRegion(Region reg, cv::Mat* img);

int main(int argc, char* argv[])
{
	cv::Mat image;
	cv::Vec3b val;
	Region R1;
  image= cv::imread(argv[1],CV_LOAD_IMAGE_GRAYSCALE);
  if(!image.data)
	{
		std::cout << "nao abriu " << argv[1] << std::endl;
	}

	std::cout << "Define a region:" << "X1: ";
	std::cin >> R1.p1.x;
	std::cout << "Y1: ";
	std::cin >> R1.p1.y;
	std::cout << "X2: ";
	std::cin >> R1.p2.x;
	std::cout << "Y2: ";
	std::cin >> R1.p2.y;
	negRegion(R1,&image);

	//cvNamedWindow("Window",CV_WINDOW_AUTOSIZE);

  
	cv::imshow("window", image);  
  cvWaitKey();

  return 0;
}

void negRegion(Region reg,cv::Mat *img)
{
  for(int i=reg.p1.y;i<reg.p2.y;i++)
	{
    for(int j=reg.p1.x;j<reg.p2.x;j++)
		{
      img->at<uchar>(i,j)= (-1)* img->at<uchar>(i,j);
    }
  }
}
