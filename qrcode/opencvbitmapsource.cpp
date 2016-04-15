#include "opencvbitmapsource.h"


OpenCVBitmapSource::OpenCVBitmapSource(cv::Mat& image)
	: LuminanceSource(image.cols, image.rows)
{
	this->m_pImage = image.clone();
}

OpenCVBitmapSource::~OpenCVBitmapSource()
{
}

int OpenCVBitmapSource::getWidth() const
{
	return this->m_pImage.cols;
}

int OpenCVBitmapSource::getHeight() const
{
	return this->m_pImage.rows;
}

ArrayRef<char> OpenCVBitmapSource::getRow(int y, ArrayRef<char> row) const
{
	int width_ = getWidth();
	if (!row)
		row = ArrayRef<char>(width_);
	const char *p = this->m_pImage.ptr<char>(y);
	for(int x = 0; x<width_; ++x, ++p)
		row[x] = *p;
	return row;
}

ArrayRef<char> OpenCVBitmapSource::getMatrix() const
{
	int width_ = getWidth();
	int height_ =  getHeight();
	ArrayRef<char> matrix = ArrayRef<char>(width_ * height_);
	for (int y = 0; y < height_; ++y)
	{
		const char *p = this->m_pImage.ptr<char>(y);
		int yoffset = y * width_;
		for(int x = 0; x < width_; ++x, ++p)
		{
			matrix[yoffset + x] = *p;
		}
	}
	return matrix;
}