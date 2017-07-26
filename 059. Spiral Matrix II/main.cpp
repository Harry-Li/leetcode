#include"solution.h"
int main()
{
	Solution sol;
	int n;
	cin >> n;
	vector<vector<int>>matrix = sol.generateMatrix(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << matrix[i][j] << ' ';
		cout << endl;
	}
	return 0;
}
