#include"leetCode.h"

/*
利用已有空间排序，排好序之后查找就很easy了
*/

int Solution::firstMissingPositive(vector<int>& nums) {
	for (int i = 0; i < nums.size(); i++) {
		if (nums[i] > 0 && i != (nums[i] - 1) && nums[i] < nums.size()){
			int temp = nums[nums[i]- 1];
			if (temp == nums[i]) continue;
			nums[nums[i] - 1] = nums[i];
			nums[i] = temp;
			i--;
		}
	}
	int i = 0;
	for (; i < nums.size(); i++) {
		if (i != (nums[i] - 1)) {
			return i+1;
		}
	}
	return i+1;
}