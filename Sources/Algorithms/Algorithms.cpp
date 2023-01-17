#include "Algorithms.h"
#include <iostream>
#include <opencv2/core/matx.hpp>
#include <opencv2/highgui.hpp>
#include <math.h>
#include <opencv2/imgproc.hpp>

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

				uchar grayscale = (0.3 * red + 0.59 * green + 0.11 * blue);

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

	bool DisplayImage(cv::Mat& outImage, FilterName filterName)
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

	bool RGB_to_HSV_pixels(const cv::Mat& inImage, cv::Mat& outImage)
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
		outImage = cv::Mat::zeros(inImage.rows, inImage.cols, CV_8UC3);
		for (int r = 0; r < inImage.rows; r++)
		{
			const cv::Vec3b* pInImage = inImage.ptr<cv::Vec3b>(r);
			cv::Vec3b* pOutImage = outImage.ptr<cv::Vec3b>(r);

			for (int c = 0; c < inImage.cols; c++)
			{
				uchar red = pInImage[c][0];
				uchar green = pInImage[c][1];
				uchar blue = pInImage[c][2];
				/*uchar blue = inImage.at<cv::Vec3b>(r, c)[0];
				uchar green = inImage.at<cv::Vec3b>(r, c)[1];
				uchar red = inImage.at<cv::Vec3b>(r, c)[2];*/

				//We devide R, G and B by 255 to change the range from 0...255 to 0...1
				/*blue = blue / 255.0;
				green = green / 255.0;
				red = red / 255.0;*/

				uchar MaxValueRGB = max(red, max(green, blue));
				uchar MinValueRGB = min(red, min(green, blue));

				//Hue calculation
				uchar hue = -1;
				if (MaxValueRGB - MinValueRGB == 0)
					hue = 0;
				else if (MaxValueRGB == red)
					hue = 60 *((green - blue) / (MaxValueRGB - MinValueRGB) % 360);
					//hue = 0 + 43 *((green - blue) / (MaxValueRGB - MinValueRGB));
				else if (MaxValueRGB == green)
					hue = 60 * (((blue - red) / (MaxValueRGB - MinValueRGB)) + 120);
					//hue = 85 + 43 * (((blue - red) / (MaxValueRGB - MinValueRGB)));
				else if (MaxValueRGB == blue)
					hue = 60 * (((red - green) / (MaxValueRGB - MinValueRGB)) + 240);
					//hue = 171 + 43 * (((red - green) / (MaxValueRGB - MinValueRGB)));


				//Saturation calculation
				uchar saturation = -1;
				if (MaxValueRGB == 0)
					saturation = 0;
				else
					saturation = ((MaxValueRGB - MinValueRGB) / MaxValueRGB)*100 ;

				//Value calculation
				uchar value = -1;
				value = MaxValueRGB;

				hue = (hue - 0) / (255 - 0) * 179;
				;

				pOutImage[c][0] = hue;
				pOutImage[c][1] = saturation;
				pOutImage[c][2] = value;

				/*outImage.at<cv::Vec3b>(r, c)[0] = hue;
				outImage.at<cv::Vec3b>(r, c)[0] = saturation;
				outImage.at<cv::Vec3b>(r, c)[0] = value;*/


			}

		}
		return true;

	}

	bool BGR_to_HSV_pixels(const cv::Mat& inImage, cv::Mat& outImage)
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
		outImage = cv::Mat::zeros(inImage.rows, inImage.cols, CV_8UC3);
		for (int r = 0; r < inImage.rows; r++)
		{
			const cv::Vec3b* pInImage = inImage.ptr<cv::Vec3b>(r);
			cv::Vec3b* pOutImage = outImage.ptr<cv::Vec3b>(r);

			for (int c = 0; c < inImage.cols; c++)
			{
				uchar blue = pInImage[c][0];
				uchar green = pInImage[c][1];
				uchar red = pInImage[c][2];
				/*uchar blue = inImage.at<cv::Vec3b>(r, c)[0];
				uchar green = inImage.at<cv::Vec3b>(r, c)[1];
				uchar red = inImage.at<cv::Vec3b>(r, c)[2];*/

				//We devide R, G and B by 255 to change the range from 0...255 to 0...1
				blue = blue / 255.0;
				green = green / 255.0;
				red = red / 255.0;

				uchar MaxValueRGB = max(red, max(green, blue));
				uchar MinValueRGB = min(red, min(green, blue));

				//Hue calculation
				uchar hue = -1;
				if (MaxValueRGB - MinValueRGB == 0)
					hue = 0;
				else if (MaxValueRGB == blue)
					hue = 60 * fmod((green - blue) / (MaxValueRGB - MinValueRGB), 60);
				//hue = 0 + 43 *((green - blue) / (MaxValueRGB - MinValueRGB));
				else if (MaxValueRGB == green)
					hue = 60 * (((blue - red) / (MaxValueRGB - MinValueRGB)) + 2);
				//hue = 85 + 43 * (((blue - red) / (MaxValueRGB - MinValueRGB)));
				else if (MaxValueRGB == red)
					hue = 60 * (((red - green) / (MaxValueRGB - MinValueRGB)) + 4);
				//hue = 171 + 43 * (((red - green) / (MaxValueRGB - MinValueRGB)));


				//hue = ((hue - 0) / (359 - 0)) * (179 - 0) + 0;
				//Saturation calculation
				uchar saturation = -1;
				if (MaxValueRGB == 0)
					saturation = 0;
				else
					saturation = ((MaxValueRGB - MinValueRGB) / MaxValueRGB) * 100;

				//Value calculation
				uchar value = -1;
				value = MaxValueRGB * 100;

				pOutImage[c][0] = hue;
				pOutImage[c][1] = saturation;
				pOutImage[c][2] = value;

				/*outImage.at<cv::Vec3b>(r, c)[0] = hue;
				outImage.at<cv::Vec3b>(r, c)[0] = saturation;
				outImage.at<cv::Vec3b>(r, c)[0] = value;*/


			}

		}
		return true;
	}

	//bool HSV_to_RGB_pixels(const cv::Mat& inImage, cv::Mat& outImage)
	//{

	//	//Verify if inImage parameter represents a valid input image
	//	if (inImage.empty())
	//	{
	//		std::cout << "The image was not loaded or the image is empty!" << std::endl;
	//		return false;
	//	}

	//	const int noOfChannels = inImage.channels();

	//	//Verify if the image has 3 channels
	//	if (noOfChannels != 3)
	//	{
	//		std::cout << "No support for images with less then 3 channels!" << std::endl;
	//		return false;
	//	}

	//	// Output image - memory allocation
	//	outImage = cv::Mat::zeros(inImage.rows, inImage.cols, CV_8UC3);
	//	for (int r = 0; r < inImage.rows; r++)
	//	{
	//		const cv::Vec3b* pInImage = inImage.ptr<cv::Vec3b>(r);
	//		cv::Vec3b* pOutImage = outImage.ptr<cv::Vec3b>(r);

	//		for (int c = 0; c < inImage.cols; c++)
	//		{
	//			uchar blue = pInImage[c][0];
	//			uchar green = pInImage[c][1];
	//			uchar red = pInImage[c][2];

	//	double C = S * V;
	//	double X = C * (1 - fmod(H / 60, 2) - 1);
	//	double m = V - C;
	//	double R = -1, G = -1, B = -1;
	//	if (H < 60 && H >= 0)
	//	{
	//		R = C;
	//		G = X;
	//		B = 0;
	//	}
	//	else if (H < 120 && H >= 60)
	//	{
	//		R = X;
	//		G = C;
	//		B = 0;
	//	}
	//	else if (H < 180 && H >= 120)
	//	{
	//		R = 0;
	//		G = C;
	//		B = X;
	//	}
	//	else if (H < 240 && H >= 180)
	//	{
	//		R = 0;
	//		G = X;
	//		B = C;
	//	}
	//	else if (H < 300 && H >= 240)
	//	{
	//		R = X;
	//		G = 0;
	//		B = C;
	//	}
	//	else if (H < 360 && H >= 300)
	//	{
	//		R = C;
	//		G = 0;
	//		B = X;
	//	}

	//	R = (R + m) * 2.55;
	//	G = (G + m) * 2.55;
	//	B = (B + m) * 2.55;

	//	//Print the conversion result
	//	std::cout << "R: " << R << " G: " << G << " B: " << B << std::endl;

	//}

	/*bool HSV_to_BGR(const cv::Mat& inImage, cv::Mat& outImage)
	{

	}*/

	bool RGB_to_BGR_pixels(const cv::Mat& inImage, cv::Mat& outImage)
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
		outImage = cv::Mat::zeros(inImage.rows, inImage.cols, CV_8UC3);

		for (int r = 0; r < inImage.rows; r++)
		{

			const cv::Vec3b* pInImage = inImage.ptr<cv::Vec3b>(r);
			cv::Vec3b* pOutImage = outImage.ptr<cv::Vec3b>(r);

			for (int c = 0; c < inImage.cols; c++)
			{
				uchar red = pInImage[c][0];
				uchar green = pInImage[c][1];
				uchar blue = pInImage[c][2];

				pOutImage[c][0] = blue;
				pOutImage[c][1] = green;
				pOutImage[c][2] = red;
				/*outImage.at<cv::Vec3b>(r, c)[0] = red;
				outImage.at<cv::Vec3b>(r, c)[1] = green;
				outImage.at<cv::Vec3b>(r, c)[2] = blue;*/
			}
		}
		return true;
	}

	bool BGR_to_RGB_pixels(const cv::Mat& inImage, cv::Mat& outImage)
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
		outImage = cv::Mat::zeros(inImage.rows, inImage.cols, CV_8UC3);

		for (int r = 0; r < inImage.rows; r++)
		{

			const cv::Vec3b* pInImage = inImage.ptr<cv::Vec3b>(r);
			cv::Vec3b* pOutImage = outImage.ptr<cv::Vec3b>(r);

			for (int c = 0; c < inImage.cols; c++)
			{
				uchar blue = pInImage[c][0];
				uchar green = pInImage[c][1];
				uchar red = pInImage[c][2];

				pOutImage[c][0] = red;
				pOutImage[c][1] = green;
				pOutImage[c][2] = blue;
				/*outImage.at<cv::Vec3b>(r, c)[0] = red;
				outImage.at<cv::Vec3b>(r, c)[1] = green;
				outImage.at<cv::Vec3b>(r, c)[2] = blue;*/
			}
		}
		return true;
	}

	bool ConvertTo_usingOpenCVFunctions(const cv::Mat& inImage, cv::Mat& outImage, ConversionSpace conversionspace)
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
		switch (conversionspace)
		{
		case ConversionSpace::BGR_to_HSV:
			cv::cvtColor(inImage, outImage, cv::COLOR_BGR2HSV);
			break;
		case ConversionSpace::BGR_to_RGB:
			cv::cvtColor(inImage, outImage, cv::COLOR_BGR2RGB);
			break;
		case ConversionSpace::HSV_to_BGR:
			cv::cvtColor(inImage, outImage, cv::COLOR_HSV2BGR);
			break;
		case ConversionSpace::HSV_to_RGB:
			cv::cvtColor(inImage, outImage, cv::COLOR_HSV2RGB);
			break;
		case ConversionSpace::RGB_to_BGR:
			cv::cvtColor(inImage, outImage, cv::COLOR_RGB2BGR);
			break;
		case ConversionSpace::RGB_to_HSV:
			cv::cvtColor(inImage, outImage, cv::COLOR_RGB2HSV);
			break;
		}
		return true;
	}

}