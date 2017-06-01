## [029. Divide Two Integers](https://leetcode.com/problems/divide-two-integers/#/description)
### 题目要求：
Divide two integers without using multiplication, division and mod operator.

If it is overflow, return MAX_INT.
### 我的思路：
商是多少就要多少次循环，很慢，TLE
```c
	int divide(int dividend, int divisor) {
		if (divisor == 0||(divisor == -1 && dividend == INT_MIN)) return INT_MAX;
		int flag = 1, count = 0;
		if (dividend>0 && divisor<0 || dividend<0 && divisor>0) flag = -1;
		int a = abs(dividend), b = abs(divisor);
		while (a - b >= 0) {
			++count;
			a -= b;
		}
		return count*flag;
	}
```
### 推荐思路与解法：
左移除数，即可快速求商，详见[solution](https://discuss.leetcode.com/topic/15568/detailed-explained-8ms-c-solution)
```c
	int divide(int dividend, int divisor) {
		if (!divisor || (dividend == INT_MIN && divisor == -1))
			return INT_MAX;
		int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
		long long dvd = labs(dividend);
		long long dvs = labs(divisor);
		int res = 0;
		while (dvd >= dvs) {
			long long temp = dvs, multiple = 1;
			while (dvd >= (temp << 1)) {
				temp <<= 1;
				multiple <<= 1;
			}
			dvd -= temp;
			res += multiple;
		}
		return sign == 1 ? res : -res;
	}
```
