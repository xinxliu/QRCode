#include <opencv2/opencv.hpp>
#include <string>
#include <iostream>

#include "zxingdecoder.h"
using namespace zxing;

using namespace zxing::qrcode;
using namespace cv;
using std::string;
using std::cout;
using std::cin;
using std::endl;


vector<int> charToBits(vector<char>& a) {
	vector<int> bits(8 * a.size(), 0);
	for (int i = 0; i < a.size(); ++i) {
		for (int j = 0; j < 8; ++j) {
			if (a[i] & (0x01 << j)) {
				bits[8 * i + 7 - j] = 1;
			}
		}
	}
	return bits;
}

void printUsage(){
cout << "./qrcode imagename to parse a qrcode in a image" << endl;
cout << "./qrcode --camera to parse a qrcode through the camera" << endl;
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
	string cmd = cmdParse(argc, argv);
	if (cmd == string("--camera")) {
		VideoCapture capture(0);
		Mat frame;
		namedWindow("QRCode Parser", WINDOW_NORMAL);
		namedWindow("GrayImage",WINDOW_NORMAL);
		while (1) {
			capture >> frame;
			imshow("QRCode Parser", frame);
			ZxingDecoder zxingdecoder;
			string str = zxingdecoder.decode(frame);
			if (str != string()) {
				cout << "The result is a "<<str.size()<<"-long string: " << str << endl;
				zxingdecoder.showGrayImage();
				Mat gray = imread("GrayImage.png");
				imshow("GrayImage",gray);
				//cout<<zxingdecoder.Zxingstr_;
				//cout << zxingdecoder.bitMap_;
				auto rawbytes = zxingdecoder.rawBytes_;
				auto bitstream = charToBits(rawbytes);
				cout << "The bitstream is "<<bitstream.size()<<"-bits: " << endl;
				int count = 0;
				for (auto it = bitstream.begin(); it != bitstream.end(); ++it) {
					cout << *it;
					if (!((count + 1) % 8)) {cout << " ";}
					if (!((count++ + 1) % 64)) {cout<<endl;}
				}
				if(char(waitKey(0)) == 'q'){
					break;
				}
			}

			if (char(waitKey(1)) == 'q') {
				break;
			}
		}
		getchar();
		return 0;
	}
	string filename = cmd;
    Mat image = cv::imread(filename);
	if (image.empty()) {
		cout << "cannot find the image" << endl;
		return 0;
	}
    ZxingDecoder zxingdecoder;
    
    string str = zxingdecoder.decode(image);
    cout << str <<endl;
	return 0;
}
