#include "QRCodeDecoder.h"
namespace xQRCodeDecoder {
	QRCodeDecoder::QRCodeDecoder() :Zxingstr_(string()) {
	}

	QRCodeDecoder::~QRCodeDecoder() {
	}

	string QRCodeDecoder::decode(cv::Mat& image) {
		if (image.channels() != 1) {
			cv::cvtColor(image, gray_, CV_BGR2GRAY);
		}
		else {
			gray_ = image.clone();
		}
		//clone the gray to source
		//Ref<> is a resource manager, its constuctor accepts a pointer to the resources
		Ref<OpenCVLuminanceSource> source(new OpenCVLuminanceSource(gray_));
		return decodeSource_(source);
	}

	void QRCodeDecoder::writeGrayImage() {
		cv::imwrite("GrayImage.png", gray_);
	}

	string QRCodeDecoder::decodeSource_(Ref<OpenCVLuminanceSource>& source) {
		//
		auto pBinarizer = new xGlobalHistogramBinarizer(source);
		Ref<Binarizer> binarizer(pBinarizer);
		bitMap_ = pBinarizer->getBlackMatrix();
		BlackPoint_ = pBinarizer->BlackPoint_;
		//
		auto pBitmap = new BinaryBitmap(binarizer);
		Ref<BinaryBitmap> bitmap(pBitmap);
		xQRCodeReader reader;
		Ref<Result> result;
		try {
			result = reader.decode(bitmap, DecodeHints(DecodeHints::TRYHARDER_HINT));
			bits_ = reader.bits_;
		}
		catch (const std::exception& e) {
			//std::cerr<<e.what()<<std::endl;
			return string();
		}
		Zxingstr_ = *(result->getText());
		rawBytes_ = (*(result->getRawBytes())).values_;
		return result->getText()->getText();
	}
}
