#include"leetCode.h"

/*
1.沿顺时针方向对角线做对称变换
2.变换后的矩阵沿水平方向对称
*/

void Solution::rotate(vector<vector<int>>& matrix) {
	int n = matrix.size() - 1,m;
	int temp;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < (n - i);j++) {
			temp = matrix[i][j];
			matrix[i][j] = matrix[n - j][n - i];
			matrix[n - j][n - i] = temp;
		}
	}
	n++;
	m = n / 2;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n;j++) {
			temp = matrix[i][j];
			matrix[i][j] = matrix[n - i - 1][j];
			matrix[n - i - 1][j] = temp;
		}
	}
}