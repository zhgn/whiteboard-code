/*
Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure. 
Note:
 A solution using O(n) space is pretty straight forward. Could you devise a constant space solution? 
*/

#include "stdafx.h"

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private: 
	void recoverTree(TreeNode *root, TreeNode *&unordered_node_1, TreeNode *&unordered_node_2, TreeNode *&prev) {
		if (root == NULL) {
			return;
		}
		recoverTree(root->left, unordered_node_1, unordered_node_2, prev);	
		if (prev != NULL && prev->val > root->val) {
			if (unordered_node_1 == NULL) {
				unordered_node_1 = prev;
			}
			unordered_node_2 = root;							 
		}
		prev = root;
		recoverTree(root->right, unordered_node_1, unordered_node_2, prev);
	}

public:
    void recoverTree(TreeNode *root) {
		TreeNode* unordered_node_1 = NULL;
        TreeNode* unordered_node_2 = NULL;
        TreeNode* prev = NULL;
        recoverTree(root, unordered_node_1, unordered_node_2, prev);
        if (unordered_node_1 != NULL && unordered_node_2 != NULL)
        {
            int swap = unordered_node_1->val;
            unordered_node_1->val = unordered_node_2->val;
            unordered_node_2->val = swap;
        }
        
    }
};