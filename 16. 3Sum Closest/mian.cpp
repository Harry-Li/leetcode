#include"solution.h"
int main()
{
	Solution sol;
	vector<int> nums = { -1,2,1,-4 };
	int target = 1;
	cout << sol.threeSumClosest(nums, target) << endl;
	return 0;
}
