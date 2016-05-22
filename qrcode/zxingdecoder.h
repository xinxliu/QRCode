#ifndef __ZXINGDECODER_H__
#define __ZXINGDECODER_H__

#include <iostream>
#include <string>
#include <exception>

#include <zxing/Binarizer.h>
#include <zxing/Result.h>
#include <zxing/ReaderException.h>
#include <zxing/common/GlobalHistogramBinarizer.h>
#include <zxing/Exception.h>
#include <zxing/BinaryBitmap.h>
#include <zxing/DecodeHints.h>
#include <zxing/qrcode/QRCodeReader.h>

#include "OpenCVLuminanceSource.h"

using namespace std;
using namespace zxing;
using namespace zxing::qrcode;

class ZxingDecoder
{
public:
	ZxingDecoder();
	~ZxingDecoder();
	string decode(cv::Mat& image);
	void showGrayImage();
	void showBinaryImage();
	cv::Mat gray_;
	cv::Mat binaryImage_;
	zxing::String Zxingstr_;
	Ref<BitMatrix> bitMap_;
	vector<char> rawBytes_;
	string decodeSource_(Ref<OpenCVLuminanceSource>& source);
};

#endif
