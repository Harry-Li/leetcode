## [048. Rotate Image](https://leetcode.com/problems/rotate-image/#/description)
### 题目要求：
You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Follow up:<br>
Could you do this in-place?
### 解法一：
互换位置的四个数字为一组，找到下标关系，用交换，或者循环赋值
```c
	void rotate(vector<vector<int>>& matrix) {
		int n = matrix.size(), circle = n >> 1;
		for (int i = 0; i<circle; i++) {
			for (int j = i; j<n - 1 - i; j++) {
				//int t = matrix[i][j];
				//matrix[i][j] = matrix[n - 1 - j][i];
				//matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j];
				//matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];
				//matrix[j][n - 1 - i] = t;
				swap(matrix[i][j], matrix[j][n - 1 - i]);
				swap(matrix[i][j], matrix[n - 1 - i][n - 1 - j]);
				swap(matrix[i][j], matrix[n - 1 - j][i]);
			}
		}
	}
```
### 解法二：
可以想象成翻转，自己拿一张纸试试
```c
/*
 * clockwise rotate
 * first reverse up to down, then swap the symmetry 
 * 1 2 3     7 8 9     7 4 1
 * 4 5 6  => 4 5 6  => 8 5 2
 * 7 8 9     1 2 3     9 6 3
*/
void rotate(vector<vector<int> > &matrix) {
    reverse(matrix.begin(), matrix.end());
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = i + 1; j < matrix[i].size(); ++j)
            swap(matrix[i][j], matrix[j][i]);
    }
}

/*
 * anticlockwise rotate
 * first reverse left to right, then swap the symmetry
 * 1 2 3     3 2 1     3 6 9
 * 4 5 6  => 6 5 4  => 2 5 8
 * 7 8 9     9 8 7     1 4 7
*/
void anti_rotate(vector<vector<int> > &matrix) {
    for (auto vi : matrix) reverse(vi.begin(), vi.end());
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = i + 1; j < matrix[i].size(); ++j) //for(int j = 0;j < i; j++)
            swap(matrix[i][j], matrix[j][i]);
    }
}
```
