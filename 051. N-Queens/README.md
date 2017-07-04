## [051. N-Queens](https://leetcode.com/problems/n-queens/#/description)
### 题目要求：
The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

For example,<br>
There exist two distinct solutions to the 4-queens puzzle:

[
 [".Q..",
  "...Q",
  "Q...",
  "..Q."],// Solution 1

 ["..Q.",
  "Q...",
  "...Q",
  ".Q.."]// Solution 2
]
### 我的解法：
n皇后问题，按要求输出
```c
	vector<vector<string>> solveNQueens(int n) {
		vector<vector<int>>sol;
		vector<int>index;
		queens(sol, index, n);
		//vector<string>str(n,string(n,'.'));
		//vector<vector<string>>res(sol.size(),str);
		vector<vector<string>>res(sol.size(), vector<string>(n, string(n, '.')));
		for (int i = 0; i < sol.size(); i++) {
			for (int j = 0; j < n; j++) {
				res[i][j][sol[i][j]] = 'Q';
			}
		}
		return res;
	}
	void queens(vector<vector<int>> &sol, vector<int>&index, int n) {
		if (index.size() == n) {
			sol.push_back(index);
			return;
		}
		else {
			for (int i = 0; i < n; i++) {
				index.push_back(i);
				if (isvalid(index)) queens(sol, index, n);
				index.pop_back();
			}
		}
	}
	bool isvalid(vector<int>& index) {
		int i = index.size() - 1;
		for (int j = i - 1; j >= 0; j--) {
			if (index[i] == index[j] || (index[i] - index[j]) == i - j || (index[i] - index[j]) == j - i) return false;
		}
		return true;
	}
```
### [其他解法](https://discuss.leetcode.com/category/59)

