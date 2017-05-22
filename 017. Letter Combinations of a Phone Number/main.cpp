#include"solution.h"
int main()
{
	Solution sol;
	string digits;
	cin >> digits;
	vector<string> ans = sol.letterCombinations(digits);
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << ' ';
	cout << endl;
	return 0;
}
