#pragma once
#include <opencv2/core/mat.hpp>

#ifdef ALGORITHMS_EXPORT
	#define ALGORITHMS_API __declspec(dllexport)
#else
	#define ALGORITHMS_API __declspec(dllimport)
#endif

namespace Algo {

	///@brief   Method to convert a BGR image into a grayscale image.
	///@details This is the most common method. It is fast and simple.
	///@details This method uses the formula: Gray = (Red + Green + Blue) / 3
	///@param   const cv::Mat& inImage (The image to be converted into a grayscale image)
	///@param   cv::Mat& outImage (The image converted into a grayscale image)
	///@return  bool
	bool ALGORITHMS_API Averaging(const cv::Mat& inImage, cv::Mat& outImage);

	///@brief   Method to convert a BGR image into a grayscale image. (The weighted method)
	///@details Used in color television and video systems such as PAL, SECAM and NTSC.
	///@details Use weights 0.3 for red, 0.59 for green and 0.11 for blue.
	///@details The color red is the most bright in an image and the color green gives a calming effect for eyes.
	///@details Therefore, according to the standard ITU-R Rec. 601 or BT.601, the red color contribution is reduced and
	///@details the green one is increased, the contribution of the blue color being between these two.
	///@details This method uses the formula:  Gray = (Red * 0.3 + Green * 0.59 + Blue * 0.11)
	///@param   const cv::Mat& inImage (The image to be converted into a grayscale image)
	///@param   cv::Mat& outImage (The image converted into a grayscale image)
	///@return  bool
	bool ALGORITHMS_API Luminance(const cv::Mat& inImage, cv::Mat& outImage);

	///@brief   Method to convert a BGR image into a grayscale image.
	///@details The algorithm takes a color and converts it to its least saturated variant.
	///details  A pixel can be desaturated by finding the middle between the maximum (B, G, R) and the minimum (B, G, R). 
	///@details This method uses the formula: Gray = ( Max(Red, Green, Blue) + Min(Red, Green, Blue) ) / 2
	///@param   const cv::Mat& inImage (The image to be converted into a grayscale image)
	///@param   cv::Mat& outImage (The image converted into a grayscale image)
	///@return  bool
	bool ALGORITHMS_API Desaturation(const cv::Mat& inImage, cv::Mat& outImage);

	///@brief   Method to convert a BGR image into a grayscale image.
	///@details This algorithm can be considered a simpler method of the desaturation algorithm.
	///details  The algorithm sets each pixel to maximum red, green and blue values.
	///@details This method uses the formula: Gray = Max(Red, Green, Blue)
	///@param   const cv::Mat& inImage (The image to be converted into a grayscale image)
	///@param   cv::Mat& outImage (The image converted into a grayscale image)
	///@return  bool
	bool ALGORITHMS_API Maximum_decomposition(const cv::Mat& inImage, cv::Mat& outImage);

	///@brief   Method to convert a BGR image into a grayscale image.
	///@details This algorithm can be considered a simpler method of the desaturation algorithm.
	///details  The algorithm sets each pixel to minimum red, green and blue values.
	///@details This method uses the formula: Gray = Min(Red, Green, Blue)
	///@param   const cv::Mat& inImage (The image to be converted into a grayscale image)
	///@param   cv::Mat& outImage (The image converted into a grayscale image)
	///@return  bool
	bool ALGORITHMS_API Minimum_decomposition(const cv::Mat& inImage, cv::Mat& outImage);

	///@brief An enum that allows the user to choose a channel (Red, Green or Blue) for the Single_Color_Channel algorithm.
	enum ColorChannel
	{
		Blue = 0,
		Green,
		Red
	};
	///@brief   Method to convert a BGR image into a grayscale image.
	///@details The algorithm is used by most digital cameras.
	///details  This algorithm uses information from a single channel, chosen by the user (red, green or blue).
	///@details The default color channel is green.
	///@details This method uses the formula: Gray = Red or Gray = Green or Gray = Blue
	///@param   const cv::Mat& inImage (The image to be converted into a grayscale image)
	///@param   cv::Mat& outImage (The image converted into a grayscale image)
	///@param   ColorChannel colorCh = ColorChannel::Green 
	///@return  bool
	bool ALGORITHMS_API Single_color_channel(const cv::Mat& inImage, cv::Mat& outImage, ColorChannel colorCh = ColorChannel::Green);

	///@brief   Method to convert a BGR image into a grayscale image.
	///@details This algorithm allows the user to choose how many shades of gray the resulting image will be.
	///details  Any value between 2 and 256 is accepted. (the value is entered as a parameter -> numberOfShades)
	///@details 2 represents a black and white image, 256 represents an identical image as the Averaging algorithm.
	///@details This method uses the next formulas: 
	///@details ConversionFactor = 256 / numberOfShades
	///@details AverageValue = (Red + Green + Blue) / 3
	///@details Gray = Integer((AverageValue / ConversionFactor) + 0.5) * ConversionFactor
	///@param   const cv::Mat& inImage (The image to be converted into a grayscale image)
	///@param   cv::Mat& outImage (The image converted into a grayscale image)
	///@param   int numberOfShades
	///@return  bool
	bool ALGORITHMS_API Custom_gray_shades(const cv::Mat& inImage, cv::Mat& outImage, int numberOfShades);

	///@brief An enum that allows the user to choose the algorithm for the grayscale transformation.
	enum FilterName
	{
		averaging, luminance, desaturation, maximumDecomposition, minimumDecomposition, singleColorChannel, customGrayShades
	};

	///@brief  Function to display an cv::Mat image depending on the grayscale algorithm chosen by the user.
	///@param  cv::Mat& outImage (The image to be displayed, after the grayscale algorithm is applied)
	///@param  FilterName filterName (Enum that allows the user to choose the algorithm for the grayscale transformation)
	///@return bool
	bool ALGORITHMS_API DisplayImage(cv::Mat& outImage, FilterName filterName);

	void ALGORITHMS_API RGB_to_HSV(double R, double G, double B);

	void ALGORITHMS_API BGR_to_HSV(double B, double G, double R);

	void ALGORITHMS_API HSV_to_RGB(double H, double S, double V);

	void ALGORITHMS_API HSV_to_BGR();

	bool ALGORITHMS_API RGB_to_HSV_imagesOpenCV(const cv::Mat& inImage, cv::Mat& outImage);

	bool ALGORITHMS_API BGR_to_HSV_imagesOpenCV(const cv::Mat& inImage, cv::Mat& outImage);

	bool ALGORITHMS_API HSV_to_RGB_imagesOpenCV(const cv::Mat& inImage, cv::Mat& outImage);

	bool ALGORITHMS_API HSV_to_BGR_imagesOpenCV(const cv::Mat& inImage, cv::Mat& outImage);

}