#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
	string countAndSay(int n) {
		if (n<1) return "";
		if (n == 1) return "1";
		if (n == 2) return "11";
		string s = "11";
		while (n-->2) {
			string stemp;
			int len = s.length(), count = 1;
			char ctemp = s[0];
			for (int i = 1; i<len; i++) {
				if (ctemp == s[i]) {
					count++;
					if (i == len - 1) stemp += to_string(count) + ctemp;
				}
				else {
					stemp += to_string(count) + ctemp;
					count = 1;
					ctemp = s[i];
					if (i == len - 1) stemp += string("1") + s[i];
				}
			}
			s = stemp;
		}
		return s;
	}
};
