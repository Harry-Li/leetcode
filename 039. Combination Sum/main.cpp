#include"solution.h"
int main()
{
	Solution sol;
	vector<int>candidates{ 2,3,6,7 };
	vector<vector<int>>res = sol.combinationSum(candidates, 7);
	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[i].size(); j++) {
			cout << res[i][j] << ',';
		}
		cout << "\b " << endl;
	}
	return 0;
}
