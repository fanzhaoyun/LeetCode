#include"leetCode.h"

string Solution::longestCommonPrefix(vector<string>& strs) {
	if (strs.size() == 0)
		return "";
	string comstr = "";
	bool flag = true;
	int minlength = INT_MAX;
	for (auto it = strs.cbegin(); it != strs.cend(); it++) {
		if ((*it).length() < minlength) {
			minlength = (*it).length();
		}
	}
	for (int j = 0; j < minlength; j++) {
		char str = strs.at(0)[j];
		for (auto it = strs.cbegin(); it != strs.cend(); it++) {
			if (str == (*it)[j])
				continue;
			else {
				flag = false;
				break;
			}
				
		}
		if (flag)
			comstr += str;
		else
			break;
	}
	return comstr;
}