#include"solution.h"
int main()
{
	Solution sol;
	vector<int>nums{ 1,3,5,6 };
	cout << sol.searchInsert(nums, 7) << endl;
	return 0;
}
