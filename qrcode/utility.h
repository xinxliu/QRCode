#ifndef _UTILITY_H_
#define _UTILITY_H_
#include <vector>
#include <iostream>
#include <string>
#include <zxing/common/BitMatrix.h>
#include <zxing/common/Counted.h>
#include <limits>

using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::endl;
using namespace zxing;

vector<int> charToBits(vector<char>& a);
vector<int> BitMatToBits(Ref<BitMatrix> bits);
void BitMatrixToVector(Ref<BitMatrix> bits,vector<int>& vec);

void printUsage();

std::string cmdParse(int argc, char* argv[]);

#endif // !_UTILITY_H_
