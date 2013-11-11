/*
Given a singly linked list L: L0¡úL1¡ú¡­¡úLn-1¡úLn,
 reorder it to: L0¡úLn¡úL1¡úLn-1¡úL2¡úLn-2¡ú¡­ 

You must do this in-place without altering the nodes' values.

 For example,
 Given {1,2,3,4}, reorder it to {1,4,2,3}. 
*/

#include "stdafx.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
private:
    ListNode *reverse(ListNode *head) {
        ListNode *cur = head;
        ListNode *prev = NULL;
        while (cur != NULL) {
            ListNode *next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }

public:
    void reorderList(ListNode *head) {    
        ListNode *cur = head;
        ListNode *half_head = new ListNode(0);
        half_head->next = head;
        while (cur != NULL) {
            cur = cur->next;            
            half_head = half_head->next;
            if (cur != NULL) {
                cur = cur->next;
            }
        }
        ListNode *mid = half_head;
        half_head = half_head->next;
        mid->next = NULL;

        half_head = reverse(half_head);
        cur = head;
        while (half_head != NULL) {
            ListNode *next_1 = cur->next;
            ListNode *next_2 = half_head->next;
            cur->next = half_head;
            half_head->next = next_1;
            cur = next_1;
            half_head = next_2;
        }        
    }
};