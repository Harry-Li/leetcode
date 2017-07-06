## [052. N-Queens II](https://leetcode.com/problems/n-queens-ii/#/description)
### 题目要求：
Follow up for [N-Queens problem](https://github.com/Harry-Li/leetcode/tree/master/051.%20N-Queens).

Now, instead outputting board configurations, return the total number of distinct solutions.
### 我的解法：
```c
	int totalNQueens(int n) {
		vector<int>index;
		int count = 0;
		queens(count, index, n);
		return count;
	}
	void queens(int &count, vector<int>&index, int n) {
		if (index.size() == n) {
			count++;
			return;
		}
		else {
			for (int i = 0; i < n; i++) {
				index.push_back(i);
				if (isvalid(index)) queens(count, index, n);
				index.pop_back();
			}
		}
	}
	bool isvalid(vector<int>& index) {
		int i = index.size() - 1;
		for (int j = i - 1; j >= 0; j--) {
			if (index[i] == index[j] || abs(index[i] - index[j]) == i - j) return false;
		}
		return true;
	}
```
### [其他解法](https://discuss.leetcode.com/category/60/n-queens-ii)
