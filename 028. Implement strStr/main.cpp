#include"solution.h"
int main()
{
	Solution sol;
	string haystack, needle;
	cin >> haystack >> needle;
	cout << sol.strStr(haystack, needle) << endl;
	return 0;
}
