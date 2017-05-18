#include"leetCode.h"

/*
bool isvaile(int x, int y, vector<pair<int, int>> vail) {
	for (int i = 0; i < vail.size(); i++) {
		if (abs(x - vail[i].first) == abs(y - vail[i].second)) return false;
	}
	return true;
}

void dfs(vector<vector<string>> &res, vector<string> temp, int ia[], int x, int y, int id,bool *flag[2], vector<pair<int, int>> vail) {
	if (id == 0) {
		res.push_back(temp);
	}
	
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (abs(ia[i]) != abs(ia[j])) {
				int xx = x + ia[i];
				int yy = y + ia[j];
				if (xx < 0 || yy < 0 || xx >= temp.size() || yy >= temp.size()) continue;
				if (temp[xx][yy] == 'Q' || flag[0][xx] || flag[1][yy]) continue;
				if (!isvaile(xx, yy, vail)) continue;
				temp[xx][yy] = 'Q';
				flag[0][xx] = true;
				flag[1][yy] = true;
				vail.push_back(make_pair(xx, yy));
				dfs(res, temp, ia, xx, yy, id - 1,flag,vail);
				vail.pop_back();
				flag[0][xx] = false;
				flag[1][yy] = false;
				temp[xx][yy] = '.';
			}
		}
	}
}

vector<vector<string>> Solution::solveNQueens(int n) {
	int ia[4] = { -2,-1,1,2 };
	bool *flag[2];
	flag[0] = new bool[n];
	flag[1] = new bool[n];
	vector<vector<string>> res;
	vector<string> strs;
	vector<pair<int, int>> vail;
	string str(n, '.');
	for(int i = 0; i < n; i++){ 
		strs.push_back(str);
	}
	for (int i = 0; i < n; i++) {
		vector<string> temp = strs;
		memset(flag[0], 0, sizeof(bool)*n);
		memset(flag[1], 0, sizeof(bool)*n);
		temp[0][i] = 'Q';
		flag[0][0] = true;
		flag[1][i] = true;
		vail.push_back(make_pair(0, i));
		dfs(res,temp,ia,0,i,n-1, flag,vail);
		vail.pop_back();
	}
	return res;
}
*/

bool check(int x, int y, vector<pair<int, int>> vail) {
	for (int i = 0; i < vail.size(); i++) {
		if (x == vail[i].first || y == vail[i].second) return false;
		if (abs(x - vail[i].first) == abs(y - vail[i].second)) return false;
	}
	return true;
}
void dfs(vector<vector<string>> &res, vector<string> temp, int x, int y, vector<pair<int, int>> vail, int n) {
	if (x == n) {
		res.push_back(temp);
	}
	else {
		for(int i = 0; i < n; i++) {
			if (check(x, i, vail)) {
				temp[x][i] = 'Q';
				vail.push_back(make_pair(x, i));
				dfs(res, temp, x + 1, 0, vail, n);
				temp[x][i] = '.';
				vail.pop_back();
			}	
		}
	}
	
	/*
	if (check(x,y,vail)) {
		temp[x][y] = 'Q';
		if (x == n - 1) {
			res.push_back(temp);
			return;
		}
		vail.push_back(make_pair(x, y));
		for (int i = 0; i < n; i++) {
			
			dfs(res, temp, x + 1, i, vail, n);
		}
		temp[x][y] = '.';
		vail.pop_back();
	}
	else {
		if (y == n - 1)
			return;
		dfs(res, temp, x, y+1, vail, n);
	}
	*/
}

vector<vector<string>> Solution::solveNQueens(int n) {
	vector<vector<string>> res;
	vector<string> strs;
	vector<pair<int, int>> vail;
	string str(n, '.');
	for (int i = 0; i < n; i++) {
		strs.push_back(str);
	}
	dfs(res, strs, 0, 0, vail, n);
	/*for (int i = 0; i < n; i++) {
		vector<string> temp = strs;
		dfs(res, strs, 0, i, vail, n);
	}*/
	return res;
}