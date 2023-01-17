#pragma once
#include <opencv2\core\mat.hpp> 
#include <opencv2/videoio.hpp>
#include "Utils.h"



void UTILS_API OpenCamera(cv::VideoCapture cap, cv::Mat& frame);

bool UTILS_API CheckIfCameraCanBeOpen(cv::VideoCapture& cap);



