#include "Camera.h"
#include <opencv2/opencv.hpp>


 bool UTILS_API OpenCamera()

{
	cv::VideoCapture cap(0);
	if (!cap.isOpened()) {
		std::cout << "Cannot open camera" << std::endl;
		return -1;
	}
	
	while (true) {
		cv::Mat frame;
		cap.read(frame);
		cv::imshow("Camera", frame);
		if (cv::waitKey(30) == 'c')
		{
			cv::Mat frame2;
			frame2 = frame.clone();
			cv::imshow("Webcame Frame", frame2);
		}

		if (cv::waitKey(30) == 27)
			break;
		return 1;
		


	}
}