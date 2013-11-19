/*
Sort a linked list in O(n log n) time using constant space complexity.
*/

#include "stdafx.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *sortList(ListNode *head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }

        ListNode *fast = head;
        ListNode *slow = head;
        while (fast->next != NULL && fast->next->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode *half_head = slow->next;
        slow->next = NULL;

        head = sortList(head);
        half_head = sortList(half_head);

        ListNode *dummy_head = new ListNode(0);
        ListNode *cur = dummy_head;
        while (head != NULL || half_head != NULL) {
            if (head == NULL) {
                cur->next = half_head;
                half_head = half_head->next;                
            } else if (half_head == NULL) {
                cur->next = head;
                head = head->next;                
            } else if (head->val < half_head->val) {
                cur->next = head;
                head = head->next;
            } else {
                cur->next = half_head;
                half_head = half_head->next;   
            }
            cur = cur->next;
        }
        return dummy_head->next;
    }
};
