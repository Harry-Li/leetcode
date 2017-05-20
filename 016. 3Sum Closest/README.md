## [016. 3Sum Closest](https://leetcode.com/problems/3sum-closest/#/description)
对比一下[001. Two Sum](https://github.com/Harry-Li/leetcode/tree/master/001.%20Two%20Sum)
### 题目要求：
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.
### 解法：
时间复杂度O(n^2),abs函数求绝对值
```c
	int threeSumClosest(vector<int>& nums, int target) {
		int size = nums.size();
		assert(size >= 3);
		sort(nums.begin(), nums.end());
		int ret = nums[0] + nums[1] + nums[2], sum;
		int i = 0, j = 1, k = size - 1;
		while (i <= size - 3 && nums[i] + 2 * nums[j] <= target) {
			while (j<k) {
				sum = nums[i] + nums[j] + nums[k];
				if (abs(ret - target)>abs(sum - target)) {
					ret = sum;
					if (ret == target) return ret;
				}
				sum<target ? ++j : --k;
			}
			while (i <= size - 2 && nums[i] == nums[i + 1]) ++i;
			++i;
			j = i + 1;
			k = size - 1;
		}
		return ret;
	}
```
