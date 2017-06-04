## [034. Search for a Range](https://leetcode.com/problems/search-in-rotated-sorted-array/#/description)
### 题目要求：
Given an array of integers sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].
### 我的解法：
用三个二分查找，第一次找等于target的，然后分为左右两个序列，再找左边第一个target和右边最后一个target
```c
	vector<int> searchRange(vector<int>& nums, int target) {
		int min = 0, max = nums.size() - 1, mid, midx, midl, midr;
		while (min <= max) {
			mid = (min + max) >> 1;
			if (nums[mid] == target) {
				midx = mid;
				while (min<mid) {
					midl = (min + mid) >> 1;
					if (nums[midl] == target) mid = midl;
					else min = midl + 1;
				}
				while (midx<max) {
					midr = (midx + max + 1) >> 1;
					if (nums[midr] == target) midx = midr;
					else max = midr - 1;
				}				
				return{ mid,midx };
			}
			else if (nums[mid]<target) min = mid + 1;
			else max = mid - 1;
		}
		return {-1, -1};
	}

```
### 解法二：
用两个二分查找，分别查找第一个target和最后一个target
```c
	vector<int> searchRange(vector<int>& nums, int target) {
		if (nums.empty()) return{ -1,-1 };
		vector<int>ans;
		int i = 0, j = nums.size() - 1, mid;
		while (i < j) {
			mid = (i + j) >> 1;
			if (nums[mid] < target) i = mid + 1;
			else j = mid;
		}
		if (nums[i] == target) ans.push_back(i);
		else return{ -1,-1 };
		j = nums.size() - 1;
		while (i < j) {
			mid = (i + j + 1) >> 1;
			if (nums[mid] > target) j = mid - 1;
			else i = mid;
		}
		ans.push_back(j);
		return ans;
	}
```
