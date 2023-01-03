#include "Algorithms.h"
#include <iostream>
#include <opencv2/core/matx.hpp>
#include <opencv2/highgui.hpp>

using namespace std;

namespace Algo {


	bool Averaging(const cv::Mat& inImage, cv::Mat& outImage)
	{
		//Verify if inImage parameter represents a valid input image
		if (inImage.empty())
		{
			std::cout << "The image was not loaded or the image is empty!" << std::endl;
			return false;
		}

		const int noOfChannels = inImage.channels();

		//Verify if the image has 3 channels
		if (noOfChannels != 3)
		{
			std::cout << "No support for images with less then 3 channels!" << std::endl;
			return false;
		}
		// Output image - memory allocation
		outImage = cv::Mat::zeros(inImage.rows, inImage.cols, CV_8UC1);

		for (int r = 0; r < inImage.rows; r++) 
		{
			const cv::Vec3b* pInImage = inImage.ptr<cv::Vec3b>(r);
			uchar* pOutImage = outImage.ptr<uchar>(r);

			for (int c = 0; c < inImage.cols; c++)
			{
				
				uchar blue = pInImage[c][0];
				uchar green = pInImage[c][1];
				uchar red = pInImage[c][2];
				uchar grayscale = (red + green + blue) / noOfChannels;

				pOutImage[c] = grayscale;
			}
		}
		return true;
	}

	bool Luminance(const cv::Mat& inImage, cv::Mat& outImage)
	{
		//Verify if inImage parameter represents a valid input image
		if (inImage.empty())
		{
			std::cout << "The image was not loaded or the image is empty!" << std::endl;
			return false;
		}

		const int noOfChannels = inImage.channels();

		//Verify if the image has 3 channels
		if (noOfChannels != 3)
		{
			std::cout << "No support for images with less then 3 channels!" << std::endl;
			return false;
		}

		// Output image - memory allocation
		outImage = cv::Mat::zeros(inImage.rows, inImage.cols, CV_8UC1);

		for (int r = 0; r < inImage.rows; r++) 
		{
			const cv::Vec3b* pInImage = inImage.ptr<cv::Vec3b>(r);
			uchar* pOutImage = outImage.ptr<uchar>(r);

			for (int c = 0; c < inImage.cols; c++)
			{
				uchar blue = pInImage[c][0];
				uchar green = pInImage[c][1];
				uchar red = pInImage[c][2];

				uchar grayscale = (0.3*red + 0.59*green + 0.11*blue);

				pOutImage[c] = grayscale;
				
			}
		}
		return true;
	}

	bool Desaturation(const cv::Mat& inImage, cv::Mat& outImage)
	{
		//Verify if inImage parameter represents a valid input image
		if (inImage.empty())
		{
			std::cout << "The image was not loaded or the image is empty!" << std::endl;
			return false;
		}

		const int noOfChannels = inImage.channels();
		//Verify if the image has 3 channels
		if (noOfChannels != 3)
		{
			std::cout << "No support for images with less then 3 channels!" << std::endl;
			return false;
		}

		// Output image - memory allocation
		outImage = cv::Mat::zeros(inImage.rows, inImage.cols, CV_8UC1);

		for (int r = 0; r < inImage.rows; r++) 
		{
			const cv::Vec3b* pInImage = inImage.ptr<cv::Vec3b>(r);
			uchar* pOutImage = outImage.ptr<uchar>(r);

			for (int c = 0; c < inImage.cols; c++)
			{
				uchar blue = pInImage[c][0];
				uchar green = pInImage[c][1];
				uchar red = pInImage[c][2];

				uchar grayscale = (max({ red, green, blue }) + min({ red, green, blue })) / 2;

				pOutImage[c] = grayscale;

			}
		}
		return true;
	}

	bool Maximum_decomposition(const cv::Mat& inImage, cv::Mat& outImage)
	{
		//Verify if inImage parameter represents a valid input image
		if (inImage.empty())
		{
			std::cout << "The image was not loaded or the image is empty!" << std::endl;
			return false;
		}

		const int noOfChannels = inImage.channels();

	    //Verify if the image has 3 channels
		if (noOfChannels != 3)
		{
			std::cout << "No support for images with less then 3 channels!" << std::endl;
			return false;
		}

		// Output image - memory allocation
		outImage = cv::Mat::zeros(inImage.rows, inImage.cols, CV_8UC1);

		for (int r = 0; r < inImage.rows; r++) 
		{
			const cv::Vec3b* pInImage = inImage.ptr<cv::Vec3b>(r);
			uchar* pOutImage = outImage.ptr<uchar>(r);
			

			for (int c = 0; c < inImage.cols; c++)
			{
				uchar blue = pInImage[c][0];
				uchar green = pInImage[c][1];
				uchar red = pInImage[c][2];

				uchar grayscale = (max({ red, green, blue }));

				pOutImage[c] = grayscale;
			}
		}

		return true;
	}
	bool Minimum_decomposition(const cv::Mat& inImage, cv::Mat& outImage)
	{
		//Verify if inImage parameter represents a valid input image
		if (inImage.empty())
		{
			std::cout << "The image was not loaded or the image is empty!" << std::endl;
			return false;
		}

		const int noOfChannels = inImage.channels();

		//Verify if the image has 3 channels
		if (noOfChannels != 3)
		{
			std::cout << "No support for images with less then 3 channels!" << std::endl;
			return false;
		}

		// Output image - memory allocation
		outImage = cv::Mat::zeros(inImage.rows, inImage.cols, CV_8UC1);

		for (int r = 0; r < inImage.rows; r++) 
		{
			const cv::Vec3b* pInImage = inImage.ptr<cv::Vec3b>(r);
			uchar* pOutImage = outImage.ptr<uchar>(r);

			for (int c = 0; c < inImage.cols; c++)
			{
				uchar blue = pInImage[c][0];
				uchar green = pInImage[c][1];
				uchar red = pInImage[c][2];

				uchar grayscale = (min({ red, green, blue })) / 2;

				pOutImage[c] = grayscale;
			}
		}

		return true;
	}

	bool Single_color_channel(const cv::Mat& inImage, cv::Mat& outImage, ColorChannel colorCh)
	{
		//Verify if inImage parameter represents a valid input image
		if (inImage.empty())
		{
			std::cout << "The image was not loaded or the image is empty!" << std::endl;
			return false;
		}
		

		const int noOfChannels = inImage.channels();

		//Verify if the image has 3 channels
		if (noOfChannels != 3)
		{
			std::cout << "No support for images with less then 3 channels!" << std::endl;
			return false;
		}

		// Output image - memory allocation
		outImage = cv::Mat::zeros(inImage.rows, inImage.cols, CV_8UC1);

		int colorChIdx = -1;
		switch (colorCh)
		{
		case ColorChannel::Blue:
			colorChIdx = 0;
			break;
		case ColorChannel::Green:
			colorChIdx = 1;
			break;
		case ColorChannel::Red:
			colorChIdx = 2;
			break;
		}

		for (int r = 0; r < inImage.rows; r++)
		{
			const cv::Vec3b* pInImage = inImage.ptr<cv::Vec3b>(r);
			uchar* pOutImage = outImage.ptr<uchar>(r);

			for (int c = 0; c < inImage.cols; c++)
			{
				uchar color = pInImage[c][colorChIdx];
				
				uchar grayscale = color;

				pOutImage[c] = grayscale;
			}
		}
		return true;
	}
	bool Custom_gray_shades(const cv::Mat& inImage, cv::Mat& outImage, int numberOfShades)
	{
		//Verify if inImage parameter represents a valid input image
		if (inImage.empty())
		{
			std::cout << "The image was not loaded or the image is empty!" << std::endl;
			return false;
		}

		const int noOfChannels = inImage.channels();

		//Verify if the image has 3 channels
		if (noOfChannels != 3)
		{
			std::cout << "No support for images with less then 3 channels!" << std::endl;
			return false;
		}

		// Output image - memory allocation
		outImage = cv::Mat::zeros(inImage.rows, inImage.cols, CV_8UC1);

		for (int r = 0; r < inImage.rows; r++)
		{
			const cv::Vec3b* pInImage = inImage.ptr<cv::Vec3b>(r);
			uchar* pOutImage = outImage.ptr<uchar>(r);

			for (int c = 0; c < inImage.cols; c++)
			{
				uchar blue = pInImage[c][0];
				uchar green = pInImage[c][1];
				uchar red = pInImage[c][2];

				int conversionFactor = 256 / numberOfShades;
				int averageValue = (blue + green + red) / noOfChannels;
				uchar grayscale = (int)((averageValue / conversionFactor) + 0.5) * conversionFactor;

				pOutImage[c] = grayscale;
			}
		}

		return true;
	}

	bool DisplayImage(cv::Mat&outImage, FilterName filterName)
	{
		//Verify if outImage parameter is valid
		if (outImage.rows < 1 || outImage.cols < 1)
			return false;

		if (!outImage.data)
		{
			std::cout << "Error loading image... \n";
			return false;

		}

		std::string windowName = "";

		switch (filterName)
		{
		case FilterName::averaging:
			windowName = "Averaging";
			break;
		case FilterName::desaturation:
			windowName = "Desaturation";
			break;
		case FilterName::maximumDecomposition:
			windowName = "Maximum_decomposition";
			break;
		case FilterName::minimumDecomposition:
			windowName = "Minimum_decomposition";
			break;
		case FilterName::singleColorChannel:
			windowName = "Single_color_channel";
			break;
		case FilterName::customGrayShades:
			windowName = "Custom_gray_shades";
			break;
		case FilterName::luminance:
			windowName = "Luminance";
			break;
		default:
			windowName = "";
			break;
		}
		
		cv::namedWindow(windowName, cv::WINDOW_AUTOSIZE);
		cv::imshow(windowName, outImage);
		cv::waitKey(0);

		return true;
	}
}