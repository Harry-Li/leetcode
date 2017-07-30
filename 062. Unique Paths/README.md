## [062. Unique Paths](https://leetcode.com/problems/unique-paths/description/)
### 题目要求：
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?

Note: m and n will be at most 100.
### 推荐解法：
这是一个基础的动态规划问题，下面这种方法时间复杂度和空间复杂度均为O(m*n),可以进一步讲空间复杂度减小为O(min(m, n))，[详细解释](https://discuss.leetcode.com/topic/15265/0ms-5-lines-dp-solution-in-c-with-explanations?page=1)。除此之外，还可以用一些数学方法解决。
```c
	int uniquePaths(int m, int n) {
		vector<vector<int>>path(m, vector<int>(n, 1));
		for (int i = 1; i<m; i++)
			for (int j = 1; j<n; j++)
				path[i][j] = path[i][j - 1] + path[i - 1][j];
		return path[m - 1][n - 1];
	}
```
