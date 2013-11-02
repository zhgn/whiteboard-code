/*
Given a linked list, swap every two adjacent nodes and return its head. 

For example,
 Given 1->2->3->4, you should return the list as 2->1->4->3. 

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
*/

#include "stdafx.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *swapPairs(ListNode *head) {        
        ListNode *dummy_head = new ListNode(0);
        dummy_head->next = head;        
        ListNode *cur = head;
        ListNode *pre_head = dummy_head;
        while (cur != NULL && cur->next != NULL) {            
            ListNode *next = cur->next;
            ListNode *to_link = next->next;
            pre_head->next = next;            
            next->next = cur;
            cur->next = to_link;
            pre_head = cur;
            cur = to_link;
        }
        return dummy_head->next;
    }
};
