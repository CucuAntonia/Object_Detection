#include <iostream>
#include "Utils.h"
#include <opencv2/imgproc.hpp>

namespace Utils
{
    bool ConvertMat2QImage(const cv::Mat& src, QImage& dest)
    {
        //Verify if src parameter represents a valid input image
        if (src.empty())
        {
            std::cout << "The image was not loaded or the image is empty!" << std::endl;
            return false;
        }


        ///Documentation link: https://doc.qt.io/qt-5/qimage.html#QImage-4
        if (src.channels() == 1)
        {
            dest = QImage(src.cols, src.rows, QImage::Format_Grayscale8);

            for (size_t r = 0; r < src.rows; ++r)
            {
                const uchar* pSrc = src.ptr<uchar>(r);

                for (size_t c = 0; c < src.cols; ++c)
                {
                    int color = (int)pSrc[c];
                    dest.setPixelColor(c, r, QColor(color, color, color));
                }
            }
        }
        else if (src.channels() == 3)
        {
            dest = QImage(src.cols, src.rows, QImage::Format_RGB888);

            for (size_t r = 0; r < src.rows; ++r)
            {
                const cv::Vec3b* pSrc = src.ptr<cv::Vec3b>(r);

                for (size_t c = 0; c < src.cols; ++c)
                {
                    uchar blue = pSrc[c][0];
                    uchar green = pSrc[c][1];
                    uchar red = pSrc[c][2];

                    dest.setPixelColor(c, r, QColor(red, green, blue));
                }
            }
        }
        else
        {
            std::cout << "Unimplemented" << std::endl;
            return false;
        }

        return true;
    }

    bool ConvertQImage2Mat(const QImage& src, cv::Mat& dest)
    {
        //Verify if src parameter represents a valid input image
        if (src.isNull() == 1)
        {
            std::cout << "The image was not loaded or the image is empty!" << std::endl;
            return false;
        }

        switch (src.format())
        {
        case QImage::Format::Format_RGB888:
        {
            cv::Mat view(src.height(), src.width(), CV_8UC3, (void*)src.constBits(), src.bytesPerLine());
            cvtColor(view, dest, cv::COLOR_RGB2BGR);
        }
        break;
        case QImage::Format::Format_RGB32:
        {
            cv::Mat view(src.height(), src.width(), CV_8UC4, (void*)src.constBits(), src.bytesPerLine());
            cvtColor(view, dest, cv::COLOR_BGRA2BGR);
        }
        break;
        case QImage::Format_Grayscale8:
        {

            cv::Mat view(src.height(), src.width(), CV_8UC1, (void*)src.constBits(), src.bytesPerLine());
            view.copyTo(dest);
            break;
        }
        break;
        default:
            std::cout << "Unimplemented" << std::endl;
            return false;
        }

        return true;
    }

    bool GetDisimilarityMat(cv::Mat inImage1, cv::Mat inImage2)
    {
        double totaldiff = 0.0;
        int r1 = inImage1.rows;
        int c1 = inImage1.cols;
        int r2 = inImage2.rows;
        int c2 = inImage2.cols;
        if (r1 != r2 || c1 != c2)
        {
            std::cout << "Error, pictures must have identical dimensions!\n";
            return false;
        }
        for (int row = 0; row < r1; row++)
        {
            for (int col = 0; col < c1; col++)
            {
                uchar pInImage1 = inImage1.at<uchar>(row, col);
                uchar pInImage2 = inImage2.at<uchar>(row, col);
                totaldiff += std::abs(pInImage1 - pInImage2) / 255.0;
            }
        }
        double rate = (totaldiff * 100) / (r1 * c1 * 3);
        if (rate < 5)
            return true;
        else
            return false;
    }

    bool UTILS_API GetDisimilarityQImage(QImage inImage1, QImage inImage2)
    {
        double totaldiff = 0.0;
        int r1 = inImage1.width();
        int c1 = inImage1.height();
        int r2 = inImage2.width();
        int c2 = inImage2.height();
        if (r1 != r2 || c1 != c2)
        {
            std::cout << "Error, pictures must have identical dimensions!\n";
            return false;
        }
        for (int row = 0; row < r1; row++)
        {
            for (int col = 0; col < c1; col++)
            {
                uchar pInImage1 = inImage1.pixel(row, col);
                uchar pInImage2 = inImage2.pixel(row, col);
                totaldiff += std::abs(pInImage1 - pInImage2) / 255.0;
            }
        }
        double rate = (totaldiff * 100) / (r1 * c1 * 3);
        if (rate < 5)
            return true;
        else
            return false;

    }

    bool UTILS_API VerifIfMatQImageAreSame(cv::Mat inImage1, QImage inImage2)
    {
        
        if (inImage2.height() == inImage1.rows && inImage2.width() == inImage1.cols)
        {
            if (inImage1.type() == 0 && inImage2.format() == 24)
            {

                return true;
            }
            else if (inImage1.type() == 16 && inImage2.format() == 13)
            {

                return true;
            }
            else if (inImage1.type() == 16 && inImage2.format() == 4)
            {

                return true;
            }
        }
        return false;
    }
}
