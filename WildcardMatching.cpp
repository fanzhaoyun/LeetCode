#include"leetCode.h"

int dfs(string s, string p, int si, int pi) {
	if (si == s.size()) {
		while (p.size() > pi && p[pi] == '*') pi++;
		if (pi == p.size()) {
			return 1;
		}
		return 0;
	}
	if (pi == p.size()) return 2;
	if (p[pi] == '?' || s[si] == p[pi]) {
		return dfs(s, p, si + 1, pi + 1);
	}
	if (p[pi] == '*') {
		while (p.size() > pi && p[pi] == '*')pi++;
		pi--;
		for (int i = 0; i <= s.size() - si; i++) {
			int res = dfs(s, p, si + i, pi + 1);
			if (res == 0 || res == 1) return res;
		}
	}
	return 2;
}

//bool dfs(string s, string p, int si, int pi) {
//	if (s.empty()) {
//		while (p.length() > 0 && p[0] == '*') p = p.substr(1);
//		if (p.empty()) {
//			return true;
//		}
//
//		return false;
//	}
//	if (!p.empty()) {
//		if (p[0] == '?' || s[0] == p[0]) {
//			res = isMatch(s.substr(1), p.substr(1));
//
//		}
//		else if (p[0] == '*') {
//			int index = 1;
//			while (p.size() > 0 && p[index] == '*')index++;
//			p = p.substr(index - 1);
//			if (p.size() > 1 && s[0] == p[1]) {
//				res = isMatch(s.substr(1), p.substr(2));
//			}
//			if (res == false) res = isMatch(s.substr(1), p);
//			if (res == false) res = isMatch(s, p.substr(1));
//		}
//		else {
//			return false;
//		}
//	}
//	else {
//		return false;
//	}
//	return res;
//}

bool Solution::isMatch(string s, string p) {
	return dfs(s,p,0,0)==1;
	
}