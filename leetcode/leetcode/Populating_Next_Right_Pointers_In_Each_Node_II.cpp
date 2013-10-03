/*
Follow up for problem "Populating Next Right Pointers in Each Node".
 
What if the given tree could be any binary tree? Would your previous solution still work?
 
Note: 
•You may only use constant extra space.
 

For example,
 Given the following binary tree,
 
         1
       /  \
      2    3
     / \    \
    4   5    7
 

After calling your function, the tree should look like:
 
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \    \
    4-> 5 -> 7 -> NULL
*/

#include "stdafx.h"
#include <vector>

using namespace std;

struct TreeLinkNode {
    TreeLinkNode *left;
    TreeLinkNode *right;
    TreeLinkNode *next;
};

class Solution {
private:
	TreeLinkNode *findNextNode(TreeLinkNode *parent) {
		TreeLinkNode *cur = parent->next;
		while (cur != NULL) {				
			if (cur->left != NULL) {				
				return cur->left;
			} 
			if (cur->right != NULL) {
				return cur->right;	
			}
			cur = cur->next;
		}
		return NULL;
	}

public:
    void connect(TreeLinkNode *root) {
		if (root == NULL) {
			return;
		}
		if (root->left != NULL) {
			root->left->next = (root->right == NULL) ? findNextNode(root) : root->right;
		}
		if (root->right != NULL) {
			root->right->next = findNextNode(root);
		}
		connect(root->right);   
		connect(root->left);		       
    }
};
