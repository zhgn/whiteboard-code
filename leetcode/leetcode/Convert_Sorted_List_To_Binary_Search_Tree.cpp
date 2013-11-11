/*
Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
*/

#include "stdafx.h"
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
private:
    int getLen(ListNode *head) {
        int len = 0;
        while (head != NULL) {
            len++;
            head = head->next;
        }
        return len;        
    }

public:
    TreeNode *sortedListToBST(ListNode *head) {
        int len = getLen(head);
        if (len == 0) {
            return NULL;
        }
        if (len == 1) {            
            return new TreeNode(head->val);
        }
        ListNode *prev_mid = head;
        for (int count=len/2-1; count>0; count--) {
            prev_mid = prev_mid->next;
        }
        ListNode *mid = prev_mid->next;
        prev_mid->next = NULL;
        TreeNode *root = new TreeNode(mid->val);
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(mid->next);
        return root;
    }
};

