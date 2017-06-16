## [041. First Missing Positive](https://leetcode.com/problems/first-missing-positive/#/description)
### 题目要求：
Given an unsorted integer array, find the first missing positive integer.

For example,<br>
Given [1,2,0] return 3,<br>
and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space.
### 解法：
第i轮循环，把nums[i]放到正确的位置上（如果有位置），例如，nums[2]=5,如果把nums[2]与nums[4]进行交换；最后遍历，若某个位置没有出现正确元素，则该位置应该对应的元素即为所求。
```c
	int firstMissingPositive(vector<int>& nums) {
		int size = nums.size();
		for (int i = 0; i<size; i++) {
			while (nums[i]>0 && nums[i]<size&&nums[i]!=nums[nums[i]-1]) {
				swap(nums[i], nums[nums[i] - 1]);
			}
		}
		int i = 0;
		for (; i<size; i++) {
			if (nums[i] != i + 1) break;
		}
		return i + 1;
	}
```
