#include"solution.h"
int main()
{
	vector<string> strs = { "eat","tea","tan","ate","nat","bat" };
	Solution sol;
	vector<vector<string>>res = sol.groupAnagrams(strs);
	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[i].size(); j++) {
			cout << res[i][j] << ',';
		}
		cout << "\b " << endl;
	}
	return 0;
}
