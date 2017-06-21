#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>>res;
		vector<int>tnums;
		//sort(nums.begin(),nums.end());
		search(res, tnums, nums);
		return res;
	}
	void search(vector<vector<int>>&res, vector<int>&tnums, vector<int>&nums) {
		if (tnums.size() == nums.size()) {
			res.push_back(tnums);
			return;
		}
		else {
			for (int i = 0; i<nums.size(); i++) {
				if (find(tnums.begin(), tnums.end(), nums[i]) != tnums.end()) continue;
				tnums.push_back(nums[i]);
				search(res, tnums, nums);
				tnums.pop_back();
			}
		}
	}
};
