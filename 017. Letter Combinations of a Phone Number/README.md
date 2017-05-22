## [017. Letter Combinations of a Phone Number](https://leetcode.com/problems/letter-combinations-of-a-phone-number/#/description)
对比一下[001. Two Sum](https://github.com/Harry-Li/leetcode/tree/master/001.%20Two%20Sum)
### 题目要求：
Given a digit string, return all possible letter combinations that the number could represent.
### 解法：
可以使用[swap()函数](https://discuss.leetcode.com/topic/17262/iterative-c-solution-in-0ms)
```c
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
```
