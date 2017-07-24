## [053. Maximum Subarray](https://leetcode.com/problems/maximum-subarray/#/description)
### 题目要求：
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [-2,1,-3,4,-1,2,1,-5,4],<br>
the contiguous subarray [4,-1,2,1] has the largest sum = 6.

More practice:<br>
If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
### 解法一：
最优化问题，可以使用动态规划，[详细解释](https://discuss.leetcode.com/topic/6413/dp-solution-some-thoughts)
```c
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
```
### 解法二：
分而治之的办法 
[1](https://github.com/pezy/LeetCode/blob/master/014.%20Maximum%20Subarray/divide_conquer.h)
[2](https://discuss.leetcode.com/category/61/maximum-subarray)

