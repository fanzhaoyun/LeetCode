#include"leetCode.h"

void trackback(vector<int>& candidates, int target, vector<vector<int>> &res, vector<int> tempres,int k) {
	for (int i = k; i < candidates.size(); i++) {		
		if (candidates[i] < target) {
			tempres.push_back(candidates[i]);
			trackback(candidates, target - candidates[i], res, tempres, i);
			tempres.pop_back();
		}
		else if (target == candidates[i]) {
			tempres.push_back(candidates[i]);
			res.push_back(tempres);
			return;
		}
		else {
			break;
		}
			
	}
}

vector<vector<int>> Solution::combinationSum(vector<int>& candidates, int target) {
	vector<vector<int>> res;
	vector<int> tempres;
	sort(candidates.begin(), candidates.end(), less<int>());
	trackback(candidates, target, res, tempres,0);
	return res;
}