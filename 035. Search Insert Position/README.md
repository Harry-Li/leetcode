## [035. Search Insert Position](https://leetcode.com/problems/search-insert-position/#/description)
### 题目要求：
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.
### 我的解法：
```c
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
```
