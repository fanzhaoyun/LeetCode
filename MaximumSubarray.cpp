#include"leetCode.h"

int Solution::maxSubArray(vector<int>& nums) {
	if (nums.size() == 0) return 0;
	int sum = 0, maxSum;
	maxSum = nums[0];
	for (int i = 0; i < nums.size(); i++) {
		sum += nums[i];
		if (sum > maxSum) maxSum = sum;
		if (sum < 0) sum = 0;
	}
	return maxSum;
}