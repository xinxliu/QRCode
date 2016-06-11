#include <opencv2/opencv.hpp>
#include <string>
#include <iostream>

#include "QRCodeDecoder.h"
#include "utility.h"
using namespace zxing;

using namespace zxing::qrcode;
using namespace cv;
using namespace std; 
using xQRCodeDecoder::QRCodeDecoder;


int main(int argc,char *argv[]){
	string cmd = cmdParse(argc, argv);
	if (cmd == string("--camera")) {
		VideoCapture capture(0);
		Mat frame;
		//initialize the result
		namedWindow("QRCode Parser", WINDOW_NORMAL);
		namedWindow("GrayImage",WINDOW_NORMAL);
		namedWindow("Binarized Image", WINDOW_NORMAL);
		while (1) {
			capture >> frame;
			imshow("QRCode Parser", frame);
			QRCodeDecoder zxingdecoder;
			string str = zxingdecoder.decode(frame);

			if (str != string()) {
				
				//show the gray image
				Mat gray = zxingdecoder.gray_;
				imshow("GrayImage",gray);
				//show the binarized image
				auto bina = gray.clone();
				int blackPoint = zxingdecoder.BlackPoint_;
				for (int i = 0; i < bina.rows; ++i) {
					for (int j = 0; j < bina.cols; ++j) {
						bina.at<uchar>(i, j) = bina.at<uchar>(i, j)>blackPoint ? 255 : 0;
					}
				}
				imshow("Binarized Image", bina);
				//show the orignal bitstream
				auto bits = zxingdecoder.bits_;
				auto oriBitstream = BitMatToBits(bits);
				cout << "The original bitstream is " << oriBitstream.size() << "-bits: " << endl;
				int count = 0;
				for (auto it = oriBitstream.begin(); it != oriBitstream.end(); ++it) {
					cout << *it;
					if (!((count + 1) % 8)) { cout << " "; }
					if (!((count++ + 1) % 64)) { cout << endl; }
				}
				//show the rawbytes
				auto rawbytes = zxingdecoder.rawBytes_;
				auto bitstream = charToBits(rawbytes);
				cout << "The bitstream is "<<bitstream.size()<<"-bits: " << endl;
				count = 0;
				for (auto it = bitstream.begin(); it != bitstream.end(); ++it) {
					cout << *it;
					if (!((count + 1) % 8)) {cout << " ";}
					if (!((count++ + 1) % 64)) {cout<<endl;}
				}
				//show the result string
				cout << "The result is a " << str.size() << "-character(s) string: " << str << endl;
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
    QRCodeDecoder zxingdecoder;
    string str = zxingdecoder.decode(image);
	//original bitstream
	auto bits = zxingdecoder.bits_;
	auto oriBitstream = BitMatToBits(bits);
	cout << "The original bitstream is " << oriBitstream.size() << "-bits: " << endl;
	int count = 0;
	for (auto it = oriBitstream.begin(); it != oriBitstream.end(); ++it) {
		cout << *it;
		if (!((count + 1) % 8)) { cout << " "; }
		if (!((count++ + 1) % 64)) { cout << endl; }
	}
	//rawBytes
	auto rawbytes = zxingdecoder.rawBytes_;
	auto bitstream = charToBits(rawbytes);
	cout << "The bitstream is " << bitstream.size() << "-bits: " << endl;
	count = 0;
	for (auto it = bitstream.begin(); it != bitstream.end(); ++it) {
		cout << *it;
		if (!((count + 1) % 8)) { cout << " "; }
		if (!((count++ + 1) % 64)) { cout << endl; }
	}
	cout << endl;
    cout << str <<endl;
	getchar();
	return 0;
}
