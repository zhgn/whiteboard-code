/*
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.
 
Return a deep copy of the list. 
*/

#include "stdafx.h"
#include <algorithm>

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == NULL) {
			return NULL;
		}
		RandomListNode *cur = head;				
		while (cur != NULL) {
			RandomListNode *cloned_node = new RandomListNode(cur->label);
			cloned_node->next = cur->next;
			cloned_node->random = cur->random;
			cur->next = cloned_node;
			cur = cloned_node->next;
		}
		cur = head;
		while (cur != NULL) {
			cur = cur->next;
			if (cur->random != NULL) {
				cur->random = cur->random->next;
			}
			cur = cur->next;
		}
		RandomListNode *cloned_head = head->next;	
		cur = head;
		while (cur->next != NULL) {
			RandomListNode *cur_next = cur->next;
			cur->next = cur_next->next;
			cur = cur_next;
		}
		return cloned_head;
    }
};
