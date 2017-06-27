#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		int n = matrix.size(), circle = n >> 1;
		for (int i = 0; i<circle; i++) {
			for (int j = i; j<n - 1 - i; j++) {
				//int t = matrix[i][j];
				//matrix[i][j] = matrix[n - 1 - j][i];
				//matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j];
				//matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];
				//matrix[j][n - 1 - i] = t;
				swap(matrix[i][j], matrix[j][n - 1 - i]);
				swap(matrix[i][j], matrix[n - 1 - i][n - 1 - j]);
				swap(matrix[i][j], matrix[n - 1 - j][i]);
			}
		}
	}
};
