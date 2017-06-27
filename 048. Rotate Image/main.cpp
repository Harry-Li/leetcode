#include"solution.h"
int main()
{
	Solution sol;
	vector<vector<int>>matrix = { {1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16} };
	cout << "Before rotate:" << endl;
	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix[i].size(); j++) {
			cout << matrix[i][j] << '\t';
		}
		cout << endl;
	}
	cout << "After rotate:" << endl;
	sol.rotate(matrix);
	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix[i].size(); j++) {
			cout << matrix[i][j] << '\t';
		}
		cout << endl;
	}
	return 0;
}
