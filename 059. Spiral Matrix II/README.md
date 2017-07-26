## [059. Spiral Matrix II](https://leetcode.com/problems/spiral-matrix-ii/#/description)
### 题目要求：
Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

For example,<br>
Given n = 3,

You should return the following matrix:<br>
[<br>
 [ 1, 2, 3 ],<br>
 [ 8, 9, 4 ],<br>
 [ 7, 6, 5 ]<br>
]
### 解法：
对比[054. Spiral Matrix](https://github.com/Harry-Li/leetcode/tree/master/054.%20Spiral%20Matrix),if判断可以不加
```c
	vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>>matrix(n, vector<int>(n));
		int N = 0, circle = (n + 1) >> 1;
		for (int i = 0; i < circle; i++) {
			int x = i, y = x;
			int endx = n - i - 1, endy = endx;
			for (; y <= endy; y++) matrix[x][y] = ++N;
			//if (x < endx) {
				for (--y, ++x; x <= endx; x++) matrix[x][y] = ++N;
				for (--x, --y; y >= i; y--) matrix[x][y] = ++N;
				for (++y, --x; x > i; x--) matrix[x][y] = ++N;
			//}
		}
		return matrix;
	}
```
