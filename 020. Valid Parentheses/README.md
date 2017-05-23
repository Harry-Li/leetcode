## [020. Valid Parentheses](https://leetcode.com/problems/valid-parentheses/#/description)
### 题目要求：
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.<br>
The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
### 解法：
```c
bool isValid(string s) {
	stack<char> s1;
	for (int i = 0; i<s.length(); i++) {
		switch (s[i]) {
		case ')':if (!s1.empty() && s1.top() == '(') s1.pop(); else return false; break;
		case '}':if (!s1.empty() && s1.top() == '{') s1.pop(); else return false; break;
		case ']':if (!s1.empty() && s1.top() == '[') s1.pop(); else return false; break;
		default:s1.push(s[i]); break;
		}
	}
	if (s1.empty()) return true;
	else return false;
}
```
