#include"leetCode.h"
/*
��ƪ�����ᰡ������Ŀ��˼�����ˣ�Ȼ��һֱ��������
˼·�ܼ򵥣�ÿһ���ߵĶ�Ҫ��󣬽�ϵ�ǰ��Ծ���Ⱥ���һ����Ծ���ȣ�ÿ�ζ�ѡ�����߽�ϵ����ֵ��Ϊ�����Ծ����
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