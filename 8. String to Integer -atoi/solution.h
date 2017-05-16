#include<iostream>
#include<string>
#include<limits.h>
using namespace std;
class Solution {
public:
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
			if (str[i] >= '0'&&str[i] <= '9') {
				if (ret>INT_MAX / 10 || ret == INT_MAX / 10 && str[i]>'7') return flag>0 ? INT_MAX : INT_MIN;
				ret = ret * 10 + str[i] - '0';
			}
			else return flag*ret;
			++i;
		}
		return flag*ret;
	}
};
