/*
Given a sorted linked list, delete all duplicates such that each element appear only once.
 
For example,
 Given 1->1->2, return 1->2.
 Given 1->1->2->3->3, return 1->2->3. 
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
        ListNode *root = head;
        ListNode *cur = head;
        ListNode *before = new ListNode(0);
        before->next = head;
        ListNode *save = before;
        while (cur != NULL)
        {
            if (cur->next == NULL || cur->next->val != cur->val)
            {
                save = save->next;
                save->val = cur->val;
            }
            cur = cur->next;
        }
        if (save != NULL)
        {
            save->next = NULL;
        }
        return root;
    }
};

