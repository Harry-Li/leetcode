## [042. Trapping Rain Water](https://leetcode.com/problems/trapping-rain-water/#/description)
### 题目要求：
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

For example, <br>
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
### 解法一：
```c
	int trap(vector<int>& height) {
		int l = 0, r = height.size() - 1, leftmax = 0, rightmax = 0, sum = 0;
		while (l < r) {
			if (height[l] < height[r]) {
				if (height[l] >= leftmax) leftmax = height[l];
				else sum += leftmax - height[l];
				l++;
			}
			else {
				if (height[r] >= rightmax) rightmax = height[r];
				else sum += rightmax - height[r];
				r--;
			}
		}
		return sum;
	}
```
### 解法二：
更为简洁
```c
int trap(vector<int>& height) {
    auto l = height.begin(), r = height.end() - 1;
    int level = 0, water = 0;
    while (l != r + 1) {
        int lower = *l < *r ? *l++ : *r--;
        level = max(level, lower);
        water += level - lower;
    }
    return water;
}
```
或
```c
int trap(vector<int>& height) {
    int l = 0, r = height.size()-1, level = 0, water = 0;
    while (l < r) {
        int lower = height[height[l] < height[r] ? l++ : r--];
        level = max(level, lower);
        water += level - lower;
    }
    return water;
}
```
