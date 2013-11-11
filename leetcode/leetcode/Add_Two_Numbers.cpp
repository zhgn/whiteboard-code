/*
You are given two linked lists representing two non-negative numbers. 
The digits are stored in reverse order and each of their nodes contain a single digit. 
Add the two numbers and return it as a linked list.
 
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
*/

#include "stdafx.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *dummy_head = new ListNode(0);
        ListNode *cur = dummy_head;
        int plus = 0;
        while (l1 != NULL || l2 != NULL) {   
            cur->next = new ListNode(plus);
            cur = cur->next;
            if (l1 != NULL) {
                cur->val += l1->val;
                l1 = l1->next;
            }
            if (l2 != NULL) {
                cur->val += l2->val;
                l2 = l2->next;
            }            
            plus = cur->val / 10;
            cur->val %= 10;            
        }
        if (plus > 0) {
            cur->next = new ListNode(plus);
        }
        return dummy_head->next;
    }
};
