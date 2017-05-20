#include<iostream>
#include<vector>
#include<algorithm>
#include<assert.h>
using namespace std;
class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		int size = nums.size();
		assert(size >= 3);
		sort(nums.begin(), nums.end());
		int ret = nums[0] + nums[1] + nums[2], sum;
		int i = 0, j = 1, k = size - 1;
		while (i <= size - 3 && nums[i] + 2 * nums[j] <= target) {
			while (j<k) {
				sum = nums[i] + nums[j] + nums[k];
				if (abs(ret - target)>abs(sum - target)) {
					ret = sum;
					if (ret == target) return ret;
				}
				sum<target ? ++j : --k;
			}
			while (i <= size - 2 && nums[i] == nums[i + 1]) ++i;
			++i;
			j = i + 1;
			k = size - 1;
		}
		return ret;
	}
};
