#include"leetCode.h"

void reverse(ListNode* &h1, ListNode* &temp2) {
	ListNode* t1 = h1;
	temp2->next = h1;
	h1 = temp2;
	temp2 = t1;
}

void reversen(ListNode* &h1, ListNode* &temp1,int k) {
	ListNode* temp2,*temp3;
	//每次交换两个指针
	temp2 = h1->next;
	while (k--) {
		temp3 = temp2->next; //保存下一次的开始
		reverse(h1, temp2);
		temp2 = temp3;
	}
	temp1 = temp2;
}

ListNode* Solution::reverseKGroup(ListNode* head, int k) {
	ListNode* h = head;
	ListNode* temp1,*ra=NULL,*op=NULL;
	int sum = 0;
	temp1 = head;
	h = head;
	while (temp1) {
		sum++;
		if (sum % k == 0) {
			ra = head;
			reversen(head,temp1,k-1);
			if (sum == k) {
				h = head;
				ra->next = nullptr;
				op = ra;
			}
			else {
				op->next = head;
				op = ra;
			}
			head = temp1;
			sum++;
		}
		if(temp1)
			temp1 = temp1->next;
	}
	if(ra)
		ra->next = head;
	return h;
}