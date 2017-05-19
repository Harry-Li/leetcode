#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		int num = strs.size();
		if (num == 0) return "";
		if (num == 1) return strs[0];
		int i = 0;
		while (true) {
			for (int j = 0; j<num - 1; j++) {
				if (strs[j].size()<i || strs[j + 1].size()<i || strs[j][i] != strs[j + 1][i]) return strs[0].substr(0, i);
			}
			++i;
		}
	}
};
