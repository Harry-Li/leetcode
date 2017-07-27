## [060. Permutation Sequence](https://leetcode.com/problems/permutation-sequence/tabs/description)
### 题目要求：
The set [1,2,3,…,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,<br>
We get the following sequence (ie, for n = 3):

"123"<br>
"132"<br>
"213"<br>
"231"<br>
"312"<br>
"321"<br>
Given n and k, return the kth permutation sequence.

Note: Given n will be between 1 and 9 inclusive.
### 推荐解法：
[explaination](https://discuss.leetcode.com/topic/17348/explain-like-i-m-five-java-solution-in-o-n)
```c
	string getPermutation(int n, int k) {
		vector<int>nums;
		vector<int>fact(n + 1);
		string s;
		fact[0] = 1;
		for (int i = 1; i <= n; i++) {
			nums.push_back(i);// numbers = {1, 2, 3, 4}
			fact[i] = fact[i - 1] * i;// factorial[] = {1, 1, 2, 6, 24, ... n!}
		}
		--k;
		for (int i = 1; i <= n; i++) {
			int index = k / fact[n - i];
			s += to_string(nums[index]);
			nums.erase(nums.begin() + index);
			k -= index*fact[n - i];
		}
		return s;
	}
```
