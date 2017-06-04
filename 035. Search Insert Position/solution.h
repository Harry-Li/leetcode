#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		int min = 0, max = nums.size() - 1, mid;
		while (min <= max) {
			mid = (min + max) >> 1;
			if (nums[mid] == target) return mid;
			else if (nums[mid]>target) max = mid - 1;
			else min = mid + 1;
		}
		return min;
	}
};
