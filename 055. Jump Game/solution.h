#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	bool canJump(vector<int>& nums) {
		int maxpos = 0;
		for (int i = 0; i<nums.size(); i++) {
			if (i>maxpos) return false;
			if (i + nums[i]>maxpos) maxpos = i + nums[i];
			if (maxpos >= nums.size() - 1) break;
		}
		return true;
	}
};
