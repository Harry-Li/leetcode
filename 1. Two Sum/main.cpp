#include"solution.h"

int main()
{
	Solution sol;
	vector<int> nums = { 2, 7, 11, 15 };
	vector<int> vec = sol.twoSum(nums, 26);
	if (vec.size() == 2)
		cout << '[' << vec[0] << ',' << vec[1] << ']' << endl;
	return 0;
}
