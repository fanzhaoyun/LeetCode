#include"leetCode.h"

bool mycheck(int x, int y, vector<pair<int, int>> vail) {
	for (int i = 0; i < vail.size(); i++) {
		if (x == vail[i].first || y == vail[i].second) return false;
		if (abs(x - vail[i].first) == abs(y - vail[i].second)) return false;
	}
	return true;
}
void dfs(int &res, int x, vector<pair<int, int>> vail, int n) {
	if (x == n) {
		res++;
	}
	else {
		for (int i = 0; i < n; i++) {
			if (mycheck(x, i, vail)) {
				vail.push_back(make_pair(x, i));
				dfs(res,x + 1, vail, n);
				vail.pop_back();
			}
		}
	}
}

int Solution::totalNQueens(int n) {
	int res = 0;
	vector<pair<int, int>> vail;
	dfs(res, 0,vail, n);
	return res;
}