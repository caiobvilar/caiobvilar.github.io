#include <iostream>
#include <opencv2/opencv.hpp>
#include <highgui.h>
#include <vector>
#include <algorithm>

int main(int argc, char* argv[])
{
	cv::Mat image,quad0,quad1,quad2,quad3;
	std::vector<cv::Mat> quadrants;
	std::vector<cv::Mat>::iterator quadrantsITR;

	
  image= cv::imread(argv[1],CV_LOAD_IMAGE_GRAYSCALE);

  if(!image.data)
	{
		std::cout << "[ERROR]: image " << argv[1] << "didn't load." << std::endl;
	}
	cv::Mat imageAux //auxiliary matrix for quadrant capture
	quadrants.push_back(cv::Mat(image.size().width/2,image.size().height/2,CV_8U)); //first quadrant
	quadrants.push_back(cv::Mat(image.size().width/2,image.size().height/2,CV_8U)); //second quadrant
	quadrants.push_back(cv::Mat(image.size().width/2,image.size().height/2,CV_8U)); //third quadrant
	quadrants.push_back(cv::Mat(image.size().width/2,image.size().height/2,CV_8U)); //fourth quadrant


	cvNamedWindow("Window",CV_WINDOW_AUTOSIZE);
	cv::imshow("Window", image);  
  cvWaitKey();

  return 0;
}
