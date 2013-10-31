/*
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
*/

#include "stdafx.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *merged_dummy_head = new ListNode(0);
		ListNode *cur = merged_dummy_head;
        while (l1 != NULL && l2 != NULL) {
			if (l1->val < l2->val) {
				cur->next = l1;
				cur = l1;
				l1 = l1->next;
			} else {
				cur->next = l2;
				cur = l2;
				l2 = l2->next;
			}
		}
		if (l1 != NULL) {
			cur->next = l1;
		} else if (l2 != NULL) {
			cur->next = l2;
		}
		return merged_dummy_head->next;
    }
};
