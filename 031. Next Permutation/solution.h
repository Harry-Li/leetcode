#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		if (nums.size()<2) return;
		int i = nums.size() - 1;
		for (; i>0; i--) {
			if (nums[i]>nums[i - 1]) {
				break;
			}
		}
		if (i == 0) {//此时数组中元素从大到小，翻转即可
			reverse(nums.begin(), nums.end());
			return;
		}
		int j = i;
		for (; j<nums.size(); j++) {
			if (nums[i - 1] >= nums[j]) {
				//需要用>=，因为要找最后一个比nums[i-1]大的，即第一个<=它的前面一个，而不是不比它小的前面一个
				break;
			}
		}
		swap(nums[j - 1], nums[i - 1]);
		reverse(nums.begin() + i, nums.end());
		return;
	}
};
