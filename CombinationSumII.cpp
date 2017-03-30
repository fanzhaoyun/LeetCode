#include"leetCode.h"

void trackback2(vector<int>& candidates, int target, vector<vector<int>> &res, vector<int> tempres, int k) {
	for (int i = k; i < candidates.size(); i++) {
		if (candidates[i] < target) {
			tempres.push_back(candidates[i]);
			trackback2(candidates, target - candidates[i], res, tempres, i+1);
			tempres.pop_back();
			while ((i < candidates.size() - 1) && candidates[i] == candidates[i + 1]) i++;
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

vector<vector<int>> Solution::combinationSum2(vector<int>& candidates, int target) {
	vector<vector<int>> res;
	vector<int> tempres;
	sort(candidates.begin(), candidates.end(), less<int>());
	trackback2(candidates, target, res, tempres, 0);
	return res;
}