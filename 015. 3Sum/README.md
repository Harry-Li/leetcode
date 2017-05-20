## [015. 3Sum](https://leetcode.com/problems/3sum/#/description)
### 题目要求：
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
### 解法：
时间复杂度O(n^2)
```c
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> ret;
		int size = nums.size();
		if (size < 3) return ret;
		sort(nums.begin(), nums.end());
		int i = 0, j = 1, k = size - 1;
		while (i <= size - 3 && nums[i] + 2 * nums[j] <= 0) {
			while (j<k) {
				if (nums[i] + nums[j] + nums[k] == 0) {
					ret.push_back(vector<int>{nums[i], nums[j], nums[k]});
					while (j<k&&nums[j] == nums[j + 1]) ++j;
					++j;
					while (j<k&&nums[k] == nums[k - 1]) --k;
					--k;
				}
				else if (nums[i] + nums[j] + nums[k] < 0) ++j;
				else if (nums[i] + nums[j] + nums[k] > 0) --k;
			}
			while (i <= size - 2 && nums[i] == nums[i + 1]) ++i;
			++i;
			j = i + 1;//注意while循环条件，这句要放这里
			k = size - 1;//可以放前面
		}
		return ret;
	}
```
