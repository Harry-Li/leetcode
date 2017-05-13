#include<iostream>
#include<string>
#include<map>
#include<algorithm>
using namespace std;
int lengthOfLongestSubstring(string s) {
	map<char, int> charMap;
	int start = -1;
	int maxLen = 0;
	for (int i = 0; i < s.size(); i++) {
		if (charMap.count(s[i]) != 0) {
			start = max(start, charMap[s[i]]);
		}
		charMap[s[i]] = i;
		maxLen = max(maxLen, i - start);
	}
	return maxLen;
}
/*
int lengthOfLongestSubstring(string s) {
	vector<int> dict(256, -1);
	int maxLen = 0, start = -1;
	for (int i = 0; i != s.length(); i++) {
		if (dict[s[i]] > start)
			start = dict[s[i]];
		dict[s[i]] = i;
		maxLen = max(maxLen, i - start);
	}
	return maxLen;
}
*/
