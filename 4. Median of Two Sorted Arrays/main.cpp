#include"solution.h"
int main()
{
	Solution sol;
	vector<int> nums1 = { 1,2 }, nums2 = {3,4};
	cout << sol.findMedianSortedArrays(nums1, nums2) << endl;
	return 0;
}
