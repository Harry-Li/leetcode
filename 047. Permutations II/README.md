## [047. Permutations II](https://leetcode.com/problems/permutations-ii/#/description)
### 题目要求：
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,<br>
[1,1,2] have the following unique permutations:<br>
[[1,1,2],[1,2,1],[2,1,1]]
### 解法一：
[回溯](https://discuss.leetcode.com/topic/46162/a-general-approach-to-backtracking-questions-in-java-subsets-permutations-combination-sum-palindrome-partioning/1)，注意比较与[046. Permutations](https://github.com/Harry-Li/leetcode/tree/master/046.%20Permutations)的区别，这题要先排序，还要跳过一些情况
```c
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		vector<vector<int>>res;
		vector<int>tnums;
		vector<bool>used(nums.size(),false);
		sort(nums.begin(),nums.end());
		search(res, tnums, nums,used);
		return res;
	}
	void search(vector<vector<int>>&res, vector<int>&tnums, vector<int>&nums,vector<bool>&used) {
		if (tnums.size() == nums.size()) {
			res.push_back(tnums);
			//return;
		}
		else {
			for (int i = 0; i<nums.size(); i++) {
				if (used[i]||i>0&&nums[i]==nums[i-1]&&!used[i-1]) continue;
				used[i] = true;
				tnums.push_back(nums[i]);
				search(res, tnums, nums,used);
				used[i] = false;
				tnums.pop_back();
			}
		}
	}
```
### 解法二：
[交换](https://discuss.leetcode.com/topic/8831/a-simple-c-solution-in-only-20-lines)，要注意这种方法，num不能使用引用，交换以后也不能再换回来
```c
    void recursion(vector<int> num, int i, int j, vector<vector<int> > &res) {
        if (i == j-1) {
            res.push_back(num);
            return;
        }
        for (int k = i; k < j; k++) {
            if (i != k && num[i] == num[k]) continue;
            swap(num[i], num[k]);
            recursion(num, i+1, j, res);
        }
    }
    vector<vector<int> > permuteUnique(vector<int> &num) {
        sort(num.begin(), num.end());
        vector<vector<int> >res;
        recursion(num, 0, num.size(), res);
        return res;
    }
```
### 解法三：
```c
    void permuteUnique(vector<int>& nums, int index, vector<vector<int>>& res) {
        // cout << "inrecurse" << index << endl;
        int len = nums.size();
        if(index == len - 1) {
            // cout << "insert ";
            // for(int e: nums) cout << e << ' ';
            //     cout << endl;
            res.push_back(nums);
            return;
        }

        unordered_set<int> s;
        for(int i = index; i < len; i++) {
            // cout << 'i' << i << endl;
            // for(int e: s) cout << e << ' ';
            //     cout << endl;
            // for(int e: nums) cout << e << ' ';
            // cout << endl;
            if(s.find(nums[i]) == s.end()) {
                // cout << "swap" << i << ' ' << index << endl;
                s.insert(nums[i]);
                swap(nums[i], nums[index]);
                permuteUnique(nums, index + 1, res);
                // cout << "backrecurse" << index << endl;
                swap(nums[i], nums[index]);
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        permuteUnique(nums, 0, res);
        return res;
    }
```
