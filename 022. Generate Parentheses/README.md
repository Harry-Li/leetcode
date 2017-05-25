## [022. Generate Parentheses](https://leetcode.com/problems/generate-parentheses/#/description)
### 题目要求：
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
### 解法一：
递归
```c
	vector<string> generateParenthesis(int n) {
		vector<string> res;
		addingpar(res, "", n, n);
		return res;
	}
	void addingpar(vector<string> &v, string str, int n, int m) {
		if (n == 0 && m == 0) {
			v.push_back(str);
			return;
		}
		if (n > 0) { addingpar(v, str + "(", n - 1, m); }
		if (m > n) { addingpar(v, str + ")", n, m - 1); }
	}
```
### 解法二：
Creating new strings will take up too much space. Let's use string references.
```c
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        if (n < 1) return result;
        string parens;
        collect(result, parens, n, n);
        return result;
    }
    void collect(vector<string> &result, string &parens, int left, int right) {
        if (left > right || left < 0) return;
        if (left + right == 0) {
            result.push_back(parens);
            return;
        }
        parens.push_back('(');
        collect(result, parens, left - 1, right);
        parens.pop_back();
        parens.push_back(')');
        collect(result, parens, left, right - 1);
        parens.pop_back();
    }
```
