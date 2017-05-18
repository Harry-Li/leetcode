#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
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
};
