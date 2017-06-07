## [038. Count and Say](https://leetcode.com/problems/count-and-say/#/description)
### 题目要求：
The count-and-say sequence is the sequence of integers beginning as follows:<br>
1, 11, 21, 1211, 111221, ...

Given an integer n, generate the nth sequence.
### 我的解法：
一些处理不太好，可以参考推荐解法
```c
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
```
### 推荐解法：
```c
string countAndSay(int n) {
    if (n == 0) return "";
    string res = "1";
    while (--n) {
        string cur = "";
        for (int i = 0; i < res.size(); i++) {
            int count = 1;
             while ((i + 1 < res.size()) && (res[i] == res[i + 1])){
                count++;    
                i++;
            }
            cur += to_string(count) + res[i];
        }
        res = cur;
    }
    return res;
}
```
