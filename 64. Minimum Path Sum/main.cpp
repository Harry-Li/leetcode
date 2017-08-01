#include"solution.h"
int main()
{
	Solution sol;
	vector<vector<int>>grid = { {1,2},{1,1} };
	cout << sol.minPathSum(grid) << endl;
	return 0;
}
