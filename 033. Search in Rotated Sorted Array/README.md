## [033. Search in Rotated Sorted Array](https://leetcode.com/problems/search-in-rotated-sorted-array/#/description)
### 题目要求：
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.
### 我的解法：
可以简化：循环条件改为min<=max，最前面的判断不需要，最后也可以直接返回-1
```c
	int search(vector<int>& nums, int target) {
		if (nums.size() == 0) return -1;
		int min = 0, max = nums.size() - 1, mid;
		while (min<max) {
			mid = (min + max) / 2;
			if (target == nums[mid]) return mid;

			if (nums[mid] >= nums[min]) {
				if (target >= nums[min] && target<nums[mid]) max = mid - 1;
				else min = mid + 1;
			}
			else {
				if (target>nums[mid] && target <= nums[max]) min = mid + 1;
				else max = mid - 1;
			}
		}
		if (nums[min] == target) return min;
		return -1;
	}
```
### 解法二：
先求出最小值的index，再用二分查找法，注意realmid处理，感觉也可以用mid对应的值与target比较，再用二分查找法。
```c
    int search(int A[], int n, int target) {
        int lo=0,hi=n-1;
        // find the index of the smallest value using binary search.
        // Loop will terminate since mid < hi, and lo or hi will shrink by at least 1.
        // Proof by contradiction that mid < hi: if mid==hi, then lo==hi and loop would have been terminated.
        while(lo<hi){
            int mid=(lo+hi)/2;
            if(A[mid]>A[hi]) lo=mid+1;
            else hi=mid;
        }
        // lo==hi is the index of the smallest value and also the number of places rotated.
        int rot=lo;
        lo=0;hi=n-1;
        // The usual binary search and accounting for rotation.
        while(lo<=hi){
            int mid=(lo+hi)/2;
            int realmid=(mid+rot)%n;
            if(A[realmid]==target)return realmid;
            if(A[realmid]<target)lo=mid+1;
            else hi=mid-1;
        }
        return -1;
```
