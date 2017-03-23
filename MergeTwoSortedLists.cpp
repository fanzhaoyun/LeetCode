#include"leetCode.h"

ListNode* Solution::mergeTwoLists(ListNode* l1, ListNode* l2) {
	ListNode* head, *temp;;
	if (!l1) return l2;
	if (!l2) return l1;
	if (l1->val < l2->val) {
		head = l1;
		l1 = l1->next;
	}
	else {
		head = l2;
		l2 = l2->next;
	}
	temp = head;
	while (l1 && l2) {
		if (l1->val < l2->val) {
			head->next = l1;
			head = head->next;
			l1 = l1->next;
		}
		else {
			head->next = l2;
			head = head->next;
			l2 = l2->next;
		}
	}
	while (l1) {
		head->next = l1;
		head = head->next;
		l1 = l1->next;
	}
	while (l2) {
		head->next = l2;
		head = head->next;
		l2 = l2->next;
	}
	return temp;
}