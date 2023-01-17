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

	void ALGORITHMS_API RGB_to_HSV(double R, double G, double B)
	{
		//We devide R, G and B by 255 to change the range from 0...255 to 0...1
		R = R / 255.0;
		G = G / 255.0;
		B = B / 255.0;

		double Cmax = max(R, max(G, B));
		double Cmin = min(R, min(G, B));
		double delta = Cmax - Cmin;

		//Hue calculation
		double H = -1;
		if (delta == 0)
			H = 0;
		else if (Cmax == R)
			H = 60 * fmod((G - B) / delta, 6);
		else if (Cmax == G)
			H = 60 * (((B - R) / delta) + 2);
		else if (Cmax == B)
			H = H = 60 * (((R - G) / delta) + 4);

		//Saturation calculation
		double S = -1;
		if (Cmax == 0)
			S = 0;
		else
			S = (delta / Cmax) * 100;

		//Value calculation
		double V = -1;
		V = Cmax * 100;

		//Print the conversion result
		std::cout << "H: " << H << " S: " << S << " V: " << V << std::endl;
	}

	void ALGORITHMS_API BGR_to_HSV(double B, double G, double R)
	{
		//We devide B, G and R by 255 to change the range from 0...255 to 0...1
		
		B = B / 255.0;
		G = G / 255.0;
		R = R / 255.0;
		

		double Cmax = max(B, max(G, R));
		double Cmin = min(B, min(G, R));
		double delta = Cmax - Cmin;

		//Hue calculation
		double H = -1;
		if (delta == 0)
			H = 0;
		else if (Cmax == B)
			H = 60 * fmod((G - B) / delta, 6);
		else if (Cmax == G)
			H = 60 * (((B - R) / delta) + 2);
		else if (Cmax == R)
			H = H = 60 * (((R - G) / delta) + 4);

		//Saturation calculation
		double S = -1;
		if (Cmax == 0)
			S = 0;
		else
			S = (delta / Cmax) * 100;

		//Value calculation
		double V = -1;
		V = Cmax * 100;

		//Print the conversion result
		std::cout << "H: " << H << " S: " << S << " V: " << V << std::endl;
	}

	void ALGORITHMS_API HSV_to_RGB(double H, double S, double V) 
	{
		double C = S * V;
		double X = C * (1 - fmod(H/60, 2) - 1);
		double m = V - C;
		double R = -1,  G = -1,  B = -1;
		if (H < 60 && H >= 0)
		{
			R = C;
			G = X;
			B = 0;
		}
		else if (H < 120 && H >= 60)
		{
			R = X;
			G = C;
			B = 0;
		}
		else if (H < 180 && H >= 120)
		{
			R = 0;
			G = C;
			B = X;
		}
		else if (H < 240 && H >= 180)
		{
			R = 0;
			G = X;
			B = C;
		}
		else if (H < 300 && H >= 240)
		{
			R = X;
			G = 0;
			B = C;
		}
		else if (H < 360 && H >= 300)
		{
			R = C;
			G = 0;
			B = X;
		}

		R = (R + m) * 2.55;
		G = (G + m) * 2.55;
		B = (B + m) * 2.55;

		//Print the conversion result
		std::cout << "R: " << R << " G: " << G << " B: " << B << std::endl;

	}

	/*bool ALGORITHMS_API HSV_to_BGR()
	{

	}*/

	bool ALGORITHMS_API RGB_to_HSV_imagesOpenCV(const cv::Mat& inImage, cv::Mat& outImage)
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

		cv::cvtColor(inImage, outImage, cv::COLOR_RGB2HSV);
		return true;
	}

	bool ALGORITHMS_API BGR_to_HSV_imagesOpenCV(const cv::Mat& inImage, cv::Mat& outImage)
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

		cv::cvtColor(inImage, outImage, cv::COLOR_BGR2HSV);
		return true;
	}

	bool ALGORITHMS_API HSV_to_RGB_imagesOpenCV(const cv::Mat& inImage, cv::Mat& outImage)
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
		//fara alocare, timpul crescut 
		outImage = cv::Mat::zeros(inImage.rows, inImage.cols, CV_8UC3);

		cv::cvtColor(inImage, outImage, cv::COLOR_HSV2RGB);
		return true;
	}

	bool ALGORITHMS_API HSV_to_BGR_imagesOpenCV(const cv::Mat& inImage, cv::Mat& outImage)
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

		cv::cvtColor(inImage, outImage, cv::COLOR_HSV2BGR);
		return true;
	}

	bool ALGORITHMS_API RGB_to_BGR_imagesOpenCV(const cv::Mat& inImage, cv::Mat& outImage)
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

		cv::cvtColor(inImage, outImage, cv::COLOR_RGB2BGR);
		return true;
	}

	bool ALGORITHMS_API BGR_to_RGB_imagesOpenCV(const cv::Mat& inImage, cv::Mat& outImage)
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

		cv::cvtColor(inImage, outImage, cv::COLOR_BGR2RGB);
		return true;
	}
}