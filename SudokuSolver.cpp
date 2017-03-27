#include"leetCode.h"

bool check(vector<vector<char>>& board, char ch, int row, int col) {
	for (int i = 0; i < board.size(); i++) {
		if (board[row][i] == ch || board[i][col] == ch)
			return false;
	}
	int x = row / 3 * 3;
	int y = col / 3 * 3;
	for (int xx = x;xx < x + 3; xx++) {
		for (int yy = y; yy < y + 3; yy++) {
			if (board[x][y] == ch) return false;
		}
	}
	return true;
}


bool sign = false;
int sudokuBack(vector<vector<char>>& board, int row, int col) {
	if (row >= board.size()) {
		sign = true;
		return 0;
	}
	if (board[row][col] == '.') {
		for (int i = 1; i <= 9; i++) {
			if (check(board, i + '0', row, col)) {
				board[row][col] = i + '0';
				if (col == 8) {
					sudokuBack(board, row + 1, 0);
				}
				else {
					sudokuBack(board, row, col + 1);
				}
				if (sign) return 0;
				board[row][col] = '.';
			}
		}
	}
	else {
		if (col == 8) {
			sudokuBack(board, row + 1, 0);
		}
		else {
			sudokuBack(board, row, col + 1);
		}	
	}
}

void Solution::solveSudoku(vector<vector<char>>& board) {
	sudokuBack(board,0,0);
}