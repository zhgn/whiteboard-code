/*
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
 
You should preserve the original relative order of the nodes in each of the two partitions.
 
For example,
 Given 1->4->3->2->5->2 and x = 3,
 return 1->2->2->4->3->5. 
*/

#include "stdafx.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
		ListNode *less_head = new ListNode(0);
		ListNode *greater_equal_head = new ListNode(0);
		ListNode *less_cur = less_head;
		ListNode *greater_equal_cur = greater_equal_head;
		ListNode *cur = head;
		while (cur != NULL) {
			if (cur->val < x) {
				less_cur->next = cur;
				less_cur = cur;
				cur = cur->next;
				less_cur->next = NULL;
			} else {
				greater_equal_cur->next = cur;
				greater_equal_cur = cur;
				cur = cur->next;
				greater_equal_cur->next = NULL;
			}
		}
		less_cur->next = greater_equal_head->next;
		return less_head->next;
    }
};
