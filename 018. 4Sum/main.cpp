#include"solution.h"
int main()
{
	Solution sol;
	vector<int> nums = { 1, 0, -1, 0, -2, 2 };
	vector<vector<int>> ans = sol.fourSum(nums, 0);
	for (int i = 0; i < ans.size(); i++) {
		cout << '[';
		for (int j = 0; j < ans[i].size(); j++) {
			cout << ans[i][j] << ',';
		}
		cout << "\b]" << endl;
	}
	return 0;
}
