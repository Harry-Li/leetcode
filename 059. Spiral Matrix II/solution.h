#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
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
};
