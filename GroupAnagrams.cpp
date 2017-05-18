#include"leetCode.h"


vector<vector<string>> Solution::groupAnagrams(vector<string>& strs) {
	unordered_map<string, int> findstr;
	vector<vector<string>> res;
	int index = 1;
	for (int i = 0; i < strs.size(); i++) {
		string temp = strs[i];
		sort(temp.begin(), temp.end());
		if (findstr[temp]) {
			res[findstr[temp] - 1].push_back(strs[i]);
		}
		else {
			vector<string> ts;
			ts.push_back(strs[i]);
			res.push_back(ts);
			findstr[temp] = index++;
		}
	}
	return res;
}