#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int size = nums.size();
		if (size == 0) return 0;
		int max = nums[0], cur = nums[0];
		for (int i = 1; i < size; i++) {
			if (cur <= 0) cur = nums[i];
			else cur += nums[i];
			if (cur > max) max = cur;
		}
		return max;
	}
};
