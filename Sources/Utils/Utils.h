#pragma once
#include <opencv2\core\mat.hpp>  
#include "qimage.h"

#ifdef UTILS_EXPORT
#define UTILS_API __declspec(dllexport)
#else
#define UTILS_API __declspec(dllimport)
#endif

namespace Utils
{
	///@brief   Function to convert a cv::Mat element to a QImage element.
	///@details It returns true or false, depending on the conversion result.
	///@details More info about QImage at: https://doc.qt.io/qt-5/qimage.html#QImage-4
	///@details More info about cv::Mat at: https://docs.opencv.org/4.x/d3/d63/classcv_1_1Mat.html
	///@return  bool
	///@param	const cv::Mat& src (The source image, the conversion will be done depending on it)
	///@param	QImage& dest (The destination image, resulted if the conversion was made successfully)
	bool UTILS_API ConvertMat2QImage(const cv::Mat& src, QImage& dest);

	///@brief   Function to convert a QImage element to a cv::Mat element.
	///@details It returns true or false, depending on the conversion result.
	///@details More info about QImage at: https://doc.qt.io/qt-5/qimage.html#QImage-4
	///@details More info about cv::Mat at: https://docs.opencv.org/4.x/d3/d63/classcv_1_1Mat.html
	///@return  bool
	///@param	QImage& src (The source image, the conversion will be done depending on it)
	///@param	const cv::Mat& dest (The destination image, resulted if the conversion was made successfully)
	bool UTILS_API ConvertQImage2Mat(const QImage& src, cv::Mat& dest);

	///@brief Function to check the difference between two cv::Mat images.
	///@details It returns true or false, depending on the disimilarity percentage.
	///@details If the percentage is less then 5%, the function is true. Otherwise, it returns false.
	///@details More info about cv::Mat at: https://docs.opencv.org/4.x/d3/d63/classcv_1_1Mat.html
	///@param cv::Mat inImage1 
	///@param cv::Mat inImage2
	///@return bool
	bool UTILS_API GetDisimilarityMat(cv::Mat inImage1, cv::Mat inImage2);

	///@brief Function to check the difference between are two QImage images.
	///@details It returns true or false, depending on the disimilarity percentage.
	///@details If the percentage is less then 5%, the function is true. Otherwise, it returns false.
	///@details More info about QImage at: https://doc.qt.io/qt-5/qimage.html#QImage-4
	///@param QImage inImage1
	///@param QImage inImage2
	///@return bool
	bool UTILS_API GetDisimilarityQImage(QImage inImage1, QImage inImage2);

	///@brief Function to check if two images are identical.
	///@details It returns true or false, depending on the images sizes and formats.
	///@details More info about QImage at: https://doc.qt.io/qt-5/qimage.html#QImage-4
	///@details More info about cv::Mat at: https://docs.opencv.org/4.x/d3/d63/classcv_1_1Mat.html
	///@param cv::Mat inImage1
	///@param QImage inImage2
	///@return bool
	bool UTILS_API VerifIfMatQImageAreSame(cv::Mat inImage1, QImage inImage2);
}