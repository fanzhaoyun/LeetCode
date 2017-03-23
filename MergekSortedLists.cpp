#include"leetCode.h"
/*
����1�����÷���˼�룬�����ڹ鲢���򣬲��ϵĽ�����������СȻ��ϲ���֮���ٲ��ϵ���������
����2������������ĵ�һ��Ԫ���ó�������С�����У����Ѷ���Ԫ��ȡ����Ϊ��һ����Ȼ���ԭ����С�������ƶ�����һ��λ�ã�ȡ��һ��Ԫ�ط�����У��ٴӶ�������
�Ѷ��������ظ��˹���ֱ��vectorΪ��
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