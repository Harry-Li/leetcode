## [039. Combination Sum](https://leetcode.com/problems/count-and-say/#/description)
### 题目要求：
Given a set of candidate numbers (C) (without duplicates) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.
### 解法一：
迭代
```c
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end());
		vector<vector<int>>res;
		vector<int>combination;
		search(res, combination, candidates, target, 0);
		return res;
	}
	void search(vector<vector<int>>& res, vector<int>& combination, vector<int>& candidates, int target, int k) {
		if (target == 0) {
			res.push_back(combination);
			return;
		}
		for (int i = k; i<candidates.size() && candidates[i] <= target; i++) {
			combination.push_back(candidates[i]);
			search(res, combination, candidates, target - candidates[i], i);
			combination.pop_back();
		}
	}
```
### 解法二：
动态规划
```c
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		//vector<vector<int>> result;
		int size = candidates.size();
		//if (size == 0) return result;
		sort(candidates.begin(), candidates.end());
		vector<vector<vector<int>>> dp(target + 1, vector<vector<int>>());
		dp[0].push_back(vector<int>());

		for (int i = 1; i <= target; ++i) {
			for (int j = 0; j < size && candidates[j] <= i; ++j) {
				for (int k = 0; k < dp[i - candidates[j]].size(); ++k) {
					vector<int> temp = dp[i - candidates[j]][k];
					if (temp.size() && (temp[temp.size() - 1] > candidates[j])) continue;
					temp.push_back(candidates[j]);
					dp[i].push_back(temp);
				}
			}
		}
		return dp[target];
	}
```
两种方法都要好好理解！
