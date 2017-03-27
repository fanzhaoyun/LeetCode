#include<iostream>
#include"leetCode.h"

void test1() {
	vector<int> test;
	test.push_back(1);
	test.push_back(0);
	test.push_back(-1);
	test.push_back(0);
	test.push_back(-2);
	test.push_back(2);

	Solution solution;
	vector<vector<int>> result = solution.fourSum(test, 0);
	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < result[i].size(); j++) {
			cout << result[i][j] << " ";
		}
		cout << endl;
	}
}
void test2() {
	ListNode l1(1), l2(3), l3(4), l4(7), l5(8);
	ListNode ll1(10), ll2(20), ll3(30), ll4(100), ll5(101);
	ListNode l21(2), l22(4), l23(6), l24(9), l25(11);
	l1.next = &l2;
	l2.next = &l3;
	l3.next = &l4;
	l4.next = &l5;
	ll1.next = &ll2;
	ll2.next = &ll3;
	ll3.next = &ll4;
	ll4.next = &ll5;
	l21.next = &l22;
	l22.next = &l23;
	l23.next = &l24;
	l24.next = &l25;
	vector<ListNode*> src;
	src.push_back(&l1);
	src.push_back(&ll1);
	src.push_back(&l21);
	Solution solution;
	ListNode *p = solution.mergeKLists(src);
	while (p) {
		cout << p->val << "->";
		p = p->next;
	}
	cout << endl;
}
void test3() {
	Solution solution;
	//cout << solution.isValid("") << endl;
	vector<string> res = solution.generateParenthesis(10);
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << endl;
	}
}
void test4() {
	ListNode l1(1), l2(2), l3(3), l4(4), l5(8),l6(100);
	l1.next = &l2;
	l2.next = &l3;
	l3.next = &l4;
	l4.next = &l5;
	l5.next = &l6;
	Solution solution;
	ListNode *p = solution.reverseKGroup(&l1,100);
	while (p) {
		cout << p->val << "->";
		p = p->next;
	}
	cout << endl;
}
void test5() {
	vector<int> nums;
	nums.push_back(1);
	/*	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(4);
	nums.push_back(5);
	nums.push_back(6);
	nums.push_back(7);
	nums.push_back(8);
	nums.push_back(9);
	nums.push_back(9);*/

	Solution solution;
	cout << solution.removeElement(nums,2) << endl;
	for (int i = 0; i < nums.size(); i++) {
		cout << nums[i] << " ";
	}
	cout << endl;
}
void test6() {
	string str1 = "(()((()";
	string str2 = "";
	Solution solution;
	cout << solution.longestValidParentheses(str1) << endl;
}
void test7() {
	vector<string> words;
	words.push_back("word");
	words.push_back("good");
	words.push_back("best");
	words.push_back("good");
	Solution solution;
	//cout << solution.divide(-2147483648,1)<< endl;
	vector<int> res = solution.findSubstring("wordgoodgoodgoodbestword",words);
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << endl;
	}
}
void test8() {
	Solution solution;
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(3);
	nums.push_back(5);
	nums.push_back(6);
	//nums.push_back(2);
	//nums.push_back(10);
	//nums.push_back(8);
	cout << solution.searchInsert(nums, 0) << endl;
	/*for (int i = 0; i < res.size(); i++) {
		cout << res[i] << " ";
	}
	cout << endl;*/
}
void test9() {
	string s[9] = { "....5..1.",".4.3.....",".....3..1","8......2.","..2.7....",".15......",".....2...",".2.9.....","..4......" };
	vector<vector<char>> board;
	Solution solution;
	for (int i = 0; i < 9; i++) {
		vector<char> temp;
		for (int j = 0; j < s[i].length(); j++) {
			temp.push_back(s[i][j]);
		}
		board.push_back(temp);
	}
	solution.solveSudoku(board);
	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[i].size(); j++) {
			cout << board[i][j];
		}
		cout << endl;
	}
}

int main(int argc, char** argv) {
	cout << "·¶ÕÕÔÆ³öÆ·" << endl;
	cout << 6 / 3 * 3<< endl;
	test9();
	system("pause");
	return 0;
}