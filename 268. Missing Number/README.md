## [268. Missing Number](https://leetcode.com/problems/missing-number/#/description)
### 题目要求：
Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

For example,
Given nums = [0, 1, 3] return 2.（不一定有序）

Note:
Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?
### 解法一：
求和
```c
	int missingNumber(vector<int>& nums) {
		int size = nums.size();
		long sum = 0;
		for (int i = 0; i<size; i++) {
			sum += i - nums[i];
		}
		return sum + size;
	}
```
### 解法二：
异或
```c
	int missingNumber(vector<int>& nums) {
		int res = nums.size();
		for (int i = 0; i < nums.size(); i++) {
			res ^= i^nums[i];
		}
		return res;
	}
```
### 解法三：
交换，不太好理解
```c
	int missingNumber(vector<int>& nums) {
		int missing = nums.size();
		for (int i = 0; i<nums.size(); i++) {
			while (nums[i] != i) {
				if (nums[i] != nums.size())
					swap(nums[i], nums[nums[i]]);
				else {
					missing = i;
					break;
				}
			}
		}
		return missing;
	}
```
###解法四：
在有序的情况下可以用二分查找，否则不满足线性复杂度。
