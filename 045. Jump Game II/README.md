## [045. Jump Game II](https://leetcode.com/problems/jump-game-ii/#/description)
### 题目要求：
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

For example:
Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)

Note:
You can assume that you can always reach the last index.
### 超时解法：
逆推，计算每个位置到最后一个位置所需的最小步数，但是无法达到线性的时间复杂度
```c
	int jump(vector<int>& nums) {
		if (nums.size() <= 1) return 0;
		vector<long long>steps(nums.size(), INT_MAX);
		for (int i = nums.size() - 2; i >= 0; i--) {
			if (i + nums[i] >= nums.size() - 1) steps[i] = 1;
			else steps[i] = 1 + *min_element(steps.begin() + i, steps.begin() + i + nums[i] + 1);
		}
		return steps[0];
	}
```
### 推荐解法：
判断从第一个位置开始，每一步最多走到哪里，时间复杂度O(n)
```c
	int jump(vector<int>& nums) {
		if (nums.size() <= 1) return 0;
		int step = 0, curpos = 0, nextpos = 0;
		for (int i = 0; i <= nums.size() - 2; i++) {
			if (i + nums[i] > curpos) {
				curpos = i + nums[i];
			}
			if (i == nextpos) {
				nextpos = curpos;
				step++;
			}
		}
		return step;
	}
```


