## [7. Reverse Integer](https://leetcode.com/problems/reverse-integer/#/description)
### 题目要求：
Reverse digits of an integer.
### 我的思路：
比较容易，不过要注意溢出。
```c
	int reverse(int x) {
		long long ret = 0;
		while (x != 0) {
			ret = ret * 10 + x % 10;
			x /= 10;
		}
		return ret<INT_MIN || ret>INT_MAX ? 0 : ret;
	}
```
