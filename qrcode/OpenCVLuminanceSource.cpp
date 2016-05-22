#include "OpenCVLuminanceSource.h"

OpenCVLuminanceSource::OpenCVLuminanceSource(cv::Mat& image)
	: LuminanceSource(image.cols, image.rows){
	this->image_ = image.clone();
}

OpenCVLuminanceSource::~OpenCVLuminanceSource(){
}

int OpenCVLuminanceSource::getWidth() const{
	return this->image_.cols;
}

int OpenCVLuminanceSource::getHeight() const{
	return this->image_.rows;
}

//get all the element of y-th row
ArrayRef<char> OpenCVLuminanceSource::getRow(int y, ArrayRef<char> row) const{
	int width_ = getWidth();
	if (!row)
		row = ArrayRef<char>(width_);
	const char *p = this->image_.ptr<char>(y);
	for (int x = 0; x < width_; ++x, ++p) {
		row[x] = *p;
	}
	return row;
}

ArrayRef<char> OpenCVLuminanceSource::getMatrix() const{
	int width_ = getWidth();
	int height_ =  getHeight();
	ArrayRef<char> matrix = ArrayRef<char>(width_ * height_);
	for (int y = 0; y < height_; ++y){
		const char *p = this->image_.ptr<char>(y);
		int yoffset = y * width_;
		for(int x = 0; x < width_; ++x, ++p){
			matrix[yoffset + x] = *p;
		}
	}
	return matrix;
}