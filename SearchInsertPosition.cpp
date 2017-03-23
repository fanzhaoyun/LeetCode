#include"leetCode.h"

/*
if middle²»ÊÇnums - 1 return middle£¬else return middle+1
*/

int Solution::searchInsert(vector<int>& nums, int target) {
	int start = 0;
	int end = nums.size() - 1;
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
			return middle;
		}
	}
	//if (nums[middle] < target) middle += 1;
	return start;
}