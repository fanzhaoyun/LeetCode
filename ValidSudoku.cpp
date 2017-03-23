#include"leetCode.h"

/*
��֤�к��м����жϵ�ǰ�Ƿ���Ч
��֤ÿ��3*3�����Ƿ���Ч
�˴����÷�ʽ�ӽǸ��ӶȽϸߣ�����Ч��̫��������λ�����жϣ����ظ�����ÿ����֮���������㣬���û�����Ľ�����¼�������λ��Ľ�������㡣
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