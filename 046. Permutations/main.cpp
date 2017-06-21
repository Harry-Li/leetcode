#include"solution.h"
int main()
{
	Solution sol;
	vector<int>nums = { 1,2,3 };
	vector<vector<int>>res = sol.permute(nums);
	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < nums.size(); j++) {
			cout << res[i][j] << ',';
		}
		cout << "\b " << endl;
	}
	return 0;
}
