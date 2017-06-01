## [026. Remove Duplicates from Sorted Array](https://leetcode.com/problems/remove-duplicates-from-sorted-array/#/description)
### 题目要求：
Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

For example,
Given input array nums = [1,1,2],

Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively. It doesn't matter what you leave beyond the new length.
### 解法：
```c
	int removeDuplicates(vector<int>& nums) {
		if (nums.empty()) return 0;
		int i = 1;
		for (int j = 1; j<nums.size(); j++) {
			if (nums[j] != nums[j - 1]) {
				nums[i++] = nums[j];
			}
		}
		return i;
	}
```
