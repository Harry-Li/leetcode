## 5. Longest Palindromic Substring
https://leetcode.com/problems/longest-palindromic-substring/#/description
### 题目要求：
求字符串中的最长回文子串。
### 我的思路：
从长到短，从左到右，判断字符串是否是回文字符串，耗时很长。
```c
  bool isPS(string s, int start, int end)
	{
		while (start < end) {
			if (s[start] != s[end]) {
				return false;
			}
			++start, --end;
		}
		return true;
	}
	string longestPalindrome(string s) {
		int len = s.length();
		if (len <= 1) return s;
		while (len > 1) {
			for (int i = 0, j = i + len - 1; j < s.length(); ++i, ++j) {
				if (isPS(s, i, j)) {
					return s.substr(i, len);
				}
			}
			--len;
		}
	}
```
### 推荐思路与解法：
跳过相同的字符，向两边扩展！ "i=K+1"很巧妙
```c
	string longestPalindrome(string s) {
		if (s.size() <= 1) return s;
		int min_start = 0, max_len = 1, i = 0;
		while (true) {
			if (s.size() - i <= (max_len + 1) / 2) break;
			int j = i, k = i;
			while (k < s.size() - 1 && s[k + 1] == s[k]) ++k; // Skip duplicate characters.
			i = k + 1;
			while (k < s.size() - 1 && j > 0 && s[k + 1] == s[j - 1]) { ++k; --j; } // Expand.
			int new_len = k - j + 1;
			if (new_len > max_len) { min_start = j; max_len = new_len; }
		}
		return s.substr(min_start, max_len);
	}
```
