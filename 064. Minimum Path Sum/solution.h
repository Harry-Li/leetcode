#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		if (grid.empty()) return 0;
		int m = grid.size(), n = grid[0].size();
		vector<vector<int>>dp = grid;
		for (int i = 0; i<m; i++)
			for (int j = 0; j<n; j++)
				if (i == 0 && j == 0) dp[i][i] = grid[i][j];
				else if (i == 0 && j>0) dp[i][j] += dp[i][j - 1];
				else if (i>0 && j == 0) dp[i][j] += dp[i - 1][j];
				else dp[i][j] += min(dp[i - 1][j], dp[i][j - 1]);
		return dp[m - 1][n - 1];
	}
};
