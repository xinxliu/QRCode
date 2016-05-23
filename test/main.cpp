#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main() {
	vector<char> a = { 'a','b','c' };
	vector<bool> bits(8 * a.size(), 0);
	for (int i = 0; i < a.size(); ++i) {
		for (int j = 0; j < 8; ++j) {
			if (a[i] & (0x01 << j)) {
				bits[8 * i + 7 - j] = 1;
				
			}
		}
	}
	
	for (int i = 0; i < bits.size(); ++i) {
		cout << bits[i];
	}
	getchar();
	return 0;
}