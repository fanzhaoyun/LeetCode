#include"leetCode.h"
/*
�ⷨͬ3Sum��3Sum��Ŀ�����ҵ��������ĺ�Ϊ0�������Ŀ�����ҵ���������Ϊһ��Ŀ������target),
ͬ������ת��Ϊ���������ĺ�Ϊ0���ٶ�������Ϊnumber1��number2,nuber3����Ϊ0��Ŀ�����ҵ�������number2,nuber3�ĺ�Ϊ-number1��
���ںͲ�Ϊ0������ֻ��Ҫ�ҵ�һ���ƽ�number2,nuber3��Ϊ-(number1 - target)������Ϊ�⡣
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