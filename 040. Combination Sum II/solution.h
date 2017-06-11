#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
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
			if (i > k&& candidates[i] == candidates[i - 1]) continue;
			//if (i == begin || candidates[i] != candidates[i - 1]) {
			combination.push_back(candidates[i]);
			search(res, combination, candidates, target - candidates[i], i+1);
			combination.pop_back();
			//}
		}
	}
};
