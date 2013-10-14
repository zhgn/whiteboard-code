/*
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.
 
For example,
 Given 1->2->3->3->4->4->5, return 1->2->5.
 Given 1->1->1->2->3, return 2->3. 
*/

#include "stdafx.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *cur = head;
        ListNode *before = new ListNode(0);
        ListNode *root = before;        
        before->next = head;
        while (cur != NULL)
        {
            int x = cur->val;
            int same = 0;
            while (cur->next != NULL && cur->next->val == x)
            {
                cur = cur->next;
                same = 1;
            }            
            if (same)
            {
                cur = cur->next;
            }
            else
            {
                before = before->next;
                before->val = cur->val;
                cur = cur->next;
            }
        }
        before->next = NULL;
        return root->next;
    }
};