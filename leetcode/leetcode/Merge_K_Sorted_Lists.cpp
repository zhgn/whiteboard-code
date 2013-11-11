/*
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity. 
*/

#include "stdafx.h"
#include <vector>
#include <stack>
#include <queue>

using namespace std;

struct ListNode {
   int val;
   ListNode *next;
   ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        priority_queue<pair<int,int>, vector<pair<int,int> >, Solution::MyCmp> p;
        int n = lists.size();
        ListNode *head = NULL;
        ListNode *cur = NULL;        
        for (int i=0; i<n; i++)
        {
            if (lists[i] != NULL)
            {
                p.push(make_pair(lists[i]->val, i));
            }
        }
        while (!p.empty())
        {
            if (head == NULL)
            {
                head = new ListNode(p.top().first);
                cur = head;
            }
            else
            {
                cur->next = new ListNode(p.top().first);
                cur = cur->next;
            }
            int x = p.top().second;
            lists[x] = lists[x]->next;
            p.pop();
            if (lists[x] != NULL)
            {
                p.push(make_pair(lists[x]->val, x));
            }                        
        }
        return head;
    }
    
    class MyCmp
    {
    public:
        bool operator() (const pair<int, int> &lhs, const pair<int, int> &rhs) const
        {        
            return lhs.first > rhs.first;
        }
    };
};
