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
	//Set the application stylesheet
		//__FILE__
	/*QString pathToQss = "C:\\Users\\Antonia\\Desktop\\qss\\QSS\\ElegantDark.qss";
	QFile styleSheetFile(pathToQss);
	styleSheetFile.open(QFile::ReadOnly);
	QString styleSheet = QLatin1String(styleSheetFile.readAll());
	a.setStyleSheet(styleSheet);*/
	MainWindow w;
	w.resize(650, 650);
	w.show();

	
	/*Algo::RGB_to_HSV(129, 100, 89);
	Algo::HSV_to_RGB(130, 98, 100);
	Algo::BGR_to_HSV(129, 100, 89);*/

	Mat inImage = cv::imread("C:\\Users\\Antonia\\Desktop\\img1.jpg");
	Mat outImage1, outImage2, outImage3, outImage4;
	/*cv::cvtColor(inImage, outImage1, cv::COLOR_BGR2RGB);
	cv::cvtColor(inImage, outImage2, cv::COLOR_RGB2BGR);
	imshow("BGR-RGB", outImage1);
	imshow("RGB-BGR", outImage2);
	bool result = Utils::GetDisimilarityMat(outImage1, outImage2);
	std::cout << "................RESULT ::::::: " << result << std::endl;*/ 

	/*bool result1 = Algo::ConvertTo_usingOpenCVFunctions(inImage, outImage1, Algo::ConversionSpace::RGB_to_BGR);
	bool result2 = Algo::ConvertTo_usingOpenCVFunctions(inImage, outImage2, Algo::ConversionSpace::BGR_to_RGB);
	bool result3 = Algo::BGR_to_RGB_pixels(inImage, outImage3);
	bool result4 = Algo::RGB_to_BGR_pixels(inImage, outImage4);
	cv::imshow("RGB-BGR", outImage1);
	cv::imshow("BGR-RGB", outImage2);
	cv::imshow("BGR-RGB-pixel", outImage3);
	cv::imshow("RGB-BGR-pixel", outImage4);
	std::cout << Utils::GetDisimilarityMat(outImage1, outImage4) << std::endl;
	std::cout << Utils::GetDisimilarityMat(outImage2, outImage3) << std::endl;*/
	

	/*bool result2 = Algo::ConvertTo_usingOpenCVFunctions(inImage, outImage2, Algo::ConversionSpace::BGR_to_HSV);
	bool result3 = Algo::BGR_to_HSV_pixels(inImage, outImage3);
	cv::imshow("BGR-HSV", outImage2);
	cv::imshow("NGR-HSV-pixel", outImage3);
	std::cout << Utils::GetDisimilarityMat(outImage2, outImage3) << std::endl;*/

	bool result2 = Algo::ConvertTo_usingOpenCVFunctions(inImage, outImage2, Algo::ConversionSpace::RGB_to_HSV);
	bool result3 = Algo::RGB_to_HSV_pixels(inImage, outImage3);

	cv::imshow("RGB-HSV", outImage2);
	cv::imshow("RGB-HSV-pixel", outImage3);
	std::cout << Utils::GetDisimilarityMat(outImage2, outImage3) << std::endl;
	std::cout << inImage.channels() << std::endl;
	std::cout << outImage2.channels() << std::endl;
	std::cout << outImage3.channels() << std::endl;

	/*bool result2 = Algo::ConvertTo_usingOpenCVFunctions(inImage, outImage2, Algo::ConversionSpace::HSV_to_BGR);
	bool result3 = Algo::HSV_to_BGR_pixels(inImage, outImage3);

	cv::imshow("HSV-BGR", outImage2);
	cv::imshow("HSV-BGR-pixel", outImage3);
	std::cout << Utils::GetDisimilarityMat(outImage2, outImage3) << std::endl;
	std::cout << inImage.channels() << std::endl;
	std::cout << outImage2.channels() << std::endl;
	std::cout << outImage3.channels() << std::endl;
	*/
	return a.exec();
	return 0;
	
}

