#include<iostream>
using namespace std;
class Solution {
public:
	double myPow(double x, int n) {
		if (n == INT_MIN) return 1 / myPow(x, -(n + 1)) / x;
		if (n<0) return 1 / myPow(x, -n);
		if (n == 0) return 1;
		if (n == 1) return x;
		//double x2 = myPow(x, n >> 1);
		//return x2*x2*myPow(x, n % 2);
    return myPow(x*x,n>>1)*myPow(x,n%2);
	}
};
