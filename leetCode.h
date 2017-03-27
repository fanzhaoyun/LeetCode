#pragma once
#include<string>
#include<vector>
#include<limits>
#include<algorithm>
#include<set>
#include<map>
#include<stack>
#include<unordered_map>

#include"dataStruct.h"

using namespace std;

class Solution {
public:
	int romanToInt(string s);
	string longestCommonPrefix(vector<string>& strs);
	vector<vector<int>> threeSum(vector<int>& nums);
	int threeSumClosest(vector<int>& nums, int target);
	vector<string> letterCombinations(string digits);
	vector<vector<int>> fourSum(vector<int>& nums, int target);
	ListNode* removeNthFromEnd(ListNode* head, int n);
	bool isValid(string s);
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2);
	vector<string> generateParenthesis(int n);
	ListNode* mergeKLists(vector<ListNode*>& lists);
	ListNode* swapPairs(ListNode* head);
	ListNode* reverseKGroup(ListNode* head, int k);
	int removeDuplicates(vector<int>& nums);
	int removeElement(vector<int>& nums, int val);
	int strStr(string haystack, string needle);
	int divide(int dividend, int divisor);
	vector<int> findSubstring(string s, vector<string>& words);
	void nextPermutation(vector<int>& nums);
	int longestValidParentheses(string s);
	int search(vector<int>& nums, int target);
	vector<int> searchRange(vector<int>& nums, int target);
	int searchInsert(vector<int>& nums, int target);
	bool isValidSudoku(vector<vector<char>>& board);
	void solveSudoku(vector<vector<char>>& board);
};
