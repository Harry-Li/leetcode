#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
	vector<string> letterCombinations(string digits) {
		int len = digits.length();
		vector<string> ret;
		if (len == 0) return ret;
		ret.push_back("");
		vector<string> str = { "0","1","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
		for (int i = 0; i < len; i++) {
			vector<string> temp;
			string chars = str[digits[i] - '0'];
			for(int j=0;j<chars.length();j++)
				for (int k=0; k < ret.size(); k++) {
					temp.push_back(ret[k] + chars[j]);
				}
			ret = temp;
		}
		return ret;
	}
};
