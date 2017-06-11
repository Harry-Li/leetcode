#include"solution.h"
int main()
{
	Solution sol;
	vector<int>candidates{ 10, 1, 2, 7, 6, 1, 5 };
	vector<vector<int>>res = sol.combinationSum2(candidates, 8);
	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[i].size(); j++) {
			cout << res[i][j] << ',';
		}
		cout << "\b " << endl;
	}
	return 0;
}
