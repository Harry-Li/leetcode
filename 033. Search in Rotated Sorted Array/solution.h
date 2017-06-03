#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	int search(vector<int>& nums, int target) {
		if (nums.size() == 0) return -1;
		int min = 0, max = nums.size() - 1, mid;
		while (min<max) {
			mid = (min + max) / 2;
			if (target == nums[mid]) return mid;

			if (nums[mid] >= nums[min]) {
				if (target >= nums[min] && target<nums[mid]) max = mid - 1;
				else min = mid + 1;
			}
			else {
				if (target>nums[mid] && target <= nums[max]) min = mid + 1;
				else max = mid - 1;
			}
		}
		if (nums[min] == target) return min;
		return -1;
	}
};
