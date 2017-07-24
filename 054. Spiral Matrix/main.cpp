#include"solution.h"
int main()
{
	Solution sol;
	vector<vector<int>>nums = { {1,2,3},{4,5,6},{7,8,9} };
	vector<int> spiral = sol.spiralOrder(nums);
	for (auto iter = spiral.begin(); iter != spiral.end(); iter++){
		cout << *iter << ' ';
	}
	cout << endl;
	return 0;
}
