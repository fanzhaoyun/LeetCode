#include"leetCode.h"

void backtrack(vector<string> &res, string str, int left, int right) {
	if (left == 0 && right == 0) {
		res.push_back(str);
		return;
	}
	if (left < 0 || right < 0) return;
	if (right < left) return;  //一定是先有左括号
	backtrack(res, str + ")", left, right-1);
	backtrack(res, str + "(", left-1,right);
	return;
}

vector<string> Solution::generateParenthesis(int n) {
	vector<string> res;
	backtrack(res,"(", n-1,n);
	return res;
}