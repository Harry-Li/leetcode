#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
	string getPermutation(int n, int k) {
		vector<int>nums;
		vector<int>fact(n + 1);
		string s;
		fact[0] = 1;
		for (int i = 1; i <= n; i++) {
			nums.push_back(i);
			fact[i] = fact[i - 1] * i;
		}
		--k;
		for (int i = 1; i <= n; i++) {
			int index = k / fact[n - i];
			s += to_string(nums[index]);
			nums.erase(nums.begin() + index);
			k -= index*fact[n - i];
		}
		return s;
	}
};
