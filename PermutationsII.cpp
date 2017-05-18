#include"leetCode.h"

void undfs(vector<vector<int>> &res, vector<int> nums, vector<int> temp, int n) {
	if (n == 0) {
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
		undfs(res, nums, temp, n - 1);
		nums.push_back(copy);
		temp.pop_back();
		while((*nums.begin()) == copy && i < nums.size()) {
			i++;
			int t = *nums.begin();
			nums.erase(nums.begin());
			nums.push_back(t);
		}
	}
}

vector<vector<int>> Solution::permuteUnique(vector<int>& nums) {
	vector<vector<int>> res;
	vector<int> temp;
	sort(nums.begin(), nums.end(), less<int>());
	undfs(res, nums, temp, nums.size());
	return res;
}