## [040. Combination Sum II](https://leetcode.com/problems/combination-sum-ii/#/description)
### 题目要求：
Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

与[039. Combination Sum](https://leetcode.com/problems/count-and-say/#/description)相比，区别在于39的数组没有重复元素，一个元素可以用多次，而本题有重复元素，但是每个元素只能用一次，注意比较。
### 解法：
[回溯](https://discuss.leetcode.com/topic/14654/accepted-16ms-c-solution-use-backtracking-easy-understand)
```c
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
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
			if (i > k&& candidates[i] == candidates[i - 1]) continue;//两种判断都可以
			//if (i == begin || candidates[i] != candidates[i - 1]) {
			combination.push_back(candidates[i]);
			search(res, combination, candidates, target - candidates[i], i+1);
			combination.pop_back();
			//}
		}
	}
```
