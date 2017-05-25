#include"solution.h"
int main()
{
	Solution sol;
	int n;
	cin >> n;
	vector<string> ans = sol.generateParenthesis(n);
	for (auto s : ans) {
		cout << s << endl;
	}
	return 0;
}
