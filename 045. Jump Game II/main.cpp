#include"solution.h"
int main()
{
	Solution sol;
	vector<int>nums = { 2,3,1,1,4 };
	int min_step = sol.jump(nums);
	cout << min_step << endl;
	return 0;
}
