## [058. Length of Last Word](https://leetcode.com/problems/length-of-last-word/#/description)
### 题目要求：
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example, <br>
Given s = "Hello World",<br>
return 5.
### 解法：
先求最后一个不是空格的下标，再往前找第一个是空格的下表，然后相减
```c
	int lengthOfLastWord(string s) {
		auto len = s.length();
		if (len == 0) return 0;
		int a = len - 1;
		while (a >= 0 && s[a] == ' ') --a;
		int b = a;
		while (b >= 0 && s[b] != ' ') --b;
		return a - b;
	}
```
