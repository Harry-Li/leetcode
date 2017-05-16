## [9. Palindrome Number](https://leetcode.com/problems/palindrome-number/#/description)
对比一下[7. Reverse Integer](https://github.com/Harry-Li/leetcode/tree/master/7.%20Reverse%20Integer)
### 题目要求：
Determine whether an integer is a palindrome. Do this without extra space.
### 我的思路：
实际rev可定义为int，溢出的时候肯定不相等了。
```c
	bool isPalindrome(int x) {
		if (x<0) return false;
		long long rev = 0;
		int x1 = x;
		while (x1) {
			rev = rev * 10 + x1 % 10;
			x1 /= 10;
		}
		return rev == x;
	}
```
### 推荐思路与解法：
只要翻转一半，但是要注意x=123210这种情况，需要做特殊处理。
```c
	bool isPalindrome(int x) {
		if (x<0 || (x != 0 && x % 10 == 0)) return false;
		int rev = 0;
		while (rev<x) {
			rev = rev * 10 + x % 10;
			x /= 10;
		}
		return rev == x || x == rev / 10;
	}
```
