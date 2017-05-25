#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
	vector<string> generateParenthesis(int n) {
		vector<string> res;
		addingpar(res, "", n, n);
		return res;
	}
	void addingpar(vector<string> &v, string str, int n, int m) {
		if (n == 0 && m == 0) {
			v.push_back(str);
			return;
		}
		if (n > 0) { addingpar(v, str + "(", n - 1, m); }
		if (m > n) { addingpar(v, str + ")", n, m - 1); }
	}
};
