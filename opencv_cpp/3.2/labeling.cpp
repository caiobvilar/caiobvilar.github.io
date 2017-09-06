#include <iostream>
#include <opencv2/opencv.hpp>
#include <queue>

int main(int argc, char** argv){
	cv::Mat image, mask;
	int width, height;
	int nobjects;

	cv::CvPoint p;
	image = imread(argv[1],CV_LOAD_IMAGE_GRAYSCALE);

	if(!image.data)
	{
		std::cout << "imagem nao carregou corretamente\n";
		return(-1);
	}
	width=image.size().width;
	height=image.size().height;

	p.x=0;
	p.y=0;

	// busca objetos com buracos presentes
	nobjects=0;
	for(int i=0; i<height; i++)
	{
		for(int j=0; j<width; j++)
		{
			if(image.at<uchar>(i,j) == 255)
			{
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

void seedfill(cv::Mat *inputimg,cv::CvPoint *point,int *target_color,int *replace_color)
{
	if(inputimg->at<uchar>(point->x,point->y) == target_color)
	{
		return;
	}
	else
	{
		inputimg->at<uchar>(point->x,point->y) = replace_color;
	}
	point->x+1;
	seedfill(inputimg,point,target_color,replace_color);
	
}
