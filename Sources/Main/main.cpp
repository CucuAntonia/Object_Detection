#include <opencv2/opencv.hpp>
#include <QApplication>
#include "../Interface/mainwindow.h"
#include "Algorithms.h"

using namespace cv;
using namespace std;

int main(int argc, char* argv[]) {


	QApplication a(argc, argv);
	MainWindow w;
	w.resize(1200, 800);
	w.show();

	
	Algo::RGB_to_HSV(129, 100, 89);
	Algo::HSV_to_RGB(130, 98, 100);
	Algo::BGR_to_HSV(129, 100, 89);

	Mat inImage = cv::imread("C:\\Users\\Antonia\\Desktop\\img1.jpg");
	Mat outImage1;
	Mat outImage2;
	Mat outImage3;
	Mat outImage4;

	cv::imshow("Original", inImage);

    bool r1 = Algo::RGB_to_HSV_imagesOpenCV(inImage, outImage1);
	cv::imshow("RGB2HSV", outImage1);
	std::cout << r1 << std::endl;

	bool r2 = Algo::HSV_to_RGB_imagesOpenCV(inImage, outImage2);
	cv::imshow("HSV2RGB", outImage2);
	std::cout << r2 << std::endl;

	bool r3 = Algo::BGR_to_HSV_imagesOpenCV(inImage, outImage3);
	cv::imshow("BGR2HSV", outImage3);
	std::cout << r3 << std::endl;

	bool r4 = Algo::HSV_to_BGR_imagesOpenCV(inImage, outImage4);
	cv::imshow("HSV2BGR", outImage4);
	std::cout << r4 << std::endl;


	VideoCapture cap(0);
	if (!cap.isOpened()) {
		cout << "Cannot open camera" << endl;
		return -1;
	}
	while (true) {
		Mat frame;
		cap.read(frame);
		imshow("Camera", frame);
		if (waitKey(30) == 'c')
		{
			Mat frame2;
			frame2 = frame.clone();
			imshow("Webcame Frame", frame2);
		}

		if (waitKey(30) == 27)
			break;


	}


	return a.exec();
	return 0;
	
}

