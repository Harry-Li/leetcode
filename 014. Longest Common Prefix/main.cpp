#include"solution.h"
int main()
{
	Solution sol;
	vector<string> strs;
	string str;
	while (cin >> str) {
		strs.push_back(str);
	}
	cout << sol.longestCommonPrefix(strs) << endl;
	return 0;
}
