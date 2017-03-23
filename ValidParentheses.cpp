#include"leetCode.h"

bool Solution::isValid(string s) {
	stack<char> ss;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
			ss.push(s[i]);
		}
		else {
			if (ss.empty())
				return false;
			if ((s[i] == ')'&&ss.top() == '(') || (s[i] == ']'&&ss.top() == '[') || (s[i] == '}'&&ss.top() == '{'))
				ss.pop();
			else
				return false;
		}
	}
	if (!ss.empty())
		return false;
	return true;
}