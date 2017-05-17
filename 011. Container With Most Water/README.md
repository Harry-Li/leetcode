## [11. Container With Most Water](https://leetcode.com/problems/container-with-most-water/#/description)
### 题目要求：
最大水容器
### 我的思路：
```c
	int maxArea(vector<int>& height) {
		if (height.size()<2) return 0;
		int maxarea = 0, i = 0, j = height.size() - 1;
		while (i<j) {
			if (height[i]<height[j]) {
				maxarea = max(maxarea, (j - i)*height[i]);
				++i;
			}
			else {
				maxarea = max(maxarea, (j - i)*height[j]);
				--j;
			}
		}
		return maxarea;
	}
```
### 推荐思路与解法：
值得学习
```c
int maxArea(vector<int>& height) {
    int water = 0;
    int i = 0, j = height.size() - 1;
    while (i < j) {
        int h = min(height[i], height[j]);
        water = max(water, (j - i) * h);
        while (height[i] <= h && i < j) i++;
        while (height[j] <= h && i < j) j--;
    }
    return water;
}
```
