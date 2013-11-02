/*
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
 
If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

 For example,
 Given this linked list: 1->2->3->4->5 

For k = 2, you should return: 2->1->4->3->5 

For k = 3, you should return: 3->2->1->4->5 
*/

#include "stdafx.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
private:
	bool reverse_k_nodes(ListNode *&pre_head, int k) {
		ListNode *tail = pre_head;
		for (int i=0; i<k; i++) {
			if (tail != NULL) {
				tail = tail->next;
			} else {
				return false;
			}			
		}
        if (tail == NULL) {
            return false;
        }
        
        ListNode *cur = pre_head->next;
        ListNode *pre = tail->next;
        ListNode *stop = tail->next;
        while (cur != stop) {
            ListNode *next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        ListNode *next_pre_head = pre_head->next;
        pre_head->next = tail;
        pre_head = next_pre_head;
        return true;
	}

public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        ListNode *dummy_head = new ListNode(0);
		dummy_head->next = head;		
		ListNode *pre_head = dummy_head;        
		while (reverse_k_nodes(pre_head, k)) {
			;
		}
		return dummy_head->next;
    }
};
