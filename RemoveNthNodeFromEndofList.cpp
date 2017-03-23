#include"leetCode.h"
/*
������İ취����ʵ�����ڵ�һ������ܵ�������ʱ����һ������ָ�룬�����Ϳ���ֱ�ӴӺ���ǰ���ҡ�ʱ�临�Ӷ�һ����
*/

ListNode* Solution::removeNthFromEnd(ListNode* head, int n) {
	if (head == nullptr)
		return head;
	ListNode* temp = head;
	int total = 1;
	while (temp->next) {
		temp = temp->next;
		total++;
	}
	if (total == n) {
		return head->next;
	}
	total -= n; //ʵ��λ��Ӧ���ټ�1
	total--;
	temp = head;
	while (total > 0) {
		total--;
		temp = temp->next;
	}
	temp->next = temp->next->next;
	return head;
}