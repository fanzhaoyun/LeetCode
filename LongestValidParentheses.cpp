#include"leetCode.h"

/*
���������˱����ⷨ��ʱ�临�ӶȱȽϸߣ����ս����336ms��
��ջ�Ľⷨ�ǲο��˼ҵģ�����������ַ����з������е���ʼλ�ã�Ȼ�����������ֵ��
dp�ⷨ������µ��ַ�Ϊ(��ֱ����f[i]Ϊ0����������뵱ǰ��ƥ���ǰһ��λ�����ģ�ǰһ��λ�ÿ���(i - f[i-1]-1)ȷ��
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
