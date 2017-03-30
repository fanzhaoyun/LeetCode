#include"leetCode.h"

int Solution::trap(vector<int>& height) {
	if (height.size() <= 2) return 0;
	int sum = 0;
	int start = 0, end = height.size() - 1;
	int n = 0,min = INT_MAX, lastmin = 0;
	while (height[start] == 0)start++;
	while (height[end] == 0) end--;
	while (start < end) {
		min = (height[start] > height[end] ? height[end] : height[start]);
		for (int i = start + 1; i < end; i++) {
			if (height[i] >= lastmin && height[i] < min) {
				sum += (min - height[i]);
			}
			else if(height[i] < lastmin){
				sum += (min - lastmin);
			}
		}
		while (height[start] <= min && start < end) start++;
		while (height[end] <= min && start < end) end--;
		lastmin = min;
	}
	return sum;
}