#include "Camera.h"
#include <opencv2/opencv.hpp>


bool UTILS_API CheckIfCameraCanBeOpen(cv::VideoCapture& cap)
{
	cap.open(0);
	if (!cap.isOpened())
	{
		return -1;
	}
	return 1;
}

void UTILS_API OpenCamera(cv::VideoCapture cap, cv::Mat& frame)

{

	cap.read(frame);
}
	
	 
     
