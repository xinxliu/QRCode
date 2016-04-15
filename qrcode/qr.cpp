#include <opencv2/opencv.hpp>
#include <string>


#include "zxingdecoder.h"
using namespace zxing;
using namespace zxing::multi;
using namespace zxing::qrcode;

void printUsage(){
std::cout << "./qrcode imagename" << std::endl;
}

//parse the cmd
std::string cmdParse(int argc, char* argv[]) {
	if (argc != 2) {
		printUsage();
		return std::string();
	}
	return std::string(argv[1]);

}
int main(int argc,char *argv[]){
	std::string filename = cmdParse(argc, argv);
    cv::Mat image = cv::imread(filename);
	if (image.empty()) {
		std::cout << "cannot find the image" << endl;
		return 0;
	}
    ZxingDecoder zxingdecoder;
    //cv::VideoCapture capture(0);
    //capture >> image;
    std::string str = zxingdecoder.decode(image);
    std::cout << str <<endl;
	while (char(cv::waitKey(1)) != 'q') {};
	return 0;
}
