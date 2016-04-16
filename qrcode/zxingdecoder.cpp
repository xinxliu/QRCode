#include "zxingdecoder.h"

ZxingDecoder::ZxingDecoder()
{
}

ZxingDecoder::~ZxingDecoder()
{
}

string ZxingDecoder::decode(cv::Mat& image){
	cv::Mat gray;
	if(image.channels() != 1){
		cv::cvtColor(image, gray, CV_BGR2GRAY);
	}
	else{
		gray = image.clone();
	}
	Ref<OpenCVBitmapSource> source(new OpenCVBitmapSource(gray));
	return decodeImage(source);
}


string ZxingDecoder::decodeImage(Ref<OpenCVBitmapSource>& source){
	Ref<Binarizer> binarizer(new GlobalHistogramBinarizer(source));
	Ref<BinaryBitmap> bitmap(new BinaryBitmap(binarizer));
	MultiFormatReader reader;
	Ref<Result> result;
	try{
		result = reader.decode(bitmap, DecodeHints(DecodeHints::TRYHARDER_HINT));
	}
	catch(const std::exception& e){
		std::cerr<<e.what()<<std::endl;
		return string();
	}
	return result->getText()->getText();
}