#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv/highgui.h>
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
	cv::Mat imageAux; //auxiliary matrix for quadrant capture

	quadrants.push_back(cv::Mat(cv::Rect(0,0,image.size().width/2,image.size().height/2))); //first quadrant
	quadrants.push_back(cv::Mat(cv::Rect(image.size().width/2,0,image.size().width/2,image.size().height/2))); //second quadrant
	quadrants.push_back(cv::Mat(cv::Rect(0,image.size().height/2,image.size().width/2,image.size().height/2))); //third quadrant
	quadrants.push_back(cv::Mat(cv::Rect(image.size().width/2,image.size().height/2,image.size().width/2,image.size().height/2))); //fourth quadrant
	for(quadrantsITR = quadrants.begin(); quadrantsITR != quadrants.end();quadrantsITR++)
	{
		image.copyTo((*quadrantsITR));
	}

	cvNamedWindow("Window",CV_WINDOW_AUTOSIZE);
	cv::imshow("Window", image);  
  cvWaitKey();

  return 0;
}
