#ifndef _QRCODEDECODER_H_
#define _QRCODEDECODER_H_

#include <iostream>
#include <string>
#include <exception>

#include <zxing/Binarizer.h>
#include <zxing/Result.h>
#include <zxing/ReaderException.h>

#include <zxing/Exception.h>
#include <zxing/BinaryBitmap.h>
#include <zxing/DecodeHints.h>
#include <zxing/qrcode/QRCodeReader.h>

#include "xGlobalHistogramBinarizer.h"
#include "xQRCodeReader.h"
#include "OpenCVLuminanceSource.h"

using namespace std;
using namespace zxing;
using namespace zxing::qrcode;

namespace xQRCodeDecoder {
	class QRCodeDecoder{
	public:
		QRCodeDecoder();
		~QRCodeDecoder();
		string decode(cv::Mat& image);
		void writeGrayImage();
		
		cv::Mat gray_;
		int BlackPoint_;
		vector<char> bits;
		Ref<BitMatrix> bits_;
		vector<char> rawBytes_;
		string decodeSource_(Ref<OpenCVLuminanceSource>& source);
	private:
		zxing::String Zxingstr_;
		Ref<BitMatrix> bitMap_;
		

	};
}
#endif
