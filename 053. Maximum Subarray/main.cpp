#include"solution.h"
int main()
{
	Solution sol;
	vector<int>nums = { -2,1,-3,4,-1,2,1,-5,4 };
	cout << sol.maxSubArray(nums) << endl;
	return 0;
}
