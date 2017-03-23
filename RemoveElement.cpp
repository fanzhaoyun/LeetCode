#include"leetCode.h"

int Solution::removeElement(vector<int>& nums, int val) {
	int length = 0;
	for (int i = 0; i < nums.size(); i++) {
		if (nums[i] != val) {
			nums[length++] = nums[i];
		}		
	}
	if (length == 0) nums.clear();
	return length;
}