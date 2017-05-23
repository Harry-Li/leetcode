#include<iostream>
#include<string>
#include<stack>
using namespace std;
class Solution {
public:
	bool isValid(string s) {
		stack<char> s1;
		for (int i = 0; i<s.length(); i++) {
			switch (s[i]) {
			case ')':if (!s1.empty() && s1.top() == '(') s1.pop(); else return false; break;
			case '}':if (!s1.empty() && s1.top() == '{') s1.pop(); else return false; break;
			case ']':if (!s1.empty() && s1.top() == '[') s1.pop(); else return false; break;
			default:s1.push(s[i]); break;
			}
		}
		if (s1.empty()) return true;
		else return false;
	}
};
