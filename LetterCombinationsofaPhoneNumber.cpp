#include"leetCode.h"

/*
另一种更快的方法是直接添加一个数字对应的字母。
*/

char dig[10][4] = { { ' ',' ',' ',' ' },{ ' ',' ',' ',' ' } ,{ 'a','b','c',' ' },
{ 'd','e','f',' ' },{ 'g','h','i',' ' },{ 'j','k','l',' ' },{ 'm','n','o',' ' },
{ 'p','q','r','s' } ,{ 't','u','v',' ' } ,{ 'w','x','y','z' } };

void backtracking(vector<string> &res, string objstr, string srcstr) {
	if (srcstr.length() == 0) {
		res.push_back(objstr);
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (dig[srcstr[0] - '0'][i] != ' ') {
					backtracking(res, objstr+dig[srcstr[0] - '0'][i], srcstr.substr(1));
		}
	}
	return;
}

vector<string> Solution::letterCombinations(string digits) {
	
	vector<string> res;
	string obj = "";
	if (digits.length() != 0) {
		for (int i = 0; i < 4; i++) {
			if(dig[digits[0]-'0'][i]!=' ')
				backtracking(res,obj+dig[digits[0] - '0'][i], digits.substr(1));
		}
	}
	
	
	return res;
}

