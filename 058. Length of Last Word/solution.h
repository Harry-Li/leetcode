#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
	int lengthOfLastWord(string s) {
		auto len = s.length();
		if (len == 0) return 0;
		int a = len - 1;
		while (a >= 0 && s[a] == ' ') --a;
		int b = a;
		while (b >= 0 && s[b] != ' ') --b;
		return a - b;
	}
};
