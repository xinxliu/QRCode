#include "zxingdecoder.h"

ZxingDecoder::ZxingDecoder(){
}

ZxingDecoder::~ZxingDecoder(){
}

string ZxingDecoder::decode(cv::Mat& image){
	if(image.channels() != 1){
		cv::cvtColor(image, gray_, CV_BGR2GRAY);
	}
	else{
		gray_ = image.clone();
	}
	//clone the gray to source
	//Ref<> is a resource manager, its constuctor accepts a pointer to the resources
	Ref<OpenCVLuminanceSource> source(new OpenCVLuminanceSource(gray_));
	return decodeSource_(source);
}

void ZxingDecoder::showGrayImage(){
	cv::imwrite("GrayImage.png", gray_);
}

void ZxingDecoder::showBinaryImage(){
	cv::imwrite("BinaryImage", binaryImage_);
}


string ZxingDecoder::decodeSource_(Ref<OpenCVLuminanceSource>& source){
	auto pBinarizer = new GlobalHistogramBinarizer(source);
	Ref<Binarizer> binarizer(pBinarizer);
	
	auto pBitmap = new BinaryBitmap(binarizer);
	Ref<BinaryBitmap> bitmap(pBitmap);
	bitMap_ = bitmap->getBlackMatrix();
	
	QRCodeReader reader;
	Ref<Result> result;
	try{
		result = reader.decode(bitmap, DecodeHints(DecodeHints::TRYHARDER_HINT));
	}
	catch(const std::exception& e){
		//std::cerr<<e.what()<<std::endl;
		return string();
	}
	Zxingstr_ = result->getText(); 
	return result->getText()->getText();
}