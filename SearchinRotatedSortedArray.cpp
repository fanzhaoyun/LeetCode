#include"leetCode.h"

/*
1.判断目标值在旋转排序列的哪一部分
2.找到分割点，在其中运用二分查找
*/


int Solution::search(vector<int>& nums, int target) {
	int start = 0;
	int end = nums.size() - 1;
	int middle = -1;
	int res = -1;
	if (nums.size() == 0) return -1;
	int temp = nums[0];
	for (int i = 1; i < nums.size(); i++) {
		if (nums[i] < nums[i - 1]) {
			middle = i - 1;
			break;
		}
	}
	if (middle != -1) {
		if (target >= nums[start] && target <= nums[middle]) {
			end = middle;
		}
		else {
			start = middle + 1;
		}
	}

	while (start <= end) {
		middle = start + (end - start) / 2;
		if (target > nums[middle]) {
			start = middle + 1;
		}
		else if(target < nums[middle]){
			end = middle - 1;
		}
		else {
			res = middle;
			break;
		}
	}

	return res;
}