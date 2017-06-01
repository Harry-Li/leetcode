## [028. Implement strStr()](https://leetcode.com/problems/implement-strstr/#/description)
### 题目要求：
Implement strStr().

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
### 我的解法：
```c
	int strStr(string haystack, string needle) {
		int len1 = needle.length(), len2 = haystack.length();
		if (len1 == 0) return 0;
		int i = 0, j = 0, k = 0;
		while (j + len1 <= len2) {
			i = 0;
			while (i<len1&&haystack[i + j] == needle[i]) {
				++i;
			}
			if (i == len1) return j;
			++j;
		}
		return -1;
	}
```
### 推荐解法:
这题也可以用[kmp算法](https://discuss.leetcode.com/topic/15569/explained-4ms-easy-c-solution)，
[kmp算法详解](http://blog.csdn.net/yutianzuijin/article/details/11954939/)
