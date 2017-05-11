#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		int i, j;
		vector<int> vec;
		for (i = 0; i<nums.size(); i++)
			for (j = i + 1; j<nums.size(); j++)
				if (nums[i] + nums[j] == target) {
					vec.push_back(i);
					vec.push_back(j);
					return vec;
				}
		return vec;
	}
};
int main()
{
	Solution sol;
	vector<int> nums = { 2, 7, 11, 15 };
	vector<int> vec = sol.twoSum(nums, 16);
	if(vec.size()==2)
		cout << '[' << vec[0] << ',' << vec[1] << ']' << endl;
	return 0;
}
