## 4. Median of Two Sorted Arrays
https://leetcode.com/problems/median-of-two-sorted-arrays/#/description
### 题目要求：
给两个排序后的数组，求中位数，使得其时间复杂度为O(log (m+n))。
### 我的思路：
开始没看到题目对于时间复杂度的要求，做了两种方法，一是用四个指针，比较并进行移动，二是用辅助数组，时间复杂度都是O(m+n)
```c
//用四个指针，临界判断非常复杂，建议跳过 66ms，超过了38%
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int a1 = 0, a2 = 0, b1 = nums1.size() - 1, b2 = nums2.size() - 1;
		while (a1<b1&&a2<b2) {
			if (nums1[a1]<nums2[a2]) ++a1;
			else ++a2;
			if (nums1[b1]>nums2[b2]) --b1;
			else --b2;
		}
		if (a1 == b1&&a2 == b2) {
			return 1.0*(nums1[a1] + nums2[a2]) / 2;
		}
		if (a1 == b1&&a2<b2) {
			while (nums1[a1]>nums2[a2] && nums1[a1]<nums2[b2]) {
				++a2;
				--b2;
			}
			if (a2>b2) return nums1[a1];
			if (a2 == b2) return 1.0*(nums1[a1] + nums2[a2]) / 2;
			if (nums1[a1] <= nums2[a2]) {
				if ((a2 + b2 - 1) % 2 == 0) return nums2[(a2 + b2 - 1) / 2];
				else return 1.0*(nums2[(a2 + b2) / 2] + nums2[(a2 + b2 - 2) / 2]) / 2;
			}
			if (nums1[a1] >= nums2[b2]) {
				if ((a2 + b2 + 1) % 2 == 0) return nums2[(a2 + b2 + 1) / 2];
				else return 1.0*(nums2[(a2 + b2) / 2] + nums2[(a2 + b2 + 2) / 2]) / 2;
			}
		}
		if (a1<b1&&a2 == b2) {
			while (nums2[a2]>nums1[a1] && nums2[a2]<nums1[b1]) {
				++a1;
				--b1;
			}
			if (a1>b1) return nums2[a2];
			if (a1 == b1) return 1.0*(nums1[a1] + nums2[a2]) / 2;
			if (nums2[a2] <= nums1[a1]) {
				if ((a1 + b1 - 1) % 2 == 0) return nums1[(a1 + b1 - 1) / 2];
				else return 1.0*(nums1[(a1 + b1) / 2] + nums1[(a1 + b1 - 2) / 2]) / 2;
			}
			if (nums2[a2] >= nums1[b1]) {
				if ((a1 + b1 + 1) % 2 == 0) return nums1[(a1 + b1 + 1) / 2];
				else return 1.0*(nums1[(a1 + b1) / 2] + nums1[(a1 + b1 + 2) / 2]) / 2;
			}
		}
		if (a1>b1) {
			if ((a2 + b2) % 2 == 0) return nums2[(a2 + b2) / 2];
			else return 1.0*(nums2[(a2 + b2 + 1) / 2] + nums2[(a2 + b2 - 1) / 2]) / 2;
		}
		if (a2>b2) {
			if ((a1 + b1) % 2 == 0) return nums1[(a1 + b1) / 2];
			else return 1.0*(nums1[(a1 + b1 + 1) / 2] + nums1[(a1 + b1 - 1) / 2]) / 2;
		}

	}
```
```c
//用额外的数组空间来存储 42ms，超过了91%
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int size1 = nums1.size(), size2 = nums2.size();
		vector<int>num;
		int a = 0, b = 0;
		while (a<size1&&b<size2) {
			if (nums1[a]<nums2[b]) {
				num.push_back(nums1[a]);
				++a;
			}
			else {
				num.push_back(nums2[b]);
				++b;
			}
		}
		if (a == size1) {
			while (b<size2) {
				num.push_back(nums2[b]);
				++b;
			}
		}
		else {
			while (a<size1) {
				num.push_back(nums1[a]);
				++a;
			}
		}
		if ((size1 + size2) % 2 == 1) return num[(size1 + size2 - 1) / 2];
		else return 1.0*(num[(size1 + size2) / 2] + num[(size1 + size2) / 2 - 1]) / 2;
	}
```
### 推荐思路与解法：
题目要求时间复杂度为O(log (m+n))，上述两种方法均不符题意。<br>
推荐方法：<br>
[Share my O(log(min(m,n)) solution with explanation](https://discuss.leetcode.com/topic/4996/share-my-o-log-min-m-n-solution-with-explanation)<br>
下面是这种方法的c++实现： 49ms 超过了78%
```c
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		if (nums1.size()>nums2.size()) return findMedianSortedArrays(nums2, nums1);
		if (nums2.size() == 0) return -1;
		int m = nums1.size(), n = nums2.size();
		int min = 0, max = m, half = (m + n + 1) / 2, i, j;
		while (min <= max) {
			i = (min + max) / 2, j = half - i;
			if (i<m&&nums1[i]<nums2[j - 1]) min = i + 1;
			else if (i>0 && nums1[i - 1]>nums2[j]) max = i - 1;
			else {
				int left, right;
				if (i == 0) left = nums2[j - 1];
				else if (j == 0) left = nums1[i - 1];
				else left = nums1[i - 1]>nums2[j - 1] ? nums1[i - 1] : nums2[j - 1];

				if ((m + n) % 2 == 1) return left;

				if (i == m) right = nums2[j];
				else if (j == n) right = nums1[i];
				else right = nums1[i]<nums2[j] ? nums1[i] : nums2[j];
				return (left + right) / 2.0;
			}
		}
	}
```
比较奇怪，时间复杂度O(m+n)反而比O(log(m+n))更快，可能是因为testcase的问题，跟oj服务器的负载情况可能也有一定关系。
