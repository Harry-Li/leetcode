## [6. ZigZag Conversion](https://leetcode.com/problems/zigzag-conversion/#/description)
### 题目要求：
将字符串转换为Z字形并按行存储。
### 我的思路：
使用嵌套for循环，按行存储，每行内的步长为2 * (numRows - 1)；若该行存储完毕，则转到下一行。
```c
	string convert(string s, int numRows) {
		if (numRows <= 1) return s;
		int len = s.length();
		string res = "";
		for (int i = 0; i<numRows; i++) {
			for (int j = 0; i + 2 * (numRows - 1)*j <= len - 1; j++) {
				res += s[i + 2 * (numRows - 1)*j];
				if (i > 0 && i < numRows - 1 && 2 * (numRows - 1)*(j + 1) - i <= len - 1) {
					res += s[2 * (numRows - 1)*(j + 1) - i];
				}
			}
		}
		return res;
	}
```
### 推荐思路与解法：
使用指向string的指针或vector，沿着原字符串顺序移动，将对应字符存放到对应的行中，最后依次连接各行。
```c
string convert(string s, int nRows) {
    if (nRows <= 1)
        return s;
    const int len = (int)s.length();
    string *str = new string[nRows];
    int row = 0, step = 1;
    for (int i = 0; i < len; ++i)
    {
        str[row].push_back(s[i]);
        if (row == 0)
            step = 1;
        else if (row == nRows - 1)
            step = -1;
        row += step;
    }
    s.clear();
    for (int j = 0; j < nRows; ++j)
    {
        s.append(str[j]);
    }
    delete[] str;
    return s;
}
```
下面这种方法本质和我的思路差不多，可以参考注释
```c
	string convert(string s, int numRows) {
		string result = "";
		if (numRows == 1)
			return s;
		int step1, step2;
		int len = s.size();
		for (int i = 0; i<numRows; ++i) { //同样按行存储
			step1 = (numRows - i - 1) * 2;   //step1与step2为两个步长
			step2 = (i) * 2;
			int pos = i;
			if (pos<len)
				result += s.at(pos);  //存储该行的第一个（下降）
			while (1) {
				pos += step1;
				if (pos >= len)
					break;
				if (step1)
					result += s.at(pos);  //存储（上升）
				pos += step2;
				if (pos >= len)
					break;
				if (step2)              //存储（下降）
					result += s.at(pos);
			}
		}
		return result;
	}
```
另一种方法：<br>
对(nRows-1)取余，可以区分行数;<br>
对(nRows-1)做除，可以区分当前是上升还是下降（偶数上升，奇数下降）。
```c
    string convert(string s, int nRows) {
        if (s.empty() || nRows < 2) return s;
        std::vector<string> ret(nRows);
        for (size_t i=0; i<s.size(); ++i) {
            int m = i % (nRows-1), n = i / (nRows-1);
            (n & 0x1 ? ret[nRows-m-1] : ret[m]) += s[i];
        }
        return std::accumulate(ret.cbegin(), ret.cend(), string());
    }
```
