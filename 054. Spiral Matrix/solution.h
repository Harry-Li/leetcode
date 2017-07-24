#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> res;
		int m = matrix.size();
		if (m == 0) return res;
		int n = matrix[0].size();
		int circle = min(m, n) + 1 >> 1;
		for (int i = 0; i<circle; i++) {
			int endx = m - i - 1, endy = n - i - 1;
			for (int j = i; j <= endy; j++) res.push_back(matrix[i][j]);
			if (i<endx)
				for (int j = i + 1; j <= endx; j++) res.push_back(matrix[j][endy]);
			if (i<endy&&i<endx)
				for (int j = endy - 1; j >= i; j--) res.push_back(matrix[endx][j]);
			if (i<endx - 1 && i<endy)
				for (int j = endx - 1; j>i; j--) res.push_back(matrix[j][i]);
		}
		return res;
	}
};
