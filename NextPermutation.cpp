#include"leetCode.h"

void Solution::nextPermutation(vector<int>& nums) {
	auto it = nums.end() - 1;
	for (; it != nums.begin(); it--) {
		if (*it > *(it - 1)) {
			auto ij = it;
			int dt = (*it) - (*(it - 1));
			for (auto jt = it + 1; jt != nums.end(); jt++) {
				if ((*jt - (*(it - 1))) > 0 && (*jt - (*(it - 1))) <= dt) {
					ij = jt;
					dt = abs(*jt - (*(it - 1)));
				}
			}
			int temp = *(it - 1);
			*(it - 1) = *ij;
			*ij = temp;
			break;
		}
	}
	for (auto ij = nums.end() - 1;it < ij; it++, ij--) {
		int temp = *it;
		*it = *ij;
		*ij = temp;
	}
}