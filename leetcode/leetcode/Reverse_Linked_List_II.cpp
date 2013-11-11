/*
Reverse a linked list from position m to n. Do it in-place and in one-pass. 

For example:
 Given 1->2->3->4->5->NULL, m = 2 and n = 4, 

return 1->4->3->2->5->NULL. 

Note:
 Given m, n satisfy the following condition:
 1 ¡Ü m ¡Ü n ¡Ü length of list. 
*/

#include "stdafx.h"
#include <algorithm>

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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode *pre_node_m = new ListNode(0);
        pre_node_m->next = head;        
        for (int i=1; i<m; i++) {
            pre_node_m = pre_node_m->next;            
        }
        ListNode *node_m = pre_node_m->next;

        ListNode *node_n = head;        
        for (int i=1; i<n; i++) {
            node_n = node_n->next;
        }
        ListNode *post_node_n = node_n->next;
        node_n->next = NULL;

        pre_node_m->next = reverse(node_m);
        node_m->next = post_node_n;
        return (m==1) ? node_n : head;
    }
};
