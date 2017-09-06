#include <iostream>
#include <opencv2/opencv.hpp>
#include <queue>

int main(int argc, char** argv){
	cv::Mat image, mask;
	int width, height;
	int nobjects;

	cv::CvPoint p;
	image = imread(argv[1],CV_LOAD_IMAGE_GRAYSCALE);

	if(!image.data){
		std::cout << "imagem nao carregou corretamente\n";
		return(-1);
	}
	width=image.size().width;
	height=image.size().height;

	p.x=0;
	p.y=0;

	// busca objetos com buracos presentes
	nobjects=0;
	for(int i=0; i<height; i++){
		for(int j=0; j<width; j++){
			if(image.at<uchar>(i,j) == 255){
				// achou um objeto
				nobjects++;
				p.x=j;
				p.y=i;
				cv::floodFill(image,p,nobjects);
			}
		}
	}
	cv::imshow("image", image);
	cv::imwrite("labeling.png", image);
	cvwaitKey();
	return 0;
}

void seedfill(cv::Mat* inputImg)
{
	int region_grayscale = 0;
	std::queue<cv::CvPoint> vizinhos;
	for(int i = 0;i < inputImg->size().width;i++)
	{
		for(int j = 0;j < inputImg->size().height;j++)
		{

			if(image.at<uchar>(i,j) == 255)
			{
				image.at<uchar>(i,j) == region_grayscale;
				region_grayscale++;
			}
			if(i== 0 && j == 0)
			{
				if(image.at<uchar>(i))
			}
		}
	}
}
