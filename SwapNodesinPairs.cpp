#include"leetCode.h"

ListNode* Solution::swapPairs(ListNode* head) {
	if (head == nullptr || head->next==nullptr) return head;
	ListNode* temp = head, *p1;
	head = head->next;
	temp->next = head->next;
	head->next = temp;
	p1 = temp->next;
	ListNode* pp = p1;
	while (pp && pp->next) {
		temp->next = p1->next;
		temp = temp->next;
		p1 = temp->next; //��¼ָ��
		temp->next = pp;
		temp = temp->next;
		pp->next = p1;  //����ָ��
		pp = pp->next;
	}
	return head;
}