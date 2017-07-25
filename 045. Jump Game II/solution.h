#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	int jump(vector<int>& nums) {
		if (nums.size() <= 1) return 0;
		int step = 0, curpos = 0, nextpos = 0;
		for (int i = 0; i <= nums.size() - 2; i++) {
			if (i + nums[i] > curpos) {
				curpos = i + nums[i];
			}
			if (i == nextpos) {
				nextpos = curpos;
				step++;
			}
		}
		return step;
	}
};
