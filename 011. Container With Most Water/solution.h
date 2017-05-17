#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	int maxArea(vector<int>& height) {
		if (height.size()<2) return 0;
		int maxarea = 0, i = 0, j = height.size() - 1;
		while (i<j) {
			if (height[i]<height[j]) {
				maxarea = max(maxarea, (j - i)*height[i]);
				++i;
			}
			else {
				maxarea = max(maxarea, (j - i)*height[j]);
				--j;
			}
		}
		return maxarea;
	}
};
