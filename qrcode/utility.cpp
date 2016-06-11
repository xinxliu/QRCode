#include "utility.h"

const int bitOfInt = std::numeric_limits<unsigned int>::digits;
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

vector<int> BitMatToBits(Ref<BitMatrix> bits){
	vector<int> vec;
	BitMatrixToVector(bits, vec);
	vector<int> bitStream(bitOfInt*vec.size(), 0);
	for (int i = 0; i < vec.size(); ++i) {
		for (int j = 0; j < bitOfInt; ++j) {
			if (vec[i] & (1 << j)) {
				bitStream[bitOfInt * i + bitOfInt - 1 - j] = 1;
			}
		}
	}
	return bitStream;
}

void BitMatrixToVector(Ref<BitMatrix> bits,vector<int>& vec)
{
	int height = bits->getHeight();
	for (int i = 0; i < height; ++i) {
		Ref<BitArray> row;
		row = bits->getRow(i, row);
		auto temp = row->getBitArray();
		vec.insert(vec.end(), temp.begin(), temp.end());
	}
}

void printUsage() {
	cout << "./qrcode imagename to parse a qrcode in a image" << endl;
	cout << "./qrcode --camera to parse a qrcode through the camera" << endl;
}

std::string cmdParse(int argc, char* argv[]) {
	if (argc != 2) {
		printUsage();
		return std::string();
	}
	return std::string(argv[1]);
}