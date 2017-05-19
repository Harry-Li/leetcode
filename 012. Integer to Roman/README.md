## [12. Integer to Roman](https://leetcode.com/problems/integer-to-roman/#/description)
### 题目要求：
将整数转化为罗马数字，整数范围1~3999
### 解法一：
```c
	string intToRoman(int num) {
		string c[4][10] =
		{
			{ "","I","II","III","IV","V","VI","VII","VIII","IX" },
			{ "","X","XX","XXX","XL","L","LX","LXX","LXXX","XC" },
			{ "","C","CC","CCC","CD","D","DC","DCC","DCCC","CM" },
			{ "","M","MM","MMM" }
		};
		string roman;
		roman = c[3][num / 1000 % 10] + c[2][num / 100 % 10] + c[1][num / 10 % 10] + c[0][num % 10];
		return roman;
	}
```
### 解法二：
```c
    string intToRoman(int num) {
		if (num == 0)    return "";
		if (num >= 1000) return "M" + intToRoman(num - 1000);
		if (num >= 900)  return "CM" + intToRoman(num - 900);
		if (num >= 500)  return "D" + intToRoman(num - 500);
		if (num >= 400)  return "CD" + intToRoman(num - 400);
		if (num >= 100)  return "C" + intToRoman(num - 100);
		if (num >= 90)   return "XC" + intToRoman(num - 90);
		if (num >= 50)   return "L" + intToRoman(num - 50);
		if (num >= 40)   return "XL" + intToRoman(num - 40);
		if (num >= 10)   return "X" + intToRoman(num - 10);
		if (num >= 9)    return "IX" + intToRoman(num - 9);
		if (num >= 5)    return "V" + intToRoman(num - 5);
		if (num >= 4)    return "IV" + intToRoman(num - 4);
		if (num >= 1)    return "I" + intToRoman(num - 1);
    }
```
