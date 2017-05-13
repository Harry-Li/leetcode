## 3. Longest Substring Without Repeating Characters
https://leetcode.com/problems/longest-substring-without-repeating-characters/#/description
### 题目要求：
求给定字符串中，没有重复字符的最长子串的长度。<br>
例如：<br>
"abcabcbb"长度为3
### 我的思路：
用嵌套的while循环，找出没有重复字符的最长子串。
```c
int lengthOfLongestSubstring(string s) {
	int len = s.size(), length = 0;
	int i = 0, j = 0, k = 0;
	while (i<len) {
		do {
			++j;
			if (i + j<len)
				k = s.substr(i, j).find(s[i + j]);
		} while (k == string::npos&&i + j<len); //如果没有重复，继续向后找
		if (j>length) length = j;
		if (k != string::npos) {//k不为0，即找到了
			i = k + i + 1;
			j = j - k - 1;
		}
		else break;
	}
	return length;
}
```
### 推荐思路与解法：
用vector保存出现过的字符出现的最近位置，如果再次出现，则更新start
```c
int lengthOfLongestSubstring(string s) {
	vector<int> dict(256, -1);
	int maxLen = 0, start = -1;
	for (int i = 0; i != s.length(); i++) {
		if (dict[s[i]] > start)
			start = dict[s[i]];
		dict[s[i]] = i;
		maxLen = max(maxLen, i - start);
	}
	return maxLen;
}
```
空间优化：
```c
int lengthOfLongestSubstring(string s) {
	map<char, int> charMap;  //用map保存位置
	int start = -1;
	int maxLen = 0;
	for (int i = 0; i < s.size(); i++) {
		if (charMap.count(s[i]) != 0) { //如果字符已经出现过
			start = max(start, charMap[s[i]]);
		}
		charMap[s[i]] = i;
		maxLen = max(maxLen, i - start);
	}
	return maxLen;
}
```
要注意上面两种解法的不同，前者是如果当前字符的最近出现位置大于start，则更新start；后者是当前字符出现过，start取出现过的最近位置与start的较大者：两者实际是相同的
