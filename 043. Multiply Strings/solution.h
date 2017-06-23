#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
	string multiply(string num1, string num2) {
		vector<int>num(num1.size()+num2.size(),0);
		for (int i = num1.size() - 1; i >= 0; i--) {
			for (int j = num2.size() - 1; j >= 0; j--) {
				int mul = (num1[i] - '0')*(num2[j] - '0');
				num[i + j] += (mul + num[i + j + 1]) / 10;
				num[i + j + 1] = (mul + num[i + j + 1]) % 10;
			}
		}
		string res;
		for (auto val : num) {
			if (val != 0 || !res.empty())
				res += to_string(val);
		}
		return res.empty() ? "0" : res;
	}
};
