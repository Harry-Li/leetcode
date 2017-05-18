#include"solution.h"
int main()
{
	Solution sol;
	string s;
	cin >> s;
	string subs = sol.longestPalindrome(s);
	cout << subs << endl;
	return 0;
}
