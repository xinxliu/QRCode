#ifndef __OPENCVBITMAPSOURCE_H__
#define __OPENCVBITMAPSOURCE_H__

#include <zxing/LuminanceSource.h>
#include <opencv2/opencv.hpp>

using namespace zxing;

class OpenCVBitmapSource : public LuminanceSource
{
private:
    cv::Mat m_pImage;

public:
    OpenCVBitmapSource(cv::Mat &image);

    ~OpenCVBitmapSource();

    int getWidth() const;   
    int getHeight() const;

    ArrayRef<char> getRow(int y, ArrayRef<char> row) const; //See Zxing Array.h for ArrayRef def

    ArrayRef<char> getMatrix() const;
};

#endif
