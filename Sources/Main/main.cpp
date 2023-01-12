#include <opencv2/opencv.hpp>
#include <QApplication>
#include "../Interface/mainwindow.h"
#include "Algorithms.h"
#include "Utils.h"
#include "Camera.h"

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
	Mat outImage5;
	Mat outImage6;

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

	bool r5 = Algo::RGB_to_BGR_imagesOpenCV(inImage, outImage5);
	cv::imshow("RGB2BGR", outImage5);
	std::cout << r5 << std::endl;

	bool r6 = Algo::BGR_to_RGB_imagesOpenCV(inImage, outImage6);
	cv::imshow("BGR2RGB", outImage4);
	std::cout << r6 << std::endl;

	OpenCamera();
	
	return a.exec();
	return 0;
	
}

