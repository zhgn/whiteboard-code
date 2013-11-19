/*
Sort a linked list using insertion sort.
*/

#include "stdafx.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        ListNode *dummy_head = new ListNode(0);
        dummy_head->next = head;
        ListNode *cur = dummy_head;
        while (cur->next != NULL) {
            ListNode *ins;
            ListNode *node = cur->next;
            for (ins = dummy_head; ins != cur; ins = ins->next) {
                if (ins->next->val >= node->val) {
                    break;
                }
            }
            if (ins != cur) {
                cur->next = node->next;
                ListNode *save = ins->next;
                ins->next = node;
                node->next = save;
            } else {
                cur = cur->next;
            }            
        }
        return dummy_head->next;
    }
};
