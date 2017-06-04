#include<iostream>
#include<vector>
using namespace std;
//方法一
class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		int min = 0, max = nums.size() - 1, mid, midx, midl, midr;
		while (min <= max) {
			mid = (min + max) >> 1;
			if (nums[mid] == target) {
				midx = mid;
				while (min<mid) {
					midl = (min + mid) >> 1;
					if (nums[midl] == target) mid = midl;
					else min = midl + 1;
				}
				while (midx<max) {
					midr = (midx + max + 1) >> 1;
					if (nums[midr] == target) midx = midr;
					else max = midr - 1;
				}				
				return{ mid,midx };
			}
			else if (nums[mid]<target) min = mid + 1;
			else max = mid - 1;
		}
		return {-1, -1};
	}
};

/*方法二
class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		if (nums.empty()) return{ -1,-1 };
		vector<int>ans;
		int i = 0, j = nums.size() - 1, mid;
		while (i < j) {
			mid = (i + j) >> 1;
			if (nums[mid] < target) i = mid + 1;
			else j = mid;
		}
		if (nums[i] == target) ans.push_back(i);
		else return{ -1,-1 };
		j = nums.size() - 1;
		while (i < j) {
			mid = (i + j + 1) >> 1;
			if (nums[mid] > target) j = mid - 1;
			else i = mid;
		}
		ans.push_back(j);
		return ans;
	}
};
*/
