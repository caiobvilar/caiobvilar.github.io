#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv/highgui.h>

int main(int argc, char* argv[])
{
	cv::Mat image;
  image = cv::imread(argv[1],CV_LOAD_IMAGE_GRAYSCALE);

  if(!image.data)
	{
		std::cout << "[ERROR]: image " << argv[1] << "didn't load." << std::endl;
	}

	cv::Mat imgaux(image.size().width,image.size().height,CV_8UC1);

	cv::Mat quad1(image,cv::Rect(0,
															 0,
															 image.size().width/2,
															 image.size().height/2));

	cv::Mat quad2(image,cv::Rect(image.size().width/2,
															 0,
															 image.size().width/2,
															 image.size().height/2));

	cv::Mat quad3(image,cv::Rect(0,
															 image.size().height/2,
															 image.size().width/2,
															 image.size().height/2));

	cv::Mat quad4(image,cv::Rect(image.size().width/2, 
															 image.size().height/2,
															 image.size().width/2,
															 image.size().height/2));

	quad1.copyTo(imgaux(cv::Rect(image.size().width/2,
															 image.size().height/2,
															 image.size().width/2,
															 image.size().height/2)));

	quad2.copyTo(imgaux(cv::Rect(0,
															 image.size().height/2,
															 image.size().width/2,
															 image.size().height/2)));

	quad3.copyTo(imgaux(cv::Rect(image.size().width/2,
															 0,
															 image.size().width/2,
															 image.size().height/2)));

	quad4.copyTo(imgaux(cv::Rect(0,
															 0,
															 image.size().width/2,
															 image.size().height/2)));
	
	cvNamedWindow("Window",CV_WINDOW_AUTOSIZE);

	cv::imshow("Window",imgaux );
	cv::imwrite("changequad.png",imgaux);

  cvWaitKey();

  return 0;
}
