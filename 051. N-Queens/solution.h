#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
	vector<vector<string>> solveNQueens(int n) {
		vector<vector<int>>sol;
		vector<int>index;
		queens(sol, index, n);
		//vector<string>str(n,string(n,'.'));
		//vector<vector<string>>res(sol.size(),str);
		vector<vector<string>>res(sol.size(), vector<string>(n, string(n, '.')));
		for (int i = 0; i < sol.size(); i++) {
			for (int j = 0; j < n; j++) {
				res[i][j][sol[i][j]] = 'Q';
			}
		}
		return res;
	}
	void queens(vector<vector<int>> &sol, vector<int>&index, int n) {
		if (index.size() == n) {
			sol.push_back(index);
			return;
		}
		else {
			for (int i = 0; i < n; i++) {
				index.push_back(i);
				if (isvalid(index)) queens(sol, index, n);
				index.pop_back();
			}
		}
	}
	bool isvalid(vector<int>& index) {
		int i = index.size() - 1;
		for (int j = i - 1; j >= 0; j--) {
			if (index[i] == index[j] || (index[i] - index[j]) == i - j || (index[i] - index[j]) == j - i) return false;
		}
		return true;
	}
};
