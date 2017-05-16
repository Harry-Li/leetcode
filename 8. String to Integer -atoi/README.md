## [8. String to Integer (atoi)](https://leetcode.com/problems/string-to-integer-atoi/#/description)
### 题目要求：
Implement atoi to convert a string to an integer.
### 我的思路：
这题比较无聊。。
```c
	int myAtoi(string str) {
		int len = str.length();
		if (len == 0) return 0;
		int ret = 0;
		int flag = 1, i = 0;
		while (str[i] == ' ') i++;
		if (str[i] == '+' || str[i] == '-') {
			if (str[i] == '-') flag = -1;
			i++;
		}
		while (i<len) {
			if (str[i] >= '0'&&str[i] <= '9') {   //-2147483648 2147483647
				if (ret>INT_MAX / 10 || ret == INT_MAX / 10 && str[i]>'7') return flag>0 ? INT_MAX : INT_MIN;
				ret = ret * 10 + str[i] - '0';
			}
			else return flag*ret;
			++i;
		}
		return flag*ret;
	}
```
另一种方法，修改了while循环中的if语句，同时ret要用long，不能用int了。
```c
int myAtoi(string str) {
		int len = str.length();
		if (len == 0) return 0;
		long long ret = 0;
		int flag = 1, i = 0;
		while (str[i] == ' ') i++;
		if (str[i] == '+' || str[i] == '-') {
			if (str[i] == '-') flag = -1;
			i++;
		}
		while (i<len) {
			if (str[i] >= '0'&&str[i] <= '9') {
				ret = ret * 10 + str[i] - '0';
				if (flag*ret < INT_MIN) return INT_MIN;//-2147483648
				if (flag*ret > INT_MAX) return INT_MAX;// 2147483647
			}
			else return flag*ret;
			++i;
		}
		return flag*ret;
	}
```
