#include"leetCode.h"

int Solution::removeDuplicates(vector<int>& nums) {
	int length = 1;
	if (nums.size() < 2) return nums.size();
	vector<int>::iterator it, jt;
	for (it = nums.begin(), jt = it+1; jt != nums.end();) {
		if (*it != *jt) {
			length++;
			it++;
			jt++;
		}
		else {
			it = nums.erase(it);
			jt = it + 1;
		}
	}
	return length;
}