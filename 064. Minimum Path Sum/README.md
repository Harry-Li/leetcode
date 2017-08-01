## [064. Minimum Path Sum](https://leetcode.com/problems/minimum-path-sum/description/)
### 题目要求：
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.
### 我的解法：
典型的DP问题，下面是我的解法，同样可以[优化](https://discuss.leetcode.com/topic/15269/10-lines-28ms-o-n-space-dp-solution-in-c-with-explanations)
```c
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
```
