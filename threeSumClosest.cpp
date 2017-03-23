#include"leetCode.h"
/*
解法同3Sum。3Sum中目的是找到三个数的和为0，这里的目的是找到三个数和为一个目标数（target),
同样可以转化为找三个数的和为0，假定三个数为number1，number2,nuber3，和为0的目标是找到两个数number2,nuber3的和为-number1，
现在和不为0，我们只需要找到一个逼近number2,nuber3和为-(number1 - target)的数即为解。
*/
int Solution::threeSumClosest(vector<int>& nums, int target) {
	int closest = INT_MAX;
	int res = INT_MAX;
	sort(nums.begin(), nums.end(), less<int>());
	for (int i = 0; i < nums.size(); i++) {
		int num = -(nums[i] - target);
		int start = i + 1;
		int end = nums.size() - 1;
		if (res == target) {
			break;
		}
		int sum = closest;
		while (start < end) {
			sum = nums[start] + nums[end];
			if (abs(num - sum) < closest) {
				closest = abs(num - sum);
				res = sum + nums[i];
			}
				
			if (num > sum) {
				start++;
			}
			else if (num < sum) {
				end--;
			}
			else {
				res = target;
				break;
			}
		}
		
	}
	return res;
}