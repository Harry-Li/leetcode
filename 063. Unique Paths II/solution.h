#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		if (obstacleGrid.empty()) return 0;
		int m = obstacleGrid.size(), n = obstacleGrid[0].size();
		vector<vector<int>>path(m, vector<int>(n, 1));
		int i = 0;
		bool flag = false;
		while (i<n) {
			if (obstacleGrid[0][i] == 1) flag = true;
			if (flag == true) path[0][i] = 0;
			i++;
		}
		i = 0;
		flag = false;
		while (i<m) {
			if (obstacleGrid[i][0] == 1) flag = true;
			if (flag == true) path[i][0] = 0;
			i++;
		}
		for (int i = 1; i<m; i++)
			for (int j = 1; j<n; j++)
				if (obstacleGrid[i][j] == 0)
					path[i][j] = path[i - 1][j] + path[i][j - 1];
				else path[i][j] = 0;
				return path[m - 1][n - 1];
	}
};
