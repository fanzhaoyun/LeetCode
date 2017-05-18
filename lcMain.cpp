#include<iostream>
#include<Windows.h>
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
	string str1 = "aaa";
	string str2 = "***a";
	Solution solution;
	cout << solution.isMatch(str1,str2) << endl;
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
	string s[9] = { "..9748...","7........",".2.1.9...","..7...24.",".64.1.59.",".98...3..","...8.3.2.","........6","...2759.. "};
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

void test10() {
	Solution solution;
	vector<int> candidates;
	candidates.push_back(1);
	candidates.push_back(2);
	candidates.push_back(0);
	candidates.push_back(1);
	//candidates.push_back(4);
	//candidates.push_back(5);
	//candidates.push_back(7);
	//candidates.push_back(100);
	//candidates.push_back(2);
	//candidates.push_back(1);
	//candidates.push_back(2);
	//candidates.push_back(1);


	cout << solution.jump(candidates) << endl;
}

void test11() {
	Solution solution;
	vector<int> candidates;
	candidates.push_back(3);
	candidates.push_back(3);
	candidates.push_back(0);
	candidates.push_back(3);
	/*candidates.push_back(6);
	candidates.push_back(4);
	candidates.push_back(5);*/


	vector<vector<int>> res = solution.permuteUnique(candidates);
	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[i].size(); j++) {
			cout << res[i][j];
		}
		cout << endl;
	}
}

void test12() {
	Solution solution;
	vector<vector<int>> candidates;
	vector<int> c1, c2, c3;
	c1.push_back(2);
	c1.push_back(1);
	c1.push_back(3);

	c2.push_back(4);
	c2.push_back(5);
	c2.push_back(7);

	c3.push_back(9);
	c3.push_back(8);
	c3.push_back(10);

	candidates.push_back(c1);
	candidates.push_back(c2);
	candidates.push_back(c3);


	solution.rotate(candidates);
	for (int i = 0; i < candidates.size(); i++) {
		for (int j = 0; j < candidates[i].size(); j++) {
			cout << candidates[i][j]<<"\t";
		}
		cout << endl;
	}
}
void test13() {
	vector<string> strs;
	strs.push_back("eat");
	strs.push_back("tea");
	strs.push_back("tan");
	strs.push_back("ate");
	strs.push_back("nat");
	strs.push_back("bat");

	Solution solution;
	vector<vector<string>> board = solution.groupAnagrams(strs);
	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[i].size(); j++) {
			cout << board[i][j]<<" ";
		}
		cout << endl;
	}
}
void test14() {
	Solution solution;
	cout << solution.totalNQueens(2) << endl;
	/*for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[i].size(); j++) {
			cout << board[i][j] << " \n";
		}
		cout << endl;
	}*/
}
int main(int argc, char** argv) {
	cout << "·¶ÕÕÔÆ³öÆ·" << endl;
	LARGE_INTEGER t1, t2, tc;
	QueryPerformanceFrequency(&tc);
	QueryPerformanceCounter(&t1);
	test14();
	QueryPerformanceCounter(&t2);
	cout << "Use Time: " << (t2.QuadPart - t1.QuadPart)*1000.0 / tc.QuadPart << "ms"<<endl;
	system("pause");
	return 0;
}