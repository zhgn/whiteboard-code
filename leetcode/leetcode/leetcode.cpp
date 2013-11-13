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

class LRUCache{
private:
    int m_capacity;
    list<int> data_list;
    unordered_map<int, list<int>::iterator> data_hash;

public:
    LRUCache(int capacity) {
        m_capacity = capacity;
        data_list.clear();
        data_hash.clear();
    }
    
    int get(int key) {
        auto it_member = data_hash.find(key);
        if (it_member == data_hash.end()) {
            return -1;
        }
        auto it_value = it_member->second;
        int value = (*it_value);
        
        data_list.erase(it_value);
        data_list.push_front(value);
        it_member->second = data_list.begin();
        return value;
    }
    
    void set(int key, int value) {                
        data_list.push_front(value);
        auto it_member = data_hash.find(key);        
        if (it_member == data_hash.end()) {
            data_hash.insert(make_pair(key, data_list.begin()));
        } else {
            auto it_value = it_member->second;
            data_list.erase(it_value);            
            it_member->second = data_list.begin(); 
        }                   

        if (data_list.size() > m_capacity) {
            int del_key = data_list.back();
            data_hash.erase(del_key);
            data_list.pop_back();
        }
    }
};

int _tmain(int argc, _TCHAR* argv[])
{
    LRUCache lru(1);
    lru.set(2,1);
    lru.get(2);
    lru.set(3,2);
    lru.get(2);
    lru.get(3);
    return 0;
}

