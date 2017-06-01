#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
	int strStr(string haystack, string needle) {
		int len1 = needle.length(), len2 = haystack.length();
		if (len1 == 0) return 0;
		int i = 0, j = 0;
		while (j + len1 <= len2) {
			i = 0;
			while (i<len1&&haystack[i + j] == needle[i]) {
				++i;
			}
			if (i == len1) return j;
			++j;
		}
		return -1;
	}
};
