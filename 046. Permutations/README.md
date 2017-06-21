## [046. Permutations](https://leetcode.com/problems/permutations/#/description)
### 题目要求：
Given a collection of distinct numbers, return all possible permutations.

For example,<br>
[1,2,3] have the following permutations:<br>
[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
### 解法一：
[回溯](https://discuss.leetcode.com/topic/46162/a-general-approach-to-backtracking-questions-in-java-subsets-permutations-combination-sum-palindrome-partioning/1)，多个类似的问题都可以用到这个方法
```c
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>>res;
		vector<int>tnums;
		//sort(nums.begin(),nums.end());
		search(res, tnums, nums);
		return res;
	}
	void search(vector<vector<int>>&res, vector<int>&tnums, vector<int>&nums) 
	{
		if (tnums.size() == nums.size()) {
			res.push_back(tnums);
			return;
		}
		else {
			for (int i = 0; i<nums.size(); i++) {
				if (find(tnums.begin(), tnums.end(), nums[i]) != tnums.end()) continue;
				tnums.push_back(nums[i]);
				search(res, tnums, nums);
				tnums.pop_back();
			}
		}
	}
```
### 解法二：
直接交换，不需要辅助vector
```c
    vector<vector<int> > permute(vector<int> &num) 
    {
	    vector<vector<int> > result;  
	    permuteRecursive(num, 0, result);
	    return result;
    }  
    void permuteRecursive(vector<int> &num, int begin, vector<vector<int> > &result)	
    {
		if (begin >= num.size()) {
		    // one permutation instance
		    result.push_back(num);
		    return;
		}
		for (int i = begin; i < num.size(); i++) {
		    swap(num[begin], num[i]);
		    permuteRecursive(num, begin + 1, result);

		    swap(num[begin], num[i]);
		}
    }
```
### 解法三：
使用[Next Permutation](https://github.com/Harry-Li/leetcode/tree/master/031.%20Next%20Permutation)函数，先sort，第一个（升序）放进去，然后进行循环，直到降序排列。
```c
	vector<vector<int>>permute(vector<int>&nums) {
		vector<vector<int>>res;
		sort(nums.begin(),nums.end());
		res.push_back(nums);
		while (nextPermutation(nums))
			res.push_back(nums);
		return res;
	}
	bool nextPermutation(vector<int>& nums) {
		int i = nums.size() - 1;
		for (; i>0; i--) {
			if (nums[i]>nums[i - 1]) {
				break;
			}
		}
		if (i == 0) {//此时数组中元素从大到小，翻转即可
			reverse(nums.begin(), nums.end());
			return false;
		}
		int j = i;
		for (; j<nums.size(); j++) {
			if (nums[i - 1] >= nums[j]) {
				//需要用>=，因为要找最后一个比nums[i-1]大的，即第一个<=它的前面一个，而不是不比它小的前面一个
				break;
			}
		}
		swap(nums[j - 1], nums[i - 1]);
		reverse(nums.begin() + i, nums.end());
		return true;
	}
```
