#include"leetCode.h"
/*
这是最笨的办法，其实可以在第一遍遍历总的链表长度时设置一个反向指针，这样就可以直接从后往前查找。时间复杂度一样。
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
	total -= n; //实际位置应该再加1
	total--;
	temp = head;
	while (total > 0) {
		total--;
		temp = temp->next;
	}
	temp->next = temp->next->next;
	return head;
}