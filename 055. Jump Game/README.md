## [055. Jump Game](https://leetcode.com/problems/jump-game/#/description)
### 题目要求：
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false.
### 解法一：
这题方法很多，但是最好应该要达到O(n)的时间复杂度，否则会超时
```c
	bool canJump(vector<int>& nums) {
		int maxpos = 0;
		for (int i = 0; i<nums.size(); i++) {
			if (i>maxpos) return false;
			if (i + nums[i]>maxpos) maxpos = i + nums[i];
			if (maxpos >= nums.size() - 1) break;
		}
		return true;
	}
```
### 其他解法：
下面这个方法也不错，官方解答：https://leetcode.com/problems/jump-game/#/solution
```c
bool canJump(int A[], int n) {
    int i = 0;
    for (int reach = 0; i < n && i <= reach; ++i)
        reach = max(i + A[i], reach);
    return i == n;
}
```

