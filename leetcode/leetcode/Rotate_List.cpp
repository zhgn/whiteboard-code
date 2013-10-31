/*
Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
 Given 1->2->3->4->5->NULL and k = 2,
 return 4->5->1->2->3->NULL.
*/

#include "stdafx.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
private:
	int getListLen(ListNode *head) {
		ListNode *cur = head;
		int count = 0;
		while (cur != NULL) {
			cur = cur->next;
			count++;
		}
		return count;
	}

public:
    ListNode *rotateRight(ListNode *head, int k) {
		if (head == NULL) {
			return NULL;
		}
		int len = getListLen(head);
		k %= len;
		if (k == 0) {
			return head;
		}

		ListNode *p_to_tail = head;
		for (int count=0; count<k; count++) {
			p_to_tail = p_to_tail->next;
		}
		ListNode *cur = head;
		while (p_to_tail->next != NULL) {
			p_to_tail = p_to_tail->next;
			cur = cur->next;
		}

		p_to_tail->next = head;
		head = cur->next;
		cur->next = NULL;
		return head;
    }
};
