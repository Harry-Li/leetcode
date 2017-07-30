#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	int uniquePaths(int m, int n) {
		vector<vector<int>>path(m, vector<int>(n, 1));
		for (int i = 1; i<m; i++)
			for (int j = 1; j<n; j++)
				path[i][j] = path[i][j - 1] + path[i - 1][j];
		return path[m - 1][n - 1];
	}
};
