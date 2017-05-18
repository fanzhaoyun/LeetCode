#include"leetCode.h"
/*
满篇的心酸啊！把题目意思理解错了，然后一直过不掉。
思路很简单，每一次走的都要最大，结合当前跳跃长度和下一次跳跃长度，每次都选择两者结合的最大值作为最佳跳跃长度
*/

int Solution::jump(vector<int>& nums) {
	int res = 0;
	int step = 0;
	if (nums.size() <= 1) return 0;
	for (int i = 0; i < nums.size();) {
		res++;
		if (i + nums[i] >= nums.size() - 1) return res;
		int maxstep = nums[i] + nums[i + nums[i]];
		step = i + nums[i];
		for (int j = 1; j < nums[i];j++) {
			int temp = j + nums[i + j];
			if (temp > maxstep) {
				maxstep = temp;
				step = i + j;
			}
		}
		i = step;
	}
	return res;
}