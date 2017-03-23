#include"leetCode.h"

/*
1.二分查找得到target值的位置
2.双指针从中间开始向两端查找
*/

vector<int> Solution::searchRange(vector<int>& nums, int target) {
	vector<int> res;
	int start = 0; 
	int end = nums.size() - 1;
	int temp = nums.size() - 1;
	int index = -1;
	int middle;
	while (start <= end) {
		middle = start + (end - start) / 2;
		if (target > nums[middle]) {
			start = middle + 1;
		}
		else if (target < nums[middle]) {
			end = middle - 1;
		}
		else {
			index = middle;
			break;
		}
	}
	if (index == -1) {
		start = -1;
		end = -1;
	}
	else {
		start = end = index;
		bool flag1 = true, flag2 = true;
		while ((flag1 && nums[start] == target) || (flag2 && nums[end] == target)) {
			if (flag1 && nums[start] == target) {
				start--;
			}
			if (flag2 && nums[end] == target) {
				end++;
			}
			if (start < 0) flag1 = false;
			if (end > temp) flag2 = false;
		}
		start++;
		end--;
	}
	res.push_back(start);
	res.push_back(end);

	return res;
}