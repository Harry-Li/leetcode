	#include<iostream>
	#include<vector>
	#include<algorithm>
	using namespace std;
	class Solution {
	public:
		vector<vector<int>> fourSum(vector<int>& nums, int target) {
			vector<vector<int>>ret;
			if (nums.size()<4) return ret;
			sort(nums.begin(), nums.end());
			for (int i = 0; i<nums.size() - 3; i++) {
				for (int j = i + 1; j<nums.size() - 2; j++) {
					int k = j + 1, m = nums.size() - 1;
					while (k<m) {
						int sum = nums[i] + nums[j] + nums[k] + nums[m];
						if (sum<target) ++k;
						else if (sum>target) --m;
						else {
							ret.push_back(vector<int>{nums[i], nums[j], nums[k], nums[m]});
							while (k<m&&nums[k] == nums[k + 1]) ++k;
							while (k<m&&nums[m] == nums[m - 1]) --m;
							++k; --m;
						}
					}
					while (j<nums.size() - 2 && nums[j] == nums[j + 1]) ++j;
				}
				while (i<nums.size() - 3 && nums[i] == nums[i + 1]) ++i;
			}
			return ret;
		}
	};
