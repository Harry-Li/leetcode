#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
using namespace std;
class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		unordered_map<string,vector<string>>m;
		for (int i = 0; i<strs.size(); i++) {
			string temp = strs[i];
			sort(temp.begin(), temp.end());
			m[temp].push_back(strs[i]);
		}
		vector<vector<string>>res;
		for (auto &e : m) {
			res.push_back(e.second);
		}
		return res;
	}
};
