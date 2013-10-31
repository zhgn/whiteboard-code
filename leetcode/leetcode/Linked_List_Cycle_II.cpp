/*
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
 
Follow up:
 Can you solve it without using extra space? 
*/

#include "stdafx.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Assume that there is x steps to get the begin of cycle, then first meeting pos is just needs x more steps to return there.
class Solution {
private:
	ListNode *meet(ListNode *p, ListNode *q) {
		while (p != q) {
			p = p->next;
			q = q->next;
		}
		return p;
	}

public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head;
		ListNode *slow = head;

		while (fast != NULL && fast->next != NULL) {
			fast = fast->next->next;
			slow = slow->next;
			if (fast == slow) {
				return meet(head, fast);
			}
		}
		return NULL;    
    }
};
