#include"solution.h"
int main()
{
	Solution sol;
	vector<int> nums{ 2,3,1,3,3 };
	sol.nextPermutation(nums);
	for (auto val : nums) {
		cout << val << ',';
	}
	cout << "\b " << endl;
}
