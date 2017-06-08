#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
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
};
	//vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
	//	vector<vector<int>> result;
	//	int size = candidates.size();
	//	if (size == 0) return result;
	//	sort(candidates.begin(), candidates.end());
	//	vector<vector<vector<int>>> dp(target + 1, vector<vector<int>>());
	//	dp[0].push_back(vector<int>());

	//	for (int i = 1; i <= target; ++i) {
	//		for (int j = 0; j < size && candidates[j] <= i; ++j) {
	//			for (int k = 0; k < dp[i - candidates[j]].size(); ++k) {
	//				vector<int> temp = dp[i - candidates[j]][k];
	//				if (temp.size() && (temp[temp.size() - 1] > candidates[j])) continue;
	//				temp.push_back(candidates[j]);
	//				dp[i].push_back(temp);
	//			}
	//		}
	//	}
	//	return dp[target];
	//}
