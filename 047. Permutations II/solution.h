#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		vector<vector<int>>res;
		vector<int>tnums;
		vector<bool>used(nums.size(),false);
		sort(nums.begin(),nums.end());
		search(res, tnums, nums,used);
		return res;
	}
	void search(vector<vector<int>>&res, vector<int>&tnums, vector<int>&nums,vector<bool>&used) {
		if (tnums.size() == nums.size()) {
			res.push_back(tnums);
			//return;
		}
		else {
			for (int i = 0; i<nums.size(); i++) {
				if (used[i]||i>0&&nums[i]==nums[i-1]&&!used[i-1]) continue;
				used[i] = true;
				tnums.push_back(nums[i]);
				search(res, tnums, nums,used);
				used[i] = false;
				tnums.pop_back();
			}
		}
	}
};
