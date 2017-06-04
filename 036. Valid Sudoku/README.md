## [036. Valid Sudoku](https://leetcode.com/problems/valid-sudoku/#/description)
### 题目要求：
Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
### 我的解法：
分别判断行、列、与3*3的sub-boxes
```c
	bool isValidSudoku(vector<vector<char>>& board) {
		map<char, int>hashmap;
		for (auto chars : board) {
			hashmap.clear();
			for (auto c : chars) {
				if (c != '.') {
					hashmap[c]++;
					if (hashmap[c]>1) return false;
				}
			}
		}
		for (int i = 0; i<9; i++) {
			hashmap.clear();
			for (auto chars : board) {
				if (chars[i] != '.') {
					hashmap[chars[i]]++;
					if (hashmap[chars[i]]>1) return false;
				}
			}
		}
		for (int i = 0; i <= 6; i += 3) {
			for (int j = 0; j <= 6; j += 3) {
				hashmap.clear();
				for (int k = 0; k<3; k++) {
					for (int m = 0; m<3; m++) {
						if (board[i + k][j + m] != '.') {
							hashmap[board[i + k][j + m]]++;
							if (hashmap[board[i + k][j + m]]>1) return false;
						}
					}
				}
			}
		}
		return true;
	}
```
### 推荐解法：
The variable k so nicely maps all the cells belonging to the same box to the same element of used3.

k is mapping the 9x9 grid into a 3x3 grid of boxes like below:

0 | 1 | 2<br>
3 | 4 | 5<br>
6 | 7 | 8

还可以将三个used数组的类型改为bool，节约空间
```c
	bool isValidSudoku(vector<vector<char> > &board){
		int used1[9][9] = { 0 }, used2[9][9] = { 0 }, used3[9][9] = { 0 };

		for (int i = 0; i < board.size(); ++i)
			for (int j = 0; j < board[i].size(); ++j)
				if (board[i][j] != '.')
				{
					int num = board[i][j] - '0' - 1, k = i / 3 * 3 + j / 3;
					if (used1[i][num] || used2[j][num] || used3[k][num])
						return false;
					used1[i][num] = used2[j][num] = used3[k][num] = 1;
				}

		return true;
	}
```
