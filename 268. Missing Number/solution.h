#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
	int missingNumber(vector<int>& nums) {
		int size = nums.size();
		long sum = 0;
		for (int i = 0; i<size; i++) {
			sum += i - nums[i];
		}
		return sum + size;
	}
};
