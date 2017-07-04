#include"solution.h"
int main()
{
	Solution sol;
	int n;
	cin >> n;
	vector<vector<string>>res = sol.solveNQueens(n);
	for (int i = 0; i < res.size(); i++) {
		cout << "Solution " << i+1 << ":" << endl;
		for (int j = 0; j < n; j++) {
			cout << res[i][j] << ',' << endl;
		}
	}
	return 0;
}
