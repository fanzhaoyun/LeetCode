#include"leetCode.h"

/*
验证行和列即可判断当前是否有效
验证每个3*3框内是否有效
此处所用方式视角复杂度较高，计算效率太慢，可用位操作判断，不重复即让每个数之间做或运算，再用或运算的结果与新加入数移位后的结果与运算。
*/

bool Solution::isValidSudoku(vector<vector<char>>& board) {
	unordered_map<char, int> checkMap;
	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[i].size(); j++) {
			if (checkMap[board[i][j]] == 0) {
				checkMap[board[i][j]] = j+1;
			}
			else {
				if(board[i][j] != '.')
					return false;
			}
		}
		checkMap.clear();
	}
	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[i].size(); j++) {
			if (checkMap[board[j][i]] == 0) {
				checkMap[board[j][i]] = j + 1;
			}
			else {
				if (board[j][i] != '.')
					return false;
			}
		}
		checkMap.clear();
	}
	for (int i = 0; i < board.size(); i += 3) {
		for (int j = 0; j < 9; j += 3) {
			for (int m = i; m < i+3; m++) {
				for (int n = j; n < j+3; n++) {
					if (checkMap[board[m][n]] == 0) {
						checkMap[board[m][n]] = j + 1;
					}
					else {
						if (board[m][n] != '.')
							return false;
					}

				}
			}
			checkMap.clear();
		}
	}
	return true;
}