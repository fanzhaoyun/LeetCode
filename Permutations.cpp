#include"leetCode.h"

void dfs(vector<vector<int>> &res, vector<int>& nums, vector<int> temp, int n) {
	if (n == (nums.size()+temp.size())) {
		res.push_back(temp);
		return;
	}
	vector<int>::iterator ij;
	int i;
	for (i = 0; i < nums.size();i++) {
		ij = nums.begin();
		int copy = *ij;
		temp.push_back(copy);
		nums.erase(ij);
		dfs(res, nums, temp, n + 1);
		nums.push_back(copy);
		temp.pop_back();
	}
}

vector<vector<int>> Solution::permute(vector<int>& nums) {
	vector<vector<int>> res;
	vector<int>::iterator it;
	int i;
	for (i = 0; i < nums.size();i++) {
		vector<int> temp;
		it = nums.begin();
		int copy = *it;
		temp.push_back(copy);
		it = nums.erase(it);
		dfs(res, nums, temp, 1);
		nums.push_back(copy);
		temp.pop_back();
	}
	return res;
}