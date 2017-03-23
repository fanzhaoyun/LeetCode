#include"leetCode.h"
/*
��������Ҫע�⣺ȥ�غ�˫ָ��
�ظ�������ֻ�ܼ���һ�Σ�˫ָ����������м�ƽ���
*/

vector<vector<int>> Solution::threeSum(vector<int>& nums) {
	vector<vector<int>> result;
	/*
	vector<int>::const_iterator iit;
	sort(nums.begin(), nums.end(), less<int>());
	for (auto it = nums.begin(); it != nums.end(); it++) {
		int target = -(*it);
		if (it != nums.begin() && (*it) == (*(it - 1)))
			continue;
		if (target < 0) break;
		vector<int> tempfind;
		for (auto itj = it+1; itj != nums.end(); itj++) {
			if (itj != it + 1 && (*itj) == (*(itj - 1))) {
				continue;
			}	
			iit = find(tempfind.cbegin(), tempfind.cend(), target - (*itj));
			if (iit != tempfind.end()) {
				vector<int> triplet(3, 0);
				triplet[0] = *it;
				triplet[1] = *itj;
				triplet[2] = *iit;
				result.push_back(triplet);
			}
			tempfind.push_back((*itj));
		}
	}
	*/

	sort(nums.begin(), nums.end(), less<int>());
	for (int i = 0; i < nums.size(); i++) {
		int target = -nums[i];
		int start = i+1;
		int end = nums.size()-1;
		if (target < 0) {
			break;
		}
		while (start < end) {
			int sum = nums[start] + nums[end];
			if (target > sum) {
				start++;
			}
			else if (target < sum) {
				end--;
			}
			else {
				vector<int> temp;
				temp.push_back(nums[i]);
				temp.push_back(nums[start]);
				temp.push_back(nums[end]);
				result.push_back(temp);
				//����number2�ظ�
				while (start < end && temp[1] == nums[start]) start++;
				//����bunber3�ظ�
				while (start < end && temp[2] == nums[end]) end--;
			}
		}
		//����number1�ظ�
		while (i+1 < nums.size() && nums[i] == nums[i + 1]) i++;
	}
	return result;
}