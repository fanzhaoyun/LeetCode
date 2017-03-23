#include"leetCode.h"
/*
方法1：利用分治思想，类似于归并排序，不断的将两个链表缩小然后合并，之后再不断的扩大链表。
方法2：将所有链表的第一个元素拿出来放入小顶堆中，将堆顶的元素取出作为第一个，然后把原来最小的链表移动到下一个位置，取出一个元素放入堆中，再从堆中拿走
堆顶的数，重复此过程直到vector为空
*/
ListNode* mergeLists(ListNode* l1, ListNode* l2) {
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

ListNode* mergesort(vector<ListNode*>& lists, int first, int last) {
	if (last - first == 0) return lists[first];
	if(last - first == 1) return mergeLists(lists[first], lists[last]);
	int mid = (first + last) / 2;
	ListNode* r1 = mergesort(lists, first, mid);
	ListNode* r2 = mergesort(lists, mid+1, last);
	return mergeLists(r1, r2);
}

ListNode* Solution::mergeKLists(vector<ListNode*>& lists) {
	if (lists.size() == 0) return nullptr;
	if (lists.size() == 1) return lists[0];
	ListNode* res = mergesort(lists, 0, lists.size() - 1);
	return res;
}