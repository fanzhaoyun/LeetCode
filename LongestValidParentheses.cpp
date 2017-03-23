#include"leetCode.h"

/*
此题我用了暴力解法，时间复杂度比较高，最终结果是336ms。
用栈的解法是参考人家的，大意是求出字符串中符合序列的起始位置，然后做差求最大值。
dp解法是如果新的字符为(则直接置f[i]为0，否则计算与当前）匹配的前一个位置在哪，前一个位置可用(i - f[i-1]-1)确定
*/

int Solution::longestValidParentheses(string s) {
	
	int res = 0;
	int rightNum = 0, leftNum = 0;
	for (int i = 0; i < s.length(); i++) {
		rightNum = 0;
		leftNum = 0;
		for (int j = i; j < s.length(); j++) {
			if (s[j] == '(') leftNum++;
			else rightNum++;
			if (rightNum > leftNum) break;
			if (leftNum > (rightNum + s.length() - j)) break;
			if (leftNum == rightNum) {
				if (res < leftNum) res = leftNum;
			}
		}
	}
	return res * 2;
	/*
	stack<int> st;
	for (int i = 0; i < s.size(); ++i) {
		if (!st.empty() && s[i] == ')' && s[st.top()] == '(') st.pop();
		else st.push(i);
	}
	int res = 0;
	int pre = s.size();
	while (!st.empty()) {
		int t = pre - st.top() - 1;
		if (t > res) res = t;
		pre = st.top();
		st.pop();
	}
	if (pre > res) res = pre;
	return res;
	*/
}
