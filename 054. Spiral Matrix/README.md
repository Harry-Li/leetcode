## [054. Spiral Matrix](https://leetcode.com/problems/spiral-matrix/#/description)
### 题目要求：
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example,<br>
Given the following matrix:

[<br>
 [ 1, 2, 3 ],<br>
 [ 4, 5, 6 ],<br>
 [ 7, 8, 9 ]<br>
]<br>
You should return [1,2,3,6,9,8,7,4,5].
### 我的解法：
endx表示右下角元素位于的行数，endy表示其列数
```c
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> res;
		int m = matrix.size();
		if (m == 0) return res;
		int n = matrix[0].size();
		int circle = min(m, n) + 1 >> 1;
		for (int i = 0; i<circle; i++) {
			int endx = m - i - 1, endy = n - i - 1;
			for (int j = i; j <= endy; j++) res.push_back(matrix[i][j]);
			if (i<endx)
				for (int j = i + 1; j <= endx; j++) res.push_back(matrix[j][endy]);
			if (i<endy&&i<endx)
				for (int j = endy - 1; j >= i; j--) res.push_back(matrix[endx][j]);
			if (i<endx - 1 && i<endy)
				for (int j = endx - 1; j>i; j--) res.push_back(matrix[j][i]);
		}
		return res;
	}
```
### 其他解法：
这题方法挺多的，下面这方法就不错
```Java
public class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        
        List<Integer> res = new ArrayList<Integer>();
        
        if (matrix.length == 0) {
            return res;
        }
        
        int rowBegin = 0;
        int rowEnd = matrix.length-1;
        int colBegin = 0;
        int colEnd = matrix[0].length - 1;
        
        while (rowBegin <= rowEnd && colBegin <= colEnd) {
            // Traverse Right
            for (int j = colBegin; j <= colEnd; j ++) {
                res.add(matrix[rowBegin][j]);
            }
            rowBegin++;
            
            // Traverse Down
            for (int j = rowBegin; j <= rowEnd; j ++) {
                res.add(matrix[j][colEnd]);
            }
            colEnd--;
            
            if (rowBegin <= rowEnd) {
                // Traverse Left
                for (int j = colEnd; j >= colBegin; j --) {
                    res.add(matrix[rowEnd][j]);
                }
            }
            rowEnd--;
            
            if (colBegin <= colEnd) {
                // Traver Up
                for (int j = rowEnd; j >= rowBegin; j --) {
                    res.add(matrix[j][colBegin]);
                }
            }
            colBegin ++;
        }
        
        return res;
    }
}
```

