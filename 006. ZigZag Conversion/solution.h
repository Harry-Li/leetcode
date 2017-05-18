#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
	string convert(string s, int numRows) {
		if (numRows <= 1) return s;
		int len = s.length();
		string res = "";
		for (int i = 0; i<numRows; i++) {
			for (int j = 0; i + 2 * (numRows - 1)*j <= len - 1; j++) {
				res += s[i + 2 * (numRows - 1)*j];
				if (i > 0 && i < numRows - 1 && 2 * (numRows - 1)*(j + 1) - i <= len - 1) {
					res += s[2 * (numRows - 1)*(j + 1) - i]; //非首行和末行
				}
			}
		}
		return res;
	}
};
