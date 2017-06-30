## [050. Pow(x, n)](https://leetcode.com/problems/powx-n/#/description)
### 题目要求：
Implement pow(x, n).
### 解法：
```c
	double myPow(double x, int n) {
		if (n == INT_MIN) return 1 / myPow(x, -(n + 1)) / x;
		if (n<0) return 1 / myPow(x, -n);
		if (n == 0) return 1;
		if (n == 1) return x;
		//double x2 = myPow(x, n >> 1);
		//return x2*x2*myPow(x, n % 2);
		return myPow(x*x,n>>1)*myPow(x,n%2);
	}
```
