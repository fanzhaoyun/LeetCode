#include"leetCode.h"
/*
与3Sum相似，只不过此处用到了三重循环
*/
vector<vector<int>> Solution::fourSum(vector<int>& nums, int target) {
	vector<vector<int>> res;
	sort(nums.begin(), nums.end(), less<int>());
	for (int i = 0; i < nums.size(); i++) {
		int temp = target - nums[i];
		for (int j = i + 1; j < nums.size();j++) {
			int temp1 = temp - nums[j];
			int start = j + 1;
			int end = nums.size()-1;
			while (start < end) {
				int sum = nums[start] + nums[end];
				if (sum > temp1) {
					end--;
				}
				else if (sum < temp1) {
					start++;
				}
				else {
					vector<int> intemp;
					intemp.push_back(nums[i]);
					intemp.push_back(nums[j]);
					intemp.push_back(nums[start]);
					intemp.push_back(nums[end]);
					res.push_back(intemp);
					//处理num3重复
					while (start < end && intemp[2] == nums[start]) start++;
					//处理num4重复
					while (start < end && intemp[3] == nums[end]) end--;
				}
			}
			//处理num2重复
			while (j + 1 < nums.size() && nums[j] == nums[j + 1]) j++;
		}
		//处理num1重复
		while (i + 1 < nums.size() && nums[i] == nums[i + 1]) i++;
	}
	return res;
}