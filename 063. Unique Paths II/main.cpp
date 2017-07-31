#include"solution.h"
int main()
{
	Solution sol;
	vector<vector<int>>obstacleGrid = { { 0,0,0 },{ 0,1,0 },{ 0,0,0 } };
	cout << sol.uniquePathsWithObstacles(obstacleGrid) << endl;
	return 0;
}
