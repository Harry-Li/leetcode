## [063. Unique Paths II](https://leetcode.com/problems/unique-paths-ii/description/)
### 题目要求：
Follow up for ["Unique Paths"](https://github.com/Harry-Li/leetcode/tree/master/062.%20Unique%20Paths):

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
The total number of unique paths is 2.
### 我的解法：
与上一题相比，边界条件需要修改一下
```c
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
```
### 推荐解法：
还有一些优化的[方法](https://discuss.leetcode.com/topic/15267/4ms-o-n-dp-solution-in-c-with-explanations)
```c
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int> > dp(m + 1, vector<int> (n + 1, 0));
        dp[0][1] = 1;
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
                if (!obstacleGrid[i - 1][j - 1])
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        return dp[m][n];
    } 
```
