## [014. Longest Common Prefix](https://leetcode.com/problems/longest-common-prefix/#/description)
### 题目要求：
Write a function to find the longest common prefix string amongst an array of strings.
### 我的思路：
while循环中，i表示所有string中的第i个字符，for循环中j表示第j个string
```c
	string longestCommonPrefix(vector<string>& strs) {
		int num = strs.size();
		if (num == 0) return "";
		if (num == 1) return strs[0];
		int i = 0;
		while (true) {
			for (int j = 0; j<num - 1; j++) {
				if (strs[j].size()<i || strs[j + 1].size()<i || strs[j][i] != strs[j + 1][i]) 
					return strs[0].substr(0, i);
			}
			++i;
		}
	}
```
