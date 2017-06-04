#include"solution.h"
int main()
{
	Solution sol;
	vector<int>nums{ 5, 7, 7, 8, 8, 10 };
	vector<int>ret = sol.searchRange(nums, 8);
	cout << ret[0] << ',' << ret[1] << endl;
	return 0;
}
