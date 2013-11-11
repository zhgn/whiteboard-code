// leetcode.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <iostream>

using namespace std;

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
    bool reverse_k_nodes(ListNode *&pre_head, int k) {
        ListNode *tail = pre_head;
        for (int i=0; i<k; i++) {
            if (tail != NULL) {
                tail = tail->next;
            } else {
                return false;
            }            
        }
        if (tail == NULL) {
            return false;
        }
        
        ListNode *cur = pre_head->next;
        ListNode *pre = tail->next;
        ListNode *stop = tail->next;
        while (cur != stop) {
            ListNode *next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        ListNode *next_pre_head = pre_head->next;
        pre_head->next = tail;
        pre_head = next_pre_head;
        return true;
    }

public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        ListNode *dummy_head = new ListNode(0);
        dummy_head->next = head;        
        ListNode *pre_head = dummy_head;        
        while (reverse_k_nodes(pre_head, k)) {
            ;
        }
        return dummy_head->next;
    }
};

int _tmain(int argc, _TCHAR* argv[])
{
    Solution s;    
    ListNode *head = new ListNode(1);
    ListNode *p = new ListNode(2);
    head->next = p;
    s.reverseKGroup(head, 2);
    return 0;
}

