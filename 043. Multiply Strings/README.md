## [043. Multiply Strings](https://leetcode.com/problems/multiply-strings/#/description)
### 题目要求：
Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2.

Note:

The length of both num1 and num2 is < 110.<br>
Both num1 and num2 contains only digits 0-9.<br>
Both num1 and num2 does not contain any leading zero.<br>
You must not use any built-in BigInteger library or convert the inputs to integer directly.
### 推荐解法一：
[JAVA版本详细解释](https://discuss.leetcode.com/topic/30508/easiest-java-solution-with-graph-explanation)
```c
	string multiply(string num1, string num2) {
		vector<int>num(num1.size()+num2.size(),0);
		for (int i = num1.size() - 1; i >= 0; i--) {
			for (int j = num2.size() - 1; j >= 0; j--) {
				int mul = (num1[i] - '0')*(num2[j] - '0');
				num[i + j] += (mul + num[i + j + 1]) / 10;
				num[i + j + 1] = (mul + num[i + j + 1]) % 10;
			}
		}
		string res;
		for (auto val : num) {
			if (val != 0 || !res.empty())
				res += to_string(val);
		}
		return res.empty() ? "0" : res;
	}
```
### 推荐解法二：
直接用string存，进位加到sum[i]
```c
string multiply(string num1, string num2) {
    string sum(num1.size() + num2.size(), '0');
    
    for (int i = num1.size() - 1; 0 <= i; --i) {
        int carry = 0;
        for (int j = num2.size() - 1; 0 <= j; --j) {
            int tmp = (sum[i + j + 1] - '0') + (num1[i] - '0') * (num2[j] - '0') + carry;
            sum[i + j + 1] = tmp % 10 + '0';
            carry = tmp / 10;
        }
        sum[i] += carry;
    }
    
    size_t startpos = sum.find_first_not_of("0");
    if (string::npos != startpos) {
        return sum.substr(startpos);
    }
    return "0";
}
```
