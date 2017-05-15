#include<iostream>
#include<limits.h>
using namespace std;
class Solution {
public:
	int reverse(int x) {
		long long ret = 0;
		while (x != 0) {
			ret = ret * 10 + x % 10;
			x /= 10;
		}
		return ret<INT_MIN || ret>INT_MAX ? 0 : ret;
	}
};
