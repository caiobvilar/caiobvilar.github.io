#include <iostream>
#include <opencv2/opencv.hpp>
#include <highgui.h>


void seedfill(cv::Mat img);

int main(int argc, char *argv[])
{
	cv::Mat image;
	int width, height;
	int nbubbles = 0;
	cv::CvPoint point;

	image = cv::imread(argv[1],CV_LOAD_IMAGE_GRAYSCALE);

	if(!image.data)
	{
		std::cout << "[ERROR]: image not loaded succesfully." << std::endl;
		return -1;
	}
	else
	{
		width = image.size().width;
		height = image.size().height;
		point.y = 0;
		point.x = 0;
	}
	for(int i=0;i < height;i++)
	{
		for(int j=0;j < width; j++)
		{
			if(image.at<uchar>(i,j) == 255)
			{
				nbubbles++;

			}
		}
	}
	
}
void seedfill(cv::Mat img)
{

}
